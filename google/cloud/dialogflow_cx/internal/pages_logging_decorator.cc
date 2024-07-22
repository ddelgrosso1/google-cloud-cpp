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
// source: google/cloud/dialogflow/cx/v3/page.proto

#include "google/cloud/dialogflow_cx/internal/pages_logging_decorator.h"
#include "google/cloud/internal/log_wrapper.h"
#include "google/cloud/status_or.h"
#include <google/cloud/dialogflow/cx/v3/page.grpc.pb.h>
#include <memory>
#include <string>
#include <utility>

namespace google {
namespace cloud {
namespace dialogflow_cx_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

PagesLogging::PagesLogging(std::shared_ptr<PagesStub> child,
                           TracingOptions tracing_options,
                           std::set<std::string> const&)
    : child_(std::move(child)), tracing_options_(std::move(tracing_options)) {}

StatusOr<google::cloud::dialogflow::cx::v3::ListPagesResponse>
PagesLogging::ListPages(
    grpc::ClientContext& context, Options const& options,
    google::cloud::dialogflow::cx::v3::ListPagesRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context, Options const& options,
          google::cloud::dialogflow::cx::v3::ListPagesRequest const& request) {
        return child_->ListPages(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::dialogflow::cx::v3::Page> PagesLogging::GetPage(
    grpc::ClientContext& context, Options const& options,
    google::cloud::dialogflow::cx::v3::GetPageRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::dialogflow::cx::v3::GetPageRequest const& request) {
        return child_->GetPage(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::dialogflow::cx::v3::Page> PagesLogging::CreatePage(
    grpc::ClientContext& context, Options const& options,
    google::cloud::dialogflow::cx::v3::CreatePageRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context, Options const& options,
          google::cloud::dialogflow::cx::v3::CreatePageRequest const& request) {
        return child_->CreatePage(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::dialogflow::cx::v3::Page> PagesLogging::UpdatePage(
    grpc::ClientContext& context, Options const& options,
    google::cloud::dialogflow::cx::v3::UpdatePageRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context, Options const& options,
          google::cloud::dialogflow::cx::v3::UpdatePageRequest const& request) {
        return child_->UpdatePage(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

Status PagesLogging::DeletePage(
    grpc::ClientContext& context, Options const& options,
    google::cloud::dialogflow::cx::v3::DeletePageRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context, Options const& options,
          google::cloud::dialogflow::cx::v3::DeletePageRequest const& request) {
        return child_->DeletePage(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_cx_internal
}  // namespace cloud
}  // namespace google
