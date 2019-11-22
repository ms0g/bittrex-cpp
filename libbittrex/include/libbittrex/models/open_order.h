#ifndef BITTREX_CPP_RES_OPEN_ORDER_H
#define BITTREX_CPP_RES_OPEN_ORDER_H

#include <json.hpp>
#include <libbittrex/lib/wrappers.h>

using json=nlohmann::json;
using namespace bittrex::lib;

namespace bittrex {
namespace model {

struct OpenOrder {
    explicit OpenOrder(json j) {
        uuid = j["Uuid"];
        order_uuid = j["OrderUuid"];
        exchange = j["Exchange"];
        order_type = j["OrderType"];
        quantity = j["Quantity"];
        quantity_remaining = j["QuantityRemaining"];
        limit = j["Limit"];
        commission_paid = j["CommissionPaid"];
        price = j["Price"];
        price_per_unit = j["PricePerUnit"];
        opened = j["Opened"];
        closed = j["Closed"];
        cancel_initiated = j["CancelInitiated"];
        immediate_or_cancel = j["ImmediateOrCancel"];
        is_conditional = j["IsConditional"];
        condition = j["Condition"];
        condition_target = j["ConditionTarget"];
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
} //Namespace model
} //Namespace bittrex
#endif //BITTREX_CPP_OPEN_ORDER_H
