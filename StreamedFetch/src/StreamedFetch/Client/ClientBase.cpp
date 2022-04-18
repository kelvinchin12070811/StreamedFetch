/***********************************************************************************************************************
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 **********************************************************************************************************************/
#include "StreamedFetch/Client/ClientBase.hpp"

#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

namespace StreamedFetch::Client {
ClientBase::ClientBase() : client { std::make_unique<curlpp::Easy>() }
{
}

ClientBase &ClientBase::operator<<(Perform_t)
{
    fetch();
    return *this;
}

ClientBase::~ClientBase() = default;

ClientBase::ClientBase(ClientBase &&rhs) noexcept
{
    client = std::move(rhs.client);
}

ClientBase &ClientBase::operator=(ClientBase &&rhs) noexcept
{
    client = std::move(rhs.client);
    return *this;
}

ClientBase &ClientBase::operator<<(Options::HttpMethods::MethodBase &method) noexcept
{
    this->method = method.init();
    return *this;
}

ClientBase &ClientBase::operator<<(Options::IClientOption &option) noexcept
{
    option.assignOption(client.get());
    return *this;
}
}