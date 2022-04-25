#define BOOST_TEST_MODULE StreamedFetch Unit Test Module
#include <boost/test/unit_test.hpp>

#include <string>
#include <sstream>

#include <curlpp/Options.hpp>

#include <fmt/ostream.h>

#include <StreamedFetch/Client/SimpleFetch.hpp>
#include <StreamedFetch/Infos/Infos.hpp>

using namespace StreamedFetch;

BOOST_AUTO_TEST_CASE(simple_client_httpget_test)
{
    try {
        Client::SimpleFetch fetch;
        std::string data;
        long responseCode { 0 };
        fetch << Options::HttpMethods::Get { "https://jsonplaceholder.typicode.com/todo/1" }
              << Client::Perform;
        fetch >> data >> Infos::ResponseCode { responseCode };

        fmt::print("response:\n{}\n", data);
        fmt::print("response code: {}\n", responseCode);

        BOOST_REQUIRE(!data.empty() && responseCode < 400);
    } catch (const std::exception &e) {
        BOOST_FAIL(e.what());
    }
}