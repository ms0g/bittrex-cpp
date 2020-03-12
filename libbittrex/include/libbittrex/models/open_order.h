#ifndef BITTREX_CPP_RES_OPEN_ORDER_H
#define BITTREX_CPP_RES_OPEN_ORDER_H

#include <boost/property_tree/ptree.hpp>


namespace bittrex {
    namespace model {

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
            };

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
    } //Namespace model
} //Namespace bittrex
#endif //BITTREX_CPP_OPEN_ORDER_H
