// Copyright 2024 Google LLC
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
// source: google/cloud/servicehealth/v1/event_service.proto

#include "google/cloud/servicehealth/v1/internal/service_health_connection_impl.h"
#include "google/cloud/servicehealth/v1/internal/service_health_option_defaults.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/pagination_range.h"
#include "google/cloud/internal/retry_loop.h"
#include <memory>

namespace google {
namespace cloud {
namespace servicehealth_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN
namespace {

std::unique_ptr<servicehealth_v1::ServiceHealthRetryPolicy> retry_policy(
    Options const& options) {
  return options.get<servicehealth_v1::ServiceHealthRetryPolicyOption>()
      ->clone();
}

std::unique_ptr<BackoffPolicy> backoff_policy(Options const& options) {
  return options.get<servicehealth_v1::ServiceHealthBackoffPolicyOption>()
      ->clone();
}

std::unique_ptr<servicehealth_v1::ServiceHealthConnectionIdempotencyPolicy>
idempotency_policy(Options const& options) {
  return options
      .get<servicehealth_v1::ServiceHealthConnectionIdempotencyPolicyOption>()
      ->clone();
}

}  // namespace

ServiceHealthConnectionImpl::ServiceHealthConnectionImpl(
    std::unique_ptr<google::cloud::BackgroundThreads> background,
    std::shared_ptr<servicehealth_v1_internal::ServiceHealthStub> stub,
    Options options)
    : background_(std::move(background)),
      stub_(std::move(stub)),
      options_(internal::MergeOptions(std::move(options),
                                      ServiceHealthConnection::options())) {}

StreamRange<google::cloud::servicehealth::v1::Event>
ServiceHealthConnectionImpl::ListEvents(
    google::cloud::servicehealth::v1::ListEventsRequest request) {
  request.clear_page_token();
  auto current = google::cloud::internal::SaveCurrentOptions();
  auto idempotency = idempotency_policy(*current)->ListEvents(request);
  char const* function_name = __func__;
  return google::cloud::internal::MakePaginationRange<
      StreamRange<google::cloud::servicehealth::v1::Event>>(
      std::move(request),
      [idempotency, function_name, stub = stub_,
       retry = std::shared_ptr<servicehealth_v1::ServiceHealthRetryPolicy>(
           retry_policy(*current)),
       backoff = std::shared_ptr<BackoffPolicy>(backoff_policy(*current))](
          google::cloud::servicehealth::v1::ListEventsRequest const& r) {
        return google::cloud::internal::RetryLoop(
            retry->clone(), backoff->clone(), idempotency,
            [stub](grpc::ClientContext& context,
                   google::cloud::servicehealth::v1::ListEventsRequest const&
                       request) { return stub->ListEvents(context, request); },
            r, function_name);
      },
      [](google::cloud::servicehealth::v1::ListEventsResponse r) {
        std::vector<google::cloud::servicehealth::v1::Event> result(
            r.events().size());
        auto& messages = *r.mutable_events();
        std::move(messages.begin(), messages.end(), result.begin());
        return result;
      });
}

StatusOr<google::cloud::servicehealth::v1::Event>
ServiceHealthConnectionImpl::GetEvent(
    google::cloud::servicehealth::v1::GetEventRequest const& request) {
  auto current = google::cloud::internal::SaveCurrentOptions();
  return google::cloud::internal::RetryLoop(
      retry_policy(*current), backoff_policy(*current),
      idempotency_policy(*current)->GetEvent(request),
      [this](grpc::ClientContext& context,
             google::cloud::servicehealth::v1::GetEventRequest const& request) {
        return stub_->GetEvent(context, request);
      },
      request, __func__);
}

StreamRange<google::cloud::servicehealth::v1::OrganizationEvent>
ServiceHealthConnectionImpl::ListOrganizationEvents(
    google::cloud::servicehealth::v1::ListOrganizationEventsRequest request) {
  request.clear_page_token();
  auto current = google::cloud::internal::SaveCurrentOptions();
  auto idempotency =
      idempotency_policy(*current)->ListOrganizationEvents(request);
  char const* function_name = __func__;
  return google::cloud::internal::MakePaginationRange<
      StreamRange<google::cloud::servicehealth::v1::OrganizationEvent>>(
      std::move(request),
      [idempotency, function_name, stub = stub_,
       retry = std::shared_ptr<servicehealth_v1::ServiceHealthRetryPolicy>(
           retry_policy(*current)),
       backoff = std::shared_ptr<BackoffPolicy>(backoff_policy(*current))](
          google::cloud::servicehealth::v1::ListOrganizationEventsRequest const&
              r) {
        return google::cloud::internal::RetryLoop(
            retry->clone(), backoff->clone(), idempotency,
            [stub](grpc::ClientContext& context,
                   google::cloud::servicehealth::v1::
                       ListOrganizationEventsRequest const& request) {
              return stub->ListOrganizationEvents(context, request);
            },
            r, function_name);
      },
      [](google::cloud::servicehealth::v1::ListOrganizationEventsResponse r) {
        std::vector<google::cloud::servicehealth::v1::OrganizationEvent> result(
            r.organization_events().size());
        auto& messages = *r.mutable_organization_events();
        std::move(messages.begin(), messages.end(), result.begin());
        return result;
      });
}

StatusOr<google::cloud::servicehealth::v1::OrganizationEvent>
ServiceHealthConnectionImpl::GetOrganizationEvent(
    google::cloud::servicehealth::v1::GetOrganizationEventRequest const&
        request) {
  auto current = google::cloud::internal::SaveCurrentOptions();
  return google::cloud::internal::RetryLoop(
      retry_policy(*current), backoff_policy(*current),
      idempotency_policy(*current)->GetOrganizationEvent(request),
      [this](
          grpc::ClientContext& context,
          google::cloud::servicehealth::v1::GetOrganizationEventRequest const&
              request) {
        return stub_->GetOrganizationEvent(context, request);
      },
      request, __func__);
}

StreamRange<google::cloud::servicehealth::v1::OrganizationImpact>
ServiceHealthConnectionImpl::ListOrganizationImpacts(
    google::cloud::servicehealth::v1::ListOrganizationImpactsRequest request) {
  request.clear_page_token();
  auto current = google::cloud::internal::SaveCurrentOptions();
  auto idempotency =
      idempotency_policy(*current)->ListOrganizationImpacts(request);
  char const* function_name = __func__;
  return google::cloud::internal::MakePaginationRange<
      StreamRange<google::cloud::servicehealth::v1::OrganizationImpact>>(
      std::move(request),
      [idempotency, function_name, stub = stub_,
       retry = std::shared_ptr<servicehealth_v1::ServiceHealthRetryPolicy>(
           retry_policy(*current)),
       backoff = std::shared_ptr<BackoffPolicy>(backoff_policy(*current))](
          google::cloud::servicehealth::v1::
              ListOrganizationImpactsRequest const& r) {
        return google::cloud::internal::RetryLoop(
            retry->clone(), backoff->clone(), idempotency,
            [stub](grpc::ClientContext& context,
                   google::cloud::servicehealth::v1::
                       ListOrganizationImpactsRequest const& request) {
              return stub->ListOrganizationImpacts(context, request);
            },
            r, function_name);
      },
      [](google::cloud::servicehealth::v1::ListOrganizationImpactsResponse r) {
        std::vector<google::cloud::servicehealth::v1::OrganizationImpact>
            result(r.organization_impacts().size());
        auto& messages = *r.mutable_organization_impacts();
        std::move(messages.begin(), messages.end(), result.begin());
        return result;
      });
}

StatusOr<google::cloud::servicehealth::v1::OrganizationImpact>
ServiceHealthConnectionImpl::GetOrganizationImpact(
    google::cloud::servicehealth::v1::GetOrganizationImpactRequest const&
        request) {
  auto current = google::cloud::internal::SaveCurrentOptions();
  return google::cloud::internal::RetryLoop(
      retry_policy(*current), backoff_policy(*current),
      idempotency_policy(*current)->GetOrganizationImpact(request),
      [this](
          grpc::ClientContext& context,
          google::cloud::servicehealth::v1::GetOrganizationImpactRequest const&
              request) {
        return stub_->GetOrganizationImpact(context, request);
      },
      request, __func__);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace servicehealth_v1_internal
}  // namespace cloud
}  // namespace google
