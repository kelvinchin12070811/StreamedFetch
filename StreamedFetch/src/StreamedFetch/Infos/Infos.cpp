/***********************************************************************************************************************
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 **********************************************************************************************************************/
#include "StreamedFetch/Infos/Infos.hpp"

#include <curlpp/Infos.hpp>

namespace StreamedFetch::Infos {
ResponseCode::ResponseCode(long &output)
{
    outputTarget = &output;
}

ResponseCode::ResponseCode(std::ostream &output)
{
    outputTarget = &output;
}

void ResponseCode::writeInfo(const curlpp::Easy &client) const
{
    auto result = curlpp::infos::ResponseCode::get(client);

    switch (outputTarget.index()) {
    case 0:
        *std::get<long *>(outputTarget) = result;
        break;
    case 1:
        (*std::get<std::ostream *>(outputTarget)) << result;
        break;
    }
}
}