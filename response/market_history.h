#ifndef BITTREX_CPP_RES_MARKET_HISTORY_H
#define BITTREX_CPP_RES_MARKET_HISTORY_H

#include <iostream>
#include "../lib/json.hpp"
#include "../lib/utils.h"


using json=nlohmann::json;
using namespace bittrex::lib;

namespace bittrex {
    namespace response {
        struct Trade {
            explicit Trade(json j_market_his){
                id = j_market_his["Id"];
                time_stamp = j_market_his["TimeStamp"];
                quantity = j_market_his["Quantity"];
                price = j_market_his["Price"];
                total = j_market_his["Total"];
                fill_type = j_market_his["FillType"];
                order_type = j_market_his["OrderType"];
            };

            Int id;
            String time_stamp;
            Double quantity;
            Double price;
            Double total;
            String fill_type;
            String order_type;
        };
    }
}
#endif //BITTREX_CPP_MARKET_HISTORY_H
