#ifndef BITTREX_CPP_RES_MARKET_H
#define BITTREX_CPP_RES_MARKET_H

#include <json.hpp>
#include <libbittrex/lib/wrappers.h>

using json=nlohmann::json;
using namespace bittrex::lib;

namespace bittrex {
namespace model {

struct Market {
    explicit Market(json j_market) {
        market_currency = j_market["MarketCurrency"];
        base_currency = j_market["BaseCurrency"];
        market_currency_long = j_market["MarketCurrencyLong"];
        base_currency_long = j_market["BaseCurrencyLong"];
        min_trade_size = j_market["MinTradeSize"];
        market_name = j_market["MarketName"];
        is_active = j_market["IsActive"];
        created = j_market["Created"];
    };

    String market_currency;
    String base_currency;
    String market_currency_long;
    String base_currency_long;
    Double min_trade_size;
    String market_name;
    bool is_active;
    String created;
};
} //Namespace model
} //Namespace bittrex

#endif //BITTREX_CPP_MARKET_H
