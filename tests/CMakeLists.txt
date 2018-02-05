cmake_minimum_required(VERSION 3.8)
project(bittrex_cpp)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        bittrex_api_test.cpp)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(bittrex_api_test ${SOURCE_FILES})

target_link_libraries(bittrex_api_test bittrex curl crypto
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})