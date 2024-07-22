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
// source: google/cloud/discoveryengine/v1/conversational_search_service.proto

#include "google/cloud/discoveryengine/v1/internal/conversational_search_logging_decorator.h"
#include "google/cloud/internal/log_wrapper.h"
#include "google/cloud/status_or.h"
#include <google/cloud/discoveryengine/v1/conversational_search_service.grpc.pb.h>
#include <memory>
#include <string>
#include <utility>

namespace google {
namespace cloud {
namespace discoveryengine_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

ConversationalSearchServiceLogging::ConversationalSearchServiceLogging(
    std::shared_ptr<ConversationalSearchServiceStub> child,
    TracingOptions tracing_options, std::set<std::string> const&)
    : child_(std::move(child)), tracing_options_(std::move(tracing_options)) {}

StatusOr<google::cloud::discoveryengine::v1::ConverseConversationResponse>
ConversationalSearchServiceLogging::ConverseConversation(
    grpc::ClientContext& context, Options const& options,
    google::cloud::discoveryengine::v1::ConverseConversationRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context, Options const& options,
          google::cloud::discoveryengine::v1::ConverseConversationRequest const&
              request) {
        return child_->ConverseConversation(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::discoveryengine::v1::Conversation>
ConversationalSearchServiceLogging::CreateConversation(
    grpc::ClientContext& context, Options const& options,
    google::cloud::discoveryengine::v1::CreateConversationRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context, Options const& options,
          google::cloud::discoveryengine::v1::CreateConversationRequest const&
              request) {
        return child_->CreateConversation(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

Status ConversationalSearchServiceLogging::DeleteConversation(
    grpc::ClientContext& context, Options const& options,
    google::cloud::discoveryengine::v1::DeleteConversationRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context, Options const& options,
          google::cloud::discoveryengine::v1::DeleteConversationRequest const&
              request) {
        return child_->DeleteConversation(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::discoveryengine::v1::Conversation>
ConversationalSearchServiceLogging::UpdateConversation(
    grpc::ClientContext& context, Options const& options,
    google::cloud::discoveryengine::v1::UpdateConversationRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context, Options const& options,
          google::cloud::discoveryengine::v1::UpdateConversationRequest const&
              request) {
        return child_->UpdateConversation(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::discoveryengine::v1::Conversation>
ConversationalSearchServiceLogging::GetConversation(
    grpc::ClientContext& context, Options const& options,
    google::cloud::discoveryengine::v1::GetConversationRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::discoveryengine::v1::GetConversationRequest const&
                 request) {
        return child_->GetConversation(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::discoveryengine::v1::ListConversationsResponse>
ConversationalSearchServiceLogging::ListConversations(
    grpc::ClientContext& context, Options const& options,
    google::cloud::discoveryengine::v1::ListConversationsRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::discoveryengine::v1::ListConversationsRequest const&
                 request) {
        return child_->ListConversations(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::discoveryengine::v1::AnswerQueryResponse>
ConversationalSearchServiceLogging::AnswerQuery(
    grpc::ClientContext& context, Options const& options,
    google::cloud::discoveryengine::v1::AnswerQueryRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::discoveryengine::v1::AnswerQueryRequest const&
                 request) {
        return child_->AnswerQuery(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::discoveryengine::v1::Answer>
ConversationalSearchServiceLogging::GetAnswer(
    grpc::ClientContext& context, Options const& options,
    google::cloud::discoveryengine::v1::GetAnswerRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context, Options const& options,
          google::cloud::discoveryengine::v1::GetAnswerRequest const& request) {
        return child_->GetAnswer(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::discoveryengine::v1::Session>
ConversationalSearchServiceLogging::CreateSession(
    grpc::ClientContext& context, Options const& options,
    google::cloud::discoveryengine::v1::CreateSessionRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::discoveryengine::v1::CreateSessionRequest const&
                 request) {
        return child_->CreateSession(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

Status ConversationalSearchServiceLogging::DeleteSession(
    grpc::ClientContext& context, Options const& options,
    google::cloud::discoveryengine::v1::DeleteSessionRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::discoveryengine::v1::DeleteSessionRequest const&
                 request) {
        return child_->DeleteSession(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::discoveryengine::v1::Session>
ConversationalSearchServiceLogging::UpdateSession(
    grpc::ClientContext& context, Options const& options,
    google::cloud::discoveryengine::v1::UpdateSessionRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::discoveryengine::v1::UpdateSessionRequest const&
                 request) {
        return child_->UpdateSession(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::discoveryengine::v1::Session>
ConversationalSearchServiceLogging::GetSession(
    grpc::ClientContext& context, Options const& options,
    google::cloud::discoveryengine::v1::GetSessionRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::discoveryengine::v1::GetSessionRequest const&
                 request) {
        return child_->GetSession(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::discoveryengine::v1::ListSessionsResponse>
ConversationalSearchServiceLogging::ListSessions(
    grpc::ClientContext& context, Options const& options,
    google::cloud::discoveryengine::v1::ListSessionsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::discoveryengine::v1::ListSessionsRequest const&
                 request) {
        return child_->ListSessions(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace discoveryengine_v1_internal
}  // namespace cloud
}  // namespace google
