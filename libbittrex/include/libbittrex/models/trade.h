#pragma once

#include <string>
#include <boost/property_tree/ptree.hpp>

namespace bittrex::model {

struct Trade {
    explicit Trade(boost::property_tree::ptree &j) {
        id = j.get<std::string>("Id");
        time_stamp = j.get<std::string>("TimeStamp");
        quantity = j.get<std::string>("Quantity");
        price = j.get<std::string>("Price");
        total = j.get<std::string>("Total");
        fill_type = j.get<std::string>("FillType");
        order_type = j.get<std::string>("OrderType");
    }

    Trade(const Trade &other) {
        id = other.id;
        time_stamp = other.time_stamp;
        quantity = other.quantity;
        price = other.price;
        total = other.total;
        fill_type = other.fill_type;
        order_type = other.order_type;
    }

    Trade &operator=(const Trade &other) noexcept {
        if (this != &other) {
            id = other.id;
            time_stamp = other.time_stamp;
            quantity = other.quantity;
            price = other.price;
            total = other.total;
            fill_type = other.fill_type;
            order_type = other.order_type;
        }
        return *this;
    }

    Trade(Trade &&other) noexcept {
        id = std::move(other.id);
        time_stamp = std::move(other.time_stamp);
        quantity = std::move(other.quantity);
        price = std::move(other.price);
        total = std::move(other.total);
        fill_type = std::move(other.fill_type);
        order_type = std::move(other.order_type);
    }

    Trade &operator=(Trade &&other) noexcept {
        if (this != &other) {
            id = std::move(other.id);
            time_stamp = std::move(other.time_stamp);
            quantity = std::move(other.quantity);
            price = std::move(other.price);
            total = std::move(other.total);
            fill_type = std::move(other.fill_type);
            order_type = std::move(other.order_type);
        }
        return *this;
    }

    std::string id;
    std::string time_stamp;
    std::string quantity;
    std::string price;
    std::string total;
    std::string fill_type;
    std::string order_type;
};
} //Namespace bittrex
