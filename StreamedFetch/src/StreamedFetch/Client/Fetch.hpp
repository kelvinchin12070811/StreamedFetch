/***********************************************************************************************************************
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 **********************************************************************************************************************/
#pragma once

#include <sstream>

#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

namespace StreamedFetch::Client {
/**
 * @brief Default client for http rest client.
 */
class Fetch
{
public:
    Fetch();

    Fetch &operator<<(const curlpp::Options::Url &option);
    Fetch &operator<<(nullptr_t);

    Fetch &operator>>(std::stringstream &output);

private:
    curlpp::Easy client;
    std::stringstream result;
};
}