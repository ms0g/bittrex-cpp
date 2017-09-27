#ifndef BITTREX_CPP_RES_OPEN_ORDER_H
#define BITTREX_CPP_RES_OPEN_ORDER_H

#include "../libs/json/json.hpp"

using namespace std;
using json=nlohmann::json;

namespace bittrex {
    namespace response {
        struct OpenOrder{
            explicit OpenOrder(json j_order){
                uuid=j_order["Uuid"];
                order_uuid=j_order["OrderUuid"];
                exchange=j_order["Exchange"];
                order_type =j_order["OrderType"];
                quantity=j_order["Quantity"];
                quantity_remaining=j_order["QuantityRemaining"];
                limit=j_order["Limit"];
                commission_paid=j_order["CommissionPaid"];
                price=j_order["Price"];
                price_per_unit =j_order["PricePerUnit"];
                opened=j_order["Opened"];
                closed =j_order["Closed"];
                cancel_initiated =j_order["CancelInitiated"];
                immediate_or_cancel =j_order["ImmediateOrCancel"];
                is_conditional =j_order["IsConditional"];
                condition =j_order["Condition"];
                condition_target=j_order["ConditionTarget"];
            };
            string uuid;
            string order_uuid;
            string exchange; 
            string order_type ;
            float quantity;
            float quantity_remaining;
            float limit;
            float commission_paid;
            float price;
            string price_per_unit ;
            string opened;
            string closed ;
            bool cancel_initiated ;
            bool immediate_or_cancel ;
            bool is_conditional ;
            string condition ;
            string condition_target;

        };
    }
}
#endif //BITTREX_CPP_OPEN_ORDER_H
