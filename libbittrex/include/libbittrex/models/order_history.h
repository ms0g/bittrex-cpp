#pragma once

#include <boost/property_tree/ptree.hpp>

namespace bittrex {
namespace model {

struct OrderHistoryEntry {
    explicit OrderHistoryEntry(boost::property_tree::ptree &j) {
        order_uuid = j.get<std::string>("OrderUuid");
        exchange = j.get<std::string>("Exchange");
        time_stamp = j.get<std::string>("TimeStamp");
        order_type = j.get<std::string>("OrderType");
        limit = j.get<std::string>("Limit");
        quantity = j.get<std::string>("Quantity");
        quantity_remaining = j.get<std::string>("QuantityRemaining");
        commission = j.get<std::string>("Commission");
        price = j.get<std::string>("Price");
        price_per_unit = j.get<std::string>("PricePerUnit");
        is_conditional = j.get<std::string>("IsConditional");
        condition = j.get<std::string>("Condition");
        condition_target = j.get<std::string>("ConditionTarget");
        immediate_or_cancel = j.get<std::string>("ImmediateOrCancel");

    }

    std::string order_uuid;
    std::string exchange;
    std::string time_stamp;
    std::string order_type;
    std::string limit;
    std::string quantity;
    std::string quantity_remaining;
    std::string commission;
    std::string price;
    std::string price_per_unit;
    std::string is_conditional;
    std::string condition;
    std::string condition_target;
    std::string immediate_or_cancel;

};
} //Namespace model
} //Namespace bittrex