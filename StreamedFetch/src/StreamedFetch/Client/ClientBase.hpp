/***********************************************************************************************************************
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 **********************************************************************************************************************/
#pragma once

#include <memory>
#include <sstream>

namespace curlpp {
struct Easy;
}

/**
 * @brief Define the clients of StreamedFetch.
 */
namespace StreamedFetch::Client {
/**
 * @brief Base implementation of all fetch client.
 * 
 * Represent as the base of all fetch client, handle options and data streaming of the clients. Also mark them as
 * non-copyable but still moveable.
 */
class ClientBase
{
public:
    /**
     * @brief Create a default ClientBase.
     */
    ClientBase();

    /**
     * @brief Move constructor of the ClientBase.
     * @param rhs Target ClientBase to move from.
    */
    ClientBase(ClientBase &&rhs);
    /**
     * @brief Move operator of the ClientBase.
     * @param rhs Target ClientBase to move from.
     * @return Moved ClientBase.
     */
    ClientBase &operator=(ClientBase &&rhs);

    ClientBase(const ClientBase &) = delete;
    ClientBase &operator=(const ClientBase &) = delete;

private:
    std::unique_ptr<curlpp::Easy> client { nullptr };
    std::ostringstream buffer;
};
}