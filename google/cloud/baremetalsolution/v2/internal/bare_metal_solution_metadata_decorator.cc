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
// source: google/cloud/baremetalsolution/v2/baremetalsolution.proto

#include "google/cloud/baremetalsolution/v2/internal/bare_metal_solution_metadata_decorator.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/absl_str_cat_quiet.h"
#include "google/cloud/internal/api_client_header.h"
#include "google/cloud/internal/url_encode.h"
#include "google/cloud/status_or.h"
#include <google/cloud/baremetalsolution/v2/baremetalsolution.grpc.pb.h>
#include <memory>
#include <string>
#include <utility>
#include <vector>

namespace google {
namespace cloud {
namespace baremetalsolution_v2_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

BareMetalSolutionMetadata::BareMetalSolutionMetadata(
    std::shared_ptr<BareMetalSolutionStub> child,
    std::multimap<std::string, std::string> fixed_metadata,
    std::string api_client_header)
    : child_(std::move(child)),
      fixed_metadata_(std::move(fixed_metadata)),
      api_client_header_(
          api_client_header.empty()
              ? google::cloud::internal::GeneratedLibClientHeader()
              : std::move(api_client_header)) {}

StatusOr<google::cloud::baremetalsolution::v2::ListInstancesResponse>
BareMetalSolutionMetadata::ListInstances(
    grpc::ClientContext& context, Options const& options,
    google::cloud::baremetalsolution::v2::ListInstancesRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListInstances(context, options, request);
}

StatusOr<google::cloud::baremetalsolution::v2::Instance>
BareMetalSolutionMetadata::GetInstance(
    grpc::ClientContext& context, Options const& options,
    google::cloud::baremetalsolution::v2::GetInstanceRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetInstance(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
BareMetalSolutionMetadata::AsyncUpdateInstance(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::baremetalsolution::v2::UpdateInstanceRequest const&
        request) {
  SetMetadata(*context, *options,
              absl::StrCat("instance.name=",
                           internal::UrlEncode(request.instance().name())));
  return child_->AsyncUpdateInstance(cq, std::move(context), std::move(options),
                                     request);
}

StatusOr<google::longrunning::Operation>
BareMetalSolutionMetadata::UpdateInstance(
    grpc::ClientContext& context, Options options,
    google::cloud::baremetalsolution::v2::UpdateInstanceRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("instance.name=",
                           internal::UrlEncode(request.instance().name())));
  return child_->UpdateInstance(context, options, request);
}

StatusOr<google::cloud::baremetalsolution::v2::Instance>
BareMetalSolutionMetadata::RenameInstance(
    grpc::ClientContext& context, Options const& options,
    google::cloud::baremetalsolution::v2::RenameInstanceRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->RenameInstance(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
BareMetalSolutionMetadata::AsyncResetInstance(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::baremetalsolution::v2::ResetInstanceRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncResetInstance(cq, std::move(context), std::move(options),
                                    request);
}

StatusOr<google::longrunning::Operation>
BareMetalSolutionMetadata::ResetInstance(
    grpc::ClientContext& context, Options options,
    google::cloud::baremetalsolution::v2::ResetInstanceRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->ResetInstance(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
BareMetalSolutionMetadata::AsyncStartInstance(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::baremetalsolution::v2::StartInstanceRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncStartInstance(cq, std::move(context), std::move(options),
                                    request);
}

StatusOr<google::longrunning::Operation>
BareMetalSolutionMetadata::StartInstance(
    grpc::ClientContext& context, Options options,
    google::cloud::baremetalsolution::v2::StartInstanceRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->StartInstance(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
BareMetalSolutionMetadata::AsyncStopInstance(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::baremetalsolution::v2::StopInstanceRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncStopInstance(cq, std::move(context), std::move(options),
                                   request);
}

StatusOr<google::longrunning::Operation>
BareMetalSolutionMetadata::StopInstance(
    grpc::ClientContext& context, Options options,
    google::cloud::baremetalsolution::v2::StopInstanceRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->StopInstance(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
BareMetalSolutionMetadata::AsyncEnableInteractiveSerialConsole(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::baremetalsolution::v2::
        EnableInteractiveSerialConsoleRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncEnableInteractiveSerialConsole(
      cq, std::move(context), std::move(options), request);
}

StatusOr<google::longrunning::Operation>
BareMetalSolutionMetadata::EnableInteractiveSerialConsole(
    grpc::ClientContext& context, Options options,
    google::cloud::baremetalsolution::v2::
        EnableInteractiveSerialConsoleRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->EnableInteractiveSerialConsole(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
BareMetalSolutionMetadata::AsyncDisableInteractiveSerialConsole(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::baremetalsolution::v2::
        DisableInteractiveSerialConsoleRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncDisableInteractiveSerialConsole(
      cq, std::move(context), std::move(options), request);
}

StatusOr<google::longrunning::Operation>
BareMetalSolutionMetadata::DisableInteractiveSerialConsole(
    grpc::ClientContext& context, Options options,
    google::cloud::baremetalsolution::v2::
        DisableInteractiveSerialConsoleRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->DisableInteractiveSerialConsole(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
BareMetalSolutionMetadata::AsyncDetachLun(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::baremetalsolution::v2::DetachLunRequest const& request) {
  SetMetadata(
      *context, *options,
      absl::StrCat("instance=", internal::UrlEncode(request.instance())));
  return child_->AsyncDetachLun(cq, std::move(context), std::move(options),
                                request);
}

StatusOr<google::longrunning::Operation> BareMetalSolutionMetadata::DetachLun(
    grpc::ClientContext& context, Options options,
    google::cloud::baremetalsolution::v2::DetachLunRequest const& request) {
  SetMetadata(
      context, options,
      absl::StrCat("instance=", internal::UrlEncode(request.instance())));
  return child_->DetachLun(context, options, request);
}

StatusOr<google::cloud::baremetalsolution::v2::ListSSHKeysResponse>
BareMetalSolutionMetadata::ListSSHKeys(
    grpc::ClientContext& context, Options const& options,
    google::cloud::baremetalsolution::v2::ListSSHKeysRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListSSHKeys(context, options, request);
}

StatusOr<google::cloud::baremetalsolution::v2::SSHKey>
BareMetalSolutionMetadata::CreateSSHKey(
    grpc::ClientContext& context, Options const& options,
    google::cloud::baremetalsolution::v2::CreateSSHKeyRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->CreateSSHKey(context, options, request);
}

Status BareMetalSolutionMetadata::DeleteSSHKey(
    grpc::ClientContext& context, Options const& options,
    google::cloud::baremetalsolution::v2::DeleteSSHKeyRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->DeleteSSHKey(context, options, request);
}

StatusOr<google::cloud::baremetalsolution::v2::ListVolumesResponse>
BareMetalSolutionMetadata::ListVolumes(
    grpc::ClientContext& context, Options const& options,
    google::cloud::baremetalsolution::v2::ListVolumesRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListVolumes(context, options, request);
}

StatusOr<google::cloud::baremetalsolution::v2::Volume>
BareMetalSolutionMetadata::GetVolume(
    grpc::ClientContext& context, Options const& options,
    google::cloud::baremetalsolution::v2::GetVolumeRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetVolume(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
BareMetalSolutionMetadata::AsyncUpdateVolume(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::baremetalsolution::v2::UpdateVolumeRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("volume.name=",
                           internal::UrlEncode(request.volume().name())));
  return child_->AsyncUpdateVolume(cq, std::move(context), std::move(options),
                                   request);
}

StatusOr<google::longrunning::Operation>
BareMetalSolutionMetadata::UpdateVolume(
    grpc::ClientContext& context, Options options,
    google::cloud::baremetalsolution::v2::UpdateVolumeRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("volume.name=",
                           internal::UrlEncode(request.volume().name())));
  return child_->UpdateVolume(context, options, request);
}

StatusOr<google::cloud::baremetalsolution::v2::Volume>
BareMetalSolutionMetadata::RenameVolume(
    grpc::ClientContext& context, Options const& options,
    google::cloud::baremetalsolution::v2::RenameVolumeRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->RenameVolume(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
BareMetalSolutionMetadata::AsyncEvictVolume(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::baremetalsolution::v2::EvictVolumeRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncEvictVolume(cq, std::move(context), std::move(options),
                                  request);
}

StatusOr<google::longrunning::Operation> BareMetalSolutionMetadata::EvictVolume(
    grpc::ClientContext& context, Options options,
    google::cloud::baremetalsolution::v2::EvictVolumeRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->EvictVolume(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
BareMetalSolutionMetadata::AsyncResizeVolume(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::baremetalsolution::v2::ResizeVolumeRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("volume=", internal::UrlEncode(request.volume())));
  return child_->AsyncResizeVolume(cq, std::move(context), std::move(options),
                                   request);
}

StatusOr<google::longrunning::Operation>
BareMetalSolutionMetadata::ResizeVolume(
    grpc::ClientContext& context, Options options,
    google::cloud::baremetalsolution::v2::ResizeVolumeRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("volume=", internal::UrlEncode(request.volume())));
  return child_->ResizeVolume(context, options, request);
}

StatusOr<google::cloud::baremetalsolution::v2::ListNetworksResponse>
BareMetalSolutionMetadata::ListNetworks(
    grpc::ClientContext& context, Options const& options,
    google::cloud::baremetalsolution::v2::ListNetworksRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListNetworks(context, options, request);
}

StatusOr<google::cloud::baremetalsolution::v2::ListNetworkUsageResponse>
BareMetalSolutionMetadata::ListNetworkUsage(
    grpc::ClientContext& context, Options const& options,
    google::cloud::baremetalsolution::v2::ListNetworkUsageRequest const&
        request) {
  SetMetadata(
      context, options,
      absl::StrCat("location=", internal::UrlEncode(request.location())));
  return child_->ListNetworkUsage(context, options, request);
}

StatusOr<google::cloud::baremetalsolution::v2::Network>
BareMetalSolutionMetadata::GetNetwork(
    grpc::ClientContext& context, Options const& options,
    google::cloud::baremetalsolution::v2::GetNetworkRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetNetwork(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
BareMetalSolutionMetadata::AsyncUpdateNetwork(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::baremetalsolution::v2::UpdateNetworkRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("network.name=",
                           internal::UrlEncode(request.network().name())));
  return child_->AsyncUpdateNetwork(cq, std::move(context), std::move(options),
                                    request);
}

StatusOr<google::longrunning::Operation>
BareMetalSolutionMetadata::UpdateNetwork(
    grpc::ClientContext& context, Options options,
    google::cloud::baremetalsolution::v2::UpdateNetworkRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("network.name=",
                           internal::UrlEncode(request.network().name())));
  return child_->UpdateNetwork(context, options, request);
}

StatusOr<google::cloud::baremetalsolution::v2::VolumeSnapshot>
BareMetalSolutionMetadata::CreateVolumeSnapshot(
    grpc::ClientContext& context, Options const& options,
    google::cloud::baremetalsolution::v2::CreateVolumeSnapshotRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->CreateVolumeSnapshot(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
BareMetalSolutionMetadata::AsyncRestoreVolumeSnapshot(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::baremetalsolution::v2::RestoreVolumeSnapshotRequest const&
        request) {
  SetMetadata(*context, *options,
              absl::StrCat("volume_snapshot=",
                           internal::UrlEncode(request.volume_snapshot())));
  return child_->AsyncRestoreVolumeSnapshot(cq, std::move(context),
                                            std::move(options), request);
}

StatusOr<google::longrunning::Operation>
BareMetalSolutionMetadata::RestoreVolumeSnapshot(
    grpc::ClientContext& context, Options options,
    google::cloud::baremetalsolution::v2::RestoreVolumeSnapshotRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("volume_snapshot=",
                           internal::UrlEncode(request.volume_snapshot())));
  return child_->RestoreVolumeSnapshot(context, options, request);
}

Status BareMetalSolutionMetadata::DeleteVolumeSnapshot(
    grpc::ClientContext& context, Options const& options,
    google::cloud::baremetalsolution::v2::DeleteVolumeSnapshotRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->DeleteVolumeSnapshot(context, options, request);
}

StatusOr<google::cloud::baremetalsolution::v2::VolumeSnapshot>
BareMetalSolutionMetadata::GetVolumeSnapshot(
    grpc::ClientContext& context, Options const& options,
    google::cloud::baremetalsolution::v2::GetVolumeSnapshotRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetVolumeSnapshot(context, options, request);
}

StatusOr<google::cloud::baremetalsolution::v2::ListVolumeSnapshotsResponse>
BareMetalSolutionMetadata::ListVolumeSnapshots(
    grpc::ClientContext& context, Options const& options,
    google::cloud::baremetalsolution::v2::ListVolumeSnapshotsRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListVolumeSnapshots(context, options, request);
}

StatusOr<google::cloud::baremetalsolution::v2::Lun>
BareMetalSolutionMetadata::GetLun(
    grpc::ClientContext& context, Options const& options,
    google::cloud::baremetalsolution::v2::GetLunRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetLun(context, options, request);
}

StatusOr<google::cloud::baremetalsolution::v2::ListLunsResponse>
BareMetalSolutionMetadata::ListLuns(
    grpc::ClientContext& context, Options const& options,
    google::cloud::baremetalsolution::v2::ListLunsRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListLuns(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
BareMetalSolutionMetadata::AsyncEvictLun(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::baremetalsolution::v2::EvictLunRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncEvictLun(cq, std::move(context), std::move(options),
                               request);
}

StatusOr<google::longrunning::Operation> BareMetalSolutionMetadata::EvictLun(
    grpc::ClientContext& context, Options options,
    google::cloud::baremetalsolution::v2::EvictLunRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->EvictLun(context, options, request);
}

StatusOr<google::cloud::baremetalsolution::v2::NfsShare>
BareMetalSolutionMetadata::GetNfsShare(
    grpc::ClientContext& context, Options const& options,
    google::cloud::baremetalsolution::v2::GetNfsShareRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetNfsShare(context, options, request);
}

StatusOr<google::cloud::baremetalsolution::v2::ListNfsSharesResponse>
BareMetalSolutionMetadata::ListNfsShares(
    grpc::ClientContext& context, Options const& options,
    google::cloud::baremetalsolution::v2::ListNfsSharesRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListNfsShares(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
BareMetalSolutionMetadata::AsyncUpdateNfsShare(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::baremetalsolution::v2::UpdateNfsShareRequest const&
        request) {
  SetMetadata(*context, *options,
              absl::StrCat("nfs_share.name=",
                           internal::UrlEncode(request.nfs_share().name())));
  return child_->AsyncUpdateNfsShare(cq, std::move(context), std::move(options),
                                     request);
}

StatusOr<google::longrunning::Operation>
BareMetalSolutionMetadata::UpdateNfsShare(
    grpc::ClientContext& context, Options options,
    google::cloud::baremetalsolution::v2::UpdateNfsShareRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("nfs_share.name=",
                           internal::UrlEncode(request.nfs_share().name())));
  return child_->UpdateNfsShare(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
BareMetalSolutionMetadata::AsyncCreateNfsShare(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::baremetalsolution::v2::CreateNfsShareRequest const&
        request) {
  SetMetadata(*context, *options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->AsyncCreateNfsShare(cq, std::move(context), std::move(options),
                                     request);
}

StatusOr<google::longrunning::Operation>
BareMetalSolutionMetadata::CreateNfsShare(
    grpc::ClientContext& context, Options options,
    google::cloud::baremetalsolution::v2::CreateNfsShareRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->CreateNfsShare(context, options, request);
}

StatusOr<google::cloud::baremetalsolution::v2::NfsShare>
BareMetalSolutionMetadata::RenameNfsShare(
    grpc::ClientContext& context, Options const& options,
    google::cloud::baremetalsolution::v2::RenameNfsShareRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->RenameNfsShare(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
BareMetalSolutionMetadata::AsyncDeleteNfsShare(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::baremetalsolution::v2::DeleteNfsShareRequest const&
        request) {
  SetMetadata(*context, *options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncDeleteNfsShare(cq, std::move(context), std::move(options),
                                     request);
}

StatusOr<google::longrunning::Operation>
BareMetalSolutionMetadata::DeleteNfsShare(
    grpc::ClientContext& context, Options options,
    google::cloud::baremetalsolution::v2::DeleteNfsShareRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->DeleteNfsShare(context, options, request);
}

StatusOr<google::cloud::baremetalsolution::v2::ListProvisioningQuotasResponse>
BareMetalSolutionMetadata::ListProvisioningQuotas(
    grpc::ClientContext& context, Options const& options,
    google::cloud::baremetalsolution::v2::ListProvisioningQuotasRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListProvisioningQuotas(context, options, request);
}

StatusOr<google::cloud::baremetalsolution::v2::SubmitProvisioningConfigResponse>
BareMetalSolutionMetadata::SubmitProvisioningConfig(
    grpc::ClientContext& context, Options const& options,
    google::cloud::baremetalsolution::v2::SubmitProvisioningConfigRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->SubmitProvisioningConfig(context, options, request);
}

StatusOr<google::cloud::baremetalsolution::v2::ProvisioningConfig>
BareMetalSolutionMetadata::GetProvisioningConfig(
    grpc::ClientContext& context, Options const& options,
    google::cloud::baremetalsolution::v2::GetProvisioningConfigRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetProvisioningConfig(context, options, request);
}

StatusOr<google::cloud::baremetalsolution::v2::ProvisioningConfig>
BareMetalSolutionMetadata::CreateProvisioningConfig(
    grpc::ClientContext& context, Options const& options,
    google::cloud::baremetalsolution::v2::CreateProvisioningConfigRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->CreateProvisioningConfig(context, options, request);
}

StatusOr<google::cloud::baremetalsolution::v2::ProvisioningConfig>
BareMetalSolutionMetadata::UpdateProvisioningConfig(
    grpc::ClientContext& context, Options const& options,
    google::cloud::baremetalsolution::v2::UpdateProvisioningConfigRequest const&
        request) {
  SetMetadata(
      context, options,
      absl::StrCat("provisioning_config.name=",
                   internal::UrlEncode(request.provisioning_config().name())));
  return child_->UpdateProvisioningConfig(context, options, request);
}

StatusOr<google::cloud::baremetalsolution::v2::Network>
BareMetalSolutionMetadata::RenameNetwork(
    grpc::ClientContext& context, Options const& options,
    google::cloud::baremetalsolution::v2::RenameNetworkRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->RenameNetwork(context, options, request);
}

StatusOr<google::cloud::baremetalsolution::v2::ListOSImagesResponse>
BareMetalSolutionMetadata::ListOSImages(
    grpc::ClientContext& context, Options const& options,
    google::cloud::baremetalsolution::v2::ListOSImagesRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListOSImages(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
BareMetalSolutionMetadata::AsyncGetOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::longrunning::GetOperationRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncGetOperation(cq, std::move(context), std::move(options),
                                   request);
}

future<Status> BareMetalSolutionMetadata::AsyncCancelOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::longrunning::CancelOperationRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncCancelOperation(cq, std::move(context),
                                      std::move(options), request);
}

void BareMetalSolutionMetadata::SetMetadata(grpc::ClientContext& context,
                                            Options const& options,
                                            std::string const& request_params) {
  context.AddMetadata("x-goog-request-params", request_params);
  SetMetadata(context, options);
}

void BareMetalSolutionMetadata::SetMetadata(grpc::ClientContext& context,
                                            Options const& options) {
  google::cloud::internal::SetMetadata(context, options, fixed_metadata_,
                                       api_client_header_);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace baremetalsolution_v2_internal
}  // namespace cloud
}  // namespace google
