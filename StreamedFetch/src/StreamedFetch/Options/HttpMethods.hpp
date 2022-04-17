/***********************************************************************************************************************
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 **********************************************************************************************************************/

#include <memory>
#include <string>

namespace curlpp {
class Easy;
}

namespace StreamedFetch::Options::Methods {
/**
 * @brief Interface of HTTP request methods.
 * 
 * Represented as the interface of all HTTP request methods.
 */
struct IMethod
{
    /**
     * @brief Assign the HTTP request method's options to targeted client.
     */
    virtual void assignOptions(curlpp::Easy &client) = 0;
    /**
     * @brief Create a instance of it self.
     * @return Abstracted IMethod client option.
     */
    virtual std::unique_ptr<IMethod> init() = 0;
    virtual ~IMethod() = 0;
};

/**
 * @brief Represented as HTTP GET request option.
 */
class Get : public IMethod
{
public:
    Get(std::string url);
    void assignOptions(curlpp::Easy &client) override;
    std::unique_ptr<IMethod> init() override;

private:
    std::string url;
};
}