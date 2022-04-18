/***********************************************************************************************************************
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 **********************************************************************************************************************/

#include <memory>
#include <string>

#include "StreamedFetch/Options/IClientOption.hpp"

namespace curlpp {
class Easy;
}

namespace StreamedFetch::Options::HttpMethods {
/**
 * @brief Interface of HTTP request methods.
 * 
 * Represented as the interface of all HTTP request methods.
 */
class MethodBase : public IClientOption
{
public:
    /**
     * @brief Assign the HTTP request method's options to targeted client.
     * 
     * Assign HTTP request method to @p client.
     * 
     * @param client Client to assign the option to, must not be nullptr or assertion failed will be triggered.
     */
    virtual void assignOption(curlpp::Easy *client) noexcept override = 0;
    /**
     * @brief Create a instance of it self.
     * @return Abstracted MethodBase client option.
     */
    virtual std::unique_ptr<MethodBase> init() = 0;
    ~MethodBase() = default;
};

/**
 * @brief Represented as HTTP GET request option.
 */
class Get : public MethodBase
{
public:
    Get(std::string url);
    void assignOption(curlpp::Easy *client) noexcept override;
    std::unique_ptr<MethodBase> init() override;

private:
    std::string url;
};
}