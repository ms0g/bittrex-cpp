cmake_minimum_required(VERSION 3.7)

project(bittrex)

if (UNIX AND NOT APPLE)
    FIND_PACKAGE(OpenSSL REQUIRED)
    if (OPENSSL_FOUND)
        INCLUDE_DIRECTORIES(${OPENSSL_INCLUDE_DIR})
    else ()
        message("Could not find the OpenSSL library")
    endif ()
endif()

FIND_PACKAGE(CURL REQUIRED)
if (CURL_FOUND)
    INCLUDE_DIRECTORIES(${CURL_INCLUDE_DIR})
else ()
    message("Could not find the libCURL library")
endif ()

FIND_PACKAGE(Boost REQUIRED)
if (Boost_FOUND)
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
else ()
    message("Could not find the Boost library")
endif ()

file(GLOB_RECURSE HEADERS "include/*")
file(GLOB_RECURSE SOURCES "src/*")
set(COMPILATION_UNIT ${HEADERS} ${SOURCES})

add_library(${PROJECT_NAME} STATIC ${COMPILATION_UNIT})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/)

# For boost header only libraries
target_link_libraries(${PROJECT_NAME} Boost::boost)

if (UNIX AND NOT APPLE)
    target_link_libraries(${PROJECT_NAME} ${CURL_LIBRARIES} ${OPENSSL_CRYPTO_LIBRARY})
else ()
    target_link_libraries(${PROJECT_NAME} ${CURL_LIBRARIES})
endif ()

INSTALL(TARGETS ${PROJECT_NAME} ARCHIVE DESTINATION lib
        )
INSTALL(
        DIRECTORY ${CMAKE_SOURCE_DIR}/libbittrex/include DESTINATION include
        PATTERN "*build*" EXCLUDE
)
