#ifndef BITTREX_CPP_RES_MARKET_SUMMARY_H
#define BITTREX_CPP_RES_MARKET_SUMMARY_H

#include <iostream>
#include "../libs/json/json.hpp"


using json=nlohmann::json;
using namespace std;

namespace bittrex {
    namespace response {
        struct MarketSummary {
            explicit MarketSummary(json j_market_sum);

            string market_name;
            float high;
            float low;
            float volume;
            float last;
            float base_volume;
            string time_stamp;
            float bid;
            float ask;
            int open_buy_orders;
            int open_sell_orders;
            float prev_day;
            string created;

        };
    }
}

#endif //BITTREX_CPP_MARKET_SUMMARY_H
