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
// source: google/cloud/dataplex/v1/metadata.proto

#include "google/cloud/dataplex/v1/internal/metadata_logging_decorator.h"
#include "google/cloud/internal/log_wrapper.h"
#include "google/cloud/status_or.h"
#include <google/cloud/dataplex/v1/metadata.grpc.pb.h>
#include <memory>
#include <string>
#include <utility>

namespace google {
namespace cloud {
namespace dataplex_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

MetadataServiceLogging::MetadataServiceLogging(
    std::shared_ptr<MetadataServiceStub> child, TracingOptions tracing_options,
    std::set<std::string> const&)
    : child_(std::move(child)), tracing_options_(std::move(tracing_options)) {}

StatusOr<google::cloud::dataplex::v1::Entity>
MetadataServiceLogging::CreateEntity(
    grpc::ClientContext& context, Options const& options,
    google::cloud::dataplex::v1::CreateEntityRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::dataplex::v1::CreateEntityRequest const& request) {
        return child_->CreateEntity(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::dataplex::v1::Entity>
MetadataServiceLogging::UpdateEntity(
    grpc::ClientContext& context, Options const& options,
    google::cloud::dataplex::v1::UpdateEntityRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::dataplex::v1::UpdateEntityRequest const& request) {
        return child_->UpdateEntity(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

Status MetadataServiceLogging::DeleteEntity(
    grpc::ClientContext& context, Options const& options,
    google::cloud::dataplex::v1::DeleteEntityRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::dataplex::v1::DeleteEntityRequest const& request) {
        return child_->DeleteEntity(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::dataplex::v1::Entity> MetadataServiceLogging::GetEntity(
    grpc::ClientContext& context, Options const& options,
    google::cloud::dataplex::v1::GetEntityRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::dataplex::v1::GetEntityRequest const& request) {
        return child_->GetEntity(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::dataplex::v1::ListEntitiesResponse>
MetadataServiceLogging::ListEntities(
    grpc::ClientContext& context, Options const& options,
    google::cloud::dataplex::v1::ListEntitiesRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::dataplex::v1::ListEntitiesRequest const& request) {
        return child_->ListEntities(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::dataplex::v1::Partition>
MetadataServiceLogging::CreatePartition(
    grpc::ClientContext& context, Options const& options,
    google::cloud::dataplex::v1::CreatePartitionRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context, Options const& options,
          google::cloud::dataplex::v1::CreatePartitionRequest const& request) {
        return child_->CreatePartition(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

Status MetadataServiceLogging::DeletePartition(
    grpc::ClientContext& context, Options const& options,
    google::cloud::dataplex::v1::DeletePartitionRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context, Options const& options,
          google::cloud::dataplex::v1::DeletePartitionRequest const& request) {
        return child_->DeletePartition(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::dataplex::v1::Partition>
MetadataServiceLogging::GetPartition(
    grpc::ClientContext& context, Options const& options,
    google::cloud::dataplex::v1::GetPartitionRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::dataplex::v1::GetPartitionRequest const& request) {
        return child_->GetPartition(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::dataplex::v1::ListPartitionsResponse>
MetadataServiceLogging::ListPartitions(
    grpc::ClientContext& context, Options const& options,
    google::cloud::dataplex::v1::ListPartitionsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context, Options const& options,
          google::cloud::dataplex::v1::ListPartitionsRequest const& request) {
        return child_->ListPartitions(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dataplex_v1_internal
}  // namespace cloud
}  // namespace google
