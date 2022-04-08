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
// source: google/cloud/dialogflow/v2/session.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_ES_INTERNAL_SESSIONS_CONNECTION_IMPL_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_ES_INTERNAL_SESSIONS_CONNECTION_IMPL_H

#include "google/cloud/dialogflow_es/internal/sessions_retry_traits.h"
#include "google/cloud/dialogflow_es/internal/sessions_stub.h"
#include "google/cloud/dialogflow_es/sessions_connection.h"
#include "google/cloud/dialogflow_es/sessions_connection_idempotency_policy.h"
#include "google/cloud/dialogflow_es/sessions_options.h"
#include "google/cloud/async_streaming_read_write_rpc.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/backoff_policy.h"
#include "google/cloud/options.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <memory>

namespace google {
namespace cloud {
namespace dialogflow_es_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class SessionsConnectionImpl : public dialogflow_es::SessionsConnection {
 public:
  ~SessionsConnectionImpl() override = default;

  SessionsConnectionImpl(
      std::unique_ptr<google::cloud::BackgroundThreads> background,
      std::shared_ptr<dialogflow_es_internal::SessionsStub> stub,
      Options options);

  Options options() override { return options_; }

  StatusOr<google::cloud::dialogflow::v2::DetectIntentResponse> DetectIntent(
      google::cloud::dialogflow::v2::DetectIntentRequest const& request)
      override;

  std::unique_ptr<::google::cloud::AsyncStreamingReadWriteRpc<
      google::cloud::dialogflow::v2::StreamingDetectIntentRequest,
      google::cloud::dialogflow::v2::StreamingDetectIntentResponse>>
      AsyncStreamingDetectIntent(ExperimentalTag) override;

 private:
  std::unique_ptr<dialogflow_es::SessionsRetryPolicy> retry_policy() {
    auto const& options = internal::CurrentOptions();
    if (options.has<dialogflow_es::SessionsRetryPolicyOption>()) {
      return options.get<dialogflow_es::SessionsRetryPolicyOption>()->clone();
    }
    return options_.get<dialogflow_es::SessionsRetryPolicyOption>()->clone();
  }

  std::unique_ptr<BackoffPolicy> backoff_policy() {
    auto const& options = internal::CurrentOptions();
    if (options.has<dialogflow_es::SessionsBackoffPolicyOption>()) {
      return options.get<dialogflow_es::SessionsBackoffPolicyOption>()->clone();
    }
    return options_.get<dialogflow_es::SessionsBackoffPolicyOption>()->clone();
  }

  std::unique_ptr<dialogflow_es::SessionsConnectionIdempotencyPolicy>
  idempotency_policy() {
    auto const& options = internal::CurrentOptions();
    if (options
            .has<dialogflow_es::SessionsConnectionIdempotencyPolicyOption>()) {
      return options
          .get<dialogflow_es::SessionsConnectionIdempotencyPolicyOption>()
          ->clone();
    }
    return options_
        .get<dialogflow_es::SessionsConnectionIdempotencyPolicyOption>()
        ->clone();
  }

  std::unique_ptr<google::cloud::BackgroundThreads> background_;
  std::shared_ptr<dialogflow_es_internal::SessionsStub> stub_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_es_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_ES_INTERNAL_SESSIONS_CONNECTION_IMPL_H
