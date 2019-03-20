cmake_minimum_required(VERSION 3.7)
project(bittrex)

set(CMAKE_CXX_STANDARD 14)

FIND_PACKAGE(OpenSSL REQUIRED)
if (OPENSSL_FOUND)
    INCLUDE_DIRECTORIES(${OPENSSL_INCLUDE_DIR})
else ()
    message("Could not find the OpenSSL library")
endif ()

FIND_PACKAGE(CURL REQUIRED)
if (CURL_FOUND)
    INCLUDE_DIRECTORIES(${CURL_INCLUDE_DIR})
else ()
    message("Could not find the libCURL library")
endif ()

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
target_link_libraries(bittrex ${CURL_LIBRARIES} ${OPENSSL_CRYPTO_LIBRARY})
INSTALL(TARGETS bittrex ARCHIVE DESTINATION lib
        )
INSTALL(
        DIRECTORY ${CMAKE_SOURCE_DIR} DESTINATION include
        FILES_MATCHING PATTERN "*.h*"
        PATTERN "*build*" EXCLUDE
)
