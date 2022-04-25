cmake_minimum_required(VERSION 3.0.0)
project("StreamedFetch")
set(CMAKE_INCLUDE_CURRENT_DIR on)
set(CMAKE_CXX_STANDARD 17)

find_package(unofficial-curlpp CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

set(SOURCE_FILES
    "src/StreamedFetch/Client/ClientBase.cpp"
    "src/StreamedFetch/Client/SimpleFetch.cpp"
    "src/StreamedFetch/Infos/Infos.cpp"
    "src/StreamedFetch/Options/HttpMethods.cpp"
    "src/StreamedFetch/Options/IClientOption.cpp"
)

set(HEADER_FILES
    "src/StreamedFetch/Client/ClientBase.hpp"
    "src/StreamedFetch/Client/SimpleFetch.hpp"
    "src/StreamedFetch/Infos/IClientInfo.hpp"
    "src/StreamedFetch/Infos/Infos.hpp"
    "src/StreamedFetch/Options/HttpMethods.hpp"
    "src/StreamedFetch/Options/IClientOption.hpp"
)

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES} ${HEADER_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_link_libraries(${PROJECT_NAME} PRIVATE
    unofficial::curlpp::curlpp
    fmt::fmt
)