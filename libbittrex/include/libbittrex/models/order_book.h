#ifndef BITTREX_CPP_RES_ORDER_BOOK_H
#define BITTREX_CPP_RES_ORDER_BOOK_H

#include <json.hpp>
#include <libbittrex/lib/utils.h>
#include <libbittrex/lib/wrappers.h>

using json=nlohmann::json;
using namespace bittrex::lib;

namespace bittrex {
namespace model {

struct OrderBookEntry {
    explicit OrderBookEntry(json j) {
        quantity = j["Quantity"];
        rate = j["Rate"];
    };

    Double quantity;
    Double rate;

};

struct OrderBook {
    OrderBook(json o_book, const std::string &type) {
        for (json::iterator it = o_book.begin(); it != o_book.end(); ++it) {
            if (type == "both") {
                if (it.key() == "buy") {
                    for (auto &el:it.value())
                        buy.emplace_back(OrderBookEntry(el));
                } else {
                    for (auto &el:it.value())
                        sell.emplace_back(OrderBookEntry(el));
                }
            } else {
                if (type == "buy")
                    buy.emplace_back(OrderBookEntry(it.value()));
                else
                    sell.emplace_back(OrderBookEntry(it.value()));
            }

        }

    }

    std::vector<OrderBookEntry> buy;
    std::vector<OrderBookEntry> sell;

};
} //Namespace model
} //Namespace bittrex

#endif //BITTREX_CPP_ORDER_BOOK_H
