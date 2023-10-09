// Copyright 2023 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "google/cloud/internal/url_encode.h"
#include "google/cloud/internal/absl_str_replace_quiet.h"
#include <array>
#include <utility>

namespace google {
namespace cloud {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN
namespace internal {

namespace {

using UrlMappings =
    std::array<std::pair<absl::string_view, absl::string_view>, 25>;

constexpr auto kEncodeMappings = UrlMappings{{
    {" ", "%20"}, {"\"", "%22"}, {"#", "%23"},  {"$", "%24"}, {"%", "%25"},
    {"&", "%26"}, {"+", "%2B"},  {",", "%2C"},  {"/", "%2F"}, {":", "%3A"},
    {";", "%3B"}, {"<", "%3C"},  {"=", "%3D"},  {">", "%3E"}, {"?", "%3F"},
    {"@", "%40"}, {"[", "%5B"},  {"\\", "%5C"}, {"]", "%5D"}, {"^", "%5E"},
    {"`", "%60"}, {"{", "%7B"},  {"|", "%7C"},  {"}", "%7D"}, {"\177", "%7F"},
}};

// Until we require C++17, it isn't worth trying to eliminate the duplication
// using a constexpr function to produce kDecodeMappings from kEncodeMappings.
constexpr auto kDecodeMappings = UrlMappings{{
    {"%20", " "}, {"%22", "\""}, {"%23", "#"},  {"%24", "$"}, {"%25", "%"},
    {"%26", "&"}, {"%2B", "+"},  {"%2C", ","},  {"%2F", "/"}, {"%3A", ":"},
    {"%3B", ";"}, {"%3C", "<"},  {"%3D", "="},  {"%3E", ">"}, {"%3F", "?"},
    {"%40", "@"}, {"%5B", "["},  {"%5C", "\\"}, {"%5D", "]"}, {"%5E", "^"},
    {"%60", "`"}, {"%7B", "{"},  {"%7C", "|"},  {"%7D", "}"}, {"%7F", "\177"},
}};

}  // namespace

std::string UrlEncode(absl::string_view value) {
  return absl::StrReplaceAll(value, kEncodeMappings);
}

std::string UrlDecode(absl::string_view value) {
  return absl::StrReplaceAll(value, kDecodeMappings);
}

}  // namespace internal
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace cloud
}  // namespace google
