#pragma once

#include <string>
#include <boost/property_tree/ptree.hpp>

namespace bittrex::model {

struct OpenOrder {
    explicit OpenOrder(boost::property_tree::ptree &j) {
        uuid = j.get<std::string>("Uuid");
        order_uuid = j.get<std::string>("OrderUuid");
        exchange = j.get<std::string>("Exchange");
        order_type = j.get<std::string>("OrderType");
        quantity = j.get<std::string>("Quantity");
        quantity_remaining = j.get<std::string>("QuantityRemaining");
        limit = j.get<std::string>("Limit");
        commission_paid = j.get<std::string>("CommissionPaid");
        price = j.get<std::string>("Price");
        price_per_unit = j.get<std::string>("PricePerUnit");
        opened = j.get<std::string>("Opened");
        closed = j.get<std::string>("Closed");
        cancel_initiated = j.get<std::string>("CancelInitiated");
        immediate_or_cancel = j.get<std::string>("ImmediateOrCancel");
        is_conditional = j.get<std::string>("IsConditional");
        condition = j.get<std::string>("Condition");
        condition_target = j.get<std::string>("ConditionTarget");
    }

    OpenOrder(const OpenOrder &other) {
        uuid = other.uuid;
        order_uuid = other.order_uuid;
        exchange = other.exchange;
        order_type = other.order_type;
        quantity = other.quantity;
        quantity_remaining = other.quantity_remaining;
        limit = other.limit;
        commission_paid = other.commission_paid;
        price = other.price;
        price_per_unit = other.price_per_unit;
        opened = other.opened;
        closed = other.closed;
        cancel_initiated = other.cancel_initiated;
        immediate_or_cancel = other.immediate_or_cancel;
        is_conditional = other.is_conditional;
        condition = other.condition;
        condition_target = other.condition_target;
    }

    OpenOrder &operator=(const OpenOrder &other) noexcept {
        if (this != &other) {
            uuid = other.uuid;
            order_uuid = other.order_uuid;
            exchange = other.exchange;
            order_type = other.order_type;
            quantity = other.quantity;
            quantity_remaining = other.quantity_remaining;
            limit = other.limit;
            commission_paid = other.commission_paid;
            price = other.price;
            price_per_unit = other.price_per_unit;
            opened = other.opened;
            closed = other.closed;
            cancel_initiated = other.cancel_initiated;
            immediate_or_cancel = other.immediate_or_cancel;
            is_conditional = other.is_conditional;
            condition = other.condition;
            condition_target = other.condition_target;
        }
        return *this;
    }

    OpenOrder(OpenOrder &&other) noexcept {
        uuid = std::move(other.uuid);
        order_uuid = std::move(other.order_uuid);
        exchange = std::move(other.exchange);
        order_type = std::move(other.order_type);
        quantity = std::move(other.quantity);
        quantity_remaining = std::move(other.quantity_remaining);
        limit = std::move(other.limit);
        commission_paid = std::move(other.commission_paid);
        price = std::move(other.price);
        price_per_unit = std::move(other.price_per_unit);
        opened = std::move(other.opened);
        closed = std::move(other.closed);
        cancel_initiated = std::move(other.cancel_initiated);
        immediate_or_cancel = std::move(other.immediate_or_cancel);
        is_conditional = std::move(other.is_conditional);
        condition = std::move(other.condition);
        condition_target = std::move(other.condition_target);
    }

    OpenOrder &operator=(OpenOrder &&other) noexcept {
        if (this != &other) {
            uuid = std::move(other.uuid);
            order_uuid = std::move(other.order_uuid);
            exchange = std::move(other.exchange);
            order_type = std::move(other.order_type);
            quantity = std::move(other.quantity);
            quantity_remaining = std::move(other.quantity_remaining);
            limit = std::move(other.limit);
            commission_paid = std::move(other.commission_paid);
            price = std::move(other.price);
            price_per_unit = std::move(other.price_per_unit);
            opened = std::move(other.opened);
            closed = std::move(other.closed);
            cancel_initiated = std::move(other.cancel_initiated);
            immediate_or_cancel = std::move(other.immediate_or_cancel);
            is_conditional = std::move(other.is_conditional);
            condition = std::move(other.condition);
            condition_target = std::move(other.condition_target);
        }
        return *this;
    }

    std::string uuid;
    std::string order_uuid;
    std::string exchange;
    std::string order_type;
    std::string quantity;
    std::string quantity_remaining;
    std::string limit;
    std::string commission_paid;
    std::string price;
    std::string price_per_unit;
    std::string opened;
    std::string closed;
    std::string cancel_initiated;
    std::string immediate_or_cancel;
    std::string is_conditional;
    std::string condition;
    std::string condition_target;

};
} //Namespace bittrex
