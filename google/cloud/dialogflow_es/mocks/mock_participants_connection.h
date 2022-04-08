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

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_ES_MOCKS_MOCK_PARTICIPANTS_CONNECTION_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_ES_MOCKS_MOCK_PARTICIPANTS_CONNECTION_H

#include "google/cloud/dialogflow_es/participants_connection.h"
#include <gmock/gmock.h>

namespace google {
namespace cloud {
namespace dialogflow_es_mocks {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class MockParticipantsConnection
    : public dialogflow_es::ParticipantsConnection {
 public:
  MOCK_METHOD(Options, options, (), (override));

  MOCK_METHOD(
      StatusOr<google::cloud::dialogflow::v2::Participant>, CreateParticipant,
      (google::cloud::dialogflow::v2::CreateParticipantRequest const& request),
      (override));

  MOCK_METHOD(
      StatusOr<google::cloud::dialogflow::v2::Participant>, GetParticipant,
      (google::cloud::dialogflow::v2::GetParticipantRequest const& request),
      (override));

  MOCK_METHOD(StreamRange<google::cloud::dialogflow::v2::Participant>,
              ListParticipants,
              (google::cloud::dialogflow::v2::ListParticipantsRequest request),
              (override));

  MOCK_METHOD(
      StatusOr<google::cloud::dialogflow::v2::Participant>, UpdateParticipant,
      (google::cloud::dialogflow::v2::UpdateParticipantRequest const& request),
      (override));

  MOCK_METHOD(
      StatusOr<google::cloud::dialogflow::v2::AnalyzeContentResponse>,
      AnalyzeContent,
      (google::cloud::dialogflow::v2::AnalyzeContentRequest const& request),
      (override));

  MOCK_METHOD(
      StatusOr<google::cloud::dialogflow::v2::SuggestArticlesResponse>,
      SuggestArticles,
      (google::cloud::dialogflow::v2::SuggestArticlesRequest const& request),
      (override));

  MOCK_METHOD(
      StatusOr<google::cloud::dialogflow::v2::SuggestFaqAnswersResponse>,
      SuggestFaqAnswers,
      (google::cloud::dialogflow::v2::SuggestFaqAnswersRequest const& request),
      (override));

  MOCK_METHOD(
      StatusOr<google::cloud::dialogflow::v2::SuggestSmartRepliesResponse>,
      SuggestSmartReplies,
      (google::cloud::dialogflow::v2::SuggestSmartRepliesRequest const&
           request),
      (override));
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_es_mocks
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_ES_MOCKS_MOCK_PARTICIPANTS_CONNECTION_H
