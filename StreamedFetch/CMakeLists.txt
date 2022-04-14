cmake_minimum_required(VERSION 3.0.0)
project("StreamedFetch")
set(CMAKE_INCLUDE_CURRENT_DIR on)
set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
    "src/StreamedFetch/Test.cpp"
)

set(HEADER_FILES
    "src/StreamedFetch/Test.hpp"
)

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES} ${HEADER_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")