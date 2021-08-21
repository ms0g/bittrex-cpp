#pragma once

#include <string>
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
    }

    Balance(const Balance &other) {
        currency = other.currency;
        balance = other.balance;
        available = other.available;
        pending = other.pending;
        crypto_address = other.crypto_address;
        requested = other.requested;
        uuid = other.uuid;

    }

    Balance &operator=(const Balance &other) noexcept {
        if (this != &other) {
            currency = other.currency;
            balance = other.balance;
            available = other.available;
            pending = other.pending;
            crypto_address = other.crypto_address;
            requested = other.requested;
            uuid = other.uuid;
        }
        return *this;
    }

    Balance (Balance &&other) noexcept {
        currency = std::move(other.currency);
        balance = std::move(other.balance);
        available = std::move(other.available);
        pending = std::move(other.pending);
        crypto_address = std::move(other.crypto_address);
        requested = std::move(other.requested);
        uuid = std::move(other.uuid);
    }

    Balance &operator=(Balance &&other) noexcept {
        if (this != &other) {
            currency = std::move(other.currency);
            balance = std::move(other.balance);
            available = std::move(other.available);
            pending = std::move(other.pending);
            crypto_address = std::move(other.crypto_address);
            requested = std::move(other.requested);
            uuid = std::move(other.uuid);
        }
        return *this;
    }

    std::string currency;
    std::string balance;
    std::string available;
    std::string pending;
    std::string crypto_address;
    std::string requested;
    std::string uuid;

};
} //Namespace bittrex::model
