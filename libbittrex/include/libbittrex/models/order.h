#ifndef BITTREX_CPP_RES_ORDER_H
#define BITTREX_CPP_RES_ORDER_H

#include <json.hpp>
#include <libbittrex/lib/wrappers.h>

using json=nlohmann::json;
using namespace bittrex::lib;

namespace bittrex {
namespace model {

struct Order {
    explicit Order(json j) {
        account_id = j["AccountId"];
        order_uuid = j["OrderUuid"];
        exchange = j["Exchange"];
        type = j["Type"];
        quantity = j["Quantity"];
        quantity_remaining = j["QuantityRemaining"];
        limit = j["Limit"];
        reserved = j["Reserved"];
        reserve_remaining = j["ReserveRemaining"];
        commission_reserved = j["CommissionReserved"];
        commission_reserve_remaining = j["CommissionReserveRemaining"];
        commission_paid = j["CommissionPaid"];
        price = j["Price"];
        price_per_unit = j["PricePerUnit"];
        opened = j["Opened"];
        closed = j["Closed"];
        is_open = j["IsOpen"];
        sentinel = j["Sentinel"];
        cancel_initiated = j["CancelInitiated"];
        immediate_or_cancel = j["ImmediateOrCancel"];
        is_conditional = j["IsConditional"];
        condition = j["Condition"];
        condition_target = j["ConditionTarget"];
    };

    String account_id;
    String order_uuid;
    String exchange;
    String type;
    Double quantity{};
    Double quantity_remaining{};
    Double limit{};
    Double reserved{};
    Double reserve_remaining{};
    Double commission_reserved{};
    Double commission_reserve_remaining{};
    Double commission_paid{};
    Double price{};
    Double price_per_unit{};
    String opened;
    bool closed{};
    bool is_open{};
    String sentinel;
    bool cancel_initiated{};
    bool immediate_or_cancel{};
    bool is_conditional{};
    String condition;
    String condition_target;

};
} //Namespace model
} //Namespace bittrex
#endif //BITTREX_CPP_ORDER_H
