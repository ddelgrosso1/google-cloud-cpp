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
// source: google/cloud/dialogflow/v2/conversation_model.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_ES_CONVERSATION_MODELS_CLIENT_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_ES_CONVERSATION_MODELS_CLIENT_H

#include "google/cloud/dialogflow_es/conversation_models_connection.h"
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
/// Manages a collection of models for human agent assistant.
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
class ConversationModelsClient {
 public:
  explicit ConversationModelsClient(
      std::shared_ptr<ConversationModelsConnection> connection,
      Options opts = {});
  ~ConversationModelsClient();

  //@{
  // @name Copy and move support
  ConversationModelsClient(ConversationModelsClient const&) = default;
  ConversationModelsClient& operator=(ConversationModelsClient const&) =
      default;
  ConversationModelsClient(ConversationModelsClient&&) = default;
  ConversationModelsClient& operator=(ConversationModelsClient&&) = default;
  //@}

  //@{
  // @name Equality
  friend bool operator==(ConversationModelsClient const& a,
                         ConversationModelsClient const& b) {
    return a.connection_ == b.connection_;
  }
  friend bool operator!=(ConversationModelsClient const& a,
                         ConversationModelsClient const& b) {
    return !(a == b);
  }
  //@}

  ///
  /// Creates a model.
  ///
  /// This method is a [long-running
  /// operation](https://cloud.google.com/dialogflow/es/docs/how/long-running-operations).
  /// The returned `Operation` type has the following method-specific fields:
  ///
  /// - `metadata`:
  /// [CreateConversationModelOperationMetadata][google.cloud.dialogflow.v2.CreateConversationModelOperationMetadata]
  /// - `response`:
  /// [ConversationModel][google.cloud.dialogflow.v2.ConversationModel]
  ///
  /// @param parent  The project to create conversation model for. Format:
  ///  `projects/<Project ID>`
  /// @param conversation_model  Required. The conversation model to create.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::v2::ConversationModel,google/cloud/dialogflow/v2/conversation_model.proto#L201}
  ///
  /// [google.cloud.dialogflow.v2.CreateConversationModelRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/conversation_model.proto#L420}
  /// [google.cloud.dialogflow.v2.ConversationModel]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/conversation_model.proto#L201}
  ///
  future<StatusOr<google::cloud::dialogflow::v2::ConversationModel>>
  CreateConversationModel(
      std::string const& parent,
      google::cloud::dialogflow::v2::ConversationModel const&
          conversation_model,
      Options opts = {});

  ///
  /// Creates a model.
  ///
  /// This method is a [long-running
  /// operation](https://cloud.google.com/dialogflow/es/docs/how/long-running-operations).
  /// The returned `Operation` type has the following method-specific fields:
  ///
  /// - `metadata`:
  /// [CreateConversationModelOperationMetadata][google.cloud.dialogflow.v2.CreateConversationModelOperationMetadata]
  /// - `response`:
  /// [ConversationModel][google.cloud.dialogflow.v2.ConversationModel]
  ///
  /// @param request
  /// @googleapis_link{google::cloud::dialogflow::v2::CreateConversationModelRequest,google/cloud/dialogflow/v2/conversation_model.proto#L420}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::v2::ConversationModel,google/cloud/dialogflow/v2/conversation_model.proto#L201}
  ///
  /// [google.cloud.dialogflow.v2.CreateConversationModelRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/conversation_model.proto#L420}
  /// [google.cloud.dialogflow.v2.ConversationModel]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/conversation_model.proto#L201}
  ///
  future<StatusOr<google::cloud::dialogflow::v2::ConversationModel>>
  CreateConversationModel(
      google::cloud::dialogflow::v2::CreateConversationModelRequest const&
          request,
      Options opts = {});

  ///
  /// Gets conversation model.
  ///
  /// @param name  Required. The conversation model to retrieve. Format:
  ///  `projects/<Project ID>/conversationModels/<Conversation Model ID>`
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::v2::ConversationModel,google/cloud/dialogflow/v2/conversation_model.proto#L201}
  ///
  /// [google.cloud.dialogflow.v2.GetConversationModelRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/conversation_model.proto#L431}
  /// [google.cloud.dialogflow.v2.ConversationModel]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/conversation_model.proto#L201}
  ///
  StatusOr<google::cloud::dialogflow::v2::ConversationModel>
  GetConversationModel(std::string const& name, Options opts = {});

