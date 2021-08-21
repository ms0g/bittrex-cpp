#pragma once

#include <string>
#include <boost/property_tree/ptree.hpp>

namespace bittrex::model {

struct DepositAddress {
    explicit DepositAddress(boost::property_tree::ptree &j) {
        currency = j.get<std::string>("Currency");
        address = j.get<std::string>("Address");
    }

    DepositAddress(const DepositAddress &other) {
        currency = other.currency;
        address = other.address;
    }

    DepositAddress &operator=(const DepositAddress &other) noexcept {
        if (this != &other) {
            currency = other.currency;
            address = other.address;
        }
        return *this;
    }

    DepositAddress(DepositAddress &&other) noexcept {
        currency = std::move(other.currency);
        address = std::move(other.address);
    }

    DepositAddress &operator=(DepositAddress &&other) noexcept {
        if (this != &other) {
            currency = std::move(other.currency);
            address = std::move(other.address);
        }   
        return *this;   
    }

    std::string currency;
    std::string address;

};
} //Namespace bittrex
