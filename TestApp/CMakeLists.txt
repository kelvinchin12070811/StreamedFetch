cmake_minimum_required(VERSION 3.0.0)
project("TestApp")
set(CMAKE_INCLUDE_CURRENT_DIR on)
set(CMAKE_CXX_STANDARD 17)

find_package(unofficial-curlpp CONFIG REQUIRED)

add_executable(${PROJECT_NAME} src/Main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE
    StreamedFetch
    unofficial::curlpp::curlpp
)
