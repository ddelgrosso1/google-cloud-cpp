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

#include "google/cloud/dialogflow_es/internal/conversation_profiles_auth_decorator.h"
#include <google/cloud/dialogflow/v2/conversation_profile.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace dialogflow_es_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

ConversationProfilesAuth::ConversationProfilesAuth(
    std::shared_ptr<google::cloud::internal::GrpcAuthenticationStrategy> auth,
    std::shared_ptr<ConversationProfilesStub> child)
    : auth_(std::move(auth)), child_(std::move(child)) {}

StatusOr<google::cloud::dialogflow::v2::ListConversationProfilesResponse>
ConversationProfilesAuth::ListConversationProfiles(
    grpc::ClientContext& context,
    google::cloud::dialogflow::v2::ListConversationProfilesRequest const&
        request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->ListConversationProfiles(context, request);
}

StatusOr<google::cloud::dialogflow::v2::ConversationProfile>
ConversationProfilesAuth::GetConversationProfile(
    grpc::ClientContext& context,
    google::cloud::dialogflow::v2::GetConversationProfileRequest const&
        request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->GetConversationProfile(context, request);
}

StatusOr<google::cloud::dialogflow::v2::ConversationProfile>
ConversationProfilesAuth::CreateConversationProfile(
    grpc::ClientContext& context,
    google::cloud::dialogflow::v2::CreateConversationProfileRequest const&
        request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->CreateConversationProfile(context, request);
}

StatusOr<google::cloud::dialogflow::v2::ConversationProfile>
ConversationProfilesAuth::UpdateConversationProfile(
    grpc::ClientContext& context,
    google::cloud::dialogflow::v2::UpdateConversationProfileRequest const&
        request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->UpdateConversationProfile(context, request);
}

Status ConversationProfilesAuth::DeleteConversationProfile(
    grpc::ClientContext& context,
    google::cloud::dialogflow::v2::DeleteConversationProfileRequest const&
        request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->DeleteConversationProfile(context, request);
}

future<StatusOr<google::longrunning::Operation>>
ConversationProfilesAuth::AsyncSetSuggestionFeatureConfig(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::dialogflow::v2::SetSuggestionFeatureConfigRequest const&
        request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  auto child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncSetSuggestionFeatureConfig(cq, *std::move(context),
                                                      request);
      });
}

future<StatusOr<google::longrunning::Operation>>
ConversationProfilesAuth::AsyncClearSuggestionFeatureConfig(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::dialogflow::v2::ClearSuggestionFeatureConfigRequest const&
        request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  auto child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncClearSuggestionFeatureConfig(cq, *std::move(context),
                                                        request);
      });
}

future<StatusOr<google::longrunning::Operation>>
ConversationProfilesAuth::AsyncGetOperation(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::longrunning::GetOperationRequest const& request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  auto child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncGetOperation(cq, *std::move(context), request);
      });
}

future<Status> ConversationProfilesAuth::AsyncCancelOperation(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::longrunning::CancelOperationRequest const& request) {
  auto child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) return make_ready_future(std::move(context).status());
        return child->AsyncCancelOperation(cq, *std::move(context), request);
      });
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_es_internal
}  // namespace cloud
}  // namespace google
