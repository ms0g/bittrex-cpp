#pragma once

#include <boost/property_tree/ptree.hpp>

namespace bittrex::model {

struct Uuid {
    explicit Uuid(boost::property_tree::ptree &j) {
        uuid = j.get<std::string>("uuid");

    };

    std::string uuid;

};
} //Namespace bittrex