  ///
  /// Gets conversation model.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::dialogflow::v2::GetConversationModelRequest,google/cloud/dialogflow/v2/conversation_model.proto#L431}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::v2::ConversationModel,google/cloud/dialogflow/v2/conversation_model.proto#L201}
  ///
  /// [google.cloud.dialogflow.v2.GetConversationModelRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/conversation_model.proto#L431}
  /// [google.cloud.dialogflow.v2.ConversationModel]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/conversation_model.proto#L201}
  ///
  StatusOr<google::cloud::dialogflow::v2::ConversationModel>
  GetConversationModel(
      google::cloud::dialogflow::v2::GetConversationModelRequest const& request,
      Options opts = {});

  ///
  /// Lists conversation models.
  ///
  /// @param parent  Required. The project to list all conversation models for.
  ///  Format: `projects/<Project ID>`
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::v2::ConversationModel,google/cloud/dialogflow/v2/conversation_model.proto#L201}
  ///
  /// [google.cloud.dialogflow.v2.ListConversationModelsRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/conversation_model.proto#L439}
  /// [google.cloud.dialogflow.v2.ConversationModel]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/conversation_model.proto#L201}
  ///
  StreamRange<google::cloud::dialogflow::v2::ConversationModel>
  ListConversationModels(std::string const& parent, Options opts = {});

  ///
  /// Lists conversation models.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::dialogflow::v2::ListConversationModelsRequest,google/cloud/dialogflow/v2/conversation_model.proto#L439}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::v2::ConversationModel,google/cloud/dialogflow/v2/conversation_model.proto#L201}
  ///
  /// [google.cloud.dialogflow.v2.ListConversationModelsRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/conversation_model.proto#L439}
  /// [google.cloud.dialogflow.v2.ConversationModel]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/conversation_model.proto#L201}
  ///
  StreamRange<google::cloud::dialogflow::v2::ConversationModel>
  ListConversationModels(
      google::cloud::dialogflow::v2::ListConversationModelsRequest request,
      Options opts = {});

  ///
  /// Deletes a model.
  ///
  /// This method is a [long-running
  /// operation](https://cloud.google.com/dialogflow/es/docs/how/long-running-operations).
  /// The returned `Operation` type has the following method-specific fields:
  ///
  /// - `metadata`:
  /// [DeleteConversationModelOperationMetadata][google.cloud.dialogflow.v2.DeleteConversationModelOperationMetadata]
  /// - `response`: An [Empty
  ///   message](https://developers.google.com/protocol-buffers/docs/reference/google.protobuf#empty)
  ///
  /// @param name  Required. The conversation model to delete. Format:
  ///  `projects/<Project ID>/conversationModels/<Conversation Model ID>`
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::v2::DeleteConversationModelOperationMetadata,google/cloud/dialogflow/v2/conversation_model.proto#L602}
  ///
  /// [google.cloud.dialogflow.v2.DeleteConversationModelRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/conversation_model.proto#L465}
  /// [google.cloud.dialogflow.v2.DeleteConversationModelOperationMetadata]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/conversation_model.proto#L602}
  ///
  future<StatusOr<
      google::cloud::dialogflow::v2::DeleteConversationModelOperationMetadata>>
  DeleteConversationModel(std::string const& name, Options opts = {});

  ///
  /// Deletes a model.
  ///
  /// This method is a [long-running
  /// operation](https://cloud.google.com/dialogflow/es/docs/how/long-running-operations).
  /// The returned `Operation` type has the following method-specific fields:
  ///
  /// - `metadata`:
  /// [DeleteConversationModelOperationMetadata][google.cloud.dialogflow.v2.DeleteConversationModelOperationMetadata]
  /// - `response`: An [Empty
  ///   message](https://developers.google.com/protocol-buffers/docs/reference/google.protobuf#empty)
  ///
  /// @param request
  /// @googleapis_link{google::cloud::dialogflow::v2::DeleteConversationModelRequest,google/cloud/dialogflow/v2/conversation_model.proto#L465}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::v2::DeleteConversationModelOperationMetadata,google/cloud/dialogflow/v2/conversation_model.proto#L602}
  ///
  /// [google.cloud.dialogflow.v2.DeleteConversationModelRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/conversation_model.proto#L465}
  /// [google.cloud.dialogflow.v2.DeleteConversationModelOperationMetadata]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/conversation_model.proto#L602}
  ///
  future<StatusOr<
      google::cloud::dialogflow::v2::DeleteConversationModelOperationMetadata>>
  DeleteConversationModel(
      google::cloud::dialogflow::v2::DeleteConversationModelRequest const&
          request,
      Options opts = {});

