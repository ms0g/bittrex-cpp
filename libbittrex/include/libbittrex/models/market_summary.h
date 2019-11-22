#ifndef BITTREX_CPP_RES_MARKET_SUMMARY_H
#define BITTREX_CPP_RES_MARKET_SUMMARY_H

#include <json.hpp>
#include <libbittrex/lib/wrappers.h>

using json=nlohmann::json;
using namespace bittrex::lib;

namespace bittrex {
namespace model {

struct MarketSummary {
    explicit MarketSummary(json j) {
        market_name = j["MarketName"];
        high = j["High"];
        low = j["Low"];
        volume = j["Volume"];
        last = j["Last"];
        base_volume = j["BaseVolume"];
        time_stamp = j["TimeStamp"];
        bid = j["Bid"];
        ask = j["Ask"];
        open_buy_orders = j["OpenBuyOrders"];
        open_sell_orders = j["OpenSellOrders"];
        prev_day = j["PrevDay"];
        created = j["Created"];
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
