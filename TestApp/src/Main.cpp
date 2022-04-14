#include <iostream>
#include <any>
#include <string>

#include <StreamedFetch/Test.hpp>

using namespace std::string_literals;
using std::any_cast;

int main(int argc, char** argv)
{
    std::any test{ "hello from std::any"s };
    sayHello();
    std::cout << any_cast<std::string>(test) << std::endl;
    return 0;
}