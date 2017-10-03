#ifndef BITTREX_CPP_RES_MARKET_H
#define BITTREX_CPP_RES_MARKET_H

#include <iostream>
#include "../libs/json/json.hpp"

using namespace std;
using json=nlohmann::json;

namespace bittrex {
    namespace response {
        struct Market {
            explicit Market(json j_market){
                market_currency = j_market["MarketCurrency"];
                base_currency = j_market["BaseCurrency"];
                market_currency_long = j_market["MarketCurrencyLong"];
                base_currency_long = j_market["BaseCurrencyLong"];
                min_trade_size = j_market["MinTradeSize"];
                market_name = j_market["MarketName"];
                is_active = j_market["IsActive"];
                created = j_market["Created"];
            };

            string market_currency;
            string base_currency;
            string market_currency_long;
            string base_currency_long;
            float min_trade_size;
            string market_name;
            bool is_active;
            string created;
        };
    }
}

#endif //BITTREX_CPP_MARKET_H
