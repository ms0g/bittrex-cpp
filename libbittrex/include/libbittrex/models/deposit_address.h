#pragma once

#include <boost/property_tree/ptree.hpp>

namespace bittrex::model {

struct DepositAddress {
    explicit DepositAddress(boost::property_tree::ptree &j) {
        currency = j.get<std::string>("Currency");
        address = j.get<std::string>("Address");
    };

    std::string currency;
    std::string address;

};
} //Namespace bittrex
