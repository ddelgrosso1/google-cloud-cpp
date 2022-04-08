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

#include "google/cloud/dialogflow_es/conversation_profiles_connection_idempotency_policy.h"
#include "absl/memory/memory.h"
#include <memory>

namespace google {
namespace cloud {
namespace dialogflow_es {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

using ::google::cloud::Idempotency;

ConversationProfilesConnectionIdempotencyPolicy::
    ~ConversationProfilesConnectionIdempotencyPolicy() = default;

namespace {
class DefaultConversationProfilesConnectionIdempotencyPolicy
    : public ConversationProfilesConnectionIdempotencyPolicy {
 public:
  ~DefaultConversationProfilesConnectionIdempotencyPolicy() override = default;

  /// Create a new copy of this object.
  std::unique_ptr<ConversationProfilesConnectionIdempotencyPolicy> clone()
      const override {
    return absl::make_unique<
        DefaultConversationProfilesConnectionIdempotencyPolicy>(*this);
  }

  Idempotency ListConversationProfiles(
      google::cloud::dialogflow::v2::ListConversationProfilesRequest) override {
    return Idempotency::kIdempotent;
  }

  Idempotency GetConversationProfile(
      google::cloud::dialogflow::v2::GetConversationProfileRequest const&)
      override {
    return Idempotency::kIdempotent;
  }

  Idempotency CreateConversationProfile(
      google::cloud::dialogflow::v2::CreateConversationProfileRequest const&)
      override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency UpdateConversationProfile(
      google::cloud::dialogflow::v2::UpdateConversationProfileRequest const&)
      override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency DeleteConversationProfile(
      google::cloud::dialogflow::v2::DeleteConversationProfileRequest const&)
      override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency SetSuggestionFeatureConfig(
      google::cloud::dialogflow::v2::SetSuggestionFeatureConfigRequest const&)
      override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency ClearSuggestionFeatureConfig(
      google::cloud::dialogflow::v2::ClearSuggestionFeatureConfigRequest const&)
      override {
    return Idempotency::kNonIdempotent;
  }
};
}  // namespace

std::unique_ptr<ConversationProfilesConnectionIdempotencyPolicy>
MakeDefaultConversationProfilesConnectionIdempotencyPolicy() {
  return absl::make_unique<
      DefaultConversationProfilesConnectionIdempotencyPolicy>();
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_es
}  // namespace cloud
}  // namespace google
