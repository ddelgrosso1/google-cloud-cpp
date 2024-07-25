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

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_INTERNAL_DETECT_GCP_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_INTERNAL_DETECT_GCP_H

#include "google/cloud/version.h"
#include <string>
#include <vector>
#ifdef _WIN32
#include <Windows.h>
#endif

namespace google {
namespace cloud {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN
namespace internal {

class IVirtualMachineDetector {
 public:
  virtual bool IsGoogleCloudBios() = 0;
  virtual bool IsGoogleCloudServerless(
      std::vector<std::string> const& env_variables) = 0;
#ifdef _WIN32
  virtual std::string GetBiosInformation(HKEY key, std::string const& sub_key,
                                         std::string const& value_key) = 0;
#else  // _WIN32
  virtual std::string GetBiosInformation(std::string const& path) = 0;
#endif
};
class GoogleVirtualMachineDetector : IVirtualMachineDetector {
 public:
  bool IsGoogleCloudBios() override;
  bool IsGoogleCloudServerless(std::vector<std::string> const& env_variables = {
                                   "CLOUD_RUN_JOB", "FUNCTION_NAME",
                                   "K_SERVICE"}) override;
#ifdef _WIN32
  std::string GetBiosInformation(
      HKEY key = HKEY_LOCAL_MACHINE,
      std::string const& sub_key = "SYSTEM\\HardwareConfig\\Current",
      std::string const& value_key = "SystemProductName") override;
#else  // _WIN32
  std::string GetBiosInformation(
      std::string const& path = "/sys/class/dmi/id/product_name") override;
#endif
};

}  // namespace internal
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_INTERNAL_DETECT_GCP_H
