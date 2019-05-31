#ifndef BITTREX_CPP_RES_MARKET_SUMMARY_H
#define BITTREX_CPP_RES_MARKET_SUMMARY_H

#include <json.hpp>
#include <libbittrex/lib/wrappers.h>

using json=nlohmann::json;
using namespace bittrex::lib;

namespace bittrex {
namespace model {

struct MarketSummary {
    explicit MarketSummary(json j_market_sum) {
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

    String market_name;
    Double high;
    Double low;
    Double volume;
    Double last;
    Double base_volume;
    String time_stamp;
    Double bid;
    Double ask;
    Int open_buy_orders;
    Int open_sell_orders;
    Double prev_day;
    String created;

};
} //Namespace model
} //Namespace bittrex

#endif //BITTREX_CPP_MARKET_SUMMARY_H
