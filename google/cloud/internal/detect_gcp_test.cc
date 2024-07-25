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
#include "google/cloud/internal/random.h"
#include "absl/strings/string_view.h"
#include <gmock/gmock.h>
#include <fstream>
#ifdef _WIN32
#include <Windows.h>
#endif

namespace google {
namespace cloud {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN
namespace internal {
namespace {

class RunMultiValueTest : public ::testing::TestWithParam<absl::string_view> {};
INSTANTIATE_TEST_SUITE_P(DetectGcpPlatform, RunMultiValueTest,
                         testing::Values("Google", "Google Compute Engine",
                                         "  Google  ",
                                         " Google  Compute Engine  "));

#ifdef _WIN32
std::string const& parent_key = "SOFTWARE\\GoogleCloudCpp";
std::string const& sub_key = "SOFTWARE\\GoogleCloudCpp\\Test";
std::string const& value_key = "TestProductName";

void WriteTestRegistryValue(std::string value) {
  HKEY hKey;

  LONG result = ::RegCreateKeyExA(HKEY_CURRENT_USER, sub_key.c_str(), 0,
                                  nullptr, REG_OPTION_NON_VOLATILE,
                                  KEY_ALL_ACCESS, nullptr, &hKey, nullptr);
  if (result != ERROR_SUCCESS) return;
  result = ::RegSetValueExA(hKey, value_key.c_str(), 0, REG_SZ,
                            (LPBYTE)value.c_str(), strlen(value.c_str()) + 1);
  if (result != ERROR_SUCCESS) return;
  ::RegCloseKey(hKey);
}
void CleanupTestRegistryValue() {
  LONG result =
      ::RegDeleteKeyExA(HKEY_CURRENT_USER, sub_key.c_str(), KEY_ALL_ACCESS, 0);
  if (result != ERROR_SUCCESS) return;
  ::RegDeleteKeyExA(HKEY_CURRENT_USER, parent_key.c_str(), KEY_ALL_ACCESS, 0);
}

TEST(DetectGcpPlatform, RegistryValueDoesNotExist) {
  auto platform_detector =
      ::google::cloud::internal::GoogleVirtualMachineDetector();
  auto bios_value = platform_detector.GetBiosInformation(HKEY_CURRENT_USER,
                                                         sub_key, value_key);

  EXPECT_TRUE("" == bios_value);
}
#else  // _WIN32
std::string TempFileName() {
  static auto generator =
      google::cloud::internal::DefaultPRNG(std::random_device{}());
  return google::cloud::internal::PathAppend(
      ::testing::TempDir(),
      ::google::cloud::internal::Sample(
          generator, 16, "abcdefghijlkmnopqrstuvwxyz0123456789"));
}

TEST(DetectGcpPlatform, FileDoesNotExist) {
  auto const file_name = TempFileName();
  auto platform_detector =
      ::google::cloud::internal::GoogleVirtualMachineDetector();
  auto bios_value = platform_detector.GetBiosInformation(file_name);

  EXPECT_TRUE("" == bios_value);
}

TEST_P(RunMultiValueTest, FileExists) {
  auto const file_name = TempFileName();
  auto cur_param = GetParam();

  std::ofstream(file_name) << cur_param;

  auto platform_detector =
      ::google::cloud::internal::GoogleVirtualMachineDetector();
  auto bios_value = platform_detector.GetBiosInformation(file_name);
  (void)std::remove(file_name.c_str());

  EXPECT_TRUE(cur_param == bios_value);
}
#endif

}  // namespace
}  // namespace internal
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace cloud
}  // namespace google
