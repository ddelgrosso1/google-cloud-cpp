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
// source: google/cloud/dialogflow/v2/session.proto

#include "google/cloud/dialogflow_es/internal/sessions_logging_decorator.h"
#include "google/cloud/internal/async_read_write_stream_logging.h"
#include "google/cloud/internal/log_wrapper.h"
#include "google/cloud/status_or.h"
#include <google/cloud/dialogflow/v2/session.grpc.pb.h>
#include <memory>
#include <string>
#include <utility>

namespace google {
namespace cloud {
namespace dialogflow_es_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

SessionsLogging::SessionsLogging(std::shared_ptr<SessionsStub> child,
                                 TracingOptions tracing_options,
                                 std::set<std::string> const& components)
    : child_(std::move(child)),
      tracing_options_(std::move(tracing_options)),
      stream_logging_(components.find("rpc-streams") != components.end()) {}

StatusOr<google::cloud::dialogflow::v2::DetectIntentResponse>
SessionsLogging::DetectIntent(
    grpc::ClientContext& context, Options const& options,
    google::cloud::dialogflow::v2::DetectIntentRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context, Options const& options,
          google::cloud::dialogflow::v2::DetectIntentRequest const& request) {
        return child_->DetectIntent(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

std::unique_ptr<::google::cloud::AsyncStreamingReadWriteRpc<
    google::cloud::dialogflow::v2::StreamingDetectIntentRequest,
    google::cloud::dialogflow::v2::StreamingDetectIntentResponse>>
SessionsLogging::AsyncStreamingDetectIntent(
    google::cloud::CompletionQueue const& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options) {
  using LoggingStream =
      ::google::cloud::internal::AsyncStreamingReadWriteRpcLogging<
          google::cloud::dialogflow::v2::StreamingDetectIntentRequest,
          google::cloud::dialogflow::v2::StreamingDetectIntentResponse>;

  auto request_id = google::cloud::internal::RequestIdForLogging();
  GCP_LOG(DEBUG) << __func__ << "(" << request_id << ")";
  auto stream = child_->AsyncStreamingDetectIntent(cq, std::move(context),
                                                   std::move(options));
  if (stream_logging_) {
    stream = std::make_unique<LoggingStream>(
        std::move(stream), tracing_options_, std::move(request_id));
  }
  return stream;
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_es_internal
}  // namespace cloud
}  // namespace google
