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

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_ES_INTENTS_CLIENT_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_ES_INTENTS_CLIENT_H

#include "google/cloud/dialogflow_es/intents_connection.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/polling_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace dialogflow_es {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

///
/// Service for managing [Intents][google.cloud.dialogflow.v2.Intent].
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
class IntentsClient {
 public:
  explicit IntentsClient(std::shared_ptr<IntentsConnection> connection,
                         Options opts = {});
  ~IntentsClient();

  //@{
  // @name Copy and move support
  IntentsClient(IntentsClient const&) = default;
  IntentsClient& operator=(IntentsClient const&) = default;
  IntentsClient(IntentsClient&&) = default;
  IntentsClient& operator=(IntentsClient&&) = default;
  //@}

  //@{
  // @name Equality
  friend bool operator==(IntentsClient const& a, IntentsClient const& b) {
    return a.connection_ == b.connection_;
  }
  friend bool operator!=(IntentsClient const& a, IntentsClient const& b) {
    return !(a == b);
  }
  //@}

  ///
  /// Returns the list of all intents in the specified agent.
  ///
  /// @param parent  Required. The agent to list all intents from.
  ///  Format: `projects/<Project ID>/agent` or `projects/<Project
  ///  ID>/locations/<Location ID>/agent`.
  ///  Alternatively, you can specify the environment to list intents for.
  ///  Format: `projects/<Project ID>/agent/environments/<Environment ID>`
  ///  or `projects/<Project ID>/locations/<Location
  ///  ID>/agent/environments/<Environment ID>`.
  ///  Note: training phrases of the intents will not be returned for non-draft
  ///  environment.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::v2::Intent,google/cloud/dialogflow/v2/intent.proto#L195}
  ///
  /// [google.cloud.dialogflow.v2.ListIntentsRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/intent.proto#L913}
  /// [google.cloud.dialogflow.v2.Intent]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/intent.proto#L195}
  ///
  StreamRange<google::cloud::dialogflow::v2::Intent> ListIntents(
      std::string const& parent, Options opts = {});

  ///
  /// Returns the list of all intents in the specified agent.
  ///
  /// @param parent  Required. The agent to list all intents from.
  ///  Format: `projects/<Project ID>/agent` or `projects/<Project
  ///  ID>/locations/<Location ID>/agent`.
  ///  Alternatively, you can specify the environment to list intents for.
  ///  Format: `projects/<Project ID>/agent/environments/<Environment ID>`
  ///  or `projects/<Project ID>/locations/<Location
  ///  ID>/agent/environments/<Environment ID>`.
  ///  Note: training phrases of the intents will not be returned for non-draft
  ///  environment.
  /// @param language_code  Optional. The language used to access
  /// language-specific data.
  ///  If not specified, the agent's default language is used.
  ///  For more information, see
  ///  [Multilingual intent and entity
  ///  data](https://cloud.google.com/dialogflow/docs/agents-multilingual#intent-entity).
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::v2::Intent,google/cloud/dialogflow/v2/intent.proto#L195}
  ///
  /// [google.cloud.dialogflow.v2.ListIntentsRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/intent.proto#L913}
  /// [google.cloud.dialogflow.v2.Intent]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/intent.proto#L195}
  ///
  StreamRange<google::cloud::dialogflow::v2::Intent> ListIntents(
      std::string const& parent, std::string const& language_code,
      Options opts = {});

  ///
  /// Returns the list of all intents in the specified agent.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::dialogflow::v2::ListIntentsRequest,google/cloud/dialogflow/v2/intent.proto#L913}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::v2::Intent,google/cloud/dialogflow/v2/intent.proto#L195}
  ///
  /// [google.cloud.dialogflow.v2.ListIntentsRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/intent.proto#L913}
  /// [google.cloud.dialogflow.v2.Intent]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/intent.proto#L195}
  ///
  StreamRange<google::cloud::dialogflow::v2::Intent> ListIntents(
      google::cloud::dialogflow::v2::ListIntentsRequest request,
      Options opts = {});

