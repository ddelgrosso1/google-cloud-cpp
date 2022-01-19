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
// source: google/cloud/texttospeech/v1/cloud_tts.proto

#include "google/cloud/texttospeech/internal/text_to_speech_auth_decorator.h"
#include <google/cloud/texttospeech/v1/cloud_tts.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace texttospeech_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

TextToSpeechAuth::TextToSpeechAuth(
    std::shared_ptr<google::cloud::internal::GrpcAuthenticationStrategy> auth,
    std::shared_ptr<TextToSpeechStub> child)
    : auth_(std::move(auth)), child_(std::move(child)) {}

StatusOr<google::cloud::texttospeech::v1::ListVoicesResponse>
TextToSpeechAuth::ListVoices(
    grpc::ClientContext& context,
    google::cloud::texttospeech::v1::ListVoicesRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->ListVoices(context, request);
}

StatusOr<google::cloud::texttospeech::v1::SynthesizeSpeechResponse>
TextToSpeechAuth::SynthesizeSpeech(
    grpc::ClientContext& context,
    google::cloud::texttospeech::v1::SynthesizeSpeechRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->SynthesizeSpeech(context, request);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace texttospeech_internal
}  // namespace cloud
}  // namespace google
