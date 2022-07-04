/***********************************************************************************************************************
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 **********************************************************************************************************************/
#pragma once

#include <list>
#include <string>
#include <functional>

namespace curlpp {
class Easy;
}

namespace StreamedFetch::Options {
/**
 * @brief Interface of all client options that will assign options to the provided
 * StreamedFetch::Client::ClientBase.
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

/**
 * @brief Represent as the list of headers that will be sent to the API endpoint.
 *
 * A list of the HTTP headers in that will be sent to the API endpoint.
 *
 * Example:
 * ```
 * StreamedFetch::Client::SimpleFetch{} << HttpMethods::Post{
 *                                             "https://example.com",
 *                                             "\"test\": \"Hi!\""
 *                                         }
 *                                      << Header{ "Content-Type: application/json" }
 *                                      << Perform;
 * ```
 */
class Header : public IClientOption
{
public:
    /**
     * @brief Add a header to the request.
     * @param header Header string in.
     */
    Header(std::string header);
    /**
     * @brief Add a list of headers to the request.
     * @param headers List of Header strings.
     */
    Header(std::list<std::string> headers);
    void assignOption(curlpp::Easy *client) noexcept override;

private:
    /**
     * @brief List that hold the list of HTTP headers.
     */
    std::list<std::string> headers;
};

/**
 * @brief Add user-agent header to the request, can be manually set via Options::Header too.
 */ 
class UserAgent : public IClientOption
{
public:
    /**
     * @brief Create user-agent option object.
     * @param userAgent User-agent string to apply.
     */
    UserAgent(std::string userAgent);
    void assignOption(curlpp::Easy *client) noexcept override;

private:
    /**
     * @brief User-agent string to apply to the request.
     */
    std::string userAgent;
};

namespace functional_test {
std::function<void(std::unique_ptr<curlpp::Easy>&)> url(std::string path);
}
}