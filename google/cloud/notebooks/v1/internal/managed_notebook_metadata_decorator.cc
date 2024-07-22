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
// source: google/cloud/notebooks/v1/managed_service.proto

#include "google/cloud/notebooks/v1/internal/managed_notebook_metadata_decorator.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/absl_str_cat_quiet.h"
#include "google/cloud/internal/api_client_header.h"
#include "google/cloud/internal/url_encode.h"
#include "google/cloud/status_or.h"
#include <google/cloud/notebooks/v1/managed_service.grpc.pb.h>
#include <memory>
#include <string>
#include <utility>
#include <vector>

namespace google {
namespace cloud {
namespace notebooks_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

ManagedNotebookServiceMetadata::ManagedNotebookServiceMetadata(
    std::shared_ptr<ManagedNotebookServiceStub> child,
    std::multimap<std::string, std::string> fixed_metadata,
    std::string api_client_header)
    : child_(std::move(child)),
      fixed_metadata_(std::move(fixed_metadata)),
      api_client_header_(
          api_client_header.empty()
              ? google::cloud::internal::GeneratedLibClientHeader()
              : std::move(api_client_header)) {}

StatusOr<google::cloud::notebooks::v1::ListRuntimesResponse>
ManagedNotebookServiceMetadata::ListRuntimes(
    grpc::ClientContext& context, Options const& options,
    google::cloud::notebooks::v1::ListRuntimesRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListRuntimes(context, options, request);
}

StatusOr<google::cloud::notebooks::v1::Runtime>
ManagedNotebookServiceMetadata::GetRuntime(
    grpc::ClientContext& context, Options const& options,
    google::cloud::notebooks::v1::GetRuntimeRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetRuntime(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
ManagedNotebookServiceMetadata::AsyncCreateRuntime(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::notebooks::v1::CreateRuntimeRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->AsyncCreateRuntime(cq, std::move(context), std::move(options),
                                    request);
}

StatusOr<google::longrunning::Operation>
ManagedNotebookServiceMetadata::CreateRuntime(
    grpc::ClientContext& context, Options options,
    google::cloud::notebooks::v1::CreateRuntimeRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->CreateRuntime(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
ManagedNotebookServiceMetadata::AsyncUpdateRuntime(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::notebooks::v1::UpdateRuntimeRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("runtime.name=",
                           internal::UrlEncode(request.runtime().name())));
  return child_->AsyncUpdateRuntime(cq, std::move(context), std::move(options),
                                    request);
}

StatusOr<google::longrunning::Operation>
ManagedNotebookServiceMetadata::UpdateRuntime(
    grpc::ClientContext& context, Options options,
    google::cloud::notebooks::v1::UpdateRuntimeRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("runtime.name=",
                           internal::UrlEncode(request.runtime().name())));
  return child_->UpdateRuntime(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
ManagedNotebookServiceMetadata::AsyncDeleteRuntime(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::notebooks::v1::DeleteRuntimeRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncDeleteRuntime(cq, std::move(context), std::move(options),
                                    request);
}

StatusOr<google::longrunning::Operation>
ManagedNotebookServiceMetadata::DeleteRuntime(
    grpc::ClientContext& context, Options options,
    google::cloud::notebooks::v1::DeleteRuntimeRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->DeleteRuntime(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
ManagedNotebookServiceMetadata::AsyncStartRuntime(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::notebooks::v1::StartRuntimeRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncStartRuntime(cq, std::move(context), std::move(options),
                                   request);
}

StatusOr<google::longrunning::Operation>
ManagedNotebookServiceMetadata::StartRuntime(
    grpc::ClientContext& context, Options options,
    google::cloud::notebooks::v1::StartRuntimeRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->StartRuntime(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
ManagedNotebookServiceMetadata::AsyncStopRuntime(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::notebooks::v1::StopRuntimeRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncStopRuntime(cq, std::move(context), std::move(options),
                                  request);
}

StatusOr<google::longrunning::Operation>
ManagedNotebookServiceMetadata::StopRuntime(
    grpc::ClientContext& context, Options options,
    google::cloud::notebooks::v1::StopRuntimeRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->StopRuntime(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
ManagedNotebookServiceMetadata::AsyncSwitchRuntime(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::notebooks::v1::SwitchRuntimeRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncSwitchRuntime(cq, std::move(context), std::move(options),
                                    request);
}

StatusOr<google::longrunning::Operation>
ManagedNotebookServiceMetadata::SwitchRuntime(
    grpc::ClientContext& context, Options options,
    google::cloud::notebooks::v1::SwitchRuntimeRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->SwitchRuntime(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
ManagedNotebookServiceMetadata::AsyncResetRuntime(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::notebooks::v1::ResetRuntimeRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncResetRuntime(cq, std::move(context), std::move(options),
                                   request);
}

StatusOr<google::longrunning::Operation>
ManagedNotebookServiceMetadata::ResetRuntime(
    grpc::ClientContext& context, Options options,
    google::cloud::notebooks::v1::ResetRuntimeRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->ResetRuntime(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
ManagedNotebookServiceMetadata::AsyncUpgradeRuntime(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::notebooks::v1::UpgradeRuntimeRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncUpgradeRuntime(cq, std::move(context), std::move(options),
                                     request);
}

StatusOr<google::longrunning::Operation>
ManagedNotebookServiceMetadata::UpgradeRuntime(
    grpc::ClientContext& context, Options options,
    google::cloud::notebooks::v1::UpgradeRuntimeRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->UpgradeRuntime(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
ManagedNotebookServiceMetadata::AsyncReportRuntimeEvent(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::notebooks::v1::ReportRuntimeEventRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncReportRuntimeEvent(cq, std::move(context),
                                         std::move(options), request);
}

StatusOr<google::longrunning::Operation>
ManagedNotebookServiceMetadata::ReportRuntimeEvent(
    grpc::ClientContext& context, Options options,
    google::cloud::notebooks::v1::ReportRuntimeEventRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->ReportRuntimeEvent(context, options, request);
}

StatusOr<google::cloud::notebooks::v1::RefreshRuntimeTokenInternalResponse>
ManagedNotebookServiceMetadata::RefreshRuntimeTokenInternal(
    grpc::ClientContext& context, Options const& options,
    google::cloud::notebooks::v1::RefreshRuntimeTokenInternalRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->RefreshRuntimeTokenInternal(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
ManagedNotebookServiceMetadata::AsyncDiagnoseRuntime(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::notebooks::v1::DiagnoseRuntimeRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncDiagnoseRuntime(cq, std::move(context),
                                      std::move(options), request);
}

StatusOr<google::longrunning::Operation>
ManagedNotebookServiceMetadata::DiagnoseRuntime(
    grpc::ClientContext& context, Options options,
    google::cloud::notebooks::v1::DiagnoseRuntimeRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->DiagnoseRuntime(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
ManagedNotebookServiceMetadata::AsyncGetOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::longrunning::GetOperationRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncGetOperation(cq, std::move(context), std::move(options),
                                   request);
}

future<Status> ManagedNotebookServiceMetadata::AsyncCancelOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::longrunning::CancelOperationRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncCancelOperation(cq, std::move(context),
                                      std::move(options), request);
}

void ManagedNotebookServiceMetadata::SetMetadata(
    grpc::ClientContext& context, Options const& options,
    std::string const& request_params) {
  context.AddMetadata("x-goog-request-params", request_params);
  SetMetadata(context, options);
}

void ManagedNotebookServiceMetadata::SetMetadata(grpc::ClientContext& context,
                                                 Options const& options) {
  google::cloud::internal::SetMetadata(context, options, fixed_metadata_,
                                       api_client_header_);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace notebooks_v1_internal
}  // namespace cloud
}  // namespace google
