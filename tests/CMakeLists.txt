cmake_minimum_required(VERSION 3.8)
project(bittrex_cpp)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        main.cpp)

add_executable(main ${SOURCE_FILES})

target_link_libraries(main ${CMAKE_SOURCE_DIR}/libbittrex.a libcurlpp.a curl crypto)