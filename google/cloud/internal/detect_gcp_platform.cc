// Copyright 2024 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "google/cloud/internal/detect_gcp_platform.h"
#include "google/cloud/internal/filesystem.h"
#include <fstream>
#include <iostream>
#include <regex>
#ifdef __unix__
#include <dirent.h>
#include <sys/stat.h>
#endif

namespace google {
namespace cloud {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN
namespace internal {
bool HasGceBiosInfo(std::string const& path) {
#ifdef _WIN32
  return false;
#else   // _WIN32
  auto product_name_status = google::cloud::internal::status(path);
  if (!google::cloud::internal::exists(product_name_status)) return false;

  std::ifstream product_name_file(path);
  std::string contents;
  if (!product_name_file.is_open()) return false;

  std::getline(product_name_file, contents);
  product_name_file.close();
  contents = std::regex_replace(contents, std::regex("^ +"), "");
  contents = std::regex_replace(contents, std::regex(" $"), "");

  return contents == "Google" || contents == "Google Compute Engine";
#endif  // _WIN32
}

bool HasGceMacAddress(std::string const& dir) {
#ifndef __unix__
  return false;
#else   // __unix__
  struct dirent* ent;
  std::regex mac_re("^42:01");
  DIR* directory = opendir(dir.c_str());

  while ((ent = readdir(directory)) != NULL) {
    struct stat path_stat;
    auto directory_item_path =
        ::google::cloud::internal::PathAppend(dir, ent->d_name);
    stat(directory_item_path.c_str(), &path_stat);

    if (S_ISDIR(path_stat.st_mode) != 0) {
      auto address_path =
          ::google::cloud::internal::PathAppend(directory_item_path, "address");
      auto address_path_status = google::cloud::internal::status(address_path);
      if (!google::cloud::internal::exists(address_path_status)) continue;

      std::ifstream address_file(address_path);
      if (!address_file.is_open()) continue;

      std::string contents;
      std::getline(address_file, contents);
      if (std::regex_search(contents, mac_re)) {
        address_file.close();
        closedir(directory);
        return true;
      }
      address_file.close();
    }
  }
  closedir(directory);
#endif  // __unix__
  return false;
}
}  // namespace internal
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace cloud
}  // namespace google
