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

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_ES_MOCKS_MOCK_FULFILLMENTS_CONNECTION_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_ES_MOCKS_MOCK_FULFILLMENTS_CONNECTION_H

#include "google/cloud/dialogflow_es/fulfillments_connection.h"
#include <gmock/gmock.h>

namespace google {
namespace cloud {
namespace dialogflow_es_mocks {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class MockFulfillmentsConnection
    : public dialogflow_es::FulfillmentsConnection {
 public:
  MOCK_METHOD(Options, options, (), (override));

  MOCK_METHOD(
      StatusOr<google::cloud::dialogflow::v2::Fulfillment>, GetFulfillment,
      (google::cloud::dialogflow::v2::GetFulfillmentRequest const& request),
      (override));

  MOCK_METHOD(
      StatusOr<google::cloud::dialogflow::v2::Fulfillment>, UpdateFulfillment,
      (google::cloud::dialogflow::v2::UpdateFulfillmentRequest const& request),
      (override));
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_es_mocks
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_ES_MOCKS_MOCK_FULFILLMENTS_CONNECTION_H
