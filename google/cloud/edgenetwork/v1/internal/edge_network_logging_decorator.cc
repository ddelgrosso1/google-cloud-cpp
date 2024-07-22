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
// source: google/cloud/edgenetwork/v1/service.proto

#include "google/cloud/edgenetwork/v1/internal/edge_network_logging_decorator.h"
#include "google/cloud/internal/log_wrapper.h"
#include "google/cloud/status_or.h"
#include <google/cloud/edgenetwork/v1/service.grpc.pb.h>
#include <memory>
#include <string>
#include <utility>

namespace google {
namespace cloud {
namespace edgenetwork_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

EdgeNetworkLogging::EdgeNetworkLogging(std::shared_ptr<EdgeNetworkStub> child,
                                       TracingOptions tracing_options,
                                       std::set<std::string> const&)
    : child_(std::move(child)), tracing_options_(std::move(tracing_options)) {}

StatusOr<google::cloud::edgenetwork::v1::InitializeZoneResponse>
EdgeNetworkLogging::InitializeZone(
    grpc::ClientContext& context, Options const& options,
    google::cloud::edgenetwork::v1::InitializeZoneRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::edgenetwork::v1::InitializeZoneRequest const&
                 request) {
        return child_->InitializeZone(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::edgenetwork::v1::ListZonesResponse>
EdgeNetworkLogging::ListZones(
    grpc::ClientContext& context, Options const& options,
    google::cloud::edgenetwork::v1::ListZonesRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::edgenetwork::v1::ListZonesRequest const& request) {
        return child_->ListZones(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::edgenetwork::v1::Zone> EdgeNetworkLogging::GetZone(
    grpc::ClientContext& context, Options const& options,
    google::cloud::edgenetwork::v1::GetZoneRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::edgenetwork::v1::GetZoneRequest const& request) {
        return child_->GetZone(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::edgenetwork::v1::ListNetworksResponse>
EdgeNetworkLogging::ListNetworks(
    grpc::ClientContext& context, Options const& options,
    google::cloud::edgenetwork::v1::ListNetworksRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context, Options const& options,
          google::cloud::edgenetwork::v1::ListNetworksRequest const& request) {
        return child_->ListNetworks(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::edgenetwork::v1::Network>
EdgeNetworkLogging::GetNetwork(
    grpc::ClientContext& context, Options const& options,
    google::cloud::edgenetwork::v1::GetNetworkRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::edgenetwork::v1::GetNetworkRequest const& request) {
        return child_->GetNetwork(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::edgenetwork::v1::DiagnoseNetworkResponse>
EdgeNetworkLogging::DiagnoseNetwork(
    grpc::ClientContext& context, Options const& options,
    google::cloud::edgenetwork::v1::DiagnoseNetworkRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::edgenetwork::v1::DiagnoseNetworkRequest const&
                 request) {
        return child_->DiagnoseNetwork(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
EdgeNetworkLogging::AsyncCreateNetwork(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::edgenetwork::v1::CreateNetworkRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          google::cloud::CompletionQueue& cq,
          std::shared_ptr<grpc::ClientContext> context,
          google::cloud::internal::ImmutableOptions options,
          google::cloud::edgenetwork::v1::CreateNetworkRequest const& request) {
        return child_->AsyncCreateNetwork(cq, std::move(context),
                                          std::move(options), request);
      },
      cq, std::move(context), std::move(options), request, __func__,
      tracing_options_);
}

StatusOr<google::longrunning::Operation> EdgeNetworkLogging::CreateNetwork(
    grpc::ClientContext& context, Options options,
    google::cloud::edgenetwork::v1::CreateNetworkRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context, Options const& options,
          google::cloud::edgenetwork::v1::CreateNetworkRequest const& request) {
        return child_->CreateNetwork(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
EdgeNetworkLogging::AsyncDeleteNetwork(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::edgenetwork::v1::DeleteNetworkRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          google::cloud::CompletionQueue& cq,
          std::shared_ptr<grpc::ClientContext> context,
          google::cloud::internal::ImmutableOptions options,
          google::cloud::edgenetwork::v1::DeleteNetworkRequest const& request) {
        return child_->AsyncDeleteNetwork(cq, std::move(context),
                                          std::move(options), request);
      },
      cq, std::move(context), std::move(options), request, __func__,
      tracing_options_);
}

StatusOr<google::longrunning::Operation> EdgeNetworkLogging::DeleteNetwork(
    grpc::ClientContext& context, Options options,
    google::cloud::edgenetwork::v1::DeleteNetworkRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context, Options const& options,
          google::cloud::edgenetwork::v1::DeleteNetworkRequest const& request) {
        return child_->DeleteNetwork(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::edgenetwork::v1::ListSubnetsResponse>
EdgeNetworkLogging::ListSubnets(
    grpc::ClientContext& context, Options const& options,
    google::cloud::edgenetwork::v1::ListSubnetsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context, Options const& options,
          google::cloud::edgenetwork::v1::ListSubnetsRequest const& request) {
        return child_->ListSubnets(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::edgenetwork::v1::Subnet> EdgeNetworkLogging::GetSubnet(
    grpc::ClientContext& context, Options const& options,
    google::cloud::edgenetwork::v1::GetSubnetRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::edgenetwork::v1::GetSubnetRequest const& request) {
        return child_->GetSubnet(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
EdgeNetworkLogging::AsyncCreateSubnet(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::edgenetwork::v1::CreateSubnetRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          google::cloud::CompletionQueue& cq,
          std::shared_ptr<grpc::ClientContext> context,
          google::cloud::internal::ImmutableOptions options,
          google::cloud::edgenetwork::v1::CreateSubnetRequest const& request) {
        return child_->AsyncCreateSubnet(cq, std::move(context),
                                         std::move(options), request);
      },
      cq, std::move(context), std::move(options), request, __func__,
      tracing_options_);
}

StatusOr<google::longrunning::Operation> EdgeNetworkLogging::CreateSubnet(
    grpc::ClientContext& context, Options options,
    google::cloud::edgenetwork::v1::CreateSubnetRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context, Options const& options,
          google::cloud::edgenetwork::v1::CreateSubnetRequest const& request) {
        return child_->CreateSubnet(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
EdgeNetworkLogging::AsyncUpdateSubnet(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::edgenetwork::v1::UpdateSubnetRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          google::cloud::CompletionQueue& cq,
          std::shared_ptr<grpc::ClientContext> context,
          google::cloud::internal::ImmutableOptions options,
          google::cloud::edgenetwork::v1::UpdateSubnetRequest const& request) {
        return child_->AsyncUpdateSubnet(cq, std::move(context),
                                         std::move(options), request);
      },
      cq, std::move(context), std::move(options), request, __func__,
      tracing_options_);
}

StatusOr<google::longrunning::Operation> EdgeNetworkLogging::UpdateSubnet(
    grpc::ClientContext& context, Options options,
    google::cloud::edgenetwork::v1::UpdateSubnetRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context, Options const& options,
          google::cloud::edgenetwork::v1::UpdateSubnetRequest const& request) {
        return child_->UpdateSubnet(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
EdgeNetworkLogging::AsyncDeleteSubnet(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::edgenetwork::v1::DeleteSubnetRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          google::cloud::CompletionQueue& cq,
          std::shared_ptr<grpc::ClientContext> context,
          google::cloud::internal::ImmutableOptions options,
          google::cloud::edgenetwork::v1::DeleteSubnetRequest const& request) {
        return child_->AsyncDeleteSubnet(cq, std::move(context),
                                         std::move(options), request);
      },
      cq, std::move(context), std::move(options), request, __func__,
      tracing_options_);
}

StatusOr<google::longrunning::Operation> EdgeNetworkLogging::DeleteSubnet(
    grpc::ClientContext& context, Options options,
    google::cloud::edgenetwork::v1::DeleteSubnetRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context, Options const& options,
          google::cloud::edgenetwork::v1::DeleteSubnetRequest const& request) {
        return child_->DeleteSubnet(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::edgenetwork::v1::ListInterconnectsResponse>
EdgeNetworkLogging::ListInterconnects(
    grpc::ClientContext& context, Options const& options,
    google::cloud::edgenetwork::v1::ListInterconnectsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::edgenetwork::v1::ListInterconnectsRequest const&
                 request) {
        return child_->ListInterconnects(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::edgenetwork::v1::Interconnect>
EdgeNetworkLogging::GetInterconnect(
    grpc::ClientContext& context, Options const& options,
    google::cloud::edgenetwork::v1::GetInterconnectRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::edgenetwork::v1::GetInterconnectRequest const&
                 request) {
        return child_->GetInterconnect(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::edgenetwork::v1::DiagnoseInterconnectResponse>
EdgeNetworkLogging::DiagnoseInterconnect(
    grpc::ClientContext& context, Options const& options,
    google::cloud::edgenetwork::v1::DiagnoseInterconnectRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::edgenetwork::v1::DiagnoseInterconnectRequest const&
                 request) {
        return child_->DiagnoseInterconnect(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::edgenetwork::v1::ListInterconnectAttachmentsResponse>
EdgeNetworkLogging::ListInterconnectAttachments(
    grpc::ClientContext& context, Options const& options,
    google::cloud::edgenetwork::v1::ListInterconnectAttachmentsRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::edgenetwork::v1::
                 ListInterconnectAttachmentsRequest const& request) {
        return child_->ListInterconnectAttachments(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::edgenetwork::v1::InterconnectAttachment>
EdgeNetworkLogging::GetInterconnectAttachment(
    grpc::ClientContext& context, Options const& options,
    google::cloud::edgenetwork::v1::GetInterconnectAttachmentRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::edgenetwork::v1::
                 GetInterconnectAttachmentRequest const& request) {
        return child_->GetInterconnectAttachment(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
EdgeNetworkLogging::AsyncCreateInterconnectAttachment(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::edgenetwork::v1::CreateInterconnectAttachmentRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::cloud::internal::ImmutableOptions options,
             google::cloud::edgenetwork::v1::
                 CreateInterconnectAttachmentRequest const& request) {
        return child_->AsyncCreateInterconnectAttachment(
            cq, std::move(context), std::move(options), request);
      },
      cq, std::move(context), std::move(options), request, __func__,
      tracing_options_);
}

StatusOr<google::longrunning::Operation>
EdgeNetworkLogging::CreateInterconnectAttachment(
    grpc::ClientContext& context, Options options,
    google::cloud::edgenetwork::v1::CreateInterconnectAttachmentRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::edgenetwork::v1::
                 CreateInterconnectAttachmentRequest const& request) {
        return child_->CreateInterconnectAttachment(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
EdgeNetworkLogging::AsyncDeleteInterconnectAttachment(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::edgenetwork::v1::DeleteInterconnectAttachmentRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::cloud::internal::ImmutableOptions options,
             google::cloud::edgenetwork::v1::
                 DeleteInterconnectAttachmentRequest const& request) {
        return child_->AsyncDeleteInterconnectAttachment(
            cq, std::move(context), std::move(options), request);
      },
      cq, std::move(context), std::move(options), request, __func__,
      tracing_options_);
}

StatusOr<google::longrunning::Operation>
EdgeNetworkLogging::DeleteInterconnectAttachment(
    grpc::ClientContext& context, Options options,
    google::cloud::edgenetwork::v1::DeleteInterconnectAttachmentRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::edgenetwork::v1::
                 DeleteInterconnectAttachmentRequest const& request) {
        return child_->DeleteInterconnectAttachment(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::edgenetwork::v1::ListRoutersResponse>
EdgeNetworkLogging::ListRouters(
    grpc::ClientContext& context, Options const& options,
    google::cloud::edgenetwork::v1::ListRoutersRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context, Options const& options,
          google::cloud::edgenetwork::v1::ListRoutersRequest const& request) {
        return child_->ListRouters(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::edgenetwork::v1::Router> EdgeNetworkLogging::GetRouter(
    grpc::ClientContext& context, Options const& options,
    google::cloud::edgenetwork::v1::GetRouterRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::edgenetwork::v1::GetRouterRequest const& request) {
        return child_->GetRouter(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::edgenetwork::v1::DiagnoseRouterResponse>
EdgeNetworkLogging::DiagnoseRouter(
    grpc::ClientContext& context, Options const& options,
    google::cloud::edgenetwork::v1::DiagnoseRouterRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::edgenetwork::v1::DiagnoseRouterRequest const&
                 request) {
        return child_->DiagnoseRouter(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
EdgeNetworkLogging::AsyncCreateRouter(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::edgenetwork::v1::CreateRouterRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          google::cloud::CompletionQueue& cq,
          std::shared_ptr<grpc::ClientContext> context,
          google::cloud::internal::ImmutableOptions options,
          google::cloud::edgenetwork::v1::CreateRouterRequest const& request) {
        return child_->AsyncCreateRouter(cq, std::move(context),
                                         std::move(options), request);
      },
      cq, std::move(context), std::move(options), request, __func__,
      tracing_options_);
}

StatusOr<google::longrunning::Operation> EdgeNetworkLogging::CreateRouter(
    grpc::ClientContext& context, Options options,
    google::cloud::edgenetwork::v1::CreateRouterRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context, Options const& options,
          google::cloud::edgenetwork::v1::CreateRouterRequest const& request) {
        return child_->CreateRouter(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
EdgeNetworkLogging::AsyncUpdateRouter(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::edgenetwork::v1::UpdateRouterRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          google::cloud::CompletionQueue& cq,
          std::shared_ptr<grpc::ClientContext> context,
          google::cloud::internal::ImmutableOptions options,
          google::cloud::edgenetwork::v1::UpdateRouterRequest const& request) {
        return child_->AsyncUpdateRouter(cq, std::move(context),
                                         std::move(options), request);
      },
      cq, std::move(context), std::move(options), request, __func__,
      tracing_options_);
}

StatusOr<google::longrunning::Operation> EdgeNetworkLogging::UpdateRouter(
    grpc::ClientContext& context, Options options,
    google::cloud::edgenetwork::v1::UpdateRouterRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context, Options const& options,
          google::cloud::edgenetwork::v1::UpdateRouterRequest const& request) {
        return child_->UpdateRouter(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
EdgeNetworkLogging::AsyncDeleteRouter(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::edgenetwork::v1::DeleteRouterRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          google::cloud::CompletionQueue& cq,
          std::shared_ptr<grpc::ClientContext> context,
          google::cloud::internal::ImmutableOptions options,
          google::cloud::edgenetwork::v1::DeleteRouterRequest const& request) {
        return child_->AsyncDeleteRouter(cq, std::move(context),
                                         std::move(options), request);
      },
      cq, std::move(context), std::move(options), request, __func__,
      tracing_options_);
}

StatusOr<google::longrunning::Operation> EdgeNetworkLogging::DeleteRouter(
    grpc::ClientContext& context, Options options,
    google::cloud::edgenetwork::v1::DeleteRouterRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context, Options const& options,
          google::cloud::edgenetwork::v1::DeleteRouterRequest const& request) {
        return child_->DeleteRouter(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
EdgeNetworkLogging::AsyncGetOperation(
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

future<Status> EdgeNetworkLogging::AsyncCancelOperation(
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
}  // namespace edgenetwork_v1_internal
}  // namespace cloud
}  // namespace google
