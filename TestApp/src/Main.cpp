#define BOOST_TEST_MODULE StreamedFetch Unit Test Module
#include <boost/test/unit_test.hpp>

#include <string>
#include <sstream>

#include <curlpp/Options.hpp>

#include <fmt/ostream.h>

#include <StreamedFetch/Client/SimpleFetch.hpp>

using namespace StreamedFetch;

BOOST_AUTO_TEST_CASE(simple_client_httpget_test)
{
    try {
        Client::SimpleFetch fetch;
        std::string data;
        fetch << Options::HttpMethods::Get { "https://jsonplaceholder.typicode.com/todo/1" }
              << Client::Perform;
        fetch >> data;

        fmt::print("response:\n{}", data);

        BOOST_REQUIRE(!data.empty());
    } catch (const std::exception &e) {
        BOOST_FAIL(e.what());
    }
}