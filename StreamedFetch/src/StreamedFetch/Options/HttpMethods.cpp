/***********************************************************************************************************************
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 **********************************************************************************************************************/
#include "StreamedFetch/Options/HttpMethods.hpp"

#include <cassert>

#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

namespace StreamedFetch::Options::HttpMethods {
Client::ClientManipulatorType get(std::string url)
{
    return [url = std::move(url)](Client::ClientBase *const client, curlpp::Easy *const curl) {
        static_cast<void>(client);
        curl->setOpt(curlpp::Options::HttpGet {});
        curl->setOpt(curlpp::Options::Url { url });
    };
}

Client::ClientManipulatorType post(std::string url)
{
    return [url = std::move(url)](Client::ClientBase *const client, curlpp::Easy *const curl) {
        static_cast<void>(client);
        curl->setOpt(curlpp::Options::Url { url });
        curl->setOpt(curlpp::Options::HttpPost { curlpp::Forms {} });
    };
}

Client::ClientManipulatorType post(std::string url, std::string body)
{
    return [url = std::move(url), body = std::move(body)](Client::ClientBase *const client,
                                                          curlpp::Easy *const curl) {
        static_cast<void>(client);
        curl->setOpt(curlpp::Options::Url { url });
        curl->setOpt(curlpp::Options::PostFieldSize { static_cast<long>(body.length()) });
        curl->setOpt(curlpp::Options::PostFields { body });
    };
}
}
