#ifndef BITTREX_CPP_RES_ORDER_HISTORY_ENTRY_H
#define BITTREX_CPP_RES_ORDER_HISTORY_ENTRY_H

#include "../lib/json.hpp"
#include "../lib/wrappers.h"

using json=nlohmann::json;
using namespace bittrex::lib;

namespace bittrex {
namespace response {

struct OrderHistoryEntry {
    explicit OrderHistoryEntry(json j_order_ent) {
        order_uuid = j_order_ent["OrderUuid"];
        exchange = j_order_ent["Exchange"];
        time_stamp = j_order_ent["TimeStamp"];
        order_type = j_order_ent["OrderType"];
        limit = j_order_ent["Limit"];
        quantity = j_order_ent["Quantity"];
        quantity_remaining = j_order_ent["QuantityRemaining"];
        commission = j_order_ent["Commission"];
        price = j_order_ent["Price"];
        price_per_unit = j_order_ent["PricePerUnit"];
        is_conditional = j_order_ent["IsConditional"];
        condition = j_order_ent["Condition"];
        condition_target = j_order_ent["ConditionTarget"];
        immediate_or_cancel = j_order_ent["ImmediateOrCancel"];

    }

    String order_uuid;
    String exchange;
    String time_stamp;
    String order_type;
    Double limit;
    Double quantity;
    Double quantity_remaining;
    Double commission;
    Double price;
    Double price_per_unit;
    bool is_conditional;
    String condition;
    String condition_target;
    bool immediate_or_cancel;

};
}
}
#endif //BITTREX_CPP_ORDER_HISTORY_ENTRY_H
