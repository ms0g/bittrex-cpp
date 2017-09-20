#include "order_book.h"

using namespace bittrex::response;

OrderBookEntry::OrderBookEntry(json j) {
    quantity = j["Quantity"];
    rate = j["Rate"];
}

OrderBook::OrderBook(json o_book, const string &type) {
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
