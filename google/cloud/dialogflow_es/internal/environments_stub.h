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
// source: google/cloud/dialogflow/v2/environment.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_ES_INTERNAL_ENVIRONMENTS_STUB_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_ES_INTERNAL_ENVIRONMENTS_STUB_H

#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <google/cloud/dialogflow/v2/environment.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace dialogflow_es_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class EnvironmentsStub {
 public:
  virtual ~EnvironmentsStub() = 0;

  virtual StatusOr<google::cloud::dialogflow::v2::ListEnvironmentsResponse>
  ListEnvironments(grpc::ClientContext& context,
                   google::cloud::dialogflow::v2::ListEnvironmentsRequest const&
                       request) = 0;

  virtual StatusOr<google::cloud::dialogflow::v2::Environment> GetEnvironment(
      grpc::ClientContext& context,
      google::cloud::dialogflow::v2::GetEnvironmentRequest const& request) = 0;

  virtual StatusOr<google::cloud::dialogflow::v2::Environment>
  CreateEnvironment(
      grpc::ClientContext& context,
      google::cloud::dialogflow::v2::CreateEnvironmentRequest const&
          request) = 0;

  virtual StatusOr<google::cloud::dialogflow::v2::Environment>
  UpdateEnvironment(
      grpc::ClientContext& context,
      google::cloud::dialogflow::v2::UpdateEnvironmentRequest const&
          request) = 0;

  virtual Status DeleteEnvironment(
      grpc::ClientContext& context,
      google::cloud::dialogflow::v2::DeleteEnvironmentRequest const&
          request) = 0;

  virtual StatusOr<google::cloud::dialogflow::v2::EnvironmentHistory>
  GetEnvironmentHistory(
      grpc::ClientContext& context,
      google::cloud::dialogflow::v2::GetEnvironmentHistoryRequest const&
          request) = 0;
};

class DefaultEnvironmentsStub : public EnvironmentsStub {
 public:
  explicit DefaultEnvironmentsStub(
      std::unique_ptr<
          google::cloud::dialogflow::v2::Environments::StubInterface>
          grpc_stub)
      : grpc_stub_(std::move(grpc_stub)) {}

  StatusOr<google::cloud::dialogflow::v2::ListEnvironmentsResponse>
  ListEnvironments(grpc::ClientContext& client_context,
                   google::cloud::dialogflow::v2::ListEnvironmentsRequest const&
                       request) override;

  StatusOr<google::cloud::dialogflow::v2::Environment> GetEnvironment(
      grpc::ClientContext& client_context,
      google::cloud::dialogflow::v2::GetEnvironmentRequest const& request)
      override;

  StatusOr<google::cloud::dialogflow::v2::Environment> CreateEnvironment(
      grpc::ClientContext& client_context,
      google::cloud::dialogflow::v2::CreateEnvironmentRequest const& request)
      override;

  StatusOr<google::cloud::dialogflow::v2::Environment> UpdateEnvironment(
      grpc::ClientContext& client_context,
      google::cloud::dialogflow::v2::UpdateEnvironmentRequest const& request)
      override;

  Status DeleteEnvironment(
      grpc::ClientContext& client_context,
      google::cloud::dialogflow::v2::DeleteEnvironmentRequest const& request)
      override;

  StatusOr<google::cloud::dialogflow::v2::EnvironmentHistory>
  GetEnvironmentHistory(
      grpc::ClientContext& client_context,
      google::cloud::dialogflow::v2::GetEnvironmentHistoryRequest const&
          request) override;

 private:
  std::unique_ptr<google::cloud::dialogflow::v2::Environments::StubInterface>
      grpc_stub_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_es_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_ES_INTERNAL_ENVIRONMENTS_STUB_H
