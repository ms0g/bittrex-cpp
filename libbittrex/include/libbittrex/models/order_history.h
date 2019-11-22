#ifndef BITTREX_CPP_RES_ORDER_HISTORY_ENTRY_H
#define BITTREX_CPP_RES_ORDER_HISTORY_ENTRY_H

#include <json.hpp>
#include <libbittrex/lib/wrappers.h>

using json=nlohmann::json;
using namespace bittrex::lib;

namespace bittrex {
namespace model {

struct OrderHistoryEntry {
    explicit OrderHistoryEntry(json j) {
        order_uuid = j["OrderUuid"];
        exchange = j["Exchange"];
        time_stamp = j["TimeStamp"];
        order_type = j["OrderType"];
        limit = j["Limit"];
        quantity = j["Quantity"];
        quantity_remaining = j["QuantityRemaining"];
        commission = j["Commission"];
        price = j["Price"];
        price_per_unit = j["PricePerUnit"];
        is_conditional = j["IsConditional"];
        condition = j["Condition"];
        condition_target = j["ConditionTarget"];
        immediate_or_cancel = j["ImmediateOrCancel"];

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
} //Namespace model
} //Namespace bittrex
#endif //BITTREX_CPP_ORDER_HISTORY_ENTRY_H
