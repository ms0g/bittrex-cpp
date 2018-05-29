cmake_minimum_required(VERSION 3.8)
project(bittrex)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        api/public.cpp api/public.h
        api/account.cpp api/account.h
        api/market.cpp api/market.h
        client.cpp client.h
        connection.cpp connection.h
        request.cpp request.h
        response/order_book.cpp response/order_book.h
        lib/utils.cpp lib/utils.h
        lib/libcurlpp.cpp lib/libcurlpp.h
        )

add_library(bittrex STATIC ${SOURCE_FILES})
target_link_libraries(bittrex curl crypto)
INSTALL(TARGETS bittrex
        ARCHIVE DESTINATION lib
        )
INSTALL (
        DIRECTORY ${CMAKE_SOURCE_DIR}
        DESTINATION include
        FILES_MATCHING PATTERN "*.h*"
        )
