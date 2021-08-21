#pragma once

#include <string>
#include <boost/property_tree/ptree.hpp>

namespace bittrex::model {

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

    OrderHistoryEntry(const OrderHistoryEntry &other) {
        order_uuid = other.order_uuid;
        exchange = other.exchange;
        time_stamp = other.time_stamp;
        order_type = other.order_type;
        limit = other.limit;
        quantity = other.quantity;
        quantity_remaining = other.quantity_remaining;
        commission = other.commission;
        price = other.price;
        price_per_unit = other.price_per_unit;
        is_conditional = other.is_conditional;
        condition = other.condition;
        condition_target = other.condition_target;
        immediate_or_cancel = other.immediate_or_cancel;
    }

    OrderHistoryEntry &operator=(const OrderHistoryEntry &other) noexcept {
        if (this == &other) {
            order_uuid = other.order_uuid;
            exchange = other.exchange;
            time_stamp = other.time_stamp;
            order_type = other.order_type;
            limit = other.limit;
            quantity = other.quantity;
            quantity_remaining = other.quantity_remaining;
            commission = other.commission;
            price = other.price;
            price_per_unit = other.price_per_unit;
            is_conditional = other.is_conditional;
            condition = other.condition;
            condition_target = other.condition_target;
            immediate_or_cancel = other.immediate_or_cancel;
        }
        return *this;
    }

    OrderHistoryEntry(OrderHistoryEntry &&other) noexcept {
        order_uuid = std::move(other.order_uuid);
        exchange = std::move(other.exchange);
        time_stamp = std::move(other.time_stamp);
        order_type = std::move(other.order_type);
        limit = std::move(other.limit);
        quantity = std::move(other.quantity);
        quantity_remaining = std::move(other.quantity_remaining);
        commission = std::move(other.commission);
        price = std::move(other.price);
        price_per_unit = std::move(other.price_per_unit);
        is_conditional = std::move(other.is_conditional);
        condition = std::move(other.condition);
        condition_target = std::move(other.condition_target);
        immediate_or_cancel = std::move(other.immediate_or_cancel);
    }

    OrderHistoryEntry &operator=(OrderHistoryEntry &&other) noexcept {
        if (this == &other) {
            order_uuid = std::move(other.order_uuid);
            exchange = std::move(other.exchange);
            time_stamp = std::move(other.time_stamp);
            order_type = std::move(other.order_type);
            limit = std::move(other.limit);
            quantity = std::move(other.quantity);
            quantity_remaining = std::move(other.quantity_remaining);
            commission = std::move(other.commission);
            price = std::move(other.price);
            price_per_unit = std::move(other.price_per_unit);
            is_conditional = std::move(other.is_conditional);
            condition = std::move(other.condition);
            condition_target = std::move(other.condition_target);
            immediate_or_cancel = std::move(other.immediate_or_cancel);
        }
        return *this;
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
} //Namespace bittrex
