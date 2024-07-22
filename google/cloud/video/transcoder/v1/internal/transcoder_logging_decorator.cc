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
// source: google/cloud/video/transcoder/v1/services.proto

#include "google/cloud/video/transcoder/v1/internal/transcoder_logging_decorator.h"
#include "google/cloud/internal/log_wrapper.h"
#include "google/cloud/status_or.h"
#include <google/cloud/video/transcoder/v1/services.grpc.pb.h>
#include <memory>
#include <string>
#include <utility>

namespace google {
namespace cloud {
namespace video_transcoder_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

TranscoderServiceLogging::TranscoderServiceLogging(
    std::shared_ptr<TranscoderServiceStub> child,
    TracingOptions tracing_options, std::set<std::string> const&)
    : child_(std::move(child)), tracing_options_(std::move(tracing_options)) {}

StatusOr<google::cloud::video::transcoder::v1::Job>
TranscoderServiceLogging::CreateJob(
    grpc::ClientContext& context, Options const& options,
    google::cloud::video::transcoder::v1::CreateJobRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::video::transcoder::v1::CreateJobRequest const&
                 request) {
        return child_->CreateJob(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::video::transcoder::v1::ListJobsResponse>
TranscoderServiceLogging::ListJobs(
    grpc::ClientContext& context, Options const& options,
    google::cloud::video::transcoder::v1::ListJobsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::video::transcoder::v1::ListJobsRequest const&
                 request) {
        return child_->ListJobs(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::video::transcoder::v1::Job>
TranscoderServiceLogging::GetJob(
    grpc::ClientContext& context, Options const& options,
    google::cloud::video::transcoder::v1::GetJobRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context, Options const& options,
          google::cloud::video::transcoder::v1::GetJobRequest const& request) {
        return child_->GetJob(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

Status TranscoderServiceLogging::DeleteJob(
    grpc::ClientContext& context, Options const& options,
    google::cloud::video::transcoder::v1::DeleteJobRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::video::transcoder::v1::DeleteJobRequest const&
                 request) {
        return child_->DeleteJob(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::video::transcoder::v1::JobTemplate>
TranscoderServiceLogging::CreateJobTemplate(
    grpc::ClientContext& context, Options const& options,
    google::cloud::video::transcoder::v1::CreateJobTemplateRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context, Options const& options,
          google::cloud::video::transcoder::v1::CreateJobTemplateRequest const&
              request) {
        return child_->CreateJobTemplate(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::video::transcoder::v1::ListJobTemplatesResponse>
TranscoderServiceLogging::ListJobTemplates(
    grpc::ClientContext& context, Options const& options,
    google::cloud::video::transcoder::v1::ListJobTemplatesRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context, Options const& options,
          google::cloud::video::transcoder::v1::ListJobTemplatesRequest const&
              request) {
        return child_->ListJobTemplates(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::video::transcoder::v1::JobTemplate>
TranscoderServiceLogging::GetJobTemplate(
    grpc::ClientContext& context, Options const& options,
    google::cloud::video::transcoder::v1::GetJobTemplateRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::video::transcoder::v1::GetJobTemplateRequest const&
                 request) {
        return child_->GetJobTemplate(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

Status TranscoderServiceLogging::DeleteJobTemplate(
    grpc::ClientContext& context, Options const& options,
    google::cloud::video::transcoder::v1::DeleteJobTemplateRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context, Options const& options,
          google::cloud::video::transcoder::v1::DeleteJobTemplateRequest const&
              request) {
        return child_->DeleteJobTemplate(context, options, request);
      },
      context, options, request, __func__, tracing_options_);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace video_transcoder_v1_internal
}  // namespace cloud
}  // namespace google
