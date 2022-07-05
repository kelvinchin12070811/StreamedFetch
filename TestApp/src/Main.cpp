#define BOOST_TEST_MODULE StreamedFetch Unit Test Module
#include <boost/test/unit_test.hpp>

#include <string>
#include <sstream>

#include <fmt/ostream.h>

#include <StreamedFetch/Client/SimpleFetch.hpp>
#include <StreamedFetch/Infos/Infos.hpp>

using namespace StreamedFetch;

BOOST_AUTO_TEST_CASE(simple_client_httpget_test)
{
    try {
        fmt::print("\nTesting simple client http get\n\n");
        Client::SimpleFetch fetch;
        std::string data;
        long responseCode { 0 };
        fetch << Options::HttpMethods::Get { "https://jsonplaceholder.typicode.com/todos/1" }
              << Client::perform;
        fetch >> data >> Infos::ResponseCode { responseCode };

        fmt::print("response:\n{}\n", data);
        fmt::print("response code: {}\n", responseCode);

        BOOST_REQUIRE(!data.empty() && responseCode < 400);
    } catch (const std::exception &e) {
        BOOST_FAIL(e.what());
    }
}

BOOST_AUTO_TEST_CASE(simple_client_httppost_test)
{
    try {
        fmt::print("\nTesting simple client http post\n\n");

        Client::SimpleFetch fetch;
        std::string data;
        long responseCode { 0 };

        fetch << Options::HttpMethods::Post { "https://jsonplaceholder.typicode.com/posts", "{\"test\": \"hi\"}" }
              << Options::Header { "Content-Type: application/json" } << Options::userAgent("test")
              << Client::perform;

        fetch >> data >> Infos::ResponseCode {responseCode};
        fmt::print("response: \n{}\n", data);
        fmt::print("response code: {}\n", responseCode);
    } catch (const std::exception &e) {
        BOOST_FAIL(e.what());
    }
}