// Copyright 2022 Google LLC
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
// source: google/cloud/dialogflow/v2/conversation_profile.proto

#include "google/cloud/dialogflow_es/internal/conversation_profiles_metadata_decorator.h"
#include "google/cloud/common_options.h"
#include "google/cloud/internal/api_client_header.h"
#include "google/cloud/status_or.h"
#include <google/cloud/dialogflow/v2/conversation_profile.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace dialogflow_es_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

ConversationProfilesMetadata::ConversationProfilesMetadata(
    std::shared_ptr<ConversationProfilesStub> child)
    : child_(std::move(child)),
      api_client_header_(
          google::cloud::internal::ApiClientHeader("generator")) {}

StatusOr<google::cloud::dialogflow::v2::ListConversationProfilesResponse>
ConversationProfilesMetadata::ListConversationProfiles(
    grpc::ClientContext& context,
    google::cloud::dialogflow::v2::ListConversationProfilesRequest const&
        request) {
  SetMetadata(context, "parent=" + request.parent());
  return child_->ListConversationProfiles(context, request);
}

StatusOr<google::cloud::dialogflow::v2::ConversationProfile>
ConversationProfilesMetadata::GetConversationProfile(
    grpc::ClientContext& context,
    google::cloud::dialogflow::v2::GetConversationProfileRequest const&
        request) {
  SetMetadata(context, "name=" + request.name());
  return child_->GetConversationProfile(context, request);
}

StatusOr<google::cloud::dialogflow::v2::ConversationProfile>
ConversationProfilesMetadata::CreateConversationProfile(
    grpc::ClientContext& context,
    google::cloud::dialogflow::v2::CreateConversationProfileRequest const&
        request) {
  SetMetadata(context, "parent=" + request.parent());
  return child_->CreateConversationProfile(context, request);
}

StatusOr<google::cloud::dialogflow::v2::ConversationProfile>
ConversationProfilesMetadata::UpdateConversationProfile(
    grpc::ClientContext& context,
    google::cloud::dialogflow::v2::UpdateConversationProfileRequest const&
        request) {
  SetMetadata(context, "conversation_profile.name=" +
                           request.conversation_profile().name());
  return child_->UpdateConversationProfile(context, request);
}

Status ConversationProfilesMetadata::DeleteConversationProfile(
    grpc::ClientContext& context,
    google::cloud::dialogflow::v2::DeleteConversationProfileRequest const&
        request) {
  SetMetadata(context, "name=" + request.name());
  return child_->DeleteConversationProfile(context, request);
}

future<StatusOr<google::longrunning::Operation>>
ConversationProfilesMetadata::AsyncSetSuggestionFeatureConfig(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::dialogflow::v2::SetSuggestionFeatureConfigRequest const&
        request) {
  SetMetadata(*context,
              "conversation_profile=" + request.conversation_profile());
  return child_->AsyncSetSuggestionFeatureConfig(cq, std::move(context),
                                                 request);
}

future<StatusOr<google::longrunning::Operation>>
ConversationProfilesMetadata::AsyncClearSuggestionFeatureConfig(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::dialogflow::v2::ClearSuggestionFeatureConfigRequest const&
        request) {
  SetMetadata(*context,
              "conversation_profile=" + request.conversation_profile());
  return child_->AsyncClearSuggestionFeatureConfig(cq, std::move(context),
                                                   request);
}

future<StatusOr<google::longrunning::Operation>>
ConversationProfilesMetadata::AsyncGetOperation(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::longrunning::GetOperationRequest const& request) {
  SetMetadata(*context, "name=" + request.name());
  return child_->AsyncGetOperation(cq, std::move(context), request);
}

future<Status> ConversationProfilesMetadata::AsyncCancelOperation(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::longrunning::CancelOperationRequest const& request) {
  SetMetadata(*context, "name=" + request.name());
  return child_->AsyncCancelOperation(cq, std::move(context), request);
}

void ConversationProfilesMetadata::SetMetadata(
    grpc::ClientContext& context, std::string const& request_params) {
  context.AddMetadata("x-goog-request-params", request_params);
  SetMetadata(context);
}

void ConversationProfilesMetadata::SetMetadata(grpc::ClientContext& context) {
  context.AddMetadata("x-goog-api-client", api_client_header_);
  auto const& options = internal::CurrentOptions();
  if (options.has<UserProjectOption>()) {
    context.AddMetadata("x-goog-user-project",
                        options.get<UserProjectOption>());
  }
  auto const& authority = options.get<AuthorityOption>();
  if (!authority.empty()) context.set_authority(authority);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_es_internal
}  // namespace cloud
}  // namespace google
