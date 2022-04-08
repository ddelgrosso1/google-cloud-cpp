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
// source: google/cloud/dialogflow/v2/participant.proto

#include "google/cloud/dialogflow_es/internal/participants_metadata_decorator.h"
#include "google/cloud/common_options.h"
#include "google/cloud/internal/api_client_header.h"
#include "google/cloud/status_or.h"
#include <google/cloud/dialogflow/v2/participant.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace dialogflow_es_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

ParticipantsMetadata::ParticipantsMetadata(
    std::shared_ptr<ParticipantsStub> child)
    : child_(std::move(child)),
      api_client_header_(
          google::cloud::internal::ApiClientHeader("generator")) {}

StatusOr<google::cloud::dialogflow::v2::Participant>
ParticipantsMetadata::CreateParticipant(
    grpc::ClientContext& context,
    google::cloud::dialogflow::v2::CreateParticipantRequest const& request) {
  SetMetadata(context, "parent=" + request.parent());
  return child_->CreateParticipant(context, request);
}

StatusOr<google::cloud::dialogflow::v2::Participant>
ParticipantsMetadata::GetParticipant(
    grpc::ClientContext& context,
    google::cloud::dialogflow::v2::GetParticipantRequest const& request) {
  SetMetadata(context, "name=" + request.name());
  return child_->GetParticipant(context, request);
}

StatusOr<google::cloud::dialogflow::v2::ListParticipantsResponse>
ParticipantsMetadata::ListParticipants(
    grpc::ClientContext& context,
    google::cloud::dialogflow::v2::ListParticipantsRequest const& request) {
  SetMetadata(context, "parent=" + request.parent());
  return child_->ListParticipants(context, request);
}

StatusOr<google::cloud::dialogflow::v2::Participant>
ParticipantsMetadata::UpdateParticipant(
    grpc::ClientContext& context,
    google::cloud::dialogflow::v2::UpdateParticipantRequest const& request) {
  SetMetadata(context, "participant.name=" + request.participant().name());
  return child_->UpdateParticipant(context, request);
}

StatusOr<google::cloud::dialogflow::v2::AnalyzeContentResponse>
ParticipantsMetadata::AnalyzeContent(
    grpc::ClientContext& context,
    google::cloud::dialogflow::v2::AnalyzeContentRequest const& request) {
  SetMetadata(context, "participant=" + request.participant());
  return child_->AnalyzeContent(context, request);
}

StatusOr<google::cloud::dialogflow::v2::SuggestArticlesResponse>
ParticipantsMetadata::SuggestArticles(
    grpc::ClientContext& context,
    google::cloud::dialogflow::v2::SuggestArticlesRequest const& request) {
  SetMetadata(context, "parent=" + request.parent());
  return child_->SuggestArticles(context, request);
}

StatusOr<google::cloud::dialogflow::v2::SuggestFaqAnswersResponse>
ParticipantsMetadata::SuggestFaqAnswers(
    grpc::ClientContext& context,
    google::cloud::dialogflow::v2::SuggestFaqAnswersRequest const& request) {
  SetMetadata(context, "parent=" + request.parent());
  return child_->SuggestFaqAnswers(context, request);
}

StatusOr<google::cloud::dialogflow::v2::SuggestSmartRepliesResponse>
ParticipantsMetadata::SuggestSmartReplies(
    grpc::ClientContext& context,
    google::cloud::dialogflow::v2::SuggestSmartRepliesRequest const& request) {
  SetMetadata(context, "parent=" + request.parent());
  return child_->SuggestSmartReplies(context, request);
}

void ParticipantsMetadata::SetMetadata(grpc::ClientContext& context,
                                       std::string const& request_params) {
  context.AddMetadata("x-goog-request-params", request_params);
  SetMetadata(context);
}

void ParticipantsMetadata::SetMetadata(grpc::ClientContext& context) {
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
