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
// source: google/cloud/dialogflow/v2/document.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_ES_INTERNAL_DOCUMENTS_AUTH_DECORATOR_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_ES_INTERNAL_DOCUMENTS_AUTH_DECORATOR_H

#include "google/cloud/dialogflow_es/internal/documents_stub.h"
#include "google/cloud/internal/unified_grpc_credentials.h"
#include "google/cloud/version.h"
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>
#include <set>
#include <string>

namespace google {
namespace cloud {
namespace dialogflow_es_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class DocumentsAuth : public DocumentsStub {
 public:
  ~DocumentsAuth() override = default;
  DocumentsAuth(
      std::shared_ptr<google::cloud::internal::GrpcAuthenticationStrategy> auth,
      std::shared_ptr<DocumentsStub> child);

  StatusOr<google::cloud::dialogflow::v2::ListDocumentsResponse> ListDocuments(
      grpc::ClientContext& context,
      google::cloud::dialogflow::v2::ListDocumentsRequest const& request)
      override;

  StatusOr<google::cloud::dialogflow::v2::Document> GetDocument(
      grpc::ClientContext& context,
      google::cloud::dialogflow::v2::GetDocumentRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncCreateDocument(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      google::cloud::dialogflow::v2::CreateDocumentRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncImportDocuments(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      google::cloud::dialogflow::v2::ImportDocumentsRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncDeleteDocument(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      google::cloud::dialogflow::v2::DeleteDocumentRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncUpdateDocument(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      google::cloud::dialogflow::v2::UpdateDocumentRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncReloadDocument(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      google::cloud::dialogflow::v2::ReloadDocumentRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncExportDocument(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      google::cloud::dialogflow::v2::ExportDocumentRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncGetOperation(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      google::longrunning::GetOperationRequest const& request) override;

  future<Status> AsyncCancelOperation(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      google::longrunning::CancelOperationRequest const& request) override;

 private:
  std::shared_ptr<google::cloud::internal::GrpcAuthenticationStrategy> auth_;
  std::shared_ptr<DocumentsStub> child_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_es_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_ES_INTERNAL_DOCUMENTS_AUTH_DECORATOR_H
