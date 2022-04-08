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
// source: google/cloud/dialogflow/v2/fulfillment.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_ES_INTERNAL_FULFILLMENTS_STUB_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_ES_INTERNAL_FULFILLMENTS_STUB_H

#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <google/cloud/dialogflow/v2/fulfillment.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace dialogflow_es_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class FulfillmentsStub {
 public:
  virtual ~FulfillmentsStub() = 0;

  virtual StatusOr<google::cloud::dialogflow::v2::Fulfillment> GetFulfillment(
      grpc::ClientContext& context,
      google::cloud::dialogflow::v2::GetFulfillmentRequest const& request) = 0;

  virtual StatusOr<google::cloud::dialogflow::v2::Fulfillment>
  UpdateFulfillment(
      grpc::ClientContext& context,
      google::cloud::dialogflow::v2::UpdateFulfillmentRequest const&
          request) = 0;
};

class DefaultFulfillmentsStub : public FulfillmentsStub {
 public:
  explicit DefaultFulfillmentsStub(
      std::unique_ptr<
          google::cloud::dialogflow::v2::Fulfillments::StubInterface>
          grpc_stub)
      : grpc_stub_(std::move(grpc_stub)) {}

  StatusOr<google::cloud::dialogflow::v2::Fulfillment> GetFulfillment(
      grpc::ClientContext& client_context,
      google::cloud::dialogflow::v2::GetFulfillmentRequest const& request)
      override;

  StatusOr<google::cloud::dialogflow::v2::Fulfillment> UpdateFulfillment(
      grpc::ClientContext& client_context,
      google::cloud::dialogflow::v2::UpdateFulfillmentRequest const& request)
      override;

 private:
  std::unique_ptr<google::cloud::dialogflow::v2::Fulfillments::StubInterface>
      grpc_stub_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_es_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_ES_INTERNAL_FULFILLMENTS_STUB_H
