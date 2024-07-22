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
// source: google/cloud/contactcenterinsights/v1/contact_center_insights.proto

#include "google/cloud/contactcenterinsights/v1/internal/contact_center_insights_metadata_decorator.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/absl_str_cat_quiet.h"
#include "google/cloud/internal/api_client_header.h"
#include "google/cloud/internal/url_encode.h"
#include "google/cloud/status_or.h"
#include <google/cloud/contactcenterinsights/v1/contact_center_insights.grpc.pb.h>
#include <memory>
#include <string>
#include <utility>
#include <vector>

namespace google {
namespace cloud {
namespace contactcenterinsights_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

ContactCenterInsightsMetadata::ContactCenterInsightsMetadata(
    std::shared_ptr<ContactCenterInsightsStub> child,
    std::multimap<std::string, std::string> fixed_metadata,
    std::string api_client_header)
    : child_(std::move(child)),
      fixed_metadata_(std::move(fixed_metadata)),
      api_client_header_(
          api_client_header.empty()
              ? google::cloud::internal::GeneratedLibClientHeader()
              : std::move(api_client_header)) {}

StatusOr<google::cloud::contactcenterinsights::v1::Conversation>
ContactCenterInsightsMetadata::CreateConversation(
    grpc::ClientContext& context, Options const& options,
    google::cloud::contactcenterinsights::v1::CreateConversationRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->CreateConversation(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
ContactCenterInsightsMetadata::AsyncUploadConversation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::contactcenterinsights::v1::UploadConversationRequest const&
        request) {
  SetMetadata(*context, *options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->AsyncUploadConversation(cq, std::move(context),
                                         std::move(options), request);
}

StatusOr<google::longrunning::Operation>
ContactCenterInsightsMetadata::UploadConversation(
    grpc::ClientContext& context, Options options,
    google::cloud::contactcenterinsights::v1::UploadConversationRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->UploadConversation(context, options, request);
}

StatusOr<google::cloud::contactcenterinsights::v1::Conversation>
ContactCenterInsightsMetadata::UpdateConversation(
    grpc::ClientContext& context, Options const& options,
    google::cloud::contactcenterinsights::v1::UpdateConversationRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("conversation.name=",
                           internal::UrlEncode(request.conversation().name())));
  return child_->UpdateConversation(context, options, request);
}

StatusOr<google::cloud::contactcenterinsights::v1::Conversation>
ContactCenterInsightsMetadata::GetConversation(
    grpc::ClientContext& context, Options const& options,
    google::cloud::contactcenterinsights::v1::GetConversationRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetConversation(context, options, request);
}

StatusOr<google::cloud::contactcenterinsights::v1::ListConversationsResponse>
ContactCenterInsightsMetadata::ListConversations(
    grpc::ClientContext& context, Options const& options,
    google::cloud::contactcenterinsights::v1::ListConversationsRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListConversations(context, options, request);
}

Status ContactCenterInsightsMetadata::DeleteConversation(
    grpc::ClientContext& context, Options const& options,
    google::cloud::contactcenterinsights::v1::DeleteConversationRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->DeleteConversation(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
ContactCenterInsightsMetadata::AsyncCreateAnalysis(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::contactcenterinsights::v1::CreateAnalysisRequest const&
        request) {
  SetMetadata(*context, *options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->AsyncCreateAnalysis(cq, std::move(context), std::move(options),
                                     request);
}

StatusOr<google::longrunning::Operation>
ContactCenterInsightsMetadata::CreateAnalysis(
    grpc::ClientContext& context, Options options,
    google::cloud::contactcenterinsights::v1::CreateAnalysisRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->CreateAnalysis(context, options, request);
}

StatusOr<google::cloud::contactcenterinsights::v1::Analysis>
ContactCenterInsightsMetadata::GetAnalysis(
    grpc::ClientContext& context, Options const& options,
    google::cloud::contactcenterinsights::v1::GetAnalysisRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetAnalysis(context, options, request);
}

StatusOr<google::cloud::contactcenterinsights::v1::ListAnalysesResponse>
ContactCenterInsightsMetadata::ListAnalyses(
    grpc::ClientContext& context, Options const& options,
    google::cloud::contactcenterinsights::v1::ListAnalysesRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListAnalyses(context, options, request);
}

Status ContactCenterInsightsMetadata::DeleteAnalysis(
    grpc::ClientContext& context, Options const& options,
    google::cloud::contactcenterinsights::v1::DeleteAnalysisRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->DeleteAnalysis(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
ContactCenterInsightsMetadata::AsyncBulkAnalyzeConversations(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::contactcenterinsights::v1::
        BulkAnalyzeConversationsRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->AsyncBulkAnalyzeConversations(cq, std::move(context),
                                               std::move(options), request);
}

StatusOr<google::longrunning::Operation>
ContactCenterInsightsMetadata::BulkAnalyzeConversations(
    grpc::ClientContext& context, Options options,
    google::cloud::contactcenterinsights::v1::
        BulkAnalyzeConversationsRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->BulkAnalyzeConversations(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
ContactCenterInsightsMetadata::AsyncBulkDeleteConversations(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::contactcenterinsights::v1::
        BulkDeleteConversationsRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->AsyncBulkDeleteConversations(cq, std::move(context),
                                              std::move(options), request);
}

StatusOr<google::longrunning::Operation>
ContactCenterInsightsMetadata::BulkDeleteConversations(
    grpc::ClientContext& context, Options options,
    google::cloud::contactcenterinsights::v1::
        BulkDeleteConversationsRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->BulkDeleteConversations(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
ContactCenterInsightsMetadata::AsyncIngestConversations(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::contactcenterinsights::v1::IngestConversationsRequest const&
        request) {
  SetMetadata(*context, *options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->AsyncIngestConversations(cq, std::move(context),
                                          std::move(options), request);
}

StatusOr<google::longrunning::Operation>
ContactCenterInsightsMetadata::IngestConversations(
    grpc::ClientContext& context, Options options,
    google::cloud::contactcenterinsights::v1::IngestConversationsRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->IngestConversations(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
ContactCenterInsightsMetadata::AsyncExportInsightsData(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::contactcenterinsights::v1::ExportInsightsDataRequest const&
        request) {
  SetMetadata(*context, *options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->AsyncExportInsightsData(cq, std::move(context),
                                         std::move(options), request);
}

StatusOr<google::longrunning::Operation>
ContactCenterInsightsMetadata::ExportInsightsData(
    grpc::ClientContext& context, Options options,
    google::cloud::contactcenterinsights::v1::ExportInsightsDataRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ExportInsightsData(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
ContactCenterInsightsMetadata::AsyncCreateIssueModel(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::contactcenterinsights::v1::CreateIssueModelRequest const&
        request) {
  SetMetadata(*context, *options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->AsyncCreateIssueModel(cq, std::move(context),
                                       std::move(options), request);
}

StatusOr<google::longrunning::Operation>
ContactCenterInsightsMetadata::CreateIssueModel(
    grpc::ClientContext& context, Options options,
    google::cloud::contactcenterinsights::v1::CreateIssueModelRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->CreateIssueModel(context, options, request);
}

StatusOr<google::cloud::contactcenterinsights::v1::IssueModel>
ContactCenterInsightsMetadata::UpdateIssueModel(
    grpc::ClientContext& context, Options const& options,
    google::cloud::contactcenterinsights::v1::UpdateIssueModelRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("issue_model.name=",
                           internal::UrlEncode(request.issue_model().name())));
  return child_->UpdateIssueModel(context, options, request);
}

StatusOr<google::cloud::contactcenterinsights::v1::IssueModel>
ContactCenterInsightsMetadata::GetIssueModel(
    grpc::ClientContext& context, Options const& options,
    google::cloud::contactcenterinsights::v1::GetIssueModelRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetIssueModel(context, options, request);
}

StatusOr<google::cloud::contactcenterinsights::v1::ListIssueModelsResponse>
ContactCenterInsightsMetadata::ListIssueModels(
    grpc::ClientContext& context, Options const& options,
    google::cloud::contactcenterinsights::v1::ListIssueModelsRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListIssueModels(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
ContactCenterInsightsMetadata::AsyncDeleteIssueModel(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::contactcenterinsights::v1::DeleteIssueModelRequest const&
        request) {
  SetMetadata(*context, *options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncDeleteIssueModel(cq, std::move(context),
                                       std::move(options), request);
}

StatusOr<google::longrunning::Operation>
ContactCenterInsightsMetadata::DeleteIssueModel(
    grpc::ClientContext& context, Options options,
    google::cloud::contactcenterinsights::v1::DeleteIssueModelRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->DeleteIssueModel(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
ContactCenterInsightsMetadata::AsyncDeployIssueModel(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::contactcenterinsights::v1::DeployIssueModelRequest const&
        request) {
  SetMetadata(*context, *options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncDeployIssueModel(cq, std::move(context),
                                       std::move(options), request);
}

StatusOr<google::longrunning::Operation>
ContactCenterInsightsMetadata::DeployIssueModel(
    grpc::ClientContext& context, Options options,
    google::cloud::contactcenterinsights::v1::DeployIssueModelRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->DeployIssueModel(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
ContactCenterInsightsMetadata::AsyncUndeployIssueModel(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::contactcenterinsights::v1::UndeployIssueModelRequest const&
        request) {
  SetMetadata(*context, *options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncUndeployIssueModel(cq, std::move(context),
                                         std::move(options), request);
}

StatusOr<google::longrunning::Operation>
ContactCenterInsightsMetadata::UndeployIssueModel(
    grpc::ClientContext& context, Options options,
    google::cloud::contactcenterinsights::v1::UndeployIssueModelRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->UndeployIssueModel(context, options, request);
}

StatusOr<google::cloud::contactcenterinsights::v1::Issue>
ContactCenterInsightsMetadata::GetIssue(
    grpc::ClientContext& context, Options const& options,
    google::cloud::contactcenterinsights::v1::GetIssueRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetIssue(context, options, request);
}

StatusOr<google::cloud::contactcenterinsights::v1::ListIssuesResponse>
ContactCenterInsightsMetadata::ListIssues(
    grpc::ClientContext& context, Options const& options,
    google::cloud::contactcenterinsights::v1::ListIssuesRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListIssues(context, options, request);
}

StatusOr<google::cloud::contactcenterinsights::v1::Issue>
ContactCenterInsightsMetadata::UpdateIssue(
    grpc::ClientContext& context, Options const& options,
    google::cloud::contactcenterinsights::v1::UpdateIssueRequest const&
        request) {
  SetMetadata(
      context, options,
      absl::StrCat("issue.name=", internal::UrlEncode(request.issue().name())));
  return child_->UpdateIssue(context, options, request);
}

Status ContactCenterInsightsMetadata::DeleteIssue(
    grpc::ClientContext& context, Options const& options,
    google::cloud::contactcenterinsights::v1::DeleteIssueRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->DeleteIssue(context, options, request);
}

StatusOr<
    google::cloud::contactcenterinsights::v1::CalculateIssueModelStatsResponse>
ContactCenterInsightsMetadata::CalculateIssueModelStats(
    grpc::ClientContext& context, Options const& options,
    google::cloud::contactcenterinsights::v1::
        CalculateIssueModelStatsRequest const& request) {
  SetMetadata(
      context, options,
      absl::StrCat("issue_model=", internal::UrlEncode(request.issue_model())));
  return child_->CalculateIssueModelStats(context, options, request);
}

StatusOr<google::cloud::contactcenterinsights::v1::PhraseMatcher>
ContactCenterInsightsMetadata::CreatePhraseMatcher(
    grpc::ClientContext& context, Options const& options,
    google::cloud::contactcenterinsights::v1::CreatePhraseMatcherRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->CreatePhraseMatcher(context, options, request);
}

StatusOr<google::cloud::contactcenterinsights::v1::PhraseMatcher>
ContactCenterInsightsMetadata::GetPhraseMatcher(
    grpc::ClientContext& context, Options const& options,
    google::cloud::contactcenterinsights::v1::GetPhraseMatcherRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetPhraseMatcher(context, options, request);
}

StatusOr<google::cloud::contactcenterinsights::v1::ListPhraseMatchersResponse>
ContactCenterInsightsMetadata::ListPhraseMatchers(
    grpc::ClientContext& context, Options const& options,
    google::cloud::contactcenterinsights::v1::ListPhraseMatchersRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListPhraseMatchers(context, options, request);
}

Status ContactCenterInsightsMetadata::DeletePhraseMatcher(
    grpc::ClientContext& context, Options const& options,
    google::cloud::contactcenterinsights::v1::DeletePhraseMatcherRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->DeletePhraseMatcher(context, options, request);
}

StatusOr<google::cloud::contactcenterinsights::v1::PhraseMatcher>
ContactCenterInsightsMetadata::UpdatePhraseMatcher(
    grpc::ClientContext& context, Options const& options,
    google::cloud::contactcenterinsights::v1::UpdatePhraseMatcherRequest const&
        request) {
  SetMetadata(
      context, options,
      absl::StrCat("phrase_matcher.name=",
                   internal::UrlEncode(request.phrase_matcher().name())));
  return child_->UpdatePhraseMatcher(context, options, request);
}

StatusOr<google::cloud::contactcenterinsights::v1::CalculateStatsResponse>
ContactCenterInsightsMetadata::CalculateStats(
    grpc::ClientContext& context, Options const& options,
    google::cloud::contactcenterinsights::v1::CalculateStatsRequest const&
        request) {
  SetMetadata(
      context, options,
      absl::StrCat("location=", internal::UrlEncode(request.location())));
  return child_->CalculateStats(context, options, request);
}

StatusOr<google::cloud::contactcenterinsights::v1::Settings>
ContactCenterInsightsMetadata::GetSettings(
    grpc::ClientContext& context, Options const& options,
    google::cloud::contactcenterinsights::v1::GetSettingsRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetSettings(context, options, request);
}

StatusOr<google::cloud::contactcenterinsights::v1::Settings>
ContactCenterInsightsMetadata::UpdateSettings(
    grpc::ClientContext& context, Options const& options,
    google::cloud::contactcenterinsights::v1::UpdateSettingsRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("settings.name=",
                           internal::UrlEncode(request.settings().name())));
  return child_->UpdateSettings(context, options, request);
}

StatusOr<google::cloud::contactcenterinsights::v1::View>
ContactCenterInsightsMetadata::CreateView(
    grpc::ClientContext& context, Options const& options,
    google::cloud::contactcenterinsights::v1::CreateViewRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->CreateView(context, options, request);
}

StatusOr<google::cloud::contactcenterinsights::v1::View>
ContactCenterInsightsMetadata::GetView(
    grpc::ClientContext& context, Options const& options,
    google::cloud::contactcenterinsights::v1::GetViewRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetView(context, options, request);
}

StatusOr<google::cloud::contactcenterinsights::v1::ListViewsResponse>
ContactCenterInsightsMetadata::ListViews(
    grpc::ClientContext& context, Options const& options,
    google::cloud::contactcenterinsights::v1::ListViewsRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListViews(context, options, request);
}

StatusOr<google::cloud::contactcenterinsights::v1::View>
ContactCenterInsightsMetadata::UpdateView(
    grpc::ClientContext& context, Options const& options,
    google::cloud::contactcenterinsights::v1::UpdateViewRequest const&
        request) {
  SetMetadata(
      context, options,
      absl::StrCat("view.name=", internal::UrlEncode(request.view().name())));
  return child_->UpdateView(context, options, request);
}

Status ContactCenterInsightsMetadata::DeleteView(
    grpc::ClientContext& context, Options const& options,
    google::cloud::contactcenterinsights::v1::DeleteViewRequest const&
        request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->DeleteView(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
ContactCenterInsightsMetadata::AsyncGetOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::longrunning::GetOperationRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncGetOperation(cq, std::move(context), std::move(options),
                                   request);
}

future<Status> ContactCenterInsightsMetadata::AsyncCancelOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::longrunning::CancelOperationRequest const& request) {
  SetMetadata(*context, *options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncCancelOperation(cq, std::move(context),
                                      std::move(options), request);
}

void ContactCenterInsightsMetadata::SetMetadata(
    grpc::ClientContext& context, Options const& options,
    std::string const& request_params) {
  context.AddMetadata("x-goog-request-params", request_params);
  SetMetadata(context, options);
}

void ContactCenterInsightsMetadata::SetMetadata(grpc::ClientContext& context,
                                                Options const& options) {
  google::cloud::internal::SetMetadata(context, options, fixed_metadata_,
                                       api_client_header_);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace contactcenterinsights_v1_internal
}  // namespace cloud
}  // namespace google
