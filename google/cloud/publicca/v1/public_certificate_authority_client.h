// Copyright 2024 Google LLC
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
// source: google/cloud/security/publicca/v1/service.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBLICCA_V1_PUBLIC_CERTIFICATE_AUTHORITY_CLIENT_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBLICCA_V1_PUBLIC_CERTIFICATE_AUTHORITY_CLIENT_H

#include "google/cloud/publicca/v1/public_certificate_authority_connection.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/polling_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <memory>
#include <string>

namespace google {
namespace cloud {
namespace publicca_v1 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

///
/// Manages the resources required for ACME [external account
/// binding](https://tools.ietf.org/html/rfc8555#section-7.3.4) for
/// the public certificate authority service.
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
class PublicCertificateAuthorityServiceClient {
 public:
  explicit PublicCertificateAuthorityServiceClient(
      std::shared_ptr<PublicCertificateAuthorityServiceConnection> connection,
      Options opts = {});
  ~PublicCertificateAuthorityServiceClient();

  ///@{
  /// @name Copy and move support
  PublicCertificateAuthorityServiceClient(
      PublicCertificateAuthorityServiceClient const&) = default;
  PublicCertificateAuthorityServiceClient& operator=(
      PublicCertificateAuthorityServiceClient const&) = default;
  PublicCertificateAuthorityServiceClient(
      PublicCertificateAuthorityServiceClient&&) = default;
  PublicCertificateAuthorityServiceClient& operator=(
      PublicCertificateAuthorityServiceClient&&) = default;
  ///@}

  ///@{
  /// @name Equality
  friend bool operator==(PublicCertificateAuthorityServiceClient const& a,
                         PublicCertificateAuthorityServiceClient const& b) {
    return a.connection_ == b.connection_;
  }
  friend bool operator!=(PublicCertificateAuthorityServiceClient const& a,
                         PublicCertificateAuthorityServiceClient const& b) {
    return !(a == b);
  }
  ///@}

  // clang-format off
  ///
  /// Creates a new
  /// [ExternalAccountKey][google.cloud.security.publicca.v1.ExternalAccountKey]
  /// bound to the project.
  ///
  /// @param parent  Required. The parent resource where this external_account_key will be
  ///  created. Format: projects/[project_id]/locations/[location]. At present
  ///  only the "global" location is supported.
  /// @param external_account_key  Required. The external account key to create. This field only exists to
  ///  future-proof the API. At present, all fields in ExternalAccountKey are
  ///  output only and all values are ignored. For the purpose of the
  ///  CreateExternalAccountKeyRequest, set it to a default/empty value.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.security.publicca.v1.ExternalAccountKey])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.security.publicca.v1.CreateExternalAccountKeyRequest]: @googleapis_reference_link{google/cloud/security/publicca/v1/service.proto#L58}
  /// [google.cloud.security.publicca.v1.ExternalAccountKey]: @googleapis_reference_link{google/cloud/security/publicca/v1/resources.proto#L33}
  ///
  // clang-format on
  StatusOr<google::cloud::security::publicca::v1::ExternalAccountKey>
  CreateExternalAccountKey(
      std::string const& parent,
      google::cloud::security::publicca::v1::ExternalAccountKey const&
          external_account_key,
      Options opts = {});

  // clang-format off
  ///
  /// Creates a new
  /// [ExternalAccountKey][google.cloud.security.publicca.v1.ExternalAccountKey]
  /// bound to the project.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.security.publicca.v1.CreateExternalAccountKeyRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.security.publicca.v1.ExternalAccountKey])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.security.publicca.v1.CreateExternalAccountKeyRequest]: @googleapis_reference_link{google/cloud/security/publicca/v1/service.proto#L58}
  /// [google.cloud.security.publicca.v1.ExternalAccountKey]: @googleapis_reference_link{google/cloud/security/publicca/v1/resources.proto#L33}
  ///
  // clang-format on
  StatusOr<google::cloud::security::publicca::v1::ExternalAccountKey>
  CreateExternalAccountKey(google::cloud::security::publicca::v1::
                               CreateExternalAccountKeyRequest const& request,
                           Options opts = {});

 private:
  std::shared_ptr<PublicCertificateAuthorityServiceConnection> connection_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace publicca_v1
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBLICCA_V1_PUBLIC_CERTIFICATE_AUTHORITY_CLIENT_H
