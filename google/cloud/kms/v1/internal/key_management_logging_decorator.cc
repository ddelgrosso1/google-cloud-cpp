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
// source: google/cloud/kms/v1/service.proto

#include "google/cloud/kms/v1/internal/key_management_logging_decorator.h"
#include "google/cloud/internal/log_wrapper.h"
#include "google/cloud/status_or.h"
#include <google/cloud/kms/v1/service.grpc.pb.h>
#include <memory>
#include <string>
#include <utility>

namespace google {
namespace cloud {
namespace kms_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

KeyManagementServiceLogging::KeyManagementServiceLogging(
    std::shared_ptr<KeyManagementServiceStub> child,
    TracingOptions tracing_options, std::set<std::string> const&)
    : child_(std::move(child)), tracing_options_(std::move(tracing_options)) {}

StatusOr<google::cloud::kms::v1::ListKeyRingsResponse>
KeyManagementServiceLogging::ListKeyRings(
    grpc::ClientContext& context, Options const& options,
    google::cloud::kms::v1::ListKeyRingsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::kms::v1::ListKeyRingsRequest const& request) {
        return child_->ListKeyRings(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::kms::v1::ListCryptoKeysResponse>
KeyManagementServiceLogging::ListCryptoKeys(
    grpc::ClientContext& context, Options const& options,
    google::cloud::kms::v1::ListCryptoKeysRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::kms::v1::ListCryptoKeysRequest const& request) {
        return child_->ListCryptoKeys(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::kms::v1::ListCryptoKeyVersionsResponse>
KeyManagementServiceLogging::ListCryptoKeyVersions(
    grpc::ClientContext& context, Options const& options,
    google::cloud::kms::v1::ListCryptoKeyVersionsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context, Options const& options,
          google::cloud::kms::v1::ListCryptoKeyVersionsRequest const& request) {
        return child_->ListCryptoKeyVersions(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::kms::v1::ListImportJobsResponse>
KeyManagementServiceLogging::ListImportJobs(
    grpc::ClientContext& context, Options const& options,
    google::cloud::kms::v1::ListImportJobsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::kms::v1::ListImportJobsRequest const& request) {
        return child_->ListImportJobs(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::kms::v1::KeyRing>
KeyManagementServiceLogging::GetKeyRing(
    grpc::ClientContext& context, Options const& options,
    google::cloud::kms::v1::GetKeyRingRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::kms::v1::GetKeyRingRequest const& request) {
        return child_->GetKeyRing(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::kms::v1::CryptoKey>
KeyManagementServiceLogging::GetCryptoKey(
    grpc::ClientContext& context, Options const& options,
    google::cloud::kms::v1::GetCryptoKeyRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::kms::v1::GetCryptoKeyRequest const& request) {
        return child_->GetCryptoKey(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::kms::v1::CryptoKeyVersion>
KeyManagementServiceLogging::GetCryptoKeyVersion(
    grpc::ClientContext& context, Options const& options,
    google::cloud::kms::v1::GetCryptoKeyVersionRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context, Options const& options,
          google::cloud::kms::v1::GetCryptoKeyVersionRequest const& request) {
        return child_->GetCryptoKeyVersion(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::kms::v1::PublicKey>
KeyManagementServiceLogging::GetPublicKey(
    grpc::ClientContext& context, Options const& options,
    google::cloud::kms::v1::GetPublicKeyRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::kms::v1::GetPublicKeyRequest const& request) {
        return child_->GetPublicKey(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::kms::v1::ImportJob>
KeyManagementServiceLogging::GetImportJob(
    grpc::ClientContext& context, Options const& options,
    google::cloud::kms::v1::GetImportJobRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::kms::v1::GetImportJobRequest const& request) {
        return child_->GetImportJob(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::kms::v1::KeyRing>
KeyManagementServiceLogging::CreateKeyRing(
    grpc::ClientContext& context, Options const& options,
    google::cloud::kms::v1::CreateKeyRingRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::kms::v1::CreateKeyRingRequest const& request) {
        return child_->CreateKeyRing(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::kms::v1::CryptoKey>
KeyManagementServiceLogging::CreateCryptoKey(
    grpc::ClientContext& context, Options const& options,
    google::cloud::kms::v1::CreateCryptoKeyRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::kms::v1::CreateCryptoKeyRequest const& request) {
        return child_->CreateCryptoKey(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::kms::v1::CryptoKeyVersion>
KeyManagementServiceLogging::CreateCryptoKeyVersion(
    grpc::ClientContext& context, Options const& options,
    google::cloud::kms::v1::CreateCryptoKeyVersionRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::kms::v1::CreateCryptoKeyVersionRequest const&
                 request) {
        return child_->CreateCryptoKeyVersion(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::kms::v1::CryptoKeyVersion>
KeyManagementServiceLogging::ImportCryptoKeyVersion(
    grpc::ClientContext& context, Options const& options,
    google::cloud::kms::v1::ImportCryptoKeyVersionRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::kms::v1::ImportCryptoKeyVersionRequest const&
                 request) {
        return child_->ImportCryptoKeyVersion(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::kms::v1::ImportJob>
KeyManagementServiceLogging::CreateImportJob(
    grpc::ClientContext& context, Options const& options,
    google::cloud::kms::v1::CreateImportJobRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::kms::v1::CreateImportJobRequest const& request) {
        return child_->CreateImportJob(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::kms::v1::CryptoKey>
KeyManagementServiceLogging::UpdateCryptoKey(
    grpc::ClientContext& context, Options const& options,
    google::cloud::kms::v1::UpdateCryptoKeyRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::kms::v1::UpdateCryptoKeyRequest const& request) {
        return child_->UpdateCryptoKey(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::kms::v1::CryptoKeyVersion>
KeyManagementServiceLogging::UpdateCryptoKeyVersion(
    grpc::ClientContext& context, Options const& options,
    google::cloud::kms::v1::UpdateCryptoKeyVersionRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::kms::v1::UpdateCryptoKeyVersionRequest const&
                 request) {
        return child_->UpdateCryptoKeyVersion(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::kms::v1::CryptoKey>
KeyManagementServiceLogging::UpdateCryptoKeyPrimaryVersion(
    grpc::ClientContext& context, Options const& options,
    google::cloud::kms::v1::UpdateCryptoKeyPrimaryVersionRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::kms::v1::UpdateCryptoKeyPrimaryVersionRequest const&
                 request) {
        return child_->UpdateCryptoKeyPrimaryVersion(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::kms::v1::CryptoKeyVersion>
KeyManagementServiceLogging::DestroyCryptoKeyVersion(
    grpc::ClientContext& context, Options const& options,
    google::cloud::kms::v1::DestroyCryptoKeyVersionRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::kms::v1::DestroyCryptoKeyVersionRequest const&
                 request) {
        return child_->DestroyCryptoKeyVersion(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::kms::v1::CryptoKeyVersion>
KeyManagementServiceLogging::RestoreCryptoKeyVersion(
    grpc::ClientContext& context, Options const& options,
    google::cloud::kms::v1::RestoreCryptoKeyVersionRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::kms::v1::RestoreCryptoKeyVersionRequest const&
                 request) {
        return child_->RestoreCryptoKeyVersion(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::kms::v1::EncryptResponse>
KeyManagementServiceLogging::Encrypt(
    grpc::ClientContext& context, Options const& options,
    google::cloud::kms::v1::EncryptRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::kms::v1::EncryptRequest const& request) {
        return child_->Encrypt(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::kms::v1::DecryptResponse>
KeyManagementServiceLogging::Decrypt(
    grpc::ClientContext& context, Options const& options,
    google::cloud::kms::v1::DecryptRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::kms::v1::DecryptRequest const& request) {
        return child_->Decrypt(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::kms::v1::RawEncryptResponse>
KeyManagementServiceLogging::RawEncrypt(
    grpc::ClientContext& context, Options const& options,
    google::cloud::kms::v1::RawEncryptRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::kms::v1::RawEncryptRequest const& request) {
        return child_->RawEncrypt(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::kms::v1::RawDecryptResponse>
KeyManagementServiceLogging::RawDecrypt(
    grpc::ClientContext& context, Options const& options,
    google::cloud::kms::v1::RawDecryptRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::kms::v1::RawDecryptRequest const& request) {
        return child_->RawDecrypt(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::kms::v1::AsymmetricSignResponse>
KeyManagementServiceLogging::AsymmetricSign(
    grpc::ClientContext& context, Options const& options,
    google::cloud::kms::v1::AsymmetricSignRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::kms::v1::AsymmetricSignRequest const& request) {
        return child_->AsymmetricSign(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::kms::v1::AsymmetricDecryptResponse>
KeyManagementServiceLogging::AsymmetricDecrypt(
    grpc::ClientContext& context, Options const& options,
    google::cloud::kms::v1::AsymmetricDecryptRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::kms::v1::AsymmetricDecryptRequest const& request) {
        return child_->AsymmetricDecrypt(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::kms::v1::MacSignResponse>
KeyManagementServiceLogging::MacSign(
    grpc::ClientContext& context, Options const& options,
    google::cloud::kms::v1::MacSignRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::kms::v1::MacSignRequest const& request) {
        return child_->MacSign(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::kms::v1::MacVerifyResponse>
KeyManagementServiceLogging::MacVerify(
    grpc::ClientContext& context, Options const& options,
    google::cloud::kms::v1::MacVerifyRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::kms::v1::MacVerifyRequest const& request) {
        return child_->MacVerify(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::kms::v1::GenerateRandomBytesResponse>
KeyManagementServiceLogging::GenerateRandomBytes(
    grpc::ClientContext& context, Options const& options,
    google::cloud::kms::v1::GenerateRandomBytesRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context, Options const& options,
          google::cloud::kms::v1::GenerateRandomBytesRequest const& request) {
        return child_->GenerateRandomBytes(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace kms_v1_internal
}  // namespace cloud
}  // namespace google
