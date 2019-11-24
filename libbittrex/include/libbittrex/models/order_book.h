#ifndef BITTREX_CPP_RES_ORDER_BOOK_H
#define BITTREX_CPP_RES_ORDER_BOOK_H

#include <vector>
#include <boost/foreach.hpp>
#include <boost/property_tree/ptree.hpp>


namespace bittrex {
namespace model {

struct OrderBookEntry {
    explicit OrderBookEntry(boost::property_tree::ptree &j) {
        quantity = j.get<std::string>("Quantity");
        rate = j.get<std::string>("Rate");
    };

    std::string quantity;
    std::string rate;

};

struct OrderBook {
    explicit OrderBook(boost::property_tree::ptree &j) {

        BOOST_FOREACH(boost::property_tree::ptree::value_type &child,
                      j.get_child("buy")) {
                        buy.emplace_back(OrderBookEntry(child.second));
                    }

        BOOST_FOREACH(boost::property_tree::ptree::value_type &child,
                      j.get_child("sell")) {
                        sell.emplace_back(OrderBookEntry(child.second));
                    }


    }

    std::vector<OrderBookEntry> buy;
    std::vector<OrderBookEntry> sell;

};
} //Namespace model
} //Namespace bittrex

#endif //BITTREX_CPP_ORDER_BOOK_H