  ///
  /// Retrieves the specified intent.
  ///
  /// @param name  Required. The name of the intent.
  ///  Format: `projects/<Project ID>/agent/intents/<Intent ID>`.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::v2::Intent,google/cloud/dialogflow/v2/intent.proto#L195}
  ///
  /// [google.cloud.dialogflow.v2.GetIntentRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/intent.proto#L961}
  /// [google.cloud.dialogflow.v2.Intent]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/intent.proto#L195}
  ///
  StatusOr<google::cloud::dialogflow::v2::Intent> GetIntent(
      std::string const& name, Options opts = {});

  ///
  /// Retrieves the specified intent.
  ///
  /// @param name  Required. The name of the intent.
  ///  Format: `projects/<Project ID>/agent/intents/<Intent ID>`.
  /// @param language_code  Optional. The language used to access
  /// language-specific data.
  ///  If not specified, the agent's default language is used.
  ///  For more information, see
  ///  [Multilingual intent and entity
  ///  data](https://cloud.google.com/dialogflow/docs/agents-multilingual#intent-entity).
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::v2::Intent,google/cloud/dialogflow/v2/intent.proto#L195}
  ///
  /// [google.cloud.dialogflow.v2.GetIntentRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/intent.proto#L961}
  /// [google.cloud.dialogflow.v2.Intent]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/intent.proto#L195}
  ///
  StatusOr<google::cloud::dialogflow::v2::Intent> GetIntent(
      std::string const& name, std::string const& language_code,
      Options opts = {});

  ///
  /// Retrieves the specified intent.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::dialogflow::v2::GetIntentRequest,google/cloud/dialogflow/v2/intent.proto#L961}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::v2::Intent,google/cloud/dialogflow/v2/intent.proto#L195}
  ///
  /// [google.cloud.dialogflow.v2.GetIntentRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/intent.proto#L961}
  /// [google.cloud.dialogflow.v2.Intent]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/intent.proto#L195}
  ///
  StatusOr<google::cloud::dialogflow::v2::Intent> GetIntent(
      google::cloud::dialogflow::v2::GetIntentRequest const& request,
      Options opts = {});

  ///
  /// Creates an intent in the specified agent.
  ///
  /// Note: You should always train an agent prior to sending it queries. See
  /// the [training
  /// documentation](https://cloud.google.com/dialogflow/es/docs/training).
  ///
  /// @param parent  Required. The agent to create a intent for.
  ///  Format: `projects/<Project ID>/agent`.
  /// @param intent  Required. The intent to create.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::v2::Intent,google/cloud/dialogflow/v2/intent.proto#L195}
  ///
  /// [google.cloud.dialogflow.v2.CreateIntentRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/intent.proto#L983}
  /// [google.cloud.dialogflow.v2.Intent]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/intent.proto#L195}
  ///
  StatusOr<google::cloud::dialogflow::v2::Intent> CreateIntent(
      std::string const& parent,
      google::cloud::dialogflow::v2::Intent const& intent, Options opts = {});

  ///
  /// Creates an intent in the specified agent.
  ///
  /// Note: You should always train an agent prior to sending it queries. See
  /// the [training
  /// documentation](https://cloud.google.com/dialogflow/es/docs/training).
  ///
  /// @param parent  Required. The agent to create a intent for.
  ///  Format: `projects/<Project ID>/agent`.
  /// @param intent  Required. The intent to create.
  /// @param language_code  Optional. The language used to access
  /// language-specific data.
  ///  If not specified, the agent's default language is used.
  ///  For more information, see
  ///  [Multilingual intent and entity
  ///  data](https://cloud.google.com/dialogflow/docs/agents-multilingual#intent-entity).
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::v2::Intent,google/cloud/dialogflow/v2/intent.proto#L195}
  ///
  /// [google.cloud.dialogflow.v2.CreateIntentRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/intent.proto#L983}
  /// [google.cloud.dialogflow.v2.Intent]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/intent.proto#L195}
  ///
  StatusOr<google::cloud::dialogflow::v2::Intent> CreateIntent(
      std::string const& parent,
      google::cloud::dialogflow::v2::Intent const& intent,
      std::string const& language_code, Options opts = {});

