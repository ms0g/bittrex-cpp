#ifndef BITTREX_CPP_RES_ORDER_BOOK_H
#define BITTREX_CPP_RES_ORDER_BOOK_H

#include <iostream>
#include <memory>
#include "../lib/json.hpp"
#include "../lib/utils.h"

using json=nlohmann::json;
using namespace bittrex::lib;

namespace bittrex {
    namespace response {
        struct OrderBookEntry {
            explicit OrderBookEntry(json j){
                quantity = j["Quantity"];
                rate = j["Rate"];
            };

            Double quantity;
            Double rate;

        };

        struct OrderBook {
            OrderBook(json o_book, const std::string &type);

            List<OrderBookEntry> buy;
            List<OrderBookEntry> sell;

        };
    }
}

#endif //BITTREX_CPP_ORDER_BOOK_H
