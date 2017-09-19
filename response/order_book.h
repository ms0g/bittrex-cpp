

#ifndef BITTREX_CPP_RES_ORDER_BOOK_H
#define BITTREX_CPP_RES_ORDER_BOOK_H

#include <iostream>
#include <memory>
#include "../libs/json/json.hpp"

using json=nlohmann::json;
using namespace std;

namespace bittrex {
    namespace response {
        struct OrderBookEntry {
            explicit OrderBookEntry(json j);

            float quantity;
            float rate;

        };

        struct OrderBook {
            OrderBook(json o_book, string type);

            vector<OrderBookEntry> buy;
            vector<OrderBookEntry> sell;

        };
    }
}

#endif //BITTREX_CPP_ORDER_BOOK_H
