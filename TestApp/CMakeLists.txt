cmake_minimum_required(VERSION 3.0.0)
project("TestApp")
set(CMAKE_INCLUDE_CURRENT_DIR on)
set(CMAKE_CXX_STANDARD 17)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)
find_package(unofficial-curlpp CONFIG REQUIRED)

add_executable(${PROJECT_NAME} src/Main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Boost::unit_test_framework
    StreamedFetch
    unofficial::curlpp::curlpp
)

enable_testing()
add_test(
    NAME streamedfetch_test
    COMMAND $<TARGET_FILE:${PROJECT_NAME}>
)