/***********************************************************************************************************************
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 **********************************************************************************************************************/
#include "StreamedFetch/Client/SimpleFetch.hpp"

#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

namespace StreamedFetch::Client {
SimpleFetch::SimpleFetch() : ClientBase()
{
    client->setOpt(curlpp::Options::WriteStream { &buffer });
}

void SimpleFetch::reset() noexcept {
    ClientBase::reset();
    buffer = {};
}

SimpleFetch &SimpleFetch::operator>>(std::string &output)
{
    output = buffer.str();
    buffer = {};
    return *this;
}

SimpleFetch &SimpleFetch::operator>>(std::stringstream &output)
{
    output = std::move(buffer);
    return *this;
}

SimpleFetch &SimpleFetch::operator>>(std::vector<std::uint8_t> &output)
{
    auto start = buffer.tellg();
    buffer.seekg(0, std::ios::end);
    auto end = buffer.tellg();
    buffer.seekg(0, std::ios::beg);

    output.resize(end - start);
    buffer.read(reinterpret_cast<char *>(output.data()), output.size());

    return *this;
}

void SimpleFetch::fetch()
{
    method->assignOption(client.get());
    client->perform();
}
}