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

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_ES_SESSIONS_CLIENT_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_ES_SESSIONS_CLIENT_H

#include "google/cloud/dialogflow_es/sessions_connection.h"
#include "google/cloud/experimental_tag.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/polling_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <memory>

namespace google {
namespace cloud {
namespace dialogflow_es {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

///
/// A service used for session interactions.
///
/// For more information, see the [API interactions
/// guide](https://cloud.google.com/dialogflow/docs/api-overview).
///
/// @par Equality
///
/// Instances of this class created via copy-construction or copy-assignment
/// always compare equal. Instances created with equal
/// `std::shared_ptr<*Connection>` objects compare equal. Objects that compare
/// equal share the same underlying resources.
///
/// @par Performance
///
/// Creating a new instance of this class is a relatively expensive operation,
/// new objects establish new connections to the service. In contrast,
/// copy-construction, move-construction, and the corresponding assignment
/// operations are relatively efficient as the copies share all underlying
/// resources.
///
/// @par Thread Safety
///
/// Concurrent access to different instances of this class, even if they compare
/// equal, is guaranteed to work. Two or more threads operating on the same
/// instance of this class is not guaranteed to work. Since copy-construction
/// and move-construction is a relatively efficient operation, consider using
/// such a copy when using this class from multiple threads.
///
class SessionsClient {
 public:
  explicit SessionsClient(std::shared_ptr<SessionsConnection> connection,
                          Options opts = {});
  ~SessionsClient();

  //@{
  // @name Copy and move support
  SessionsClient(SessionsClient const&) = default;
  SessionsClient& operator=(SessionsClient const&) = default;
  SessionsClient(SessionsClient&&) = default;
  SessionsClient& operator=(SessionsClient&&) = default;
  //@}

  //@{
  // @name Equality
  friend bool operator==(SessionsClient const& a, SessionsClient const& b) {
    return a.connection_ == b.connection_;
  }
  friend bool operator!=(SessionsClient const& a, SessionsClient const& b) {
    return !(a == b);
  }
  //@}

  ///
  /// Processes a natural language query and returns structured, actionable data
  /// as a result. This method is not idempotent, because it may cause contexts
  /// and session entity types to be updated, which in turn might affect
  /// results of future queries.
  ///
  /// If you might use
  /// [Agent Assist](https://cloud.google.com/dialogflow/docs/#aa)
  /// or other CCAI products now or in the future, consider using
  /// [AnalyzeContent][google.cloud.dialogflow.v2.Participants.AnalyzeContent]
  /// instead of `DetectIntent`. `AnalyzeContent` has additional
  /// functionality for Agent Assist and other CCAI products.
  ///
  /// Note: Always use agent versions for production traffic.
  /// See [Versions and
  /// environments](https://cloud.google.com/dialogflow/es/docs/agents-versions).
  ///
  /// @param session  Required. The name of the session this query is sent to.
  /// Format:
  ///  `projects/<Project ID>/agent/sessions/<Session ID>`, or
  ///  `projects/<Project ID>/agent/environments/<Environment ID>/users/<User
  ///  ID>/sessions/<Session ID>`. If `Environment ID` is not specified, we
  ///  assume default 'draft' environment (`Environment ID` might be referred to
  ///  as environment name at some places). If `User ID` is not specified, we
  ///  are using "-". It's up to the API caller to choose an appropriate
  ///  `Session ID` and `User Id`. They can be a random number or some type of
  ///  user and session identifiers (preferably hashed). The length of the
  ///  `Session ID` and `User ID` must not exceed 36 characters. For more
  ///  information, see the [API interactions
  ///  guide](https://cloud.google.com/dialogflow/docs/api-overview).
  ///  Note: Always use agent versions for production traffic.
  ///  See [Versions and
  ///  environments](https://cloud.google.com/dialogflow/es/docs/agents-versions).
  /// @param query_input  Required. The input specification. It can be set to:
  ///  1.  an audio config
  ///      which instructs the speech recognizer how to process the speech
  ///      audio,
  ///  2.  a conversational query in the form of text, or
  ///  3.  an event that specifies which intent to trigger.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::v2::DetectIntentResponse,google/cloud/dialogflow/v2/session.proto#L170}
  ///
  /// [google.cloud.dialogflow.v2.DetectIntentRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/session.proto#L112}
  /// [google.cloud.dialogflow.v2.DetectIntentResponse]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/session.proto#L170}
  ///
  StatusOr<google::cloud::dialogflow::v2::DetectIntentResponse> DetectIntent(
      std::string const& session,
      google::cloud::dialogflow::v2::QueryInput const& query_input,
      Options opts = {});

  ///
  /// Processes a natural language query and returns structured, actionable data
  /// as a result. This method is not idempotent, because it may cause contexts
  /// and session entity types to be updated, which in turn might affect
  /// results of future queries.
  ///
  /// If you might use
  /// [Agent Assist](https://cloud.google.com/dialogflow/docs/#aa)
  /// or other CCAI products now or in the future, consider using
  /// [AnalyzeContent][google.cloud.dialogflow.v2.Participants.AnalyzeContent]
  /// instead of `DetectIntent`. `AnalyzeContent` has additional
  /// functionality for Agent Assist and other CCAI products.
  ///
  /// Note: Always use agent versions for production traffic.
  /// See [Versions and
  /// environments](https://cloud.google.com/dialogflow/es/docs/agents-versions).
  ///
  /// @param request
  /// @googleapis_link{google::cloud::dialogflow::v2::DetectIntentRequest,google/cloud/dialogflow/v2/session.proto#L112}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::v2::DetectIntentResponse,google/cloud/dialogflow/v2/session.proto#L170}
  ///
  /// [google.cloud.dialogflow.v2.DetectIntentRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/session.proto#L112}
  /// [google.cloud.dialogflow.v2.DetectIntentResponse]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/session.proto#L170}
  ///
  StatusOr<google::cloud::dialogflow::v2::DetectIntentResponse> DetectIntent(
      google::cloud::dialogflow::v2::DetectIntentRequest const& request,
      Options opts = {});

  std::unique_ptr<::google::cloud::AsyncStreamingReadWriteRpc<
      google::cloud::dialogflow::v2::StreamingDetectIntentRequest,
      google::cloud::dialogflow::v2::StreamingDetectIntentResponse>>
  AsyncStreamingDetectIntent(ExperimentalTag, Options opts = {});

 private:
  std::shared_ptr<SessionsConnection> connection_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_es
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_ES_SESSIONS_CLIENT_H
