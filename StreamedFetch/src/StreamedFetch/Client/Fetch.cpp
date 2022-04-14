/***********************************************************************************************************************
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 **********************************************************************************************************************/
#include "StreamedFetch/Client/Fetch.hpp"

namespace StreamedFetch::Client {
Fetch::Fetch()
{
    client.setOpt(curlpp::Options::WriteStream{ &result });
}

Fetch &Fetch::operator<<(const curlpp::Options::Url &option)
{
    client.setOpt(option);
    return *this;
}

Fetch &Fetch::operator<<(nullptr_t)
{
    client.perform();
    return *this;
}
Fetch &Fetch::operator>>(std::stringstream &output)
{
    output = std::move(result);
    result = {};
    return *this;
}
}