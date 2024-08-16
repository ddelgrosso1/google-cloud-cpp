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

#include "google/cloud/internal/detect_gcp.h"
#include "google/cloud/internal/filesystem.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <vector>
#ifdef _WIN32
#include <Windows.h>
#include <stdlib.h>
#endif

namespace google {
namespace cloud {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN
namespace internal {

#ifdef _WIN32
std::string GoogleVirtualMachineDetector::GetBiosInformation(
    HKEY key, std::string const& sub_key, std::string const& value_key) {
  DWORD size{};
  LONG result = ::RegGetValueA(key, sub_key.c_str(), value_key.c_str(),
                               RRF_RT_REG_SZ, nullptr, nullptr, &size);

  if (result != ERROR_SUCCESS) return "";

  std::string contents;
  contents.resize(size / sizeof(char));
  result = ::RegGetValueA(key, sub_key.c_str(), value_key.c_str(),
                          RRF_RT_REG_SZ, nullptr, &contents[0], &size);

  if (result != ERROR_SUCCESS) return "";

  DWORD content_length = size / sizeof(char);
  content_length--;  // Exclude NUL written by WIN32
  contents.resize(content_length);

  return contents;
}
#else  // _WIN32
std::string GoogleVirtualMachineDetector::GetBiosInformation(
    std::string const& path) {
  auto product_name_status = google::cloud::internal::status(path);
  if (!google::cloud::internal::exists(product_name_status)) return "";

  std::ifstream product_name_file(path);
  std::string contents;
  if (!product_name_file.is_open()) return "";

  std::getline(product_name_file, contents);
  product_name_file.close();

  return contents;
}
#endif

bool GoogleVirtualMachineDetector::IsGoogleCloudBios() { return false; }

bool GoogleVirtualMachineDetector::IsGoogleCloudServerless(
    std::vector<std::string> const& env_variables) {
#ifdef _WIN32
  for (auto env_var : env_variables) {
    char* buf = nullptr;
    size_t size = 0;
    auto result = _dupenv_s(&buf, &size, env_var.c_str());
    if (result == 0 && buf != nullptr) {
      free(buf);
      return true;
    }
  }
#else  // _WIN32
  for (auto env_var : env_variables) {
    if (std::getenv(env_var.c_str()) != nullptr) return true;
  }
#endif

  return false;
}

}  // namespace internal
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace cloud
}  // namespace google
