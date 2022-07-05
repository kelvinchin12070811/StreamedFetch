/***********************************************************************************************************************
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 **********************************************************************************************************************/

#include <memory>
#include <string>

#include "StreamedFetch/Options/ClientOption.hpp"

#define STREAMED_FETCH_METHOD_BASE_DEFINITIONS \
    void assignOption(curlpp::Easy *client) noexcept override;\
    std::unique_ptr<MethodBase> init() override;\
private:\
std::string url;

namespace curlpp {
class Easy;
}

namespace StreamedFetch::Options::HttpMethods {
/**
 * @brief Represented as the HTTP GET request method.
 * @param url Url to fetch.
 * @return Manipulator to execute by ClientBase.
 */
Client::ClientManipulatorType get(std::string url);

/**
 * @brief Represented as the empty HTTP POST request method.
 * @param url Url to POST.
 * 
 * @sa StreamedFetch::Options::HttpMethods::post(std::string url, std::string body)
 * 
 * @return Manipulator to execute by ClientBase.
*/
Client::ClientManipulatorType post(std::string url);
/**
 * @brief Represented as the HTTP POST request method with payload.
 * @param url Url to POST.
 * @param body Payload to send to @p url.
 * 
 * @sa StreamedFetch::Options::HttpMethods::post(std::string url)
 * 
 * @return Manipulator to execute by ClientBase
*/
Client::ClientManipulatorType post(std::string url, std::string body);
}