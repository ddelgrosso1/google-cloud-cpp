// Copyright 2021 Google LLC
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
// source: google/cloud/secretmanager/v1/service.proto

#include "google/cloud/secretmanager/v1/internal/secret_manager_logging_decorator.h"
#include "google/cloud/internal/log_wrapper.h"
#include "google/cloud/status_or.h"
#include <google/cloud/secretmanager/v1/service.grpc.pb.h>
#include <memory>
#include <string>
#include <utility>

namespace google {
namespace cloud {
namespace secretmanager_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

SecretManagerServiceLogging::SecretManagerServiceLogging(
    std::shared_ptr<SecretManagerServiceStub> child,
    TracingOptions tracing_options, std::set<std::string> const&)
    : child_(std::move(child)), tracing_options_(std::move(tracing_options)) {}

StatusOr<google::cloud::secretmanager::v1::ListSecretsResponse>
SecretManagerServiceLogging::ListSecrets(
    grpc::ClientContext& context, Options const& options,
    google::cloud::secretmanager::v1::ListSecretsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context, Options const& options,
          google::cloud::secretmanager::v1::ListSecretsRequest const& request) {
        return child_->ListSecrets(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::secretmanager::v1::Secret>
SecretManagerServiceLogging::CreateSecret(
    grpc::ClientContext& context, Options const& options,
    google::cloud::secretmanager::v1::CreateSecretRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::secretmanager::v1::CreateSecretRequest const&
                 request) {
        return child_->CreateSecret(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::secretmanager::v1::SecretVersion>
SecretManagerServiceLogging::AddSecretVersion(
    grpc::ClientContext& context, Options const& options,
    google::cloud::secretmanager::v1::AddSecretVersionRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::secretmanager::v1::AddSecretVersionRequest const&
                 request) {
        return child_->AddSecretVersion(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::secretmanager::v1::Secret>
SecretManagerServiceLogging::GetSecret(
    grpc::ClientContext& context, Options const& options,
    google::cloud::secretmanager::v1::GetSecretRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context, Options const& options,
          google::cloud::secretmanager::v1::GetSecretRequest const& request) {
        return child_->GetSecret(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::secretmanager::v1::Secret>
SecretManagerServiceLogging::UpdateSecret(
    grpc::ClientContext& context, Options const& options,
    google::cloud::secretmanager::v1::UpdateSecretRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::secretmanager::v1::UpdateSecretRequest const&
                 request) {
        return child_->UpdateSecret(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

Status SecretManagerServiceLogging::DeleteSecret(
    grpc::ClientContext& context, Options const& options,
    google::cloud::secretmanager::v1::DeleteSecretRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::secretmanager::v1::DeleteSecretRequest const&
                 request) {
        return child_->DeleteSecret(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::secretmanager::v1::ListSecretVersionsResponse>
SecretManagerServiceLogging::ListSecretVersions(
    grpc::ClientContext& context, Options const& options,
    google::cloud::secretmanager::v1::ListSecretVersionsRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::secretmanager::v1::ListSecretVersionsRequest const&
                 request) {
        return child_->ListSecretVersions(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::secretmanager::v1::SecretVersion>
SecretManagerServiceLogging::GetSecretVersion(
    grpc::ClientContext& context, Options const& options,
    google::cloud::secretmanager::v1::GetSecretVersionRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::secretmanager::v1::GetSecretVersionRequest const&
                 request) {
        return child_->GetSecretVersion(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::secretmanager::v1::AccessSecretVersionResponse>
SecretManagerServiceLogging::AccessSecretVersion(
    grpc::ClientContext& context, Options const& options,
    google::cloud::secretmanager::v1::AccessSecretVersionRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::secretmanager::v1::AccessSecretVersionRequest const&
                 request) {
        return child_->AccessSecretVersion(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::secretmanager::v1::SecretVersion>
SecretManagerServiceLogging::DisableSecretVersion(
    grpc::ClientContext& context, Options const& options,
    google::cloud::secretmanager::v1::DisableSecretVersionRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context, Options const& options,
          google::cloud::secretmanager::v1::DisableSecretVersionRequest const&
              request) {
        return child_->DisableSecretVersion(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::secretmanager::v1::SecretVersion>
SecretManagerServiceLogging::EnableSecretVersion(
    grpc::ClientContext& context, Options const& options,
    google::cloud::secretmanager::v1::EnableSecretVersionRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::secretmanager::v1::EnableSecretVersionRequest const&
                 request) {
        return child_->EnableSecretVersion(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::secretmanager::v1::SecretVersion>
SecretManagerServiceLogging::DestroySecretVersion(
    grpc::ClientContext& context, Options const& options,
    google::cloud::secretmanager::v1::DestroySecretVersionRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context, Options const& options,
          google::cloud::secretmanager::v1::DestroySecretVersionRequest const&
              request) {
        return child_->DestroySecretVersion(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::iam::v1::Policy> SecretManagerServiceLogging::SetIamPolicy(
    grpc::ClientContext& context, Options const& options,
    google::iam::v1::SetIamPolicyRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::iam::v1::SetIamPolicyRequest const& request) {
        return child_->SetIamPolicy(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::iam::v1::Policy> SecretManagerServiceLogging::GetIamPolicy(
    grpc::ClientContext& context, Options const& options,
    google::iam::v1::GetIamPolicyRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::iam::v1::GetIamPolicyRequest const& request) {
        return child_->GetIamPolicy(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::iam::v1::TestIamPermissionsResponse>
SecretManagerServiceLogging::TestIamPermissions(
    grpc::ClientContext& context, Options const& options,
    google::iam::v1::TestIamPermissionsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::iam::v1::TestIamPermissionsRequest const& request) {
        return child_->TestIamPermissions(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace secretmanager_v1_internal
}  // namespace cloud
}  // namespace google
