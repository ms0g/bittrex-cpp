#pragma once

#include <string>
#include <boost/property_tree/ptree.hpp>

namespace bittrex::model {

struct Order {
    explicit Order(boost::property_tree::ptree &j) {
        account_id = j.get<std::string>("AccountId");
        order_uuid = j.get<std::string>("OrderUuid");
        exchange = j.get<std::string>("Exchange");
        type = j.get<std::string>("Type");
        quantity = j.get<std::string>("Quantity");
        quantity_remaining = j.get<std::string>("QuantityRemaining");
        limit = j.get<std::string>("Limit");
        reserved = j.get<std::string>("Reserved");
        reserve_remaining = j.get<std::string>("ReserveRemaining");
        commission_reserved = j.get<std::string>("CommissionReserved");
        commission_reserve_remaining = j.get<std::string>("CommissionReserveRemaining");
        commission_paid = j.get<std::string>("CommissionPaid");
        price = j.get<std::string>("Price");
        price_per_unit = j.get<std::string>("PricePerUnit");
        opened = j.get<std::string>("Opened");
        closed = j.get<std::string>("Closed");
        is_open = j.get<std::string>("IsOpen");
        sentinel = j.get<std::string>("Sentinel");
        cancel_initiated = j.get<std::string>("CancelInitiated");
        immediate_or_cancel = j.get<std::string>("ImmediateOrCancel");
        is_conditional = j.get<std::string>("IsConditional");
        condition = j.get<std::string>("Condition");
        condition_target = j.get<std::string>("ConditionTarget");
    }

    Order(const Order &other) {
        account_id = other.account_id;
        order_uuid = other.order_uuid;
        exchange = other.exchange;
        type = other.type;
        quantity = other.quantity;
        quantity_remaining = other.quantity_remaining;
        limit = other.limit;
        reserved = other.reserved;
        reserve_remaining = other.reserve_remaining;
        commission_reserved = other.commission_reserved;
        commission_reserve_remaining = other.commission_reserve_remaining;
        commission_paid = other.commission_paid;
        price = other.price;
        price_per_unit = other.price_per_unit;
        opened = other.opened;
        closed = other.closed;
        is_open = other.is_open;
        sentinel = other.sentinel;
        cancel_initiated = other.cancel_initiated;
        immediate_or_cancel = other.immediate_or_cancel;
        is_conditional = other.is_conditional;
        condition = other.condition;
        condition_target = other.condition_target;
    }

    Order &operator=(const Order &other) noexcept {
        if (this != &other) {
            account_id = other.account_id;
            order_uuid = other.order_uuid;
            exchange = other.exchange;
            type = other.type;
            quantity = other.quantity;
            quantity_remaining = other.quantity_remaining;
            limit = other.limit;
            reserved = other.reserved;
            reserve_remaining = other.reserve_remaining;
            commission_reserved = other.commission_reserved;
            commission_reserve_remaining = other.commission_reserve_remaining;
            commission_paid = other.commission_paid;
            price = other.price;
            price_per_unit = other.price_per_unit;
            opened = other.opened;
            closed = other.closed;
            is_open = other.is_open;
            sentinel = other.sentinel;
            cancel_initiated = other.cancel_initiated;
            immediate_or_cancel = other.immediate_or_cancel;
            is_conditional = other.is_conditional;
            condition = other.condition;
            condition_target = other.condition_target;
        }
        return *this;
    }

    Order(Order &&other) noexcept {
        account_id = std::move(other.account_id);
        order_uuid = std::move(other.order_uuid);
        exchange = std::move(other.exchange);
        type = std::move(other.type);
        quantity = std::move(other.quantity);
        quantity_remaining = std::move(other.quantity_remaining);
        limit = std::move(other.limit);
        reserved = std::move(other.reserved);
        reserve_remaining = std::move(other.reserve_remaining);
        commission_reserved = std::move(other.commission_reserved);
        commission_reserve_remaining = std::move(other.commission_reserve_remaining);
        commission_paid = std::move(other.commission_paid);
        price = std::move(other.price);
        price_per_unit = std::move(other.price_per_unit);
        opened = std::move(other.opened);
        closed = std::move(other.closed);
        is_open = std::move(other.is_open);
        sentinel = std::move(other.sentinel);
        cancel_initiated = std::move(other.cancel_initiated);
        immediate_or_cancel = std::move(other.immediate_or_cancel);
        is_conditional = std::move(other.is_conditional);
        condition = std::move(other.condition);
        condition_target = std::move(other.condition_target);
    }

    Order &operator=(Order &&other) noexcept {
        if (this != &other) {
            account_id = std::move(other.account_id);
            order_uuid = std::move(other.order_uuid);
            exchange = std::move(other.exchange);
            type = std::move(other.type);
            quantity = std::move(other.quantity);
            quantity_remaining = std::move(other.quantity_remaining);
            limit = std::move(other.limit);
            reserved = std::move(other.reserved);
            reserve_remaining = std::move(other.reserve_remaining);
            commission_reserved = std::move(other.commission_reserved);
            commission_reserve_remaining = std::move(other.commission_reserve_remaining);
            commission_paid = std::move(other.commission_paid);
            price = std::move(other.price);
            price_per_unit = std::move(other.price_per_unit);
            opened = std::move(other.opened);
            closed = std::move(other.closed);
            is_open = std::move(other.is_open);
            sentinel = std::move(other.sentinel);
            cancel_initiated = std::move(other.cancel_initiated);
            immediate_or_cancel = std::move(other.immediate_or_cancel);
            is_conditional = std::move(other.is_conditional);
            condition = std::move(other.condition);
            condition_target = std::move(other.condition_target);
        }
        return *this;
    }

    std::string account_id;
    std::string order_uuid;
    std::string exchange;
    std::string type;
    std::string quantity;
    std::string quantity_remaining;
    std::string limit;
    std::string reserved;
    std::string reserve_remaining;
    std::string commission_reserved;
    std::string commission_reserve_remaining;
    std::string commission_paid;
    std::string price;
    std::string price_per_unit;
    std::string opened;
    std::string closed;
    std::string is_open;
    std::string sentinel;
    std::string cancel_initiated;
    std::string immediate_or_cancel;
    std::string is_conditional;
    std::string condition;
    std::string condition_target;

};
} //Namespace bittrex
