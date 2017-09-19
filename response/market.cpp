#include "market.h"

using namespace bittrex::response;

Market::Market(json j_market) {
    market_currency = j_market["MarketCurrency"];
    base_currency = j_market["BaseCurrency"];
    market_currency_long = j_market["MarketCurrencyLong"];
    base_currency_long = j_market["BaseCurrencyLong"];
    min_trade_size = j_market["MinTradeSize"];
    market_name = j_market["MarketName"];
    is_active = j_market["IsActive"];
    created = j_market["Created"];

}
