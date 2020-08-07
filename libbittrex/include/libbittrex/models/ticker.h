#pragma once

#include <boost/property_tree/ptree.hpp>

namespace bittrex::model {

struct Ticker {
    explicit Ticker(boost::property_tree::ptree &j) {
        bid = j.get<std::string>("Bid");
        ask = j.get<std::string>("Ask");
        last = j.get<std::string>("Last");
    };

    std::string bid;
    std::string ask;
    std::string last;

};
} //Namespace bittrex
