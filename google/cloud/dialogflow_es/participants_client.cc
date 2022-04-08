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

#include "google/cloud/dialogflow_es/participants_client.h"
#include "google/cloud/dialogflow_es/internal/participants_option_defaults.h"
#include <memory>

namespace google {
namespace cloud {
namespace dialogflow_es {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

ParticipantsClient::ParticipantsClient(
    std::shared_ptr<ParticipantsConnection> connection, Options opts)
    : connection_(std::move(connection)),
      options_(internal::MergeOptions(
          std::move(opts), dialogflow_es_internal::ParticipantsDefaultOptions(
                               connection_->options()))) {}
ParticipantsClient::~ParticipantsClient() = default;

StatusOr<google::cloud::dialogflow::v2::Participant>
ParticipantsClient::CreateParticipant(
    std::string const& parent,
    google::cloud::dialogflow::v2::Participant const& participant,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::dialogflow::v2::CreateParticipantRequest request;
  request.set_parent(parent);
  *request.mutable_participant() = participant;
  return connection_->CreateParticipant(request);
}

StatusOr<google::cloud::dialogflow::v2::Participant>
ParticipantsClient::CreateParticipant(
    google::cloud::dialogflow::v2::CreateParticipantRequest const& request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->CreateParticipant(request);
}

StatusOr<google::cloud::dialogflow::v2::Participant>
ParticipantsClient::GetParticipant(std::string const& name, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::dialogflow::v2::GetParticipantRequest request;
  request.set_name(name);
  return connection_->GetParticipant(request);
}

StatusOr<google::cloud::dialogflow::v2::Participant>
ParticipantsClient::GetParticipant(
    google::cloud::dialogflow::v2::GetParticipantRequest const& request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->GetParticipant(request);
}

StreamRange<google::cloud::dialogflow::v2::Participant>
ParticipantsClient::ListParticipants(std::string const& parent, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::dialogflow::v2::ListParticipantsRequest request;
  request.set_parent(parent);
  return connection_->ListParticipants(request);
}

StreamRange<google::cloud::dialogflow::v2::Participant>
ParticipantsClient::ListParticipants(
    google::cloud::dialogflow::v2::ListParticipantsRequest request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->ListParticipants(std::move(request));
}

StatusOr<google::cloud::dialogflow::v2::Participant>
ParticipantsClient::UpdateParticipant(
    google::cloud::dialogflow::v2::Participant const& participant,
    google::protobuf::FieldMask const& update_mask, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::dialogflow::v2::UpdateParticipantRequest request;
  *request.mutable_participant() = participant;
  *request.mutable_update_mask() = update_mask;
  return connection_->UpdateParticipant(request);
}

StatusOr<google::cloud::dialogflow::v2::Participant>
ParticipantsClient::UpdateParticipant(
    google::cloud::dialogflow::v2::UpdateParticipantRequest const& request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->UpdateParticipant(request);
}

StatusOr<google::cloud::dialogflow::v2::AnalyzeContentResponse>
ParticipantsClient::AnalyzeContent(
    std::string const& participant,
    google::cloud::dialogflow::v2::TextInput const& text_input, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::dialogflow::v2::AnalyzeContentRequest request;
  request.set_participant(participant);
  *request.mutable_text_input() = text_input;
  return connection_->AnalyzeContent(request);
}

StatusOr<google::cloud::dialogflow::v2::AnalyzeContentResponse>
ParticipantsClient::AnalyzeContent(
    std::string const& participant,
    google::cloud::dialogflow::v2::EventInput const& event_input,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::dialogflow::v2::AnalyzeContentRequest request;
  request.set_participant(participant);
  *request.mutable_event_input() = event_input;
  return connection_->AnalyzeContent(request);
}

StatusOr<google::cloud::dialogflow::v2::AnalyzeContentResponse>
ParticipantsClient::AnalyzeContent(
    google::cloud::dialogflow::v2::AnalyzeContentRequest const& request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->AnalyzeContent(request);
}

StatusOr<google::cloud::dialogflow::v2::SuggestArticlesResponse>
ParticipantsClient::SuggestArticles(std::string const& parent, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::dialogflow::v2::SuggestArticlesRequest request;
  request.set_parent(parent);
  return connection_->SuggestArticles(request);
}

StatusOr<google::cloud::dialogflow::v2::SuggestArticlesResponse>
ParticipantsClient::SuggestArticles(
    google::cloud::dialogflow::v2::SuggestArticlesRequest const& request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->SuggestArticles(request);
}

StatusOr<google::cloud::dialogflow::v2::SuggestFaqAnswersResponse>
ParticipantsClient::SuggestFaqAnswers(std::string const& parent, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::dialogflow::v2::SuggestFaqAnswersRequest request;
  request.set_parent(parent);
  return connection_->SuggestFaqAnswers(request);
}

StatusOr<google::cloud::dialogflow::v2::SuggestFaqAnswersResponse>
ParticipantsClient::SuggestFaqAnswers(
    google::cloud::dialogflow::v2::SuggestFaqAnswersRequest const& request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->SuggestFaqAnswers(request);
}

StatusOr<google::cloud::dialogflow::v2::SuggestSmartRepliesResponse>
ParticipantsClient::SuggestSmartReplies(std::string const& parent,
                                        Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::dialogflow::v2::SuggestSmartRepliesRequest request;
  request.set_parent(parent);
  return connection_->SuggestSmartReplies(request);
}

StatusOr<google::cloud::dialogflow::v2::SuggestSmartRepliesResponse>
ParticipantsClient::SuggestSmartReplies(
    google::cloud::dialogflow::v2::SuggestSmartRepliesRequest const& request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->SuggestSmartReplies(request);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_es
}  // namespace cloud
}  // namespace google
