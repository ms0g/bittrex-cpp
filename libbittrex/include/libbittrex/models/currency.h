#pragma once

#include <string>
#include <boost/property_tree/ptree.hpp>

namespace bittrex::model {

struct Currency {
    explicit Currency(boost::property_tree::ptree &j) {
        currency = j.get<std::string>("Currency");
        currency_long = j.get<std::string>("CurrencyLong");
        min_confirmation = j.get<std::string>("MinConfirmation");
        txfee = j.get<std::string>("TxFee");
        is_active = j.get<std::string>("IsActive");
        coin_type = j.get<std::string>("CoinType");
        base_address = j.get<std::string>("BaseAddress");
    }

    Currency(const Currency &other) {
        currency = other.currency;
        currency_long = other.currency_long;
        min_confirmation = other.min_confirmation;
        txfee = other.txfee;
        is_active = other.is_active;
        coin_type = other.coin_type;
        base_address = other.base_address;
    }

    Currency &operator=(const Currency &other) noexcept {
        if (this != &other) {
            currency = other.currency;
            currency_long = other.currency_long;
            min_confirmation = other.min_confirmation;
            txfee = other.txfee;
            is_active = other.is_active;
            coin_type = other.coin_type;
            base_address = other.base_address;
        }
        return *this;
    }

    Currency(Currency &&other) noexcept {
        currency = std::move(other.currency);
        currency_long = std::move(other.currency_long);
        min_confirmation = std::move(other.min_confirmation);
        txfee = std::move(other.txfee);
        is_active = std::move(other.is_active);
        coin_type = std::move(other.coin_type);
        base_address = std::move(other.base_address);
    }

    Currency &operator=(Currency &&other) noexcept {
        if (this != &other) {
            currency = std::move(other.currency);
            currency_long = std::move(other.currency_long);
            min_confirmation = std::move(other.min_confirmation);
            txfee = std::move(other.txfee);
            is_active = std::move(other.is_active);
            coin_type = std::move(other.coin_type);
            base_address = std::move(other.base_address);
        }
        return *this;
    }

    std::string currency;
    std::string currency_long;
    std::string min_confirmation;
    std::string txfee;
    std::string is_active;
    std::string coin_type;
    std::string base_address;

};
} //Namespace bittrex
