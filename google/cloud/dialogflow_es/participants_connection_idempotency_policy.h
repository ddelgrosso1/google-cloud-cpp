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

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_ES_PARTICIPANTS_CONNECTION_IDEMPOTENCY_POLICY_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_ES_PARTICIPANTS_CONNECTION_IDEMPOTENCY_POLICY_H

#include "google/cloud/idempotency.h"
#include "google/cloud/internal/retry_policy.h"
#include "google/cloud/version.h"
#include <google/cloud/dialogflow/v2/participant.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace dialogflow_es {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class ParticipantsConnectionIdempotencyPolicy {
 public:
  virtual ~ParticipantsConnectionIdempotencyPolicy() = 0;

  /// Create a new copy of this object.
  virtual std::unique_ptr<ParticipantsConnectionIdempotencyPolicy> clone()
      const = 0;

  virtual google::cloud::Idempotency CreateParticipant(
      google::cloud::dialogflow::v2::CreateParticipantRequest const&
          request) = 0;

  virtual google::cloud::Idempotency GetParticipant(
      google::cloud::dialogflow::v2::GetParticipantRequest const& request) = 0;

  virtual google::cloud::Idempotency ListParticipants(
      google::cloud::dialogflow::v2::ListParticipantsRequest request) = 0;

  virtual google::cloud::Idempotency UpdateParticipant(
      google::cloud::dialogflow::v2::UpdateParticipantRequest const&
          request) = 0;

  virtual google::cloud::Idempotency AnalyzeContent(
      google::cloud::dialogflow::v2::AnalyzeContentRequest const& request) = 0;

  virtual google::cloud::Idempotency SuggestArticles(
      google::cloud::dialogflow::v2::SuggestArticlesRequest const& request) = 0;

  virtual google::cloud::Idempotency SuggestFaqAnswers(
      google::cloud::dialogflow::v2::SuggestFaqAnswersRequest const&
          request) = 0;

  virtual google::cloud::Idempotency SuggestSmartReplies(
      google::cloud::dialogflow::v2::SuggestSmartRepliesRequest const&
          request) = 0;
};

std::unique_ptr<ParticipantsConnectionIdempotencyPolicy>
MakeDefaultParticipantsConnectionIdempotencyPolicy();

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_es
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_ES_PARTICIPANTS_CONNECTION_IDEMPOTENCY_POLICY_H
