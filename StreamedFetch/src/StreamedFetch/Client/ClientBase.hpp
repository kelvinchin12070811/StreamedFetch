/***********************************************************************************************************************
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 **********************************************************************************************************************/
#pragma once

#include <memory>
#include <functional>

#include "StreamedFetch/Infos/IClientInfo.hpp"
#include "StreamedFetch/Options/HttpMethods.hpp"

namespace curlpp {
class Easy;
}

namespace StreamedFetch::Client {
class ClientBase;

/**
 * @brief Define as the type of manipulators for client streams.
 */
using ClientManipulatorType = std::function<void(ClientBase *const, curlpp::Easy *const)>;

/**
 * @brief Base implementation of all fetch client.
 *
 * Represent as the base of all fetch client, handle options and data streaming of the clients. Also
 * mark them as non-copyable but still moveable.
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
    ClientBase(ClientBase &&rhs) noexcept;

    /**
     * @brief Reset the fetch client.
     */
    virtual void reset() noexcept;

    /**
     * @brief Method that will be called when the client recieve Perform operator.
     */
    virtual void fetch() = 0;

    /**
     * @brief Move operator of the ClientBase.
     * @param rhs Target ClientBase to move from.
     * @return Moved ClientBase.
     */
    ClientBase &operator=(ClientBase &&rhs) noexcept;

    /**
     * @brief Set http method for the client.
     * @param method Http method to fetch data
     * @return This client for chaining.
     */
    ClientBase &operator<<(Options::HttpMethods::MethodBase &method) noexcept;

    /**
     * @brief Assign client option to current client.
     * @param option Option to assign to current client.
     * @return This object for chaining operator.
     */
    ClientBase &operator<<(Options::IClientOption &option) noexcept;

    /**
     * @brief Execute manipulator on the target client.
     * @param manipulator Manipulator to execute, usually CURL options.
     */
    ClientBase &operator<<(ClientManipulatorType manipulator) noexcept;

    /**
     * @brief Output required client info to Infos::IClientInfo
     * @param info IClientInfo to write to
     * @return This client for chaining.
     */
    ClientBase &operator>>(Infos::IClientInfo &info);

    ClientBase(const ClientBase &) = delete;
    ClientBase &operator=(const ClientBase &) = delete;
    virtual ~ClientBase() = 0;

protected:
    /**
     * @brief libcurlpp client used to perform the request.
     */
    std::unique_ptr<curlpp::Easy> client { nullptr };
    /**
     * @brief Define the method
     */
    std::unique_ptr<Options::HttpMethods::MethodBase> method { nullptr };
};

/**
 * @brief Manipulator that execute fetch action on ClientBase children classes.
 * @param client Client where the manipulator get called, should not be nullptr.
 * @param curl Curl instance that @p client hold, does not assign ownership.
 */
void perform(ClientBase *const client, curlpp::Easy *const curl);

/**
 * @brief Manipulator that will reset the client where it streamed into.
 * @param client Client where the manipulator get called, should not be nullptr.
 * @param curl Curl instance that @p client hold, does not assign ownership.
*/
void reset(ClientBase *const client, curlpp::Easy *const curl);
}