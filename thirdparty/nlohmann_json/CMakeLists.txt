cmake_minimum_required(VERSION 3.7)

project(nlohmann_json CXX)


add_library(nlohmann_json INTERFACE)

target_include_directories(nlohmann_json INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include/)