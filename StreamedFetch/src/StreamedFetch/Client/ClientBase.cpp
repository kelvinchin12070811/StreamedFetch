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
    client->setOpt(curlpp::Options::WriteStream(&buffer));
}

ClientBase::ClientBase(ClientBase &&rhs) {
    buffer = std::move(rhs.buffer);
    client = std::move(rhs.client);
}

ClientBase &ClientBase::operator=(ClientBase &&rhs)
{
    buffer = std::move(rhs.buffer);
    client = std::move(rhs.client);
    return *this;
}
}