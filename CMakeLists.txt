cmake_minimum_required(VERSION 3.7)
project(bittrex_cpp)
enable_testing()
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(libbittrex)
add_subdirectory(tests)
