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
Get::Get(std::string url) : url { std::move(url) } { }

void StreamedFetch::Options::HttpMethods::Get::assignOption(curlpp::Easy *client) noexcept
{
    assert(client != nullptr);

    client->setOpt(curlpp::Options::HttpGet { true });
    client->setOpt(curlpp::Options::Url { url });
}

std::unique_ptr<MethodBase> Options::HttpMethods::Get::init()
{
    return std::make_unique<Get>(std::move(url));
}
}