  ///
  /// Creates an intent in the specified agent.
  ///
  /// Note: You should always train an agent prior to sending it queries. See
  /// the [training
  /// documentation](https://cloud.google.com/dialogflow/es/docs/training).
  ///
  /// @param request
  /// @googleapis_link{google::cloud::dialogflow::v2::CreateIntentRequest,google/cloud/dialogflow/v2/intent.proto#L983}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::v2::Intent,google/cloud/dialogflow/v2/intent.proto#L195}
  ///
  /// [google.cloud.dialogflow.v2.CreateIntentRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/intent.proto#L983}
  /// [google.cloud.dialogflow.v2.Intent]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/intent.proto#L195}
  ///
  StatusOr<google::cloud::dialogflow::v2::Intent> CreateIntent(
      google::cloud::dialogflow::v2::CreateIntentRequest const& request,
      Options opts = {});

  ///
  /// Updates the specified intent.
  ///
  /// Note: You should always train an agent prior to sending it queries. See
  /// the [training
  /// documentation](https://cloud.google.com/dialogflow/es/docs/training).
  ///
  /// @param intent  Required. The intent to update.
  /// @param language_code  Optional. The language used to access
  /// language-specific data.
  ///  If not specified, the agent's default language is used.
  ///  For more information, see
  ///  [Multilingual intent and entity
  ///  data](https://cloud.google.com/dialogflow/docs/agents-multilingual#intent-entity).
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::v2::Intent,google/cloud/dialogflow/v2/intent.proto#L195}
  ///
  /// [google.cloud.dialogflow.v2.UpdateIntentRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/intent.proto#L1008}
  /// [google.cloud.dialogflow.v2.Intent]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/intent.proto#L195}
  ///
  StatusOr<google::cloud::dialogflow::v2::Intent> UpdateIntent(
      google::cloud::dialogflow::v2::Intent const& intent,
      std::string const& language_code, Options opts = {});

  ///
  /// Updates the specified intent.
  ///
  /// Note: You should always train an agent prior to sending it queries. See
  /// the [training
  /// documentation](https://cloud.google.com/dialogflow/es/docs/training).
  ///
  /// @param intent  Required. The intent to update.
  /// @param language_code  Optional. The language used to access
  /// language-specific data.
  ///  If not specified, the agent's default language is used.
  ///  For more information, see
  ///  [Multilingual intent and entity
  ///  data](https://cloud.google.com/dialogflow/docs/agents-multilingual#intent-entity).
  /// @param update_mask  Optional. The mask to control which fields get
  /// updated.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::v2::Intent,google/cloud/dialogflow/v2/intent.proto#L195}
  ///
  /// [google.cloud.dialogflow.v2.UpdateIntentRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/intent.proto#L1008}
  /// [google.cloud.dialogflow.v2.Intent]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/intent.proto#L195}
  ///
  StatusOr<google::cloud::dialogflow::v2::Intent> UpdateIntent(
      google::cloud::dialogflow::v2::Intent const& intent,
      std::string const& language_code,
      google::protobuf::FieldMask const& update_mask, Options opts = {});

  ///
  /// Updates the specified intent.
  ///
  /// Note: You should always train an agent prior to sending it queries. See
  /// the [training
  /// documentation](https://cloud.google.com/dialogflow/es/docs/training).
  ///
  /// @param request
  /// @googleapis_link{google::cloud::dialogflow::v2::UpdateIntentRequest,google/cloud/dialogflow/v2/intent.proto#L1008}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::v2::Intent,google/cloud/dialogflow/v2/intent.proto#L195}
  ///
  /// [google.cloud.dialogflow.v2.UpdateIntentRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/intent.proto#L1008}
  /// [google.cloud.dialogflow.v2.Intent]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/intent.proto#L195}
  ///
  StatusOr<google::cloud::dialogflow::v2::Intent> UpdateIntent(
      google::cloud::dialogflow::v2::UpdateIntentRequest const& request,
      Options opts = {});

  ///
  /// Deletes the specified intent and its direct or indirect followup intents.
  ///
  /// Note: You should always train an agent prior to sending it queries. See
  /// the [training
  /// documentation](https://cloud.google.com/dialogflow/es/docs/training).
  ///
  /// @param name  Required. The name of the intent to delete. If this intent
  /// has direct or
  ///  indirect followup intents, we also delete them.
  ///  Format: `projects/<Project ID>/agent/intents/<Intent ID>`.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  ///
  /// [google.cloud.dialogflow.v2.DeleteIntentRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/intent.proto#L1027}
  ///
  Status DeleteIntent(std::string const& name, Options opts = {});