  ///
  /// Deploys a model. If a model is already deployed, deploying it
  /// has no effect. A model can only serve prediction requests after it gets
  /// deployed. For article suggestion, custom model will not be used unless
  /// it is deployed.
  ///
  /// This method is a [long-running
  /// operation](https://cloud.google.com/dialogflow/es/docs/how/long-running-operations).
  /// The returned `Operation` type has the following method-specific fields:
  ///
  /// - `metadata`:
  /// [DeployConversationModelOperationMetadata][google.cloud.dialogflow.v2.DeployConversationModelOperationMetadata]
  /// - `response`: An [Empty
  ///   message](https://developers.google.com/protocol-buffers/docs/reference/google.protobuf#empty)
  ///
  /// @param request
  /// @googleapis_link{google::cloud::dialogflow::v2::DeployConversationModelRequest,google/cloud/dialogflow/v2/conversation_model.proto#L473}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::v2::DeployConversationModelOperationMetadata,google/cloud/dialogflow/v2/conversation_model.proto#L580}
  ///
  /// [google.cloud.dialogflow.v2.DeployConversationModelRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/conversation_model.proto#L473}
  /// [google.cloud.dialogflow.v2.DeployConversationModelOperationMetadata]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/conversation_model.proto#L580}
  ///
  future<StatusOr<
      google::cloud::dialogflow::v2::DeployConversationModelOperationMetadata>>
  DeployConversationModel(
      google::cloud::dialogflow::v2::DeployConversationModelRequest const&
          request,
      Options opts = {});

  ///
  /// Undeploys a model. If the model is not deployed this method has no effect.
  /// If the model is currently being used:
  ///   - For article suggestion, article suggestion will fallback to the
  ///   default
  ///     model if model is undeployed.
  ///
  /// This method is a [long-running
  /// operation](https://cloud.google.com/dialogflow/es/docs/how/long-running-operations).
  /// The returned `Operation` type has the following method-specific fields:
  ///
  /// - `metadata`:
  /// [UndeployConversationModelOperationMetadata][google.cloud.dialogflow.v2.UndeployConversationModelOperationMetadata]
  /// - `response`: An [Empty
  ///   message](https://developers.google.com/protocol-buffers/docs/reference/google.protobuf#empty)
  ///
  /// @param request
  /// @googleapis_link{google::cloud::dialogflow::v2::UndeployConversationModelRequest,google/cloud/dialogflow/v2/conversation_model.proto#L481}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::v2::UndeployConversationModelOperationMetadata,google/cloud/dialogflow/v2/conversation_model.proto#L591}
  ///
  /// [google.cloud.dialogflow.v2.UndeployConversationModelRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/conversation_model.proto#L481}
  /// [google.cloud.dialogflow.v2.UndeployConversationModelOperationMetadata]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/conversation_model.proto#L591}
  ///
  future<StatusOr<google::cloud::dialogflow::v2::
                      UndeployConversationModelOperationMetadata>>
  UndeployConversationModel(
      google::cloud::dialogflow::v2::UndeployConversationModelRequest const&
          request,
      Options opts = {});

  ///
  /// Gets an evaluation of conversation model.
  ///
  /// @param name  Required. The conversation model evaluation resource name.
  /// Format:
  ///  `projects/<Project ID>/conversationModels/<Conversation Model
  ///  ID>/evaluations/<Evaluation ID>`
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::v2::ConversationModelEvaluation,google/cloud/dialogflow/v2/conversation_model.proto#L289}
  ///
  /// [google.cloud.dialogflow.v2.GetConversationModelEvaluationRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/conversation_model.proto#L489}
  /// [google.cloud.dialogflow.v2.ConversationModelEvaluation]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/conversation_model.proto#L289}
  ///
  StatusOr<google::cloud::dialogflow::v2::ConversationModelEvaluation>
  GetConversationModelEvaluation(std::string const& name, Options opts = {});

