cmake_minimum_required(VERSION 3.7)
project(bittrex_api_test)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        bittrex_api_test.cpp)

add_executable(bittrex_api_test ${SOURCE_FILES})

target_include_directories(bittrex_api_test PUBLIC ${CMAKE_SOURCE_DIR}/)

target_link_libraries(bittrex_api_test PRIVATE
        bittrex
        pthread
        ${Boost_LIBRARIES})

add_test(NAME bittrex_api_test
        COMMAND bittrex_api_test --report_level=detailed)