  ///
  /// Deletes the specified intent and its direct or indirect followup intents.
  ///
  /// Note: You should always train an agent prior to sending it queries. See
  /// the [training
  /// documentation](https://cloud.google.com/dialogflow/es/docs/training).
  ///
  /// @param request
  /// @googleapis_link{google::cloud::dialogflow::v2::DeleteIntentRequest,google/cloud/dialogflow/v2/intent.proto#L1027}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  ///
  /// [google.cloud.dialogflow.v2.DeleteIntentRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/intent.proto#L1027}
  ///
  Status DeleteIntent(
      google::cloud::dialogflow::v2::DeleteIntentRequest const& request,
      Options opts = {});

  ///
  /// Updates/Creates multiple intents in the specified agent.
  ///
  /// This method is a [long-running
  /// operation](https://cloud.google.com/dialogflow/es/docs/how/long-running-operations).
  /// The returned `Operation` type has the following method-specific fields:
  ///
  /// - `metadata`: An empty [Struct
  ///   message](https://developers.google.com/protocol-buffers/docs/reference/google.protobuf#struct)
  /// - `response`:
  /// [BatchUpdateIntentsResponse][google.cloud.dialogflow.v2.BatchUpdateIntentsResponse]
  ///
  /// Note: You should always train an agent prior to sending it queries. See
  /// the [training
  /// documentation](https://cloud.google.com/dialogflow/es/docs/training).
  ///
  /// @param parent  Required. The name of the agent to update or create intents
  /// in.
  ///  Format: `projects/<Project ID>/agent`.
  /// @param intent_batch_uri  The URI to a Google Cloud Storage file containing
  /// intents to update or
  ///  create. The file format can either be a serialized proto (of IntentBatch
  ///  type) or JSON object. Note: The URI must start with "gs://".
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::v2::BatchUpdateIntentsResponse,google/cloud/dialogflow/v2/intent.proto#L1075}
  ///
  /// [google.cloud.dialogflow.v2.BatchUpdateIntentsRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/intent.proto#L1039}
  /// [google.cloud.dialogflow.v2.BatchUpdateIntentsResponse]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/intent.proto#L1075}
  ///
  future<StatusOr<google::cloud::dialogflow::v2::BatchUpdateIntentsResponse>>
  BatchUpdateIntents(std::string const& parent,
                     std::string const& intent_batch_uri, Options opts = {});

  ///
  /// Updates/Creates multiple intents in the specified agent.
  ///
  /// This method is a [long-running
  /// operation](https://cloud.google.com/dialogflow/es/docs/how/long-running-operations).
  /// The returned `Operation` type has the following method-specific fields:
  ///
  /// - `metadata`: An empty [Struct
  ///   message](https://developers.google.com/protocol-buffers/docs/reference/google.protobuf#struct)
  /// - `response`:
  /// [BatchUpdateIntentsResponse][google.cloud.dialogflow.v2.BatchUpdateIntentsResponse]
  ///
  /// Note: You should always train an agent prior to sending it queries. See
  /// the [training
  /// documentation](https://cloud.google.com/dialogflow/es/docs/training).
  ///
  /// @param parent  Required. The name of the agent to update or create intents
  /// in.
  ///  Format: `projects/<Project ID>/agent`.
  /// @param intent_batch_inline  The collection of intents to update or create.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::v2::BatchUpdateIntentsResponse,google/cloud/dialogflow/v2/intent.proto#L1075}
  ///
  /// [google.cloud.dialogflow.v2.BatchUpdateIntentsRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/intent.proto#L1039}
  /// [google.cloud.dialogflow.v2.BatchUpdateIntentsResponse]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/intent.proto#L1075}
  ///
  future<StatusOr<google::cloud::dialogflow::v2::BatchUpdateIntentsResponse>>
  BatchUpdateIntents(
      std::string const& parent,
      google::cloud::dialogflow::v2::IntentBatch const& intent_batch_inline,
      Options opts = {});

  ///
  /// Updates/Creates multiple intents in the specified agent.
  ///
  /// This method is a [long-running
  /// operation](https://cloud.google.com/dialogflow/es/docs/how/long-running-operations).
  /// The returned `Operation` type has the following method-specific fields:
  ///
  /// - `metadata`: An empty [Struct
  ///   message](https://developers.google.com/protocol-buffers/docs/reference/google.protobuf#struct)
  /// - `response`:
  /// [BatchUpdateIntentsResponse][google.cloud.dialogflow.v2.BatchUpdateIntentsResponse]
  ///
  /// Note: You should always train an agent prior to sending it queries. See
  /// the [training
  /// documentation](https://cloud.google.com/dialogflow/es/docs/training).
  ///
  /// @param request
  /// @googleapis_link{google::cloud::dialogflow::v2::BatchUpdateIntentsRequest,google/cloud/dialogflow/v2/intent.proto#L1039}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::v2::BatchUpdateIntentsResponse,google/cloud/dialogflow/v2/intent.proto#L1075}
  ///
  /// [google.cloud.dialogflow.v2.BatchUpdateIntentsRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/intent.proto#L1039}
  /// [google.cloud.dialogflow.v2.BatchUpdateIntentsResponse]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/intent.proto#L1075}
  ///
  future<StatusOr<google::cloud::dialogflow::v2::BatchUpdateIntentsResponse>>
  BatchUpdateIntents(
      google::cloud::dialogflow::v2::BatchUpdateIntentsRequest const& request,
      Options opts = {});

  ///
  /// Deletes intents in the specified agent.
  ///
  /// This method is a [long-running
  /// operation](https://cloud.google.com/dialogflow/es/docs/how/long-running-operations).
  /// The returned `Operation` type has the following method-specific fields:
  ///
  /// - `metadata`: An empty [Struct
  ///   message](https://developers.google.com/protocol-buffers/docs/reference/google.protobuf#struct)
  /// - `response`: An [Empty
  ///   message](https://developers.google.com/protocol-buffers/docs/reference/google.protobuf#empty)
  ///
  /// Note: You should always train an agent prior to sending it queries. See
  /// the [training
  /// documentation](https://cloud.google.com/dialogflow/es/docs/training).
  ///
  /// @param parent  Required. The name of the agent to delete all entities
  /// types for. Format:
  ///  `projects/<Project ID>/agent`.
  /// @param intents  Required. The collection of intents to delete. Only intent
  /// `name` must be
  ///  filled in.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::protobuf::Struct,google/protobuf/struct.proto#L51}
  ///
  /// [google.cloud.dialogflow.v2.BatchDeleteIntentsRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/intent.proto#L1081}
  /// [google.protobuf.Struct]:
  /// @googleapis_reference_link{google/protobuf/struct.proto#L51}
  ///
  future<StatusOr<google::protobuf::Struct>> BatchDeleteIntents(
      std::string const& parent,
      std::vector<google::cloud::dialogflow::v2::Intent> const& intents,
      Options opts = {});

  ///
  /// Deletes intents in the specified agent.
  ///
  /// This method is a [long-running
  /// operation](https://cloud.google.com/dialogflow/es/docs/how/long-running-operations).
  /// The returned `Operation` type has the following method-specific fields:
  ///
  /// - `metadata`: An empty [Struct
  ///   message](https://developers.google.com/protocol-buffers/docs/reference/google.protobuf#struct)
  /// - `response`: An [Empty
  ///   message](https://developers.google.com/protocol-buffers/docs/reference/google.protobuf#empty)
  ///
  /// Note: You should always train an agent prior to sending it queries. See
  /// the [training
  /// documentation](https://cloud.google.com/dialogflow/es/docs/training).
  ///
  /// @param request
  /// @googleapis_link{google::cloud::dialogflow::v2::BatchDeleteIntentsRequest,google/cloud/dialogflow/v2/intent.proto#L1081}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::protobuf::Struct,google/protobuf/struct.proto#L51}
  ///
  /// [google.cloud.dialogflow.v2.BatchDeleteIntentsRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/intent.proto#L1081}
  /// [google.protobuf.Struct]:
  /// @googleapis_reference_link{google/protobuf/struct.proto#L51}
  ///
  future<StatusOr<google::protobuf::Struct>> BatchDeleteIntents(
      google::cloud::dialogflow::v2::BatchDeleteIntentsRequest const& request,
      Options opts = {});

 private:
  std::shared_ptr<IntentsConnection> connection_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_es
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_ES_INTENTS_CLIENT_H
