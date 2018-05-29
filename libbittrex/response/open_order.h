#ifndef BITTREX_CPP_RES_OPEN_ORDER_H
#define BITTREX_CPP_RES_OPEN_ORDER_H

#include "../lib/json.hpp"
#include "../lib/primitive_wrapper.h"

using json=nlohmann::json;
using namespace bittrex::lib;

namespace bittrex {
    namespace response {
        struct OpenOrder {
            explicit OpenOrder(json j_order) {
                uuid = j_order["Uuid"];
                order_uuid = j_order["OrderUuid"];
                exchange = j_order["Exchange"];
                order_type = j_order["OrderType"];
                quantity = j_order["Quantity"];
                quantity_remaining = j_order["QuantityRemaining"];
                limit = j_order["Limit"];
                commission_paid = j_order["CommissionPaid"];
                price = j_order["Price"];
                price_per_unit = j_order["PricePerUnit"];
                opened = j_order["Opened"];
                closed = j_order["Closed"];
                cancel_initiated = j_order["CancelInitiated"];
                immediate_or_cancel = j_order["ImmediateOrCancel"];
                is_conditional = j_order["IsConditional"];
                condition = j_order["Condition"];
                condition_target = j_order["ConditionTarget"];
            };

            String uuid;
            String order_uuid;
            String exchange;
            String order_type;
            Double quantity;
            Double quantity_remaining;
            Double limit;
            Double commission_paid;
            Double price;
            String price_per_unit;
            String opened;
            String closed;
            bool cancel_initiated;
            bool immediate_or_cancel;
            bool is_conditional;
            String condition;
            String condition_target;

        };
    }
}
#endif //BITTREX_CPP_OPEN_ORDER_H
