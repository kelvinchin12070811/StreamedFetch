/***********************************************************************************************************************
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 **********************************************************************************************************************/

namespace StreamedFetch::Options {
/**
 * @brief Define the methods HTTP's methods that will be used by the client.
 */
enum class HttpMethod {
    Null /**< Method not provided, should throw exception. */,
    Get /**< Http GET request. */,
    Patch /**< Http PATCH request. */,
    Put /**< Http PUT request. */,
    Delete /**< Http DELETE request. */,
    Post /**< Http POST request. */
};
}