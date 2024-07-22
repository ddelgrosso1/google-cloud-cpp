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
// source: google/spanner/admin/instance/v1/spanner_instance_admin.proto

#include "google/cloud/spanner/admin/internal/instance_admin_metadata_decorator.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/absl_str_cat_quiet.h"
#include "google/cloud/internal/api_client_header.h"
#include "google/cloud/internal/url_encode.h"
#include "google/cloud/status_or.h"
#include <google/spanner/admin/instance/v1/spanner_instance_admin.grpc.pb.h>
#include <memory>
#include <string>
#include <utility>
#include <vector>

namespace google {
namespace cloud {
namespace spanner_admin_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

InstanceAdminMetadata::InstanceAdminMetadata(
    std::shared_ptr<InstanceAdminStub> child,
    std::multimap<std::string, std::string> fixed_metadata,
    std::string api_client_header)
    : child_(std::move(child)),
      fixed_metadata_(std::move(fixed_metadata)),
      api_client_header_(
          api_client_header.empty()
              ? google::cloud::internal::GeneratedLibClientHeader()
              : std::move(api_client_header)) {}

StatusOr<google::spanner::admin::instance::v1::ListInstanceConfigsResponse>
InstanceAdminMetadata::ListInstanceConfigs(
    grpc::ClientContext& context, Options const& options,
    google::spanner::admin::instance::v1::ListInstanceConfigsRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListInstanceConfigs(context, options, request);
}

StatusOr<google::spanner::admin::instance::v1::InstanceConfig>
InstanceAdminMetadata::GetInstanceConfig(
    grpc::ClientContext& context, Options const& options,
    google::spanner::admin::instance::v1::GetInstanceConfigRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetInstanceConfig(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
InstanceAdminMetadata::AsyncCreateInstanceConfig(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::spanner::admin::instance::v1::CreateInstanceConfigRequest const&
        request) {
  SetMetadata(*context, *options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->AsyncCreateInstanceConfig(cq, std::move(context),
                                           std::move(options), request);
}

StatusOr<google::longrunning::Operation>
InstanceAdminMetadata::CreateInstanceConfig(
    grpc::ClientContext& context, Options options,
    google::spanner::admin::instance::v1::CreateInstanceConfigRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->CreateInstanceConfig(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
InstanceAdminMetadata::AsyncUpdateInstanceConfig(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::spanner::admin::instance::v1::UpdateInstanceConfigRequest const&
        request) {
  SetMetadata(
      *context, *options,
      absl::StrCat("instance_config.name=",
                   internal::UrlEncode(request.instance_config().name())));
  return child_->AsyncUpdateInstanceConfig(cq, std::move(context),
                                           std::move(options), request);
}

StatusOr<google::longrunning::Operation>
InstanceAdminMetadata::UpdateInstanceConfig(
    grpc::ClientContext& context, Options options,
    google::spanner::admin::instance::v1::UpdateInstanceConfigRequest const&
        request) {
  SetMetadata(
      context, options,
      absl::StrCat("instance_config.name=",
                   internal::UrlEncode(request.instance_config().name())));
  return child_->UpdateInstanceConfig(context, options, request);
}

Status InstanceAdminMetadata::DeleteInstanceConfig(
    grpc::ClientContext& context, Options const& options,
    google::spanner::admin::instance::v1::DeleteInstanceConfigRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->DeleteInstanceConfig(context, options, request);
}

StatusOr<
    google::spanner::admin::instance::v1::ListInstanceConfigOperationsResponse>
InstanceAdminMetadata::ListInstanceConfigOperations(
    grpc::ClientContext& context, Options const& options,
    google::spanner::admin::instance::v1::
        ListInstanceConfigOperationsRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListInstanceConfigOperations(context, options, request);
}

StatusOr<google::spanner::admin::instance::v1::ListInstancesResponse>
InstanceAdminMetadata::ListInstances(
    grpc::ClientContext& context, Options const& options,
    google::spanner::admin::instance::v1::ListInstancesRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListInstances(context, options, request);
}

StatusOr<google::spanner::admin::instance::v1::ListInstancePartitionsResponse>
InstanceAdminMetadata::ListInstancePartitions(
    grpc::ClientContext& context, Options const& options,
    google::spanner::admin::instance::v1::ListInstancePartitionsRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListInstancePartitions(context, options, request);
}

StatusOr<google::spanner::admin::instance::v1::Instance>
InstanceAdminMetadata::GetInstance(
    grpc::ClientContext& context, Options const& options,
    google::spanner::admin::instance::v1::GetInstanceRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetInstance(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
InstanceAdminMetadata::AsyncCreateInstance(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::spanner::admin::instance::v1::CreateInstanceRequest const&
        request) {
  SetMetadata(*context, *options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->AsyncCreateInstance(cq, std::move(context), std::move(options),
                                     request);
}

StatusOr<google::longrunning::Operation> InstanceAdminMetadata::CreateInstance(
    grpc::ClientContext& context, Options options,
    google::spanner::admin::instance::v1::CreateInstanceRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->CreateInstance(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
InstanceAdminMetadata::AsyncUpdateInstance(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::spanner::admin::instance::v1::UpdateInstanceRequest const&
        request) {
  SetMetadata(*context, *options,
              absl::StrCat("instance.name=",
                           internal::UrlEncode(request.instance().name())));
  return child_->AsyncUpdateInstance(cq, std::move(context), std::move(options),
                                     request);
}

StatusOr<google::longrunning::Operation> InstanceAdminMetadata::UpdateInstance(
    grpc::ClientContext& context, Options options,
    google::spanner::admin::instance::v1::UpdateInstanceRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("instance.name=",
                           internal::UrlEncode(request.instance().name())));
  return child_->UpdateInstance(context, options, request);
}

Status InstanceAdminMetadata::DeleteInstance(
    grpc::ClientContext& context, Options const& options,
    google::spanner::admin::instance::v1::DeleteInstanceRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->DeleteInstance(context, options, request);
}

StatusOr<google::iam::v1::Policy> InstanceAdminMetadata::SetIamPolicy(
    grpc::ClientContext& context, Options const& options,
    google::iam::v1::SetIamPolicyRequest const& request) {
  SetMetadata(
      context, options,
      absl::StrCat("resource=", internal::UrlEncode(request.resource())));
  return child_->SetIamPolicy(context, options, request);
}

StatusOr<google::iam::v1::Policy> InstanceAdminMetadata::GetIamPolicy(
    grpc::ClientContext& context, Options const& options,
    google::iam::v1::GetIamPolicyRequest const& request) {
  SetMetadata(
      context, options,
      absl::StrCat("resource=", internal::UrlEncode(request.resource())));
  return child_->GetIamPolicy(context, options, request);
}

StatusOr<google::iam::v1::TestIamPermissionsResponse>
InstanceAdminMetadata::TestIamPermissions(
    grpc::ClientContext& context, Options const& options,
    google::iam::v1::TestIamPermissionsRequest const& request) {
  SetMetadata(
      context, options,
      absl::StrCat("resource=", internal::UrlEncode(request.resource())));
  return child_->TestIamPermissions(context, options, request);
}

StatusOr<google::spanner::admin::instance::v1::InstancePartition>
InstanceAdminMetadata::GetInstancePartition(
    grpc::ClientContext& context, Options const& options,
    google::spanner::admin::instance::v1::GetInstancePartitionRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetInstancePartition(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
InstanceAdminMetadata::AsyncCreateInstancePartition(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::spanner::admin::instance::v1::CreateInstancePartitionRequest const&
        request) {
  SetMetadata(*context, *options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->AsyncCreateInstancePartition(cq, std::move(context),
                                              std::move(options), request);
}

StatusOr<google::longrunning::Operation>
InstanceAdminMetadata::CreateInstancePartition(
    grpc::ClientContext& context, Options options,
    google::spanner::admin::instance::v1::CreateInstancePartitionRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->CreateInstancePartition(context, options, request);
}

Status InstanceAdminMetadata::DeleteInstancePartition(
    grpc::ClientContext& context, Options const& options,
    google::spanner::admin::instance::v1::DeleteInstancePartitionRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->DeleteInstancePartition(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
InstanceAdminMetadata::AsyncUpdateInstancePartition(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::spanner::admin::instance::v1::UpdateInstancePartitionRequest const&
        request) {
  SetMetadata(
      *context, *options,
      absl::StrCat("instance_partition.name=",
                   internal::UrlEncode(request.instance_partition().name())));
  return child_->AsyncUpdateInstancePartition(cq, std::move(context),
                                              std::move(options), request);
}

StatusOr<google::longrunning::Operation>
InstanceAdminMetadata::UpdateInstancePartition(
    grpc::ClientContext& context, Options options,
    google::spanner::admin::instance::v1::UpdateInstancePartitionRequest const&
        request) {
  SetMetadata(
      context, options,
      absl::StrCat("instance_partition.name=",
                   internal::UrlEncode(request.instance_partition().name())));
  return child_->UpdateInstancePartition(context, options, request);
}

StatusOr<google::spanner::admin::instance::v1::
             ListInstancePartitionOperationsResponse>
InstanceAdminMetadata::ListInstancePartitionOperations(
    grpc::ClientContext& context, Options const& options,
    google::spanner::admin::instance::v1::
        ListInstancePartitionOperationsRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListInstancePartitionOperations(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
InstanceAdminMetadata::AsyncGetOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::longrunning::GetOperationRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncGetOperation(cq, std::move(context), std::move(options),
                                   request);
}

future<Status> InstanceAdminMetadata::AsyncCancelOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::longrunning::CancelOperationRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncCancelOperation(cq, std::move(context),
                                      std::move(options), request);
}

void InstanceAdminMetadata::SetMetadata(grpc::ClientContext& context,
                                        Options const& options,
                                        std::string const& request_params) {
  context.AddMetadata("x-goog-request-params", request_params);
  SetMetadata(context, options);
}

void InstanceAdminMetadata::SetMetadata(grpc::ClientContext& context,
                                        Options const& options) {
  google::cloud::internal::SetMetadata(context, options, fixed_metadata_,
                                       api_client_header_);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace spanner_admin_internal
}  // namespace cloud
}  // namespace google
