#pragma once

#include <string>
#include <boost/property_tree/ptree.hpp>

namespace bittrex::model {

struct Uuid {
    explicit Uuid(boost::property_tree::ptree &j) {
        uuid = j.get<std::string>("uuid");

    }

    Uuid(const Uuid &other) {
        uuid = other.uuid;
    }

    Uuid &operator=(const Uuid &other) noexcept {
        if (this != &other) {
            uuid = other.uuid;
        }
        return *this;
    }

    Uuid(Uuid &&other) noexcept {
        uuid = std::move(other.uuid);
    }

    Uuid &operator=(Uuid &&other) noexcept {
        if (this != &other) {
            uuid = std::move(other.uuid);
        }
        return *this;
    }

    std::string uuid;

};
} //Namespace bittrex
