#ifndef BITTREX_CPP_RES_MARKET_HISTORY_H
#define BITTREX_CPP_RES_MARKET_HISTORY_H

#include <iostream>
#include "../libs/json/json.hpp"

using namespace std;
using json=nlohmann::json;

namespace bittrex {
    namespace response {
        struct Trade {
            explicit Trade(json j_market_his);

            int id;
            string time_stamp;
            float quantity;
            float price;
            float total;
            string fill_type;
            string order_type;
        };
    }
}
#endif //BITTREX_CPP_MARKET_HISTORY_H
