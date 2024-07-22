// Copyright 2023 Google LLC
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

// Generated by the Codegen C++ plugin.
// If you make any local changes, they will be lost.
// source: google/api/servicecontrol/v2/service_controller.proto

#include "google/cloud/servicecontrol/v2/internal/service_controller_logging_decorator.h"
#include "google/cloud/internal/log_wrapper.h"
#include "google/cloud/status_or.h"
#include <google/api/servicecontrol/v2/service_controller.grpc.pb.h>
#include <memory>
#include <string>
#include <utility>

namespace google {
namespace cloud {
namespace servicecontrol_v2_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

ServiceControllerLogging::ServiceControllerLogging(
    std::shared_ptr<ServiceControllerStub> child,
    TracingOptions tracing_options, std::set<std::string> const&)
    : child_(std::move(child)), tracing_options_(std::move(tracing_options)) {}

StatusOr<google::api::servicecontrol::v2::CheckResponse>
ServiceControllerLogging::Check(
    grpc::ClientContext& context, Options const& options,
    google::api::servicecontrol::v2::CheckRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::api::servicecontrol::v2::CheckRequest const& request) {
        return child_->Check(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::api::servicecontrol::v2::ReportResponse>
ServiceControllerLogging::Report(
    grpc::ClientContext& context, Options const& options,
    google::api::servicecontrol::v2::ReportRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::api::servicecontrol::v2::ReportRequest const& request) {
        return child_->Report(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace servicecontrol_v2_internal
}  // namespace cloud
}  // namespace google
