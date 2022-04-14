#include <iostream>
#include <any>
#include <string>
#include <sstream>

#include <curlpp/Options.hpp>

#include <StreamedFetch/Client/Fetch.hpp>

using namespace std::string_literals;
using std::any_cast;

int main(int argc, char** argv)
{
    StreamedFetch::Client::Fetch fetch;
    fetch << curlpp::Options::Url { "https://jsonplaceholder.typicode.com/todos/1" } << nullptr;

    std::stringstream ss;
    fetch >> ss;

    std::cout << ss.str() << std::endl;
    
    return 0;
}