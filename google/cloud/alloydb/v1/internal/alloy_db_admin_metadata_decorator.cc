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
// source: google/cloud/alloydb/v1/service.proto

#include "google/cloud/alloydb/v1/internal/alloy_db_admin_metadata_decorator.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/absl_str_cat_quiet.h"
#include "google/cloud/internal/api_client_header.h"
#include "google/cloud/internal/url_encode.h"
#include "google/cloud/status_or.h"
#include <google/cloud/alloydb/v1/service.grpc.pb.h>
#include <memory>
#include <string>
#include <utility>
#include <vector>

namespace google {
namespace cloud {
namespace alloydb_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

AlloyDBAdminMetadata::AlloyDBAdminMetadata(
    std::shared_ptr<AlloyDBAdminStub> child,
    std::multimap<std::string, std::string> fixed_metadata,
    std::string api_client_header)
    : child_(std::move(child)),
      fixed_metadata_(std::move(fixed_metadata)),
      api_client_header_(
          api_client_header.empty()
              ? google::cloud::internal::GeneratedLibClientHeader()
              : std::move(api_client_header)) {}

StatusOr<google::cloud::alloydb::v1::ListClustersResponse>
AlloyDBAdminMetadata::ListClusters(
    grpc::ClientContext& context, Options const& options,
    google::cloud::alloydb::v1::ListClustersRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListClusters(context, options, request);
}

StatusOr<google::cloud::alloydb::v1::Cluster> AlloyDBAdminMetadata::GetCluster(
    grpc::ClientContext& context, Options const& options,
    google::cloud::alloydb::v1::GetClusterRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetCluster(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
AlloyDBAdminMetadata::AsyncCreateCluster(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::alloydb::v1::CreateClusterRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->AsyncCreateCluster(cq, std::move(context), std::move(options),
                                    request);
}

StatusOr<google::longrunning::Operation> AlloyDBAdminMetadata::CreateCluster(
    grpc::ClientContext& context, Options options,
    google::cloud::alloydb::v1::CreateClusterRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->CreateCluster(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
AlloyDBAdminMetadata::AsyncUpdateCluster(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::alloydb::v1::UpdateClusterRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("cluster.name=",
                           internal::UrlEncode(request.cluster().name())));
  return child_->AsyncUpdateCluster(cq, std::move(context), std::move(options),
                                    request);
}

StatusOr<google::longrunning::Operation> AlloyDBAdminMetadata::UpdateCluster(
    grpc::ClientContext& context, Options options,
    google::cloud::alloydb::v1::UpdateClusterRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("cluster.name=",
                           internal::UrlEncode(request.cluster().name())));
  return child_->UpdateCluster(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
AlloyDBAdminMetadata::AsyncDeleteCluster(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::alloydb::v1::DeleteClusterRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncDeleteCluster(cq, std::move(context), std::move(options),
                                    request);
}

StatusOr<google::longrunning::Operation> AlloyDBAdminMetadata::DeleteCluster(
    grpc::ClientContext& context, Options options,
    google::cloud::alloydb::v1::DeleteClusterRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->DeleteCluster(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
AlloyDBAdminMetadata::AsyncPromoteCluster(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::alloydb::v1::PromoteClusterRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncPromoteCluster(cq, std::move(context), std::move(options),
                                     request);
}

StatusOr<google::longrunning::Operation> AlloyDBAdminMetadata::PromoteCluster(
    grpc::ClientContext& context, Options options,
    google::cloud::alloydb::v1::PromoteClusterRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->PromoteCluster(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
AlloyDBAdminMetadata::AsyncRestoreCluster(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::alloydb::v1::RestoreClusterRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->AsyncRestoreCluster(cq, std::move(context), std::move(options),
                                     request);
}

StatusOr<google::longrunning::Operation> AlloyDBAdminMetadata::RestoreCluster(
    grpc::ClientContext& context, Options options,
    google::cloud::alloydb::v1::RestoreClusterRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->RestoreCluster(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
AlloyDBAdminMetadata::AsyncCreateSecondaryCluster(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::alloydb::v1::CreateSecondaryClusterRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->AsyncCreateSecondaryCluster(cq, std::move(context),
                                             std::move(options), request);
}

StatusOr<google::longrunning::Operation>
AlloyDBAdminMetadata::CreateSecondaryCluster(
    grpc::ClientContext& context, Options options,
    google::cloud::alloydb::v1::CreateSecondaryClusterRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->CreateSecondaryCluster(context, options, request);
}

StatusOr<google::cloud::alloydb::v1::ListInstancesResponse>
AlloyDBAdminMetadata::ListInstances(
    grpc::ClientContext& context, Options const& options,
    google::cloud::alloydb::v1::ListInstancesRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListInstances(context, options, request);
}

StatusOr<google::cloud::alloydb::v1::Instance>
AlloyDBAdminMetadata::GetInstance(
    grpc::ClientContext& context, Options const& options,
    google::cloud::alloydb::v1::GetInstanceRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetInstance(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
AlloyDBAdminMetadata::AsyncCreateInstance(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::alloydb::v1::CreateInstanceRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->AsyncCreateInstance(cq, std::move(context), std::move(options),
                                     request);
}

StatusOr<google::longrunning::Operation> AlloyDBAdminMetadata::CreateInstance(
    grpc::ClientContext& context, Options options,
    google::cloud::alloydb::v1::CreateInstanceRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->CreateInstance(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
AlloyDBAdminMetadata::AsyncCreateSecondaryInstance(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::alloydb::v1::CreateSecondaryInstanceRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->AsyncCreateSecondaryInstance(cq, std::move(context),
                                              std::move(options), request);
}

StatusOr<google::longrunning::Operation>
AlloyDBAdminMetadata::CreateSecondaryInstance(
    grpc::ClientContext& context, Options options,
    google::cloud::alloydb::v1::CreateSecondaryInstanceRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->CreateSecondaryInstance(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
AlloyDBAdminMetadata::AsyncBatchCreateInstances(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::alloydb::v1::BatchCreateInstancesRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->AsyncBatchCreateInstances(cq, std::move(context),
                                           std::move(options), request);
}

StatusOr<google::longrunning::Operation>
AlloyDBAdminMetadata::BatchCreateInstances(
    grpc::ClientContext& context, Options options,
    google::cloud::alloydb::v1::BatchCreateInstancesRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->BatchCreateInstances(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
AlloyDBAdminMetadata::AsyncUpdateInstance(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::alloydb::v1::UpdateInstanceRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("instance.name=",
                           internal::UrlEncode(request.instance().name())));
  return child_->AsyncUpdateInstance(cq, std::move(context), std::move(options),
                                     request);
}

StatusOr<google::longrunning::Operation> AlloyDBAdminMetadata::UpdateInstance(
    grpc::ClientContext& context, Options options,
    google::cloud::alloydb::v1::UpdateInstanceRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("instance.name=",
                           internal::UrlEncode(request.instance().name())));
  return child_->UpdateInstance(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
AlloyDBAdminMetadata::AsyncDeleteInstance(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::alloydb::v1::DeleteInstanceRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncDeleteInstance(cq, std::move(context), std::move(options),
                                     request);
}

StatusOr<google::longrunning::Operation> AlloyDBAdminMetadata::DeleteInstance(
    grpc::ClientContext& context, Options options,
    google::cloud::alloydb::v1::DeleteInstanceRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->DeleteInstance(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
AlloyDBAdminMetadata::AsyncFailoverInstance(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::alloydb::v1::FailoverInstanceRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncFailoverInstance(cq, std::move(context),
                                       std::move(options), request);
}

StatusOr<google::longrunning::Operation> AlloyDBAdminMetadata::FailoverInstance(
    grpc::ClientContext& context, Options options,
    google::cloud::alloydb::v1::FailoverInstanceRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->FailoverInstance(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
AlloyDBAdminMetadata::AsyncInjectFault(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::alloydb::v1::InjectFaultRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncInjectFault(cq, std::move(context), std::move(options),
                                  request);
}

StatusOr<google::longrunning::Operation> AlloyDBAdminMetadata::InjectFault(
    grpc::ClientContext& context, Options options,
    google::cloud::alloydb::v1::InjectFaultRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->InjectFault(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
AlloyDBAdminMetadata::AsyncRestartInstance(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::alloydb::v1::RestartInstanceRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncRestartInstance(cq, std::move(context),
                                      std::move(options), request);
}

StatusOr<google::longrunning::Operation> AlloyDBAdminMetadata::RestartInstance(
    grpc::ClientContext& context, Options options,
    google::cloud::alloydb::v1::RestartInstanceRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->RestartInstance(context, options, request);
}

StatusOr<google::cloud::alloydb::v1::ListBackupsResponse>
AlloyDBAdminMetadata::ListBackups(
    grpc::ClientContext& context, Options const& options,
    google::cloud::alloydb::v1::ListBackupsRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListBackups(context, options, request);
}

StatusOr<google::cloud::alloydb::v1::Backup> AlloyDBAdminMetadata::GetBackup(
    grpc::ClientContext& context, Options const& options,
    google::cloud::alloydb::v1::GetBackupRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetBackup(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
AlloyDBAdminMetadata::AsyncCreateBackup(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::alloydb::v1::CreateBackupRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->AsyncCreateBackup(cq, std::move(context), std::move(options),
                                   request);
}

StatusOr<google::longrunning::Operation> AlloyDBAdminMetadata::CreateBackup(
    grpc::ClientContext& context, Options options,
    google::cloud::alloydb::v1::CreateBackupRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->CreateBackup(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
AlloyDBAdminMetadata::AsyncUpdateBackup(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::alloydb::v1::UpdateBackupRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("backup.name=",
                           internal::UrlEncode(request.backup().name())));
  return child_->AsyncUpdateBackup(cq, std::move(context), std::move(options),
                                   request);
}

StatusOr<google::longrunning::Operation> AlloyDBAdminMetadata::UpdateBackup(
    grpc::ClientContext& context, Options options,
    google::cloud::alloydb::v1::UpdateBackupRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("backup.name=",
                           internal::UrlEncode(request.backup().name())));
  return child_->UpdateBackup(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
AlloyDBAdminMetadata::AsyncDeleteBackup(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::alloydb::v1::DeleteBackupRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncDeleteBackup(cq, std::move(context), std::move(options),
                                   request);
}

StatusOr<google::longrunning::Operation> AlloyDBAdminMetadata::DeleteBackup(
    grpc::ClientContext& context, Options options,
    google::cloud::alloydb::v1::DeleteBackupRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->DeleteBackup(context, options, request);
}

StatusOr<google::cloud::alloydb::v1::ListSupportedDatabaseFlagsResponse>
AlloyDBAdminMetadata::ListSupportedDatabaseFlags(
    grpc::ClientContext& context, Options const& options,
    google::cloud::alloydb::v1::ListSupportedDatabaseFlagsRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListSupportedDatabaseFlags(context, options, request);
}

StatusOr<google::cloud::alloydb::v1::GenerateClientCertificateResponse>
AlloyDBAdminMetadata::GenerateClientCertificate(
    grpc::ClientContext& context, Options const& options,
    google::cloud::alloydb::v1::GenerateClientCertificateRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->GenerateClientCertificate(context, options, request);
}

StatusOr<google::cloud::alloydb::v1::ConnectionInfo>
AlloyDBAdminMetadata::GetConnectionInfo(
    grpc::ClientContext& context, Options const& options,
    google::cloud::alloydb::v1::GetConnectionInfoRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->GetConnectionInfo(context, options, request);
}

StatusOr<google::cloud::alloydb::v1::ListUsersResponse>
AlloyDBAdminMetadata::ListUsers(
    grpc::ClientContext& context, Options const& options,
    google::cloud::alloydb::v1::ListUsersRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListUsers(context, options, request);
}

StatusOr<google::cloud::alloydb::v1::User> AlloyDBAdminMetadata::GetUser(
    grpc::ClientContext& context, Options const& options,
    google::cloud::alloydb::v1::GetUserRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetUser(context, options, request);
}

StatusOr<google::cloud::alloydb::v1::User> AlloyDBAdminMetadata::CreateUser(
    grpc::ClientContext& context, Options const& options,
    google::cloud::alloydb::v1::CreateUserRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->CreateUser(context, options, request);
}

StatusOr<google::cloud::alloydb::v1::User> AlloyDBAdminMetadata::UpdateUser(
    grpc::ClientContext& context, Options const& options,
    google::cloud::alloydb::v1::UpdateUserRequest const& request) {
  SetMetadata(
      context, options,
      absl::StrCat("user.name=", internal::UrlEncode(request.user().name())));
  return child_->UpdateUser(context, options, request);
}

Status AlloyDBAdminMetadata::DeleteUser(
    grpc::ClientContext& context, Options const& options,
    google::cloud::alloydb::v1::DeleteUserRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->DeleteUser(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
AlloyDBAdminMetadata::AsyncGetOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::longrunning::GetOperationRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncGetOperation(cq, std::move(context), std::move(options),
                                   request);
}

future<Status> AlloyDBAdminMetadata::AsyncCancelOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::longrunning::CancelOperationRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncCancelOperation(cq, std::move(context),
                                      std::move(options), request);
}

void AlloyDBAdminMetadata::SetMetadata(grpc::ClientContext& context,
                                       Options const& options,
                                       std::string const& request_params) {
  context.AddMetadata("x-goog-request-params", request_params);
  SetMetadata(context, options);
}

void AlloyDBAdminMetadata::SetMetadata(grpc::ClientContext& context,
                                       Options const& options) {
  google::cloud::internal::SetMetadata(context, options, fixed_metadata_,
                                       api_client_header_);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace alloydb_v1_internal
}  // namespace cloud
}  // namespace google
