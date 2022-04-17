/***********************************************************************************************************************
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 **********************************************************************************************************************/
#pragma once

#include <memory>

#include "StreamedFetch/Options/HttpMethods.hpp"

namespace curlpp {
struct Easy;
}

namespace StreamedFetch::Client {
/**
 * @brief Base data type of `Perform`.
 * 
 * @sa Perform
 */
const struct Perform_t
{
}
/**
 * @brief Operator that tell the client to execute the fetch process.
 * 
 * example:
 * ```cpp
 * StreamedFetch::Client::SimpleFetch fetch;
 * fetch << StreamedFetch::Options::Methods::Get { "https://example.com" } << StreamedFetch::Client::Perform;
 * ```
 */
Perform;

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
    ClientBase(ClientBase &&rhs) noexcept;
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
    ClientBase &operator<<(Options::Methods::IMethod &method) noexcept;
    /**
     * @brief Execute the fetch query.
     * @return This client for chaining.
     */
    virtual ClientBase &operator<<(Perform_t) = 0;

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
    std::unique_ptr<Options::Methods::IMethod> method { nullptr };
};
}