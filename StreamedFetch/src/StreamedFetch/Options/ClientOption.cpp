/***********************************************************************************************************************
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 **********************************************************************************************************************/
#include "StreamedFetch/Options/ClientOption.hpp"

#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

namespace StreamedFetch::Options {
IClientOption::~IClientOption() = default;

Header::Header(std::string header)
{
    headers.push_back(header);
}

Header::Header(std::list<std::string> headers)
{
    this->headers = std::move(headers);
}

void Header::assignOption(curlpp::Easy *client) noexcept
{
    client->setOpt(curlpp::Options::HttpHeader { headers });
}

UserAgent::UserAgent(std::string userAgent) : userAgent { userAgent } { }

void UserAgent::assignOption(curlpp::Easy *client) noexcept
{
    client->setOpt(curlpp::Options::UserAgent { userAgent });
}
}