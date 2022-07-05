/***********************************************************************************************************************
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 **********************************************************************************************************************/
#include "StreamedFetch/Client/ClientBase.hpp"

#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Infos.hpp>

namespace StreamedFetch::Client {
ClientBase::ClientBase() : client { std::make_unique<curlpp::Easy>() } { }

void ClientBase::reset() noexcept
{
    client->reset();
}

ClientBase &ClientBase::operator<<(ClientManipulatorType manipulator) noexcept
{
    manipulator(this, client.get());
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

void perform(ClientBase * const client, curlpp::Easy * const curl)
{
    static_cast<void>(curl);
    client->fetch();
}

void reset(ClientBase* const client, curlpp::Easy* const curl) {
    static_cast<void>(curl);
    client->reset();
}
}