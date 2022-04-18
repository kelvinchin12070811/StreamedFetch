/***********************************************************************************************************************
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 **********************************************************************************************************************/
#pragma once

namespace curlpp {
class Easy;
}

namespace StreamedFetch::Options {
/**
 * @brief Interface of all client options that will assign options to the provided StreamedFetch::Client::ClientBase.
 */
struct IClientOption
{
    /**
     * @brief Assign the related options to @p client.
     * 
     * Assign options to @p client, must not be nullptr and assertion failed.
     * 
     * @param client Client to supply option to.
     */
    virtual void assignOption(curlpp::Easy *client) noexcept = 0;

    /**
     * @brief Destruct the IClientOption object.
     */
    virtual ~IClientOption() = 0;
};
}