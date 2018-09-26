cmake_minimum_required(VERSION 3.8)
project(bittrex)

set(CMAKE_CXX_STANDARD 14)

file(GLOB SOURCE_FILES
        "*.h"
        "*.cpp"
        "api/*.h"
        "api/*.cpp"
        "response/*.h"
        "response/*.cpp"
        "lib/*.h"
        "lib/*.cpp")

add_library(bittrex STATIC ${SOURCE_FILES})
target_link_libraries(bittrex curl crypto)
INSTALL(TARGETS bittrex
        ARCHIVE DESTINATION lib
        )
INSTALL (
        DIRECTORY ${CMAKE_SOURCE_DIR} DESTINATION include
        FILES_MATCHING PATTERN "*.h*"
        PATTERN "*build*" EXCLUDE
        )
