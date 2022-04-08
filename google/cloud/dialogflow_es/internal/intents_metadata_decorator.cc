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
// source: google/cloud/dialogflow/v2/intent.proto

#include "google/cloud/dialogflow_es/internal/intents_metadata_decorator.h"
#include "google/cloud/common_options.h"
#include "google/cloud/internal/api_client_header.h"
#include "google/cloud/status_or.h"
#include <google/cloud/dialogflow/v2/intent.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace dialogflow_es_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

IntentsMetadata::IntentsMetadata(std::shared_ptr<IntentsStub> child)
    : child_(std::move(child)),
      api_client_header_(
          google::cloud::internal::ApiClientHeader("generator")) {}

StatusOr<google::cloud::dialogflow::v2::ListIntentsResponse>
IntentsMetadata::ListIntents(
    grpc::ClientContext& context,
    google::cloud::dialogflow::v2::ListIntentsRequest const& request) {
  SetMetadata(context, "parent=" + request.parent());
  return child_->ListIntents(context, request);
}

StatusOr<google::cloud::dialogflow::v2::Intent> IntentsMetadata::GetIntent(
    grpc::ClientContext& context,
    google::cloud::dialogflow::v2::GetIntentRequest const& request) {
  SetMetadata(context, "name=" + request.name());
  return child_->GetIntent(context, request);
}

StatusOr<google::cloud::dialogflow::v2::Intent> IntentsMetadata::CreateIntent(
    grpc::ClientContext& context,
    google::cloud::dialogflow::v2::CreateIntentRequest const& request) {
  SetMetadata(context, "parent=" + request.parent());
  return child_->CreateIntent(context, request);
}

StatusOr<google::cloud::dialogflow::v2::Intent> IntentsMetadata::UpdateIntent(
    grpc::ClientContext& context,
    google::cloud::dialogflow::v2::UpdateIntentRequest const& request) {
  SetMetadata(context, "intent.name=" + request.intent().name());
  return child_->UpdateIntent(context, request);
}

Status IntentsMetadata::DeleteIntent(
    grpc::ClientContext& context,
    google::cloud::dialogflow::v2::DeleteIntentRequest const& request) {
  SetMetadata(context, "name=" + request.name());
  return child_->DeleteIntent(context, request);
}

future<StatusOr<google::longrunning::Operation>>
IntentsMetadata::AsyncBatchUpdateIntents(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::dialogflow::v2::BatchUpdateIntentsRequest const& request) {
  SetMetadata(*context, "parent=" + request.parent());
  return child_->AsyncBatchUpdateIntents(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
IntentsMetadata::AsyncBatchDeleteIntents(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::dialogflow::v2::BatchDeleteIntentsRequest const& request) {
  SetMetadata(*context, "parent=" + request.parent());
  return child_->AsyncBatchDeleteIntents(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
IntentsMetadata::AsyncGetOperation(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::longrunning::GetOperationRequest const& request) {
  SetMetadata(*context, "name=" + request.name());
  return child_->AsyncGetOperation(cq, std::move(context), request);
}

future<Status> IntentsMetadata::AsyncCancelOperation(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::longrunning::CancelOperationRequest const& request) {
  SetMetadata(*context, "name=" + request.name());
  return child_->AsyncCancelOperation(cq, std::move(context), request);
}

void IntentsMetadata::SetMetadata(grpc::ClientContext& context,
                                  std::string const& request_params) {
  context.AddMetadata("x-goog-request-params", request_params);
  SetMetadata(context);
}

void IntentsMetadata::SetMetadata(grpc::ClientContext& context) {
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
