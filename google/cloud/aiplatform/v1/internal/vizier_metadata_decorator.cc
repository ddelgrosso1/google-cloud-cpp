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
// source: google/cloud/aiplatform/v1/vizier_service.proto

#include "google/cloud/aiplatform/v1/internal/vizier_metadata_decorator.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/absl_str_cat_quiet.h"
#include "google/cloud/internal/api_client_header.h"
#include "google/cloud/internal/url_encode.h"
#include "google/cloud/status_or.h"
#include <google/cloud/aiplatform/v1/vizier_service.grpc.pb.h>
#include <memory>
#include <string>
#include <utility>
#include <vector>

namespace google {
namespace cloud {
namespace aiplatform_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

VizierServiceMetadata::VizierServiceMetadata(
    std::shared_ptr<VizierServiceStub> child,
    std::multimap<std::string, std::string> fixed_metadata,
    std::string api_client_header)
    : child_(std::move(child)),
      fixed_metadata_(std::move(fixed_metadata)),
      api_client_header_(
          api_client_header.empty()
              ? google::cloud::internal::GeneratedLibClientHeader()
              : std::move(api_client_header)) {}

StatusOr<google::cloud::aiplatform::v1::Study>
VizierServiceMetadata::CreateStudy(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::CreateStudyRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->CreateStudy(context, options, request);
}

StatusOr<google::cloud::aiplatform::v1::Study> VizierServiceMetadata::GetStudy(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::GetStudyRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetStudy(context, options, request);
}

StatusOr<google::cloud::aiplatform::v1::ListStudiesResponse>
VizierServiceMetadata::ListStudies(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::ListStudiesRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListStudies(context, options, request);
}

Status VizierServiceMetadata::DeleteStudy(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::DeleteStudyRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->DeleteStudy(context, options, request);
}

StatusOr<google::cloud::aiplatform::v1::Study>
VizierServiceMetadata::LookupStudy(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::LookupStudyRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->LookupStudy(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
VizierServiceMetadata::AsyncSuggestTrials(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::aiplatform::v1::SuggestTrialsRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->AsyncSuggestTrials(cq, std::move(context), std::move(options),
                                    request);
}

StatusOr<google::longrunning::Operation> VizierServiceMetadata::SuggestTrials(
    grpc::ClientContext& context, Options options,
    google::cloud::aiplatform::v1::SuggestTrialsRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->SuggestTrials(context, options, request);
}

StatusOr<google::cloud::aiplatform::v1::Trial>
VizierServiceMetadata::CreateTrial(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::CreateTrialRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->CreateTrial(context, options, request);
}

StatusOr<google::cloud::aiplatform::v1::Trial> VizierServiceMetadata::GetTrial(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::GetTrialRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetTrial(context, options, request);
}

StatusOr<google::cloud::aiplatform::v1::ListTrialsResponse>
VizierServiceMetadata::ListTrials(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::ListTrialsRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListTrials(context, options, request);
}

StatusOr<google::cloud::aiplatform::v1::Trial>
VizierServiceMetadata::AddTrialMeasurement(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::AddTrialMeasurementRequest const& request) {
  SetMetadata(
      context, options,
      absl::StrCat("trial_name=", internal::UrlEncode(request.trial_name())));
  return child_->AddTrialMeasurement(context, options, request);
}

StatusOr<google::cloud::aiplatform::v1::Trial>
VizierServiceMetadata::CompleteTrial(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::CompleteTrialRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->CompleteTrial(context, options, request);
}

Status VizierServiceMetadata::DeleteTrial(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::DeleteTrialRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->DeleteTrial(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
VizierServiceMetadata::AsyncCheckTrialEarlyStoppingState(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::aiplatform::v1::CheckTrialEarlyStoppingStateRequest const&
        request) {
  SetMetadata(
      *context, *options,
      absl::StrCat("trial_name=", internal::UrlEncode(request.trial_name())));
  return child_->AsyncCheckTrialEarlyStoppingState(cq, std::move(context),
                                                   std::move(options), request);
}

StatusOr<google::longrunning::Operation>
VizierServiceMetadata::CheckTrialEarlyStoppingState(
    grpc::ClientContext& context, Options options,
    google::cloud::aiplatform::v1::CheckTrialEarlyStoppingStateRequest const&
        request) {
  SetMetadata(
      context, options,
      absl::StrCat("trial_name=", internal::UrlEncode(request.trial_name())));
  return child_->CheckTrialEarlyStoppingState(context, options, request);
}

StatusOr<google::cloud::aiplatform::v1::Trial> VizierServiceMetadata::StopTrial(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::StopTrialRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->StopTrial(context, options, request);
}

StatusOr<google::cloud::aiplatform::v1::ListOptimalTrialsResponse>
VizierServiceMetadata::ListOptimalTrials(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::ListOptimalTrialsRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListOptimalTrials(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
VizierServiceMetadata::AsyncGetOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::longrunning::GetOperationRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncGetOperation(cq, std::move(context), std::move(options),
                                   request);
}

future<Status> VizierServiceMetadata::AsyncCancelOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::longrunning::CancelOperationRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncCancelOperation(cq, std::move(context),
                                      std::move(options), request);
}

void VizierServiceMetadata::SetMetadata(grpc::ClientContext& context,
                                        Options const& options,
                                        std::string const& request_params) {
  context.AddMetadata("x-goog-request-params", request_params);
  SetMetadata(context, options);
}

void VizierServiceMetadata::SetMetadata(grpc::ClientContext& context,
                                        Options const& options) {
  google::cloud::internal::SetMetadata(context, options, fixed_metadata_,
                                       api_client_header_);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace aiplatform_v1_internal
}  // namespace cloud
}  // namespace google
