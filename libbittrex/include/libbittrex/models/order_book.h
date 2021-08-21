#pragma once

#include <string>
#include <vector>
#include <boost/foreach.hpp>
#include <boost/property_tree/ptree.hpp>


namespace bittrex::model {

struct OrderBookEntry {
    explicit OrderBookEntry(boost::property_tree::ptree &j) {
        quantity = j.get<std::string>("Quantity");
        rate = j.get<std::string>("Rate");
    }

    OrderBookEntry(const OrderBookEntry &other) {
        quantity = other.quantity;
        rate = other.rate;
    }

    OrderBookEntry &operator=(const OrderBookEntry &other) noexcept {
        if (this != &other) {
            quantity = other.quantity;
            rate = other.rate;
        }
        return *this;
    }

    OrderBookEntry(OrderBookEntry &&other) noexcept {
        quantity = std::move(other.quantity);
        rate = std::move(other.rate);
    }

    OrderBookEntry &operator=(OrderBookEntry &&other) noexcept {
        if (this != &other) {
            quantity = std::move(other.quantity);
            rate = std::move(other.rate);
        }
        return *this;
    }

    std::string quantity;
    std::string rate;

};

struct OrderBook {
    explicit OrderBook(boost::property_tree::ptree &j) {

        auto foreach_on = [&](std::vector<OrderBookEntry> &vec, const char *node) {
            BOOST_FOREACH(boost::property_tree::ptree::value_type &child,
                          j.get_child(node)) {
                            vec.emplace_back(OrderBookEntry(child.second));
                        }

        };

        foreach_on(buy, "buy");
        foreach_on(sell, "sell");
    }

    std::vector<OrderBookEntry> buy;
    std::vector<OrderBookEntry> sell;

};
} //Namespace bittrex
