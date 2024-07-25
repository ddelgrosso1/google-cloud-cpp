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
#include "google/cloud/internal/random.h"
#include <gmock/gmock.h>
#include <fstream>

namespace google {
namespace cloud {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN
namespace internal {
namespace {
std::string TempFileName() {
  static auto generator =
      google::cloud::internal::DefaultPRNG(std::random_device{}());
  return google::cloud::internal::PathAppend(
      ::testing::TempDir(),
      ::google::cloud::internal::Sample(
          generator, 16, "abcdefghijlkmnopqrstuvwxyz0123456789"));
}

TEST(DetectGcpPlatform, FileDoesNotExist) {
  auto const filename = TempFileName();
  auto has_sys_info = ::google::cloud::internal::HasGceBiosInfo(filename);

  EXPECT_FALSE(has_sys_info);
}

TEST(DetectGcpPlatform, HasGoogleString) {
  auto const google_file_name = TempFileName();
  auto const gce_file_name = TempFileName();

  std::ofstream(google_file_name) << "Google";
  std::ofstream(gce_file_name) << "Google Compute Engine";

  auto has_sys_info_google =
      ::google::cloud::internal::HasGceBiosInfo(google_file_name);
  auto has_sys_info_gce =
      ::google::cloud::internal::HasGceBiosInfo(gce_file_name);

  (void)std::remove(google_file_name.c_str());
  (void)std::remove(gce_file_name.c_str());

  EXPECT_TRUE(has_sys_info_google);
  EXPECT_TRUE(has_sys_info_gce);
}

TEST(DetectGcpPlatform, DoesNotHaveGoogleString) {
  auto const filename = TempFileName();
  std::ofstream(filename) << "Hello World";

  auto has_sys_info = ::google::cloud::internal::HasGceBiosInfo(filename);
  (void)std::remove(filename.c_str());

  EXPECT_FALSE(has_sys_info);
}

TEST(DetectGcpPlatform, HasGceMacAddress) {
  auto const temp_dir = ::testing::TempDir();
  auto const address_file =
      ::google::cloud::internal::PathAppend(temp_dir, "address");
  std::ofstream(address_file) << "42:01:c0:a8:30:6e";

  auto has_gce_mac = ::google::cloud::internal::HasGceMacAddress(temp_dir);
  (void)std::remove(address_file.c_str());

  EXPECT_TRUE(has_gce_mac);
}

TEST(DetectGcpPlatform, DoesNotHaveGceMacAddress) {
  auto const temp_dir = ::testing::TempDir();
  auto const address_file =
      ::google::cloud::internal::PathAppend(temp_dir, "address");
  std::ofstream(address_file) << "43:01:c0:a8:30:6e";

  auto has_gce_mac = ::google::cloud::internal::HasGceMacAddress(temp_dir);
  (void)std::remove(address_file.c_str());

  EXPECT_FALSE(has_gce_mac);
}
}  // namespace
}  // namespace internal
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace cloud
}  // namespace google
