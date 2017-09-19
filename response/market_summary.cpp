#include "market_summary.h"

using namespace bittrex::response;

MarketSummary::MarketSummary(json j_market_sum) {
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
}
