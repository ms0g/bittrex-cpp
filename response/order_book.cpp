#include "order_book.h"

using namespace bittrex::response;

OrderBookEntry::OrderBookEntry(json j) {
    quantity = j["Quantity"];
    rate = j["Rate"];
}

OrderBook::OrderBook(json o_book, string type) {
    for (json::iterator it = o_book.begin(); it != o_book.end(); ++it) {
        if (type == "both") {
            if (it.key() == "buy") {
                for (auto &el:it.value())
                    buy.emplace_back(el);
            } else {
                for (auto &el:it.value())
                    sell.emplace_back(el);
            }
        } else {
            if (type == "buy")
                buy.emplace_back(it.value());
            else
                sell.emplace_back(it.value());
        }

    }

}
