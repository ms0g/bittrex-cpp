#ifndef BITTREX_CPP_RES_MARKET_SUMMARY_H
#define BITTREX_CPP_RES_MARKET_SUMMARY_H

#include <iostream>
#include "../libs/json/json.hpp"


using json=nlohmann::json;
using namespace std;

namespace bittrex {
    namespace response {
        struct MarketSummary {
            explicit MarketSummary(json j_market_sum){
                market_name = j_market_sum["MarketName"];
                high = j_market_sum["High"];
                low = j_market_sum["Low"];
                volume = j_market_sum["Volume"];
                last = j_market_sum["Last"];
                base_volume = j_market_sum["BaseVolume"];
                time_stamp = j_market_sum["TimeStamp"];
                bid = j_market_sum["Bid"];
                ask = j_market_sum["Ask"];
                open_buy_orders = j_market_sum["OpenBuyOrders"];
                open_sell_orders = j_market_sum["OpenSellOrders"];
                prev_day = j_market_sum["PrevDay"];
                created = j_market_sum["Created"];
            };

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
