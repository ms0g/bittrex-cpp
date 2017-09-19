cmake_minimum_required(VERSION 3.8)
project(bittrex_cpp)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES api/public.cpp api/public.h
        api/account.cpp api/account.h
        api/market.cpp api/market.h
        client.cpp client.h
        connection.cpp connection.h
        request.cpp request.h
        tests/main.cpp
        response/market.cpp response/market.h
        api/exceptions.h response/currency.cpp response/currency.h response/ticker.cpp response/ticker.h response/market_summary.cpp response/market_summary.h response/order_book.cpp response/order_book.h response/market_history.cpp response/market_history.h)
##add_library(bittrex_cpp ${SOURCE_FILES})
add_executable(bittrex_cpp ${SOURCE_FILES})

target_link_libraries(bittrex_cpp libcurlpp.a curl)