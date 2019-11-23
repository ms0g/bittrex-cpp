cmake_minimum_required(VERSION 3.7)
project(bittrex)

set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE HEADERS "include/*")
file(GLOB_RECURSE SOURCES "src/*")
set(COMPILATION_UNIT ${HEADERS} ${SOURCES})

add_library(${PROJECT_NAME} STATIC ${COMPILATION_UNIT})
add_dependencies(${PROJECT_NAME} thirdparty)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/)
target_link_libraries(${PROJECT_NAME} ${CURL_LIBRARIES} ${OPENSSL_CRYPTO_LIBRARY})
INSTALL(TARGETS ${PROJECT_NAME} ARCHIVE DESTINATION lib
        )
INSTALL(
        DIRECTORY ${CMAKE_SOURCE_DIR}/libbittrex/include DESTINATION include
        PATTERN "*build*" EXCLUDE
)
