cmake_minimum_required(VERSION 3.5)
project(bittrex_cpp)

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
        tests/main.cpp
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
##add_library(bittrex_cpp ${SOURCE_FILES})
add_executable(bittrex_cpp ${SOURCE_FILES})

target_link_libraries(bittrex_cpp libcurlpp.a curl crypto)