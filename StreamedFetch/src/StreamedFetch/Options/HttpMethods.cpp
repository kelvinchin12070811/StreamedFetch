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

void Get::assignOption(curlpp::Easy *client) noexcept
{
    assert(client != nullptr);

    client->setOpt(curlpp::Options::HttpGet { true });
    client->setOpt(curlpp::Options::Url { url });
}

std::unique_ptr<MethodBase> Get::init()
{
    return std::make_unique<Get>(std::move(url));
}

Post::Post(std::string url) : url { url } { }
Post::Post(std::string url, std::string body) : url { url }, body { body } { }

void Post::assignOption(curlpp::Easy *client) noexcept
{
    assert(client != nullptr);

    client->setOpt(curlpp::Options::Url { url });

    if (!body.empty()) {
        client->setOpt(curlpp::Options::PostFieldSize { static_cast<long>(body.length()) });
        client->setOpt(curlpp::Options::PostFields { body });
        return;
    }

    client->setOpt(curlpp::Options::HttpPost { curlpp::Forms {} });
}

std::unique_ptr<MethodBase> Post::init()
{
    auto method = std::make_unique<Post>(std::move(url));
    method->body = std::move(body);
    return method;
}
}
