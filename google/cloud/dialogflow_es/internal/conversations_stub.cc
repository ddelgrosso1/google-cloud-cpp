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
// source: google/cloud/dialogflow/v2/conversation.proto

#include "google/cloud/dialogflow_es/internal/conversations_stub.h"
#include "google/cloud/grpc_error_delegate.h"
#include "google/cloud/status_or.h"
#include <google/cloud/dialogflow/v2/conversation.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace dialogflow_es_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

ConversationsStub::~ConversationsStub() = default;

StatusOr<google::cloud::dialogflow::v2::Conversation>
DefaultConversationsStub::CreateConversation(
    grpc::ClientContext& client_context,
    google::cloud::dialogflow::v2::CreateConversationRequest const& request) {
  google::cloud::dialogflow::v2::Conversation response;
  auto status =
      grpc_stub_->CreateConversation(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

StatusOr<google::cloud::dialogflow::v2::ListConversationsResponse>
DefaultConversationsStub::ListConversations(
    grpc::ClientContext& client_context,
    google::cloud::dialogflow::v2::ListConversationsRequest const& request) {
  google::cloud::dialogflow::v2::ListConversationsResponse response;
  auto status =
      grpc_stub_->ListConversations(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

StatusOr<google::cloud::dialogflow::v2::Conversation>
DefaultConversationsStub::GetConversation(
    grpc::ClientContext& client_context,
    google::cloud::dialogflow::v2::GetConversationRequest const& request) {
  google::cloud::dialogflow::v2::Conversation response;
  auto status =
      grpc_stub_->GetConversation(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

StatusOr<google::cloud::dialogflow::v2::Conversation>
DefaultConversationsStub::CompleteConversation(
    grpc::ClientContext& client_context,
    google::cloud::dialogflow::v2::CompleteConversationRequest const& request) {
  google::cloud::dialogflow::v2::Conversation response;
  auto status =
      grpc_stub_->CompleteConversation(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

StatusOr<google::cloud::dialogflow::v2::ListMessagesResponse>
DefaultConversationsStub::ListMessages(
    grpc::ClientContext& client_context,
    google::cloud::dialogflow::v2::ListMessagesRequest const& request) {
  google::cloud::dialogflow::v2::ListMessagesResponse response;
  auto status = grpc_stub_->ListMessages(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_es_internal
}  // namespace cloud
}  // namespace google
