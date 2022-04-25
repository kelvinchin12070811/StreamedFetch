/***********************************************************************************************************************
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 **********************************************************************************************************************/
#pragma once

#include <ostream>
#include <variant>

#include "StreamedFetch/Infos/IClientInfo.hpp"

namespace StreamedFetch::Infos {
/**
 * @brief Get the HTTP response code out of the client.
 */
class ResponseCode : public IClientInfo
{
public:
    /**
     * @brief Output the response code to the provided variable.
     * @param output Destination where the response code write to.
     */
    ResponseCode(long &output);
    /**
     * @brief Output the response code to the provided std::ostream.
     * @param output Destination stream where the response code write to.
     */
    ResponseCode(std::ostream &output);

    void writeInfo(const curlpp::Easy &client) const override;

private:
    /**
     * @brief Target where the ResponseCode info write result to.
     */
    std::variant<long *, std::ostream *> outputTarget {};
};
}