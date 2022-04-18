#include <iostream>
#include <any>
#include <string>
#include <sstream>

#include <curlpp/Options.hpp>

#include <StreamedFetch/Client/SimpleFetch.hpp>

using namespace std::string_literals;
using std::any_cast;

int main(int argc, char** argv)
{
    StreamedFetch::Client::SimpleFetch fetch;
    fetch << StreamedFetch::Options::HttpMethods::Get { "https://jsonplaceholder.typicode.com/todos/1" }
          << StreamedFetch::Client::Perform;

    std::string data;
    fetch >> data;
    std::cout << data << std::endl;
    
    return 0;
}