  ///
  /// Gets an evaluation of conversation model.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::dialogflow::v2::GetConversationModelEvaluationRequest,google/cloud/dialogflow/v2/conversation_model.proto#L489}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::v2::ConversationModelEvaluation,google/cloud/dialogflow/v2/conversation_model.proto#L289}
  ///
  /// [google.cloud.dialogflow.v2.GetConversationModelEvaluationRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/conversation_model.proto#L489}
  /// [google.cloud.dialogflow.v2.ConversationModelEvaluation]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/conversation_model.proto#L289}
  ///
  StatusOr<google::cloud::dialogflow::v2::ConversationModelEvaluation>
  GetConversationModelEvaluation(
      google::cloud::dialogflow::v2::
          GetConversationModelEvaluationRequest const& request,
      Options opts = {});

  ///
  /// Lists evaluations of a conversation model.
  ///
  /// @param parent  Required. The conversation model resource name. Format:
  ///  `projects/<Project ID>/conversationModels/<Conversation Model ID>`
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::v2::ConversationModelEvaluation,google/cloud/dialogflow/v2/conversation_model.proto#L289}
  ///
  /// [google.cloud.dialogflow.v2.ListConversationModelEvaluationsRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/conversation_model.proto#L498}
  /// [google.cloud.dialogflow.v2.ConversationModelEvaluation]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/conversation_model.proto#L289}
  ///
  StreamRange<google::cloud::dialogflow::v2::ConversationModelEvaluation>
  ListConversationModelEvaluations(std::string const& parent,
                                   Options opts = {});

  ///
  /// Lists evaluations of a conversation model.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::dialogflow::v2::ListConversationModelEvaluationsRequest,google/cloud/dialogflow/v2/conversation_model.proto#L498}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::v2::ConversationModelEvaluation,google/cloud/dialogflow/v2/conversation_model.proto#L289}
  ///
  /// [google.cloud.dialogflow.v2.ListConversationModelEvaluationsRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/conversation_model.proto#L498}
  /// [google.cloud.dialogflow.v2.ConversationModelEvaluation]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/conversation_model.proto#L289}
  ///
  StreamRange<google::cloud::dialogflow::v2::ConversationModelEvaluation>
  ListConversationModelEvaluations(
      google::cloud::dialogflow::v2::ListConversationModelEvaluationsRequest
          request,
      Options opts = {});

  ///
  /// Creates evaluation of a conversation model.
  ///
  /// @param parent  Required. The conversation model resource name. Format:
  ///  `projects/<Project ID>/locations/<Location
  ///  ID>/conversationModels/<Conversation Model ID>`
  /// @param conversation_model_evaluation  Required. The conversation model
  /// evaluation to be created.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::v2::ConversationModelEvaluation,google/cloud/dialogflow/v2/conversation_model.proto#L289}
  ///
  /// [google.cloud.dialogflow.v2.CreateConversationModelEvaluationRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/conversation_model.proto#L524}
  /// [google.cloud.dialogflow.v2.ConversationModelEvaluation]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/conversation_model.proto#L289}
  ///
  future<StatusOr<google::cloud::dialogflow::v2::ConversationModelEvaluation>>
  CreateConversationModelEvaluation(
      std::string const& parent,
      google::cloud::dialogflow::v2::ConversationModelEvaluation const&
          conversation_model_evaluation,
      Options opts = {});

  ///
  /// Creates evaluation of a conversation model.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::dialogflow::v2::CreateConversationModelEvaluationRequest,google/cloud/dialogflow/v2/conversation_model.proto#L524}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::v2::ConversationModelEvaluation,google/cloud/dialogflow/v2/conversation_model.proto#L289}
  ///
  /// [google.cloud.dialogflow.v2.CreateConversationModelEvaluationRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/conversation_model.proto#L524}
  /// [google.cloud.dialogflow.v2.ConversationModelEvaluation]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/conversation_model.proto#L289}
  ///
  future<StatusOr<google::cloud::dialogflow::v2::ConversationModelEvaluation>>
  CreateConversationModelEvaluation(
      google::cloud::dialogflow::v2::
          CreateConversationModelEvaluationRequest const& request,
      Options opts = {});

 private:
  std::shared_ptr<ConversationModelsConnection> connection_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_es
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_ES_CONVERSATION_MODELS_CLIENT_H
