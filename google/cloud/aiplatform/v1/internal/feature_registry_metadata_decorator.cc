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
// source: google/cloud/aiplatform/v1/feature_registry_service.proto

#include "google/cloud/aiplatform/v1/internal/feature_registry_metadata_decorator.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/absl_str_cat_quiet.h"
#include "google/cloud/internal/api_client_header.h"
#include "google/cloud/internal/url_encode.h"
#include "google/cloud/status_or.h"
#include <google/cloud/aiplatform/v1/feature_registry_service.grpc.pb.h>
#include <memory>
#include <string>
#include <utility>
#include <vector>

namespace google {
namespace cloud {
namespace aiplatform_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

FeatureRegistryServiceMetadata::FeatureRegistryServiceMetadata(
    std::shared_ptr<FeatureRegistryServiceStub> child,
    std::multimap<std::string, std::string> fixed_metadata,
    std::string api_client_header)
    : child_(std::move(child)),
      fixed_metadata_(std::move(fixed_metadata)),
      api_client_header_(
          api_client_header.empty()
              ? google::cloud::internal::GeneratedLibClientHeader()
              : std::move(api_client_header)) {}

future<StatusOr<google::longrunning::Operation>>
FeatureRegistryServiceMetadata::AsyncCreateFeatureGroup(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::aiplatform::v1::CreateFeatureGroupRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->AsyncCreateFeatureGroup(cq, std::move(context),
                                         std::move(options), request);
}

StatusOr<google::longrunning::Operation>
FeatureRegistryServiceMetadata::CreateFeatureGroup(
    grpc::ClientContext& context, Options options,
    google::cloud::aiplatform::v1::CreateFeatureGroupRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->CreateFeatureGroup(context, options, request);
}

StatusOr<google::cloud::aiplatform::v1::FeatureGroup>
FeatureRegistryServiceMetadata::GetFeatureGroup(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::GetFeatureGroupRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetFeatureGroup(context, options, request);
}

StatusOr<google::cloud::aiplatform::v1::ListFeatureGroupsResponse>
FeatureRegistryServiceMetadata::ListFeatureGroups(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::ListFeatureGroupsRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListFeatureGroups(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
FeatureRegistryServiceMetadata::AsyncUpdateFeatureGroup(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::aiplatform::v1::UpdateFeatureGroupRequest const& request) {
  SetMetadata(
      *context, *options,
      absl::StrCat("feature_group.name=",
                   internal::UrlEncode(request.feature_group().name())));
  return child_->AsyncUpdateFeatureGroup(cq, std::move(context),
                                         std::move(options), request);
}

StatusOr<google::longrunning::Operation>
FeatureRegistryServiceMetadata::UpdateFeatureGroup(
    grpc::ClientContext& context, Options options,
    google::cloud::aiplatform::v1::UpdateFeatureGroupRequest const& request) {
  SetMetadata(
      context, options,
      absl::StrCat("feature_group.name=",
                   internal::UrlEncode(request.feature_group().name())));
  return child_->UpdateFeatureGroup(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
FeatureRegistryServiceMetadata::AsyncDeleteFeatureGroup(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::aiplatform::v1::DeleteFeatureGroupRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncDeleteFeatureGroup(cq, std::move(context),
                                         std::move(options), request);
}

StatusOr<google::longrunning::Operation>
FeatureRegistryServiceMetadata::DeleteFeatureGroup(
    grpc::ClientContext& context, Options options,
    google::cloud::aiplatform::v1::DeleteFeatureGroupRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->DeleteFeatureGroup(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
FeatureRegistryServiceMetadata::AsyncCreateFeature(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::aiplatform::v1::CreateFeatureRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->AsyncCreateFeature(cq, std::move(context), std::move(options),
                                    request);
}

StatusOr<google::longrunning::Operation>
FeatureRegistryServiceMetadata::CreateFeature(
    grpc::ClientContext& context, Options options,
    google::cloud::aiplatform::v1::CreateFeatureRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->CreateFeature(context, options, request);
}

StatusOr<google::cloud::aiplatform::v1::Feature>
FeatureRegistryServiceMetadata::GetFeature(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::GetFeatureRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetFeature(context, options, request);
}

StatusOr<google::cloud::aiplatform::v1::ListFeaturesResponse>
FeatureRegistryServiceMetadata::ListFeatures(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::ListFeaturesRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListFeatures(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
FeatureRegistryServiceMetadata::AsyncUpdateFeature(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::aiplatform::v1::UpdateFeatureRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("feature.name=",
                           internal::UrlEncode(request.feature().name())));
  return child_->AsyncUpdateFeature(cq, std::move(context), std::move(options),
                                    request);
}

StatusOr<google::longrunning::Operation>
FeatureRegistryServiceMetadata::UpdateFeature(
    grpc::ClientContext& context, Options options,
    google::cloud::aiplatform::v1::UpdateFeatureRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("feature.name=",
                           internal::UrlEncode(request.feature().name())));
  return child_->UpdateFeature(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
FeatureRegistryServiceMetadata::AsyncDeleteFeature(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::aiplatform::v1::DeleteFeatureRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncDeleteFeature(cq, std::move(context), std::move(options),
                                    request);
}

StatusOr<google::longrunning::Operation>
FeatureRegistryServiceMetadata::DeleteFeature(
    grpc::ClientContext& context, Options options,
    google::cloud::aiplatform::v1::DeleteFeatureRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->DeleteFeature(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
FeatureRegistryServiceMetadata::AsyncGetOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::longrunning::GetOperationRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncGetOperation(cq, std::move(context), std::move(options),
                                   request);
}

future<Status> FeatureRegistryServiceMetadata::AsyncCancelOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::longrunning::CancelOperationRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncCancelOperation(cq, std::move(context),
                                      std::move(options), request);
}

void FeatureRegistryServiceMetadata::SetMetadata(
    grpc::ClientContext& context, Options const& options,
    std::string const& request_params) {
  context.AddMetadata("x-goog-request-params", request_params);
  SetMetadata(context, options);
}

void FeatureRegistryServiceMetadata::SetMetadata(grpc::ClientContext& context,
                                                 Options const& options) {
  google::cloud::internal::SetMetadata(context, options, fixed_metadata_,
                                       api_client_header_);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace aiplatform_v1_internal
}  // namespace cloud
}  // namespace google
