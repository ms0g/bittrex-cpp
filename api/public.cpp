#include "../libs/json/json.hpp"
#include "public.h"


using namespace bittrex::api;
using json = nlohmann::json;

VecMarket Public::get_markets() {
    VecMarket markets;

    json res = dispatch("public/getmarkets/", PUBLIC, "");

    auto j_markets = res["result"];
    for (auto &market:j_markets) {
        markets.emplace_back(response::Market(market));
    }
    return markets;
}

VecCurrency Public::get_currencies() {
    VecCurrency currencies;

    json res = dispatch("public/getcurrencies/", PUBLIC, "");

    auto j_currencies = res["result"];
    for (auto &currency:j_currencies) {
        currencies.emplace_back(response::Currency(currency));
    }
    return currencies;
}

response::Ticker Public::get_ticker(const string &market) {
    json res = dispatch("public/getticker?", PUBLIC, "market=", market);
    auto ticker = res["result"];
    return response::Ticker(ticker);
}

VecMarketSum Public::get_market_summaries() {
    VecMarketSum market_summaries;

    json res = dispatch("public/getmarketsummaries/", PUBLIC, "");

    auto j_summaries = res["result"];
    for (auto &sum:j_summaries) {
        market_summaries.emplace_back(response::MarketSummary(sum));
    }
    return market_summaries;
}

response::MarketSummary Public::get_market_summary(const string &market) {
    json res = dispatch("public/getmarketsummary?", PUBLIC, "market=", market);
    auto sum = res["result"];
    return response::MarketSummary(sum[0]);
}

response::OrderBook Public::get_order_book(const string &market, const string &type) {
    json res = dispatch("public/getorderbook?", PUBLIC, "market=", market, "type=", type);
    auto o_book = res["result"];
    return response::OrderBook(o_book, type);
}

VecTrade Public::get_market_history(const string &market) {
    VecTrade trades;

    string parameters = utils::make_params("market=", market);
    json res = dispatch("public/getmarkethistory?", PUBLIC, "market=", market);

    auto market_hist = res["result"];
    for (auto &j_trade:market_hist) {
        trades.emplace_back(response::Trade(j_trade));
    }
    return trades;
}
