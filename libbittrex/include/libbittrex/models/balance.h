#pragma once

#include <boost/property_tree/ptree.hpp>

namespace bittrex::model {

struct Balance {
    explicit Balance(boost::property_tree::ptree &j) {
        currency = j.get<std::string>("Currency");
        balance = j.get<std::string>("Balance");
        available = j.get<std::string>("Available");
        pending = j.get<std::string>("Pending");
        crypto_address = j.get<std::string>("CryptoAddress");
        requested = j.get<std::string>("Requested");
        uuid = j.get<std::string>("Uuid");
    };

    std::string currency;
    std::string balance;
    std::string available;
    std::string pending;
    std::string crypto_address;
    std::string requested;
    std::string uuid;

};
} //Namespace bittrex::model
