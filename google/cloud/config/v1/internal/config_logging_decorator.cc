// Copyright 2023 Google LLC
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
// source: google/cloud/config/v1/config.proto

#include "google/cloud/config/v1/internal/config_logging_decorator.h"
#include "google/cloud/internal/log_wrapper.h"
#include "google/cloud/status_or.h"
#include <google/cloud/config/v1/config.grpc.pb.h>
#include <memory>
#include <string>
#include <utility>

namespace google {
namespace cloud {
namespace config_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

ConfigLogging::ConfigLogging(std::shared_ptr<ConfigStub> child,
                             TracingOptions tracing_options,
                             std::set<std::string> const&)
    : child_(std::move(child)), tracing_options_(std::move(tracing_options)) {}

StatusOr<google::cloud::config::v1::ListDeploymentsResponse>
ConfigLogging::ListDeployments(
    grpc::ClientContext& context, Options const& options,
    google::cloud::config::v1::ListDeploymentsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::config::v1::ListDeploymentsRequest const& request) {
        return child_->ListDeployments(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::config::v1::Deployment> ConfigLogging::GetDeployment(
    grpc::ClientContext& context, Options const& options,
    google::cloud::config::v1::GetDeploymentRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::config::v1::GetDeploymentRequest const& request) {
        return child_->GetDeployment(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
ConfigLogging::AsyncCreateDeployment(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::config::v1::CreateDeploymentRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          google::cloud::CompletionQueue& cq,
          std::shared_ptr<grpc::ClientContext> context,
          google::cloud::internal::ImmutableOptions options,
          google::cloud::config::v1::CreateDeploymentRequest const& request) {
        return child_->AsyncCreateDeployment(cq, std::move(context),
                                             std::move(options), request);
      },
      cq, std::move(context), std::move(options), request, __func__,
      tracing_options_);
}

StatusOr<google::longrunning::Operation> ConfigLogging::CreateDeployment(
    grpc::ClientContext& context, Options options,
    google::cloud::config::v1::CreateDeploymentRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context, Options const& options,
          google::cloud::config::v1::CreateDeploymentRequest const& request) {
        return child_->CreateDeployment(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
ConfigLogging::AsyncUpdateDeployment(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::config::v1::UpdateDeploymentRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          google::cloud::CompletionQueue& cq,
          std::shared_ptr<grpc::ClientContext> context,
          google::cloud::internal::ImmutableOptions options,
          google::cloud::config::v1::UpdateDeploymentRequest const& request) {
        return child_->AsyncUpdateDeployment(cq, std::move(context),
                                             std::move(options), request);
      },
      cq, std::move(context), std::move(options), request, __func__,
      tracing_options_);
}

StatusOr<google::longrunning::Operation> ConfigLogging::UpdateDeployment(
    grpc::ClientContext& context, Options options,
    google::cloud::config::v1::UpdateDeploymentRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context, Options const& options,
          google::cloud::config::v1::UpdateDeploymentRequest const& request) {
        return child_->UpdateDeployment(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
ConfigLogging::AsyncDeleteDeployment(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::config::v1::DeleteDeploymentRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          google::cloud::CompletionQueue& cq,
          std::shared_ptr<grpc::ClientContext> context,
          google::cloud::internal::ImmutableOptions options,
          google::cloud::config::v1::DeleteDeploymentRequest const& request) {
        return child_->AsyncDeleteDeployment(cq, std::move(context),
                                             std::move(options), request);
      },
      cq, std::move(context), std::move(options), request, __func__,
      tracing_options_);
}

StatusOr<google::longrunning::Operation> ConfigLogging::DeleteDeployment(
    grpc::ClientContext& context, Options options,
    google::cloud::config::v1::DeleteDeploymentRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context, Options const& options,
          google::cloud::config::v1::DeleteDeploymentRequest const& request) {
        return child_->DeleteDeployment(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::config::v1::ListRevisionsResponse>
ConfigLogging::ListRevisions(
    grpc::ClientContext& context, Options const& options,
    google::cloud::config::v1::ListRevisionsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::config::v1::ListRevisionsRequest const& request) {
        return child_->ListRevisions(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::config::v1::Revision> ConfigLogging::GetRevision(
    grpc::ClientContext& context, Options const& options,
    google::cloud::config::v1::GetRevisionRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::config::v1::GetRevisionRequest const& request) {
        return child_->GetRevision(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::config::v1::Resource> ConfigLogging::GetResource(
    grpc::ClientContext& context, Options const& options,
    google::cloud::config::v1::GetResourceRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::config::v1::GetResourceRequest const& request) {
        return child_->GetResource(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::config::v1::ListResourcesResponse>
ConfigLogging::ListResources(
    grpc::ClientContext& context, Options const& options,
    google::cloud::config::v1::ListResourcesRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::config::v1::ListResourcesRequest const& request) {
        return child_->ListResources(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::config::v1::Statefile>
ConfigLogging::ExportDeploymentStatefile(
    grpc::ClientContext& context, Options const& options,
    google::cloud::config::v1::ExportDeploymentStatefileRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::config::v1::ExportDeploymentStatefileRequest const&
                 request) {
        return child_->ExportDeploymentStatefile(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::config::v1::Statefile>
ConfigLogging::ExportRevisionStatefile(
    grpc::ClientContext& context, Options const& options,
    google::cloud::config::v1::ExportRevisionStatefileRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::config::v1::ExportRevisionStatefileRequest const&
                 request) {
        return child_->ExportRevisionStatefile(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::config::v1::Statefile> ConfigLogging::ImportStatefile(
    grpc::ClientContext& context, Options const& options,
    google::cloud::config::v1::ImportStatefileRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::config::v1::ImportStatefileRequest const& request) {
        return child_->ImportStatefile(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

Status ConfigLogging::DeleteStatefile(
    grpc::ClientContext& context, Options const& options,
    google::cloud::config::v1::DeleteStatefileRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::config::v1::DeleteStatefileRequest const& request) {
        return child_->DeleteStatefile(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
ConfigLogging::AsyncLockDeployment(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::config::v1::LockDeploymentRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::cloud::internal::ImmutableOptions options,
             google::cloud::config::v1::LockDeploymentRequest const& request) {
        return child_->AsyncLockDeployment(cq, std::move(context),
                                           std::move(options), request);
      },
      cq, std::move(context), std::move(options), request, __func__,
      tracing_options_);
}

StatusOr<google::longrunning::Operation> ConfigLogging::LockDeployment(
    grpc::ClientContext& context, Options options,
    google::cloud::config::v1::LockDeploymentRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::config::v1::LockDeploymentRequest const& request) {
        return child_->LockDeployment(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
ConfigLogging::AsyncUnlockDeployment(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::config::v1::UnlockDeploymentRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          google::cloud::CompletionQueue& cq,
          std::shared_ptr<grpc::ClientContext> context,
          google::cloud::internal::ImmutableOptions options,
          google::cloud::config::v1::UnlockDeploymentRequest const& request) {
        return child_->AsyncUnlockDeployment(cq, std::move(context),
                                             std::move(options), request);
      },
      cq, std::move(context), std::move(options), request, __func__,
      tracing_options_);
}

StatusOr<google::longrunning::Operation> ConfigLogging::UnlockDeployment(
    grpc::ClientContext& context, Options options,
    google::cloud::config::v1::UnlockDeploymentRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context, Options const& options,
          google::cloud::config::v1::UnlockDeploymentRequest const& request) {
        return child_->UnlockDeployment(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::config::v1::LockInfo> ConfigLogging::ExportLockInfo(
    grpc::ClientContext& context, Options const& options,
    google::cloud::config::v1::ExportLockInfoRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::config::v1::ExportLockInfoRequest const& request) {
        return child_->ExportLockInfo(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
ConfigLogging::AsyncCreatePreview(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::config::v1::CreatePreviewRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::cloud::internal::ImmutableOptions options,
             google::cloud::config::v1::CreatePreviewRequest const& request) {
        return child_->AsyncCreatePreview(cq, std::move(context),
                                          std::move(options), request);
      },
      cq, std::move(context), std::move(options), request, __func__,
      tracing_options_);
}

StatusOr<google::longrunning::Operation> ConfigLogging::CreatePreview(
    grpc::ClientContext& context, Options options,
    google::cloud::config::v1::CreatePreviewRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::config::v1::CreatePreviewRequest const& request) {
        return child_->CreatePreview(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::config::v1::Preview> ConfigLogging::GetPreview(
    grpc::ClientContext& context, Options const& options,
    google::cloud::config::v1::GetPreviewRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::config::v1::GetPreviewRequest const& request) {
        return child_->GetPreview(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::config::v1::ListPreviewsResponse>
ConfigLogging::ListPreviews(
    grpc::ClientContext& context, Options const& options,
    google::cloud::config::v1::ListPreviewsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::config::v1::ListPreviewsRequest const& request) {
        return child_->ListPreviews(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
ConfigLogging::AsyncDeletePreview(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::config::v1::DeletePreviewRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::cloud::internal::ImmutableOptions options,
             google::cloud::config::v1::DeletePreviewRequest const& request) {
        return child_->AsyncDeletePreview(cq, std::move(context),
                                          std::move(options), request);
      },
      cq, std::move(context), std::move(options), request, __func__,
      tracing_options_);
}

StatusOr<google::longrunning::Operation> ConfigLogging::DeletePreview(
    grpc::ClientContext& context, Options options,
    google::cloud::config::v1::DeletePreviewRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::config::v1::DeletePreviewRequest const& request) {
        return child_->DeletePreview(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::config::v1::ExportPreviewResultResponse>
ConfigLogging::ExportPreviewResult(
    grpc::ClientContext& context, Options const& options,
    google::cloud::config::v1::ExportPreviewResultRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::config::v1::ExportPreviewResultRequest const&
                 request) {
        return child_->ExportPreviewResult(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::config::v1::ListTerraformVersionsResponse>
ConfigLogging::ListTerraformVersions(
    grpc::ClientContext& context, Options const& options,
    google::cloud::config::v1::ListTerraformVersionsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::config::v1::ListTerraformVersionsRequest const&
                 request) {
        return child_->ListTerraformVersions(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::config::v1::TerraformVersion>
ConfigLogging::GetTerraformVersion(
    grpc::ClientContext& context, Options const& options,
    google::cloud::config::v1::GetTerraformVersionRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::config::v1::GetTerraformVersionRequest const&
                 request) {
        return child_->GetTerraformVersion(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
ConfigLogging::AsyncGetOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::longrunning::GetOperationRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::cloud::internal::ImmutableOptions options,
             google::longrunning::GetOperationRequest const& request) {
        return child_->AsyncGetOperation(cq, std::move(context),
                                         std::move(options), request);
      },
      cq, std::move(context), std::move(options), request, __func__,
      tracing_options_);
}

future<Status> ConfigLogging::AsyncCancelOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::longrunning::CancelOperationRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::cloud::internal::ImmutableOptions options,
             google::longrunning::CancelOperationRequest const& request) {
        return child_->AsyncCancelOperation(cq, std::move(context),
                                            std::move(options), request);
      },
      cq, std::move(context), std::move(options), request, __func__,
      tracing_options_);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace config_v1_internal
}  // namespace cloud
}  // namespace google
