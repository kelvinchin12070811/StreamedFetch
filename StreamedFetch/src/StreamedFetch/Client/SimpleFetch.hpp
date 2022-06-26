/***********************************************************************************************************************
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 **********************************************************************************************************************/
#pragma once

#include <cstdint>
#include <vector>
#include <sstream>

#include "StreamedFetch/Client/ClientBase.hpp"

namespace StreamedFetch::Client {
/**
 * @brief Simple client of ClientBase to use with minimal effort.
 * 
 * This is the basic client to perform http request, with minimal effort. It provide operator>> to take output from it.
 */
class SimpleFetch : public ClientBase
{
public:
    SimpleFetch();
    using ClientBase::operator<<;
    using ClientBase::operator>>;
    
    void reset() noexcept override;

    /**
     * @brief Get output from the client and clear the buffer.
     * @param output String to write into.
     * @return The same object where operator>> is called on for chaining.
     * 
     * @sa operator>>(std::stringstream &output)
     * @sa operator>>(std::vector<std::uint8_t> &output)
     */
    SimpleFetch &operator>>(std::string &output);
    /**
     * @brief Get output from the client and clear the buffer.
     * @param output String stream to write into.
     * @return The same object where operator>> is called on for chaining.
     *
     * @sa operator>>(std::string &output)
     * @sa operator>>(std::vector<std::uint8_t> &output)
     */
    SimpleFetch &operator>>(std::stringstream &output);
    /**
     * @brief Get output from the client and clear the buffer.
     * @param output Bytes array to write into.
     * @return The same object where operator>> is called on for chaining.
     *
     * @sa operator>>(std::string &output)
     * @sa operator>>(std::stringstream &output)
     */
    SimpleFetch &operator>>(std::vector<std::uint8_t> &output);

protected:
    void fetch() override;

private:
    /**
     * @brief Buffer to store result of the client.
     */
    std::stringstream buffer;
};
}