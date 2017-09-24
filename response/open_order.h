#ifndef BITTREX_CPP_RES_OPEN_ORDER_H
#define BITTREX_CPP_RES_OPEN_ORDER_H

#include "../libs/json/json.hpp"

using namespace std;
using json=nlohmann::json;

namespace bittrex {
    namespace response {
        struct OpenOrder{
            explicit OpenOrder(json j_order);
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
