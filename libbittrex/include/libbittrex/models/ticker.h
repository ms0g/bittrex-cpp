#pragma once

#include <string>
#include <boost/property_tree/ptree.hpp>

namespace bittrex::model {

struct Ticker {
    explicit Ticker(boost::property_tree::ptree &j) {
        bid = j.get<std::string>("Bid");
        ask = j.get<std::string>("Ask");
        last = j.get<std::string>("Last");
    }

    Ticker(const Ticker &other){
        bid = other.bid;
        ask = other.ask;
        last = other.last;
    }
    
    Ticker& operator=(const Ticker &other) noexcept {
        if (this != &other) {
            bid = other.bid;
            ask = other.ask;
            last = other.last;
        }
        return *this;
    }

    Ticker(Ticker &&other) noexcept {
        bid = std::move(other.bid);
        ask = std::move(other.ask);
        last = std::move(other.last);
    }

    Ticker& operator=(Ticker &&other) noexcept {
        if (this != &other) {
            bid = std::move(other.bid);
            ask = std::move(other.ask);
            last = std::move(other.last);
        }
        return *this;
    }

    std::string bid;
    std::string ask;
    std::string last;

};
} //Namespace bittrex
