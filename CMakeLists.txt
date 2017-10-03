cmake_minimum_required(VERSION 3.8)
project(bittrex)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        api/public.cpp api/public.h
        api/account.cpp api/account.h
        api/market.cpp api/market.h
        api/api_call.h
        api/exceptions.h
        client.cpp client.h
        connection.cpp connection.h
        request.cpp request.h
        response/market.h
        response/currency.h
        response/ticker.h
        response/market_summary.h
        response/market_history.h
        response/open_order.h
        response/balance.h
        response/deposit_address.h
        response/order.h
        response/order_history.h
        response/order_book.cpp response/order_book.h
        response/withdrawal_history.h)

add_library(bittrex STATIC ${SOURCE_FILES})
target_link_libraries(bittrex curlpp curl crypto)
INSTALL(TARGETS bittrex
        ARCHIVE DESTINATION lib
        )
INSTALL (
        DIRECTORY ${CMAKE_SOURCE_DIR}
        DESTINATION include
        FILES_MATCHING PATTERN "*.h*")
