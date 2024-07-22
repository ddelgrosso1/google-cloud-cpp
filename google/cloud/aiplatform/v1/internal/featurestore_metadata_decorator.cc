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
// source: google/cloud/aiplatform/v1/featurestore_service.proto

#include "google/cloud/aiplatform/v1/internal/featurestore_metadata_decorator.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/absl_str_cat_quiet.h"
#include "google/cloud/internal/api_client_header.h"
#include "google/cloud/internal/url_encode.h"
#include "google/cloud/status_or.h"
#include <google/cloud/aiplatform/v1/featurestore_service.grpc.pb.h>
#include <memory>
#include <string>
#include <utility>
#include <vector>

namespace google {
namespace cloud {
namespace aiplatform_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

FeaturestoreServiceMetadata::FeaturestoreServiceMetadata(
    std::shared_ptr<FeaturestoreServiceStub> child,
    std::multimap<std::string, std::string> fixed_metadata,
    std::string api_client_header)
    : child_(std::move(child)),
      fixed_metadata_(std::move(fixed_metadata)),
      api_client_header_(
          api_client_header.empty()
              ? google::cloud::internal::GeneratedLibClientHeader()
              : std::move(api_client_header)) {}

future<StatusOr<google::longrunning::Operation>>
FeaturestoreServiceMetadata::AsyncCreateFeaturestore(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::aiplatform::v1::CreateFeaturestoreRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->AsyncCreateFeaturestore(cq, std::move(context),
                                         std::move(options), request);
}

StatusOr<google::longrunning::Operation>
FeaturestoreServiceMetadata::CreateFeaturestore(
    grpc::ClientContext& context, Options options,
    google::cloud::aiplatform::v1::CreateFeaturestoreRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->CreateFeaturestore(context, options, request);
}

StatusOr<google::cloud::aiplatform::v1::Featurestore>
FeaturestoreServiceMetadata::GetFeaturestore(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::GetFeaturestoreRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetFeaturestore(context, options, request);
}

StatusOr<google::cloud::aiplatform::v1::ListFeaturestoresResponse>
FeaturestoreServiceMetadata::ListFeaturestores(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::ListFeaturestoresRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListFeaturestores(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
FeaturestoreServiceMetadata::AsyncUpdateFeaturestore(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::aiplatform::v1::UpdateFeaturestoreRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("featurestore.name=",
                           internal::UrlEncode(request.featurestore().name())));
  return child_->AsyncUpdateFeaturestore(cq, std::move(context),
                                         std::move(options), request);
}

StatusOr<google::longrunning::Operation>
FeaturestoreServiceMetadata::UpdateFeaturestore(
    grpc::ClientContext& context, Options options,
    google::cloud::aiplatform::v1::UpdateFeaturestoreRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("featurestore.name=",
                           internal::UrlEncode(request.featurestore().name())));
  return child_->UpdateFeaturestore(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
FeaturestoreServiceMetadata::AsyncDeleteFeaturestore(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::aiplatform::v1::DeleteFeaturestoreRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncDeleteFeaturestore(cq, std::move(context),
                                         std::move(options), request);
}

StatusOr<google::longrunning::Operation>
FeaturestoreServiceMetadata::DeleteFeaturestore(
    grpc::ClientContext& context, Options options,
    google::cloud::aiplatform::v1::DeleteFeaturestoreRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->DeleteFeaturestore(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
FeaturestoreServiceMetadata::AsyncCreateEntityType(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::aiplatform::v1::CreateEntityTypeRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->AsyncCreateEntityType(cq, std::move(context),
                                       std::move(options), request);
}

StatusOr<google::longrunning::Operation>
FeaturestoreServiceMetadata::CreateEntityType(
    grpc::ClientContext& context, Options options,
    google::cloud::aiplatform::v1::CreateEntityTypeRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->CreateEntityType(context, options, request);
}

StatusOr<google::cloud::aiplatform::v1::EntityType>
FeaturestoreServiceMetadata::GetEntityType(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::GetEntityTypeRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetEntityType(context, options, request);
}

StatusOr<google::cloud::aiplatform::v1::ListEntityTypesResponse>
FeaturestoreServiceMetadata::ListEntityTypes(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::ListEntityTypesRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListEntityTypes(context, options, request);
}

StatusOr<google::cloud::aiplatform::v1::EntityType>
FeaturestoreServiceMetadata::UpdateEntityType(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::UpdateEntityTypeRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("entity_type.name=",
                           internal::UrlEncode(request.entity_type().name())));
  return child_->UpdateEntityType(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
FeaturestoreServiceMetadata::AsyncDeleteEntityType(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::aiplatform::v1::DeleteEntityTypeRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncDeleteEntityType(cq, std::move(context),
                                       std::move(options), request);
}

StatusOr<google::longrunning::Operation>
FeaturestoreServiceMetadata::DeleteEntityType(
    grpc::ClientContext& context, Options options,
    google::cloud::aiplatform::v1::DeleteEntityTypeRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->DeleteEntityType(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
FeaturestoreServiceMetadata::AsyncCreateFeature(
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
FeaturestoreServiceMetadata::CreateFeature(
    grpc::ClientContext& context, Options options,
    google::cloud::aiplatform::v1::CreateFeatureRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->CreateFeature(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
FeaturestoreServiceMetadata::AsyncBatchCreateFeatures(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::aiplatform::v1::BatchCreateFeaturesRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->AsyncBatchCreateFeatures(cq, std::move(context),
                                          std::move(options), request);
}

StatusOr<google::longrunning::Operation>
FeaturestoreServiceMetadata::BatchCreateFeatures(
    grpc::ClientContext& context, Options options,
    google::cloud::aiplatform::v1::BatchCreateFeaturesRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->BatchCreateFeatures(context, options, request);
}

StatusOr<google::cloud::aiplatform::v1::Feature>
FeaturestoreServiceMetadata::GetFeature(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::GetFeatureRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetFeature(context, options, request);
}

StatusOr<google::cloud::aiplatform::v1::ListFeaturesResponse>
FeaturestoreServiceMetadata::ListFeatures(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::ListFeaturesRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListFeatures(context, options, request);
}

StatusOr<google::cloud::aiplatform::v1::Feature>
FeaturestoreServiceMetadata::UpdateFeature(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::UpdateFeatureRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("feature.name=",
                           internal::UrlEncode(request.feature().name())));
  return child_->UpdateFeature(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
FeaturestoreServiceMetadata::AsyncDeleteFeature(
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
FeaturestoreServiceMetadata::DeleteFeature(
    grpc::ClientContext& context, Options options,
    google::cloud::aiplatform::v1::DeleteFeatureRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->DeleteFeature(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
FeaturestoreServiceMetadata::AsyncImportFeatureValues(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::aiplatform::v1::ImportFeatureValuesRequest const& request) {
  SetMetadata(
      *context, *options,
      absl::StrCat("entity_type=", internal::UrlEncode(request.entity_type())));
  return child_->AsyncImportFeatureValues(cq, std::move(context),
                                          std::move(options), request);
}

StatusOr<google::longrunning::Operation>
FeaturestoreServiceMetadata::ImportFeatureValues(
    grpc::ClientContext& context, Options options,
    google::cloud::aiplatform::v1::ImportFeatureValuesRequest const& request) {
  SetMetadata(
      context, options,
      absl::StrCat("entity_type=", internal::UrlEncode(request.entity_type())));
  return child_->ImportFeatureValues(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
FeaturestoreServiceMetadata::AsyncBatchReadFeatureValues(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::aiplatform::v1::BatchReadFeatureValuesRequest const&
        request) {
  SetMetadata(*context, *options,
              absl::StrCat("featurestore=",
                           internal::UrlEncode(request.featurestore())));
  return child_->AsyncBatchReadFeatureValues(cq, std::move(context),
                                             std::move(options), request);
}

StatusOr<google::longrunning::Operation>
FeaturestoreServiceMetadata::BatchReadFeatureValues(
    grpc::ClientContext& context, Options options,
    google::cloud::aiplatform::v1::BatchReadFeatureValuesRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("featurestore=",
                           internal::UrlEncode(request.featurestore())));
  return child_->BatchReadFeatureValues(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
FeaturestoreServiceMetadata::AsyncExportFeatureValues(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::aiplatform::v1::ExportFeatureValuesRequest const& request) {
  SetMetadata(
      *context, *options,
      absl::StrCat("entity_type=", internal::UrlEncode(request.entity_type())));
  return child_->AsyncExportFeatureValues(cq, std::move(context),
                                          std::move(options), request);
}

StatusOr<google::longrunning::Operation>
FeaturestoreServiceMetadata::ExportFeatureValues(
    grpc::ClientContext& context, Options options,
    google::cloud::aiplatform::v1::ExportFeatureValuesRequest const& request) {
  SetMetadata(
      context, options,
      absl::StrCat("entity_type=", internal::UrlEncode(request.entity_type())));
  return child_->ExportFeatureValues(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
FeaturestoreServiceMetadata::AsyncDeleteFeatureValues(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::aiplatform::v1::DeleteFeatureValuesRequest const& request) {
  SetMetadata(
      *context, *options,
      absl::StrCat("entity_type=", internal::UrlEncode(request.entity_type())));
  return child_->AsyncDeleteFeatureValues(cq, std::move(context),
                                          std::move(options), request);
}

StatusOr<google::longrunning::Operation>
FeaturestoreServiceMetadata::DeleteFeatureValues(
    grpc::ClientContext& context, Options options,
    google::cloud::aiplatform::v1::DeleteFeatureValuesRequest const& request) {
  SetMetadata(
      context, options,
      absl::StrCat("entity_type=", internal::UrlEncode(request.entity_type())));
  return child_->DeleteFeatureValues(context, options, request);
}

StatusOr<google::cloud::aiplatform::v1::SearchFeaturesResponse>
FeaturestoreServiceMetadata::SearchFeatures(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::SearchFeaturesRequest const& request) {
  SetMetadata(
      context, options,
      absl::StrCat("location=", internal::UrlEncode(request.location())));
  return child_->SearchFeatures(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
FeaturestoreServiceMetadata::AsyncGetOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::longrunning::GetOperationRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncGetOperation(cq, std::move(context), std::move(options),
                                   request);
}

future<Status> FeaturestoreServiceMetadata::AsyncCancelOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::longrunning::CancelOperationRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncCancelOperation(cq, std::move(context),
                                      std::move(options), request);
}

void FeaturestoreServiceMetadata::SetMetadata(
    grpc::ClientContext& context, Options const& options,
    std::string const& request_params) {
  context.AddMetadata("x-goog-request-params", request_params);
  SetMetadata(context, options);
}

void FeaturestoreServiceMetadata::SetMetadata(grpc::ClientContext& context,
                                              Options const& options) {
  google::cloud::internal::SetMetadata(context, options, fixed_metadata_,
                                       api_client_header_);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace aiplatform_v1_internal
}  // namespace cloud
}  // namespace google
