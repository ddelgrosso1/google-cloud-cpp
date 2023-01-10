// Copyright 2021 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "generator/internal/scaffold_generator.h"
#include "google/cloud/internal/absl_str_join_quiet.h"
#include "google/cloud/internal/absl_str_replace_quiet.h"
#include "google/cloud/internal/filesystem.h"
#include "google/cloud/log.h"
#include "absl/strings/str_split.h"
#include <google/protobuf/io/printer.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <nlohmann/json.hpp>
#include <fstream>
#include <iterator>
#ifdef _WIN32
#include <direct.h>
#else
#include <sys/stat.h>
#endif  // _WIN32

namespace google {
namespace cloud {
namespace generator_internal {
namespace {

struct ProductPath {
  std::string prefix;
  std::string library_name;
  std::string service_subdirectory;
};

ProductPath ParseProductPath(std::string const& product_path) {
  std::vector<absl::string_view> v =
      absl::StrSplit(product_path, '/', absl::SkipEmpty());
  if (v.empty()) return {};
  auto make_result = [&v](auto it) -> ProductPath {
    return {
        absl::StrJoin(v.begin(), it, "/"),
        std::string{*it},
        absl::StrJoin(std::next(it), v.end(), "/"),
    };
  };
  // This is the case for our production code.
  if (v.size() > 2 && v[0] == "google" && v[1] == "cloud") {
    return make_result(std::next(v.begin(), 2));
  }
  // "golden" is a special library name used in our golden testing.
  auto it = std::find(v.begin(), v.end(), "golden");
  if (it != v.end()) return make_result(it);
  // Else, just assume the last element is the library.
  return make_result(std::prev(v.end()));
}

}  // namespace

auto constexpr kApiIndexFilename = "api-index-v1.json";
auto constexpr kWorkspaceTemplate = "WORKSPACE.bazel";

std::string LibraryName(std::string const& product_path) {
  return ParseProductPath(product_path).library_name;
}

std::string LibraryPath(std::string const& product_path) {
  auto parsed = ParseProductPath(product_path);
  return absl::StrCat(parsed.prefix, "/", parsed.library_name, "/");
}

std::string ServiceSubdirectory(std::string const& product_path) {
  auto parsed = ParseProductPath(product_path);
  if (parsed.service_subdirectory.empty()) return std::string{};
  return absl::StrCat(parsed.service_subdirectory, "/");
}

std::string OptionsGroup(std::string const& product_path) {
  return absl::StrCat(
      absl::StrReplaceAll(LibraryPath(product_path), {{"/", "-"}}), "options");
}

std::string SiteRoot(
    google::cloud::cpp::generator::ServiceConfiguration const& service) {
  // TODO(#7605) - get a configurable source for this
  return LibraryName(service.product_path());
}

std::map<std::string, std::string> ScaffoldVars(
    std::string const& googleapis_path,
    google::cloud::cpp::generator::ServiceConfiguration const& service,
    bool experimental) {
  auto const api_index_path = googleapis_path + "/" + kApiIndexFilename;
  auto status = google::cloud::internal::status(api_index_path);
  if (!exists(status)) {
    GCP_LOG(WARNING) << "Cannot find API index file (" << api_index_path << ")";
    return {};
  }
  std::ifstream is(api_index_path);
  auto index = nlohmann::json::parse(is, nullptr, false);
  if (index.is_null()) {
    GCP_LOG(WARNING) << "Cannot parse API index file (" << api_index_path
                     << ")";
    return {};
  }
  if (!index.contains("apis")) {
    GCP_LOG(WARNING) << "Missing `apis` field in API index file ("
                     << api_index_path << ")";
    return {};
  }
  std::map<std::string, std::string> vars;
  for (auto const& api : index["apis"]) {
    if (!api.contains("directory")) continue;
    auto const directory = api["directory"].get<std::string>() + "/";
    if (!absl::StartsWith(service.service_proto_path(), directory)) continue;
    vars.emplace("title", api.value("title", ""));
    vars.emplace("description", api.value("description", ""));
    vars.emplace("directory", api.value("directory", ""));
  }
  auto const library = LibraryName(service.product_path());
  vars["copyright_year"] = service.initial_copyright_year();
  vars["library"] = library;
  vars["product_options_page"] = OptionsGroup(service.product_path());
  vars["service_subdirectory"] = ServiceSubdirectory(service.product_path());
  vars["site_root"] = SiteRoot(service);
  vars["library_prefix"] = experimental ? "experimental-" : "";
  vars["doxygen_version_suffix"] = experimental ? " (Experimental)" : "";
  vars["construction"] = experimental ? "\n:construction:\n" : "";
  vars["status"] =
      experimental ? "This library is **experimental**. Its APIs are subject "
                     "to change without notice.\n\nPlease,"
                   : "While this library is **GA**, please";

  return vars;
}

void MakeDirectory(std::string const& path) {
#if _WIN32
  _mkdir(path.c_str());
#else
  mkdir(path.c_str(), 0755);
#endif  // _WIN32
}

void GenerateScaffold(
    std::string const& googleapis_path,
    std::string const& scaffold_templates_path, std::string const& output_path,
    google::cloud::cpp::generator::ServiceConfiguration const& service,
    bool experimental) {
  using Generator = std::function<void(
      std::ostream&, std::map<std::string, std::string> const&)>;
  struct Destination {
    std::string name;
    Generator generator;
  } files[] = {
      {"config.cmake.in", GenerateCmakeConfigIn},
      {"README.md", GenerateReadme},
      {"BUILD.bazel", GenerateBuild},
      {"CMakeLists.txt", GenerateCMakeLists},
      {"doc/main.dox", GenerateDoxygenMainPage},
      {"doc/options.dox", GenerateDoxygenOptionsPage},
      {"quickstart/README.md", GenerateQuickstartReadme},
      {"quickstart/quickstart.cc", GenerateQuickstartSkeleton},
      {"quickstart/CMakeLists.txt", GenerateQuickstartCMake},
      {"quickstart/Makefile", GenerateQuickstartMakefile},
      {"quickstart/BUILD.bazel", GenerateQuickstartBuild},
      {"quickstart/.bazelrc", GenerateQuickstartBazelrc},
  };

  auto const vars = ScaffoldVars(googleapis_path, service, experimental);
  MakeDirectory(output_path + "/");
  auto const destination =
      output_path + "/" + LibraryPath(service.product_path());
  MakeDirectory(destination);
  MakeDirectory(destination + "doc/");
  MakeDirectory(destination + "quickstart/");
  for (auto const& f : files) {
    std::ofstream os(destination + f.name);
    f.generator(os, vars);
  }
  std::ifstream is(scaffold_templates_path + kWorkspaceTemplate);
  auto const contents = std::string{std::istreambuf_iterator<char>(is), {}};
  std::ofstream os(destination + "quickstart/WORKSPACE.bazel");
  GenerateQuickstartWorkspace(os, vars, contents);
}

void GenerateCmakeConfigIn(
    std::ostream& os, std::map<std::string, std::string> const& variables) {
  auto constexpr kText =
      R"""(# Copyright $copyright_year$ Google LLC
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     https://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

include(CMakeFindDependencyMacro)
# google_cloud_cpp_googleapis finds both gRPC and Protobuf, no need to load them here.
find_dependency(google_cloud_cpp_googleapis)
find_dependency(google_cloud_cpp_common)
find_dependency(google_cloud_cpp_grpc_utils)
find_dependency(absl)

include("$${CMAKE_CURRENT_LIST_DIR}/google_cloud_cpp_$library$-targets.cmake")
)""";
  google::protobuf::io::OstreamOutputStream output(&os);
  google::protobuf::io::Printer printer(&output, '$');
  printer.Print(variables, kText);
}

void GenerateReadme(std::ostream& os,
                    std::map<std::string, std::string> const& variables) {
  auto constexpr kText = R"""(# $title$ C++ Client Library
$construction$
This directory contains an idiomatic C++ client library for the
[$title$][cloud-service-docs], a service to $description$

$status$ note that the Google Cloud C++ client
libraries do **not** follow [Semantic Versioning](https://semver.org/).

## Supported Platforms

* Windows, macOS, Linux
* C++14 (and higher) compilers (we test with GCC >= 7.3, Clang >= 6.0, and
  MSVC >= 2017)
* Environments with or without exceptions
* Bazel (>= 4.0) and CMake (>= 3.5) builds

## Documentation

* Official documentation about the [$title$][cloud-service-docs] service
* [Reference doxygen documentation][doxygen-link] for each release of this
  client library
* Detailed header comments in our [public `.h`][source-link] files

[cloud-service-docs]: https://cloud.google.com/$site_root$
[doxygen-link]: https://googleapis.dev/cpp/google-cloud-$library$/latest/
[source-link]: https://github.com/googleapis/google-cloud-cpp/tree/main/google/cloud/$library$

## Quickstart

The [quickstart/](quickstart/README.md) directory contains a minimal environment
to get started using this client library in a larger project. The following
"Hello World" program is used in this quickstart, and should give you a taste of
this library.

<!-- inject-quickstart-start -->
<!-- inject-quickstart-end -->

* Packaging maintainers or developers who prefer to install the library in a
  fixed directory (such as `/usr/local` or `/opt`) should consult the
  [packaging guide](/doc/packaging.md).
- Developers who prefer using a package manager such as
  [vcpkg](https://vcpkg.io), [Conda](https://conda.io),
  or [Conan](https://conan.io) should follow the instructions for their package
  manager.
* Developers wanting to use the libraries as part of a larger CMake or Bazel
  project should consult the [quickstart guides](#quickstart) for the library
  or libraries they want to use.
* Developers wanting to compile the library just to run some examples or
  tests should read the current document.
* Contributors and developers to `google-cloud-cpp` should consult the guide to
  [set up a development workstation][howto-setup-dev-workstation].

[howto-setup-dev-workstation]: /doc/contributor/howto-guide-setup-development-workstation.md

## Contributing changes

See [`CONTRIBUTING.md`](/CONTRIBUTING.md) for details on how to
contribute to this project, including how to build and test your changes
as well as how to properly format your code.

## Licensing

Apache 2.0; see [`LICENSE`](/LICENSE) for details.
)""";
  google::protobuf::io::OstreamOutputStream output(&os);
  google::protobuf::io::Printer printer(&output, '$');
  printer.Print(variables, kText);
}

void GenerateBuild(std::ostream& os,
                   std::map<std::string, std::string> const& variables) {
  auto constexpr kText = R"""(# Copyright $copyright_year$ Google LLC
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     https://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

package(default_visibility = ["//visibility:private"])

licenses(["notice"])  # Apache 2.0

service_dirs = ["$service_subdirectory$"]

src_dirs = service_dirs + [d + "internal/" for d in service_dirs]

filegroup(
    name = "srcs",
    srcs = glob([d + "*.cc" for d in src_dirs]),
)

filegroup(
    name = "hdrs",
    srcs = glob([d + "*.h" for d in src_dirs]),
)

filegroup(
    name = "mocks",
    srcs = glob([d + "mocks/*.h" for d in service_dirs]),
)

cc_library(
    name = "google_cloud_cpp_$library$",
    srcs = [":srcs"],
    hdrs = [":hdrs"],
    visibility = ["//:__pkg__"],
    deps = [
        "//:common",
        "//:grpc_utils",
        "@com_google_googleapis//$directory$:$library$_cc_grpc",
    ],
)

cc_library(
    name = "google_cloud_cpp_$library$_mocks",
    hdrs = [":mocks"],
    visibility = ["//:__pkg__"],
    deps = [
        ":google_cloud_cpp_$library$",
        "@com_google_googletest//:gtest",
    ],
)

[cc_test(
    name = sample.replace("/", "_").replace(".cc", ""),
    srcs = [sample],
    tags = ["integration-test"],
    deps = [
        "//:$library$",
        "//google/cloud/testing_util:google_cloud_cpp_testing_private",
    ],
) for sample in glob([d + "samples/*.cc" for d in service_dirs])]
)""";
  google::protobuf::io::OstreamOutputStream output(&os);
  google::protobuf::io::Printer printer(&output, '$');
  printer.Print(variables, kText);
}

void GenerateCMakeLists(std::ostream& os,
                        std::map<std::string, std::string> const& variables) {
  auto constexpr kText = R"""(# ~~~
# Copyright $copyright_year$ Google LLC
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     https://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# ~~~

include(GoogleapisConfig)
set(DOXYGEN_PROJECT_NAME "$title$ C++ Client")
set(DOXYGEN_PROJECT_BRIEF "A C++ Client Library for the $title$")
set(DOXYGEN_PROJECT_NUMBER "$${PROJECT_VERSION}$doxygen_version_suffix$")
set(DOXYGEN_EXCLUDE_SYMBOLS "internal")
set(DOXYGEN_EXAMPLE_PATH $${CMAKE_CURRENT_SOURCE_DIR}/quickstart)

unset(mocks_globs)
unset(source_globs)
set(service_dirs "$service_subdirectory$")
foreach (dir IN LISTS service_dirs)
    string(REPLACE "/" "_" ns "$${dir}")
    list(APPEND source_globs "$${dir}*.h" "$${dir}*.cc" "$${dir}internal/*")
    list(APPEND mocks_globs "$${dir}mocks/*.h")
    list(APPEND DOXYGEN_EXAMPLE_PATH
         "$${CMAKE_CURRENT_SOURCE_DIR}/$${dir}samples")
    list(APPEND DOXYGEN_EXCLUDE_SYMBOLS "$library$_$${ns}internal")
endforeach ()

# Creates the proto headers needed by doxygen.
set(GOOGLE_CLOUD_CPP_DOXYGEN_DEPS google-cloud-cpp::$library$_protos)

include(GoogleCloudCppCommon)

find_path(PROTO_INCLUDE_DIR google/protobuf/descriptor.proto)
if (PROTO_INCLUDE_DIR)
    list(INSERT PROTOBUF_IMPORT_DIRS 0 "$${PROTO_INCLUDE_DIR}")
endif ()

include(CompileProtos)
google_cloud_cpp_load_protolist(
    proto_list
    "$${PROJECT_SOURCE_DIR}/external/googleapis/protolists/$library$.list")
google_cloud_cpp_load_protodeps(
    proto_deps
    "$${PROJECT_SOURCE_DIR}/external/googleapis/protodeps/$library$.deps")
google_cloud_cpp_grpcpp_library(
    google_cloud_cpp_$library$_protos # cmake-format: sort
    $${proto_list}
    PROTO_PATH_DIRECTORIES
    "$${EXTERNAL_GOOGLEAPIS_SOURCE}" "$${PROTO_INCLUDE_DIR}")
external_googleapis_set_version_and_alias($library$_protos)
target_link_libraries(google_cloud_cpp_$library$_protos PUBLIC $${proto_deps})

file(GLOB source_files
     RELATIVE "$${CMAKE_CURRENT_SOURCE_DIR}"
     $${source_globs})
list(SORT source_files)
add_library(google_cloud_cpp_$library$ $${source_files})
target_include_directories(
    google_cloud_cpp_$library$
    PUBLIC $$<BUILD_INTERFACE:$${PROJECT_SOURCE_DIR}>
           $$<BUILD_INTERFACE:$${PROJECT_BINARY_DIR}>
           $$<INSTALL_INTERFACE:include>)
target_link_libraries(
    google_cloud_cpp_$library$
    PUBLIC google-cloud-cpp::grpc_utils google-cloud-cpp::common
           google-cloud-cpp::$library$_protos)
google_cloud_cpp_add_common_options(google_cloud_cpp_$library$)
set_target_properties(
    google_cloud_cpp_$library$
    PROPERTIES EXPORT_NAME google-cloud-cpp::$library_prefix$$library$
               VERSION "$${PROJECT_VERSION}"
               SOVERSION "$${PROJECT_VERSION_MAJOR}")
target_compile_options(google_cloud_cpp_$library$
                       PUBLIC $${GOOGLE_CLOUD_CPP_EXCEPTIONS_FLAG})

add_library(google-cloud-cpp::$library_prefix$$library$ ALIAS google_cloud_cpp_$library$)

# Create a header-only library for the mocks. We use a CMake `INTERFACE` library
# for these, a regular library would not work on macOS (where the library needs
# at least one .o file). Unfortunately INTERFACE libraries are a bit weird in
# that they need absolute paths for their sources.
file(GLOB relative_mock_files
     RELATIVE "$${CMAKE_CURRENT_SOURCE_DIR}"
     $${mocks_globs})
list(SORT relative_mock_files)
set(mock_files)
foreach (file IN LISTS relative_mock_files)
  list(APPEND mock_files "$${CMAKE_CURRENT_SOURCE_DIR}/$${file}")
endforeach ()
add_library(google_cloud_cpp_$library$_mocks INTERFACE)
target_sources(google_cloud_cpp_$library$_mocks INTERFACE $${mock_files})
target_link_libraries(
    google_cloud_cpp_$library$_mocks
    INTERFACE google-cloud-cpp::$library_prefix$$library$ GTest::gmock_main
              GTest::gmock GTest::gtest)
set_target_properties(
    google_cloud_cpp_$library$_mocks
    PROPERTIES EXPORT_NAME google-cloud-cpp::$library_prefix$$library$_mocks)
target_include_directories(
    google_cloud_cpp_$library$_mocks
    INTERFACE $$<BUILD_INTERFACE:$${PROJECT_SOURCE_DIR}>
              $$<BUILD_INTERFACE:$${PROJECT_BINARY_DIR}>
              $$<INSTALL_INTERFACE:include>)
target_compile_options(google_cloud_cpp_$library$_mocks
                       INTERFACE $${GOOGLE_CLOUD_CPP_EXCEPTIONS_FLAG})

include(CTest)
if (BUILD_TESTING)
    add_executable($library$_quickstart "quickstart/quickstart.cc")
    target_link_libraries($library$_quickstart
                          PRIVATE google-cloud-cpp::$library_prefix$$library$)
    google_cloud_cpp_add_common_options($library$_quickstart)
    add_test(
        NAME $library$_quickstart
        COMMAND cmake -P "$${PROJECT_SOURCE_DIR}/cmake/quickstart-runner.cmake"
                $$<TARGET_FILE:$library$_quickstart> GOOGLE_CLOUD_PROJECT
                # EDIT HERE
                )
    set_tests_properties($library$_quickstart
                         PROPERTIES LABELS "integration-test;quickstart")
endif ()

# Get the destination directories based on the GNU recommendations.
include(GNUInstallDirs)

# Export the CMake targets to make it easy to create configuration files.
install(
    EXPORT google_cloud_cpp_$library$-targets
    DESTINATION "$${CMAKE_INSTALL_LIBDIR}/cmake/google_cloud_cpp_$library$"
    COMPONENT google_cloud_cpp_development)

# Install the libraries and headers in the locations determined by
# GNUInstallDirs
install(
    TARGETS google_cloud_cpp_$library$ google_cloud_cpp_$library$_protos
    EXPORT google_cloud_cpp_$library$-targets
    RUNTIME DESTINATION $${CMAKE_INSTALL_BINDIR}
            COMPONENT google_cloud_cpp_runtime
    LIBRARY DESTINATION $${CMAKE_INSTALL_LIBDIR}
            COMPONENT google_cloud_cpp_runtime
            NAMELINK_SKIP
    ARCHIVE DESTINATION $${CMAKE_INSTALL_LIBDIR}
            COMPONENT google_cloud_cpp_development)
# With CMake-3.12 and higher we could avoid this separate command (and the
# duplication).
install(
    TARGETS google_cloud_cpp_$library$ google_cloud_cpp_$library$_protos
    LIBRARY DESTINATION $${CMAKE_INSTALL_LIBDIR}
            COMPONENT google_cloud_cpp_development
            NAMELINK_ONLY
    ARCHIVE DESTINATION $${CMAKE_INSTALL_LIBDIR}
            COMPONENT google_cloud_cpp_development)

google_cloud_cpp_install_proto_library_protos("google_cloud_cpp_$library$_protos"
                                              "$${EXTERNAL_GOOGLEAPIS_SOURCE}")
google_cloud_cpp_install_proto_library_headers("google_cloud_cpp_$library$_protos")
google_cloud_cpp_install_headers("google_cloud_cpp_$library$"
                                 "include/google/cloud/$library$")
google_cloud_cpp_install_headers("google_cloud_cpp_$library$_mocks"
                                 "include/google/cloud/$library$")

google_cloud_cpp_add_pkgconfig(
    $library$
    "The $title$ C++ Client Library"
    "Provides C++ APIs to use the $title$."
    "google_cloud_cpp_grpc_utils"
    " google_cloud_cpp_common"
    " google_cloud_cpp_$library$_protos")

# Create and install the CMake configuration files.
include(CMakePackageConfigHelpers)
configure_file("config.cmake.in" "google_cloud_cpp_$library$-config.cmake" @ONLY)
write_basic_package_version_file(
    "google_cloud_cpp_$library$-config-version.cmake"
    VERSION $${PROJECT_VERSION}
    COMPATIBILITY ExactVersion)

install(
    FILES
        "$${CMAKE_CURRENT_BINARY_DIR}/google_cloud_cpp_$library$-config.cmake"
        "$${CMAKE_CURRENT_BINARY_DIR}/google_cloud_cpp_$library$-config-version.cmake"
    DESTINATION "$${CMAKE_INSTALL_LIBDIR}/cmake/google_cloud_cpp_$library$"
    COMPONENT google_cloud_cpp_development)

external_googleapis_install_pc("google_cloud_cpp_$library$_protos")

# google-cloud-cpp::$library$ must be defined before we can add the samples.
foreach (dir IN LISTS service_dirs)
    if (BUILD_TESTING AND GOOGLE_CLOUD_CPP_ENABLE_CXX_EXCEPTIONS)
        google_cloud_cpp_add_samples_relative("$library$" "$${dir}samples/")
    endif ()
endforeach ()
)""";
  google::protobuf::io::OstreamOutputStream output(&os);
  google::protobuf::io::Printer printer(&output, '$');
  printer.Print(variables, kText);
}

void GenerateDoxygenMainPage(
    std::ostream& os, std::map<std::string, std::string> const& variables) {
  auto constexpr kText = R"""(/*!

@mainpage $title$ C++ Client Library

An idiomatic C++ client library for the [$title$][cloud-service-docs], a service
to $description$

$status$ note that the Google Cloud C++ client libraries do **not** follow
[Semantic Versioning](https://semver.org/).

This library requires a C++14 compiler. It is supported (and tested) on multiple
Linux distributions, as well as Windows and macOS. The [README][github-readme]
on [GitHub][github-link] provides detailed instructions to install the necessary
dependencies, as well as how to compile the client library.

@tableofcontents{HTML:2}

## Setting up your repo

In order to use the $title$ C++ client library from your own code,
you'll need to configure your build system to discover and compile the Cloud
C++ client libraries. In some cases your build system or package manager may
need to download the libraries too. The Cloud C++ client libraries natively
support [Bazel](https://bazel.build/) and [CMake](https://cmake.org/) as build
systems. We've created a minimal, "Hello World", [quickstart][github-quickstart]
that includes detailed instructions on how to compile the library for use in
your application. You can fetch the source from [GitHub][github-link] as normal:

@code{.sh}
git clone https://github.com/googleapis/google-cloud-cpp.git
cd google-cloud-cpp/google/cloud/$library$/quickstart
@endcode

@par Example: Quickstart

The following shows the code that you'll run in the
`google/cloud/$library$/quickstart/` directory,
which should give you a taste of the $title$ C++ client library API.

@snippet quickstart.cc all

## Environment Variables

<!-- inject-endpoint-env-vars-start -->
<!-- inject-endpoint-env-vars-end -->

- `GOOGLE_CLOUD_CPP_ENABLE_TRACING=rpc` turns on tracing for most gRPC
  calls. The library injects an additional Stub decorator that prints each gRPC
  request and response.  Unless you have configured your own logging backend,
  you should also set `GOOGLE_CLOUD_CPP_ENABLE_CLOG` to produce any output on
  the program's console.

- `GOOGLE_CLOUD_CPP_ENABLE_TRACING=rpc-streams` turns on tracing for streaming
  gRPC calls. This can produce a lot of output, so use with caution!

- `GOOGLE_CLOUD_CPP_TRACING_OPTIONS=...` modifies the behavior of gRPC tracing,
  including whether messages will be output on multiple lines, or whether
  string/bytes fields will be truncated.

- `GOOGLE_CLOUD_CPP_ENABLE_CLOG=yes` turns on logging in the library. Basically
  the library always "logs" but the logging infrastructure has no backend to
  actually print anything until the application sets a backend or it sets this
  environment variable.

## Error Handling

[status-or-header]: https://github.com/googleapis/google-cloud-cpp/blob/main/google/cloud/status_or.h

This library never throws exceptions to signal error, but you can use exceptions
to detect errors in the returned objects. In general, the library returns a
[`StatusOr<T>`][status-or-header] if an error is possible. This is an "outcome"
type, when the operation is successful a `StatusOr<T>` converts to `true` in
boolean context (and its `.ok()` member function returns `true`), the
application can then use `operator->` or `operator*` to access the `T` value.
When the operation fails a `StatusOr<T>` converts to `false` (and `.ok()`
returns `false`). It is undefined behavior to use the value in this case.

If you prefer to use exceptions on error, you can use the `.value()` accessor.
It will return the `T` value or throw on error.

For operations that do not return a value the library simply returns
`google::cloud::Status`.

## Override the default endpoint

In some cases, you may need to override the default endpoint used by the client
library. Use the `google::cloud::EndpointOption` when initializing the client
library to change this default.

<!-- inject-endpoint-snippet-start -->
<!-- inject-endpoint-snippet-end -->

## Override the authentication configuration

Some applications cannot use the default authentication mechanism (known as
[Application Default Credentials]). You can override this default using
`google::cloud::UnifiedCredentialsOption`. The following example shows how
to explicitly load a service account key file.

<!-- inject-service-account-snippet-start -->
<!-- inject-service-account-snippet-end -->

Keep in mind that we chose this as an example because it is relatively easy to
understand. Consult the [Best practices for managing service account keys]
guide for more details.

@see @ref guac - for more information on the factory functions to create
`google::cloud::Credentials` objects.

[Best practices for managing service account keys]: https://cloud.google.com/iam/docs/best-practices-for-managing-service-account-keys
[Application Default Credentials]: https://cloud.google.com/docs/authentication#adc

## Retry, Backoff, and Idempotency Policies.

The library automatically retries requests that fail with transient errors, and
uses [exponential backoff] to backoff between retries. Application developers
can override the default policies.

[cloud-service-docs]: https://cloud.google.com/$site_root$
[exponential backoff]: https://en.wikipedia.org/wiki/Exponential_backoff
[github-link]: https://github.com/googleapis/google-cloud-cpp 'GitHub Repository'
<!-- The ugly %2E disables auto-linking in Doxygen -->
[github-readme]:  https://github.com/googleapis/google-cloud-cpp/blob/main/google/cloud/$library$/README%2Emd
[github-quickstart]:  https://github.com/googleapis/google-cloud-cpp/blob/main/google/cloud/$library$/quickstart/README%2Emd

*/

// <!-- inject-endpoint-pages-start -->
// <!-- inject-endpoint-pages-end -->
)""";
  google::protobuf::io::OstreamOutputStream output(&os);
  google::protobuf::io::Printer printer(&output, '$');
  printer.Print(variables, kText);
}

void GenerateDoxygenOptionsPage(
    std::ostream& os, std::map<std::string, std::string> const& variables) {
  auto constexpr kText = R"""(/*!
@defgroup $product_options_page$ $title$ Configuration Options

This library uses the same mechanism (`google::cloud::Options`) and the common
[options](@ref options) as all other C++ client libraries for its configuration.
Some `*Option` classes, which are only used in this library, are documented in
this page.

@see @ref options - for an overview of client library configuration.
*/
)""";
  google::protobuf::io::OstreamOutputStream output(&os);
  google::protobuf::io::Printer printer(&output, '$');
  printer.Print(variables, kText);
}

void GenerateQuickstartReadme(
    std::ostream& os, std::map<std::string, std::string> const& variables) {
  auto constexpr kText =
      R"""(# HOWTO: using the $title$ C++ client in your project

This directory contains small examples showing how to use the $title$ C++
client library in your own project. These instructions assume that you have
some experience as a C++ developer and that you have a working C++ toolchain
(compiler, linker, etc.) installed on your platform.

* Packaging maintainers or developers who prefer to install the library in a
  fixed directory (such as `/usr/local` or `/opt`) should consult the
  [packaging guide](/doc/packaging.md).
- Developers who prefer using a package manager such as
  [vcpkg](https://vcpkg.io), [Conda](https://conda.io),
  or [Conan](https://conan.io) should follow the instructions for their package
  manager.
* Developers wanting to use the libraries as part of a larger CMake or Bazel
  project should consult the current document. Note that there are similar
  documents for each library in their corresponding directories.
* Developers wanting to compile the library just to run some examples or
  tests should consult the
  [building and installing](/README.md#building-and-installing) section of the
  top-level README file.
* Contributors and developers to `google-cloud-cpp` should consult the guide to
  [set up a development workstation][howto-setup-dev-workstation].

[howto-setup-dev-workstation]: /doc/contributor/howto-guide-setup-development-workstation.md

## Before you begin

To run the quickstart examples you will need a working Google Cloud Platform
(GCP) project. The [quickstart][quickstart-link] covers the necessary
steps in detail.

## Configuring authentication for the C++ Client Library

Like most Google Cloud Platform (GCP) services, $title$ requires that
your application authenticates with the service before accessing any data. If
you are not familiar with GCP authentication please take this opportunity to
review the [Authentication Overview][authentication-quickstart]. This library
uses the `GOOGLE_APPLICATION_CREDENTIALS` environment variable to find the
credentials file. For example:

| Shell              | Command                                        |
| :----------------- | ---------------------------------------------- |
| Bash/zsh/ksh/etc.  | `export GOOGLE_APPLICATION_CREDENTIALS=[PATH]` |
| sh                 | `GOOGLE_APPLICATION_CREDENTIALS=[PATH];`<br> `export GOOGLE_APPLICATION_CREDENTIALS` |
| csh/tsch           | `setenv GOOGLE_APPLICATION_CREDENTIALS [PATH]` |
| Windows Powershell | `$$env:GOOGLE_APPLICATION_CREDENTIALS=[PATH]`   |
| Windows cmd.exe    | `set GOOGLE_APPLICATION_CREDENTIALS=[PATH]`    |

Setting this environment variable is the recommended way to configure the
authentication preferences, though if the environment variable is not set, the
library searches for a credentials file in the same location as the [Cloud
SDK](https://cloud.google.com/sdk/). For more information about *Application
Default Credentials*, see
https://cloud.google.com/docs/authentication/production

## Using with Bazel

> :warning: If you are using Windows or macOS there are additional instructions
> at the end of this document.

1. Install Bazel using [the instructions][bazel-install] from the `bazel.build`
   website.

1. Compile this example using Bazel:

   ```bash
   cd $$HOME/google-cloud-cpp/google/cloud/$library$/quickstart
   bazel build ...
   ```

   Note that Bazel automatically downloads and compiles all dependencies of the
   project. As it is often the case with C++ libraries, compiling these
   dependencies may take several minutes.

1. Run the example, changing the placeholder(s) to appropriate values:

   ```bash
   bazel run :quickstart -- [...]
   ```

## Using with CMake

> :warning: If you are using Windows or macOS there are additional instructions
> at the end of this document.

1. Install CMake. The package managers for most Linux distributions include a
   package for CMake. Likewise, you can install CMake on Windows using a package
   manager such as [chocolatey][choco-cmake-link], and on macOS using
   [homebrew][homebrew-cmake-link]. You can also obtain the software directly
   from the [cmake.org](https://cmake.org/download/).

1. Install the dependencies with your favorite tools. As an example, if you use
   [vcpkg](https://github.com/Microsoft/vcpkg.git):

   ```bash
   cd $$HOME/vcpkg
   ./vcpkg install google-cloud-cpp[core,$library$]
   ```

   Note that, as it is often the case with C++ libraries, compiling these
   dependencies may take several minutes.

1. Configure CMake, if necessary, configure the directory where you installed
   the dependencies:

   ```bash
   cd $$HOME/gooogle-cloud-cpp/google/cloud/$library$/quickstart
   cmake -H. -B.build -DCMAKE_TOOLCHAIN_FILE=$$HOME/vcpkg/scripts/buildsystems/vcpkg.cmake
   cmake --build .build
   ```

1. Run the example, changing the placeholder(s) to appropriate values:

   ```bash
   .build/quickstart [...]
   ```

## Platform Specific Notes

### macOS

gRPC [requires][grpc-roots-pem-bug] an environment variable to configure the
trust store for SSL certificates, you can download and configure this using:

```bash
curl -Lo roots.pem https://pki.google.com/roots.pem
export GRPC_DEFAULT_SSL_ROOTS_FILE_PATH="$$PWD/roots.pem"
```

To workaround a [bug in Bazel][bazel-grpc-macos-bug], gRPC requires this flag on
macOS builds, you can add the option manually or include it in your `.bazelrc`
file:

```bash
bazel build --copt=-DGRPC_BAZEL_BUILD ...
```

### Windows

Bazel tends to create very long file names and paths. You may need to use a
short directory to store the build output, such as `c:\b`, and instruct Bazel
to use it via:

```shell
bazel --output_user_root=c:\b build ...
```

gRPC [requires][grpc-roots-pem-bug] an environment variable to configure the
trust store for SSL certificates, you can download and configure this using:

```console
@powershell -NoProfile -ExecutionPolicy unrestricted -Command ^
    (new-object System.Net.WebClient).Downloadfile( ^
        'https://pki.google.com/roots.pem', 'roots.pem')
set GRPC_DEFAULT_SSL_ROOTS_FILE_PATH=%cd%\roots.pem
```

[bazel-install]: https://docs.bazel.build/versions/main/install.html
[quickstart-link]: https://cloud.google.com/$site_root$/docs/quickstart
[grpc-roots-pem-bug]: https://github.com/grpc/grpc/issues/16571
[choco-cmake-link]: https://chocolatey.org/packages/cmake
[homebrew-cmake-link]: https://formulae.brew.sh/formula/cmake
[cmake-download-link]: https://cmake.org/download/
[bazel-grpc-macos-bug]: https://github.com/bazelbuild/bazel/issues/4341
[authentication-quickstart]: https://cloud.google.com/docs/authentication/getting-started 'Authentication Getting Started'
)""";
  google::protobuf::io::OstreamOutputStream output(&os);
  google::protobuf::io::Printer printer(&output, '$');
  printer.Print(variables, kText);
}

void GenerateQuickstartSkeleton(
    std::ostream& os, std::map<std::string, std::string> const& variables) {
  auto constexpr kText = R"""(// Copyright $copyright_year$ Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

//! [all]
#include "google/cloud/$library$/ EDIT HERE .h"
#include "google/cloud/project.h"
#include <iostream>

int main(int argc, char* argv[]) try {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " project-id\n";
    return 1;
  }

  namespace $library$ = ::google::cloud::$library$;
  auto client = $library$::Client(
      $library$::MakeConnection());

  auto const project = google::cloud::Project(argv[1]);
  for (auto r : client.List/*EDIT HERE*/(project.FullName())) {
    if (!r) throw std::move(r).status();
    std::cout << r->DebugString() << "\n";
  }

  return 0;
} catch (google::cloud::Status const& status) {
  std::cerr << "google::cloud::Status thrown: " << status << "\n";
  return 1;
}
//! [all]
)""";
  google::protobuf::io::OstreamOutputStream output(&os);
  google::protobuf::io::Printer printer(&output, '$');
  printer.Print(variables, kText);
}

void GenerateQuickstartCMake(
    std::ostream& os, std::map<std::string, std::string> const& variables) {
  auto constexpr kText = R"""(# Copyright $copyright_year$ Google LLC
#
# Licensed under the Apache License, Version 2.0 (the "License"); you may not
# use this file except in compliance with the License. You may obtain a copy of
# the License at
#
# https://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
# License for the specific language governing permissions and limitations under
# the License.

# This file shows how to use the $title$ C++ client library from a larger
# CMake project.

cmake_minimum_required(VERSION 3.10...3.24)
project(google-cloud-cpp-$library$-quickstart CXX)

find_package(google_cloud_cpp_$library$ REQUIRED)

# MSVC requires some additional code to select the correct runtime library
if (VCPKG_TARGET_TRIPLET MATCHES "-static$$")
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$$<$$<CONFIG:Debug>:Debug>")
else ()
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$$<$$<CONFIG:Debug>:Debug>DLL")
endif ()

# Define your targets.
add_executable(quickstart quickstart.cc)
target_link_libraries(quickstart google-cloud-cpp::$library_prefix$$library$)
)""";
  google::protobuf::io::OstreamOutputStream output(&os);
  google::protobuf::io::Printer printer(&output, '$');
  printer.Print(variables, kText);
}

void GenerateQuickstartMakefile(
    std::ostream& os, std::map<std::string, std::string> const& variables) {
  auto constexpr kText = R"""(# Copyright $copyright_year$ Google LLC
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     https://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# This is a minimal Makefile to show how to use the $title$ C++ client
# for developers who use make(1) as their build system.

# The CXX, CXXFLAGS and CXXLD variables are hard-coded. These values work for
# our tests, but applications would typically make them configurable parameters.
CXX=g++
CXXFLAGS=
CXXLD=$$(CXX)
BIN=.

all: $$(BIN)/quickstart

# Configuration variables to compile and link against the $title$ C++
# client library.
CLIENT_MODULE     := google_cloud_cpp_$library$
CLIENT_CXXFLAGS   := $$(shell pkg-config $$(CLIENT_MODULE) --cflags)
CLIENT_CXXLDFLAGS := $$(shell pkg-config $$(CLIENT_MODULE) --libs-only-L)
CLIENT_LIBS       := $$(shell pkg-config $$(CLIENT_MODULE) --libs-only-l)

$$(BIN)/quickstart: quickstart.cc
)""";
  std::string format = kText;
  format += "\t";
  format +=
      R"""($$(CXXLD) $$(CXXFLAGS) $$(CLIENT_CXXFLAGS) $$(CLIENT_CXXLDFLAGS) -o $$@ $$^ $$(CLIENT_LIBS)
)""";
  google::protobuf::io::OstreamOutputStream output(&os);
  google::protobuf::io::Printer printer(&output, '$');
  printer.Print(variables, format.c_str());
}

void GenerateQuickstartWorkspace(
    std::ostream& os, std::map<std::string, std::string> const& variables,
    std::string const& contents) {
  google::protobuf::io::OstreamOutputStream output(&os);
  google::protobuf::io::Printer printer(&output, '$');
  printer.Print(variables, contents.c_str());
}

void GenerateQuickstartBuild(
    std::ostream& os, std::map<std::string, std::string> const& variables) {
  auto constexpr kText = R"""(# Copyright $copyright_year$ Google LLC
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     https://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

licenses(["notice"])  # Apache 2.0

cc_binary(
    name = "quickstart",
    srcs = [
        "quickstart.cc",
    ],
    deps = [
        "@google_cloud_cpp//:$library_prefix$$library$",
    ],
)
)""";
  google::protobuf::io::OstreamOutputStream output(&os);
  google::protobuf::io::Printer printer(&output, '$');
  printer.Print(variables, kText);
}

void GenerateQuickstartBazelrc(
    std::ostream& os, std::map<std::string, std::string> const& variables) {
  auto constexpr kText = R"""(# Copyright $copyright_year$ Google LLC
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     https://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# To workaround a bug in Bazel [1], gRPC requires this flag on macOS builds,
# and there is (AFAIK) no way to "inherit" their definitions.
#   [1]: https://github.com/bazelbuild/bazel/issues/4341
build --copt=-DGRPC_BAZEL_BUILD

# Use host-OS-specific config lines from bazelrc files.
build --enable_platform_specific_config=true

# The project requires C++ >= 14. By default Bazel adds `-std=c++0x` which
# disables C++14 features, even if the compilers defaults to C++ >= 14
build:linux --cxxopt=-std=c++14
build:macos --cxxopt=-std=c++14

# Do not create the convenience links. They are inconvenient when the build
# runs inside a docker image or if one builds a quickstart and then builds
# the project separately.
build --experimental_convenience_symlinks=ignore
)""";
  google::protobuf::io::OstreamOutputStream output(&os);
  google::protobuf::io::Printer printer(&output, '$');
  printer.Print(variables, kText);
}

}  // namespace generator_internal
}  // namespace cloud
}  // namespace google
