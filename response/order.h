#ifndef BITTREX_CPP_RES_ORDER_H
#define BITTREX_CPP_RES_ORDER_H
#include <iostream>
#include "../libs/json/json.hpp"

using json=nlohmann::json;

namespace bittrex {
    namespace response {
        struct Order {
            explicit Order(json j_order){
                account_id=j_order["AccountId"];
                order_uuid=j_order["OrderUuid"];
                 exchange=j_order["Exchange"];
                 type=j_order["Type"];
                 quantity=j_order["Quantity"];
                 quantity_remaining=j_order["QuantityRemaining"];
                 limit=j_order["Limit"];
                 reserved=j_order["Reserved"];
                 reserve_remaining=j_order["ReserveRemaining"];
                 commission_reserved=j_order["CommissionReserved"];
                 commission_reserve_remaining=j_order["CommissionReserveRemaining"];
                 commission_paid=j_order["CommissionPaid"];
                 price=j_order["Price"];
                 price_per_unit=j_order["PricePerUnit"];
                 opened=j_order["Opened"];
                 closed=j_order["Closed"];
                 is_open=j_order["IsOpen"];
                 sentinel=j_order["Sentinel"];
                 cancel_initiated=j_order["CancelInitiated"];
                 immediate_or_cancel=j_order["ImmediateOrCancel"];
                 is_conditional=j_order["IsConditional"];
                 condition=j_order["Condition"];
                 condition_target=j_order["ConditionTarget"];
            };
            std::string account_id;
            std::string order_uuid;
            std::string exchange;
            std::string type;
            float quantity{};
            float quantity_remaining{};
            float limit{};
            float reserved{};
            float reserve_remaining{};
            float commission_reserved{};
            float commission_reserve_remaining{};
            float commission_paid{};
            float price{};
            float price_per_unit{};
            std::string opened;
            bool closed{};
            bool is_open{};
            std::string sentinel;
            bool cancel_initiated{};
            bool immediate_or_cancel{};
            bool is_conditional{};
            std::string condition;
            std::string condition_target;

        };
    }
}
#endif //BITTREX_CPP_ORDER_H
