/***********************************************************************************************************************
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 **********************************************************************************************************************/
#pragma once

#include <curlpp/Easy.hpp>

namespace StreamedFetch::Infos {
/**
 * @brief Represented as the base template of all client infos' operation.
 */
struct IClientInfo
{
    /**
     * @brief Write the client info to targeted IClientInfos object.
     * @param client Client to retrive info.
     */
    virtual void writeInfo(const curlpp::Easy &client) const = 0;
};
}