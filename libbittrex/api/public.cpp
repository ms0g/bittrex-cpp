#include "public.h"


using namespace bittrex::api;
using json = nlohmann::json;


List<response::Market> Public::get_markets() {
    List<response::Market> markets;

    json res = _api_call->dispatch("public/getmarkets/", ApiType::PUBLIC, "");

    auto j_markets = res["result"];
    for (auto const &market:j_markets) {
        markets.emplace_back(response::Market(market));
    }
    return markets;
}


List<response::Currency> Public::get_currencies() {
    List<response::Currency> currencies;

    json res = _api_call->dispatch("public/getcurrencies/", ApiType::PUBLIC, "");

    auto j_currencies = res["result"];
    for (auto const &currency:j_currencies) {
        currencies.emplace_back(response::Currency(currency));
    }
    return currencies;
}


response::Ticker Public::get_ticker(const string &market) {
    json res = _api_call->dispatch("public/getticker?", ApiType::PUBLIC, "market=", market);
    auto ticker = res["result"];
    return response::Ticker(ticker);
}


List<response::MarketSummary> Public::get_market_summaries() {
    List<response::MarketSummary> market_summaries;

    json res = _api_call->dispatch("public/getmarketsummaries/", ApiType::PUBLIC, "");

    auto j_summaries = res["result"];
    for (auto const &sum:j_summaries) {
        market_summaries.emplace_back(response::MarketSummary(sum));
    }
    return market_summaries;
}


response::MarketSummary Public::get_market_summary(const string &market) {
    json res = _api_call->dispatch("public/getmarketsummary?", ApiType::PUBLIC, "market=", market);
    auto sum = res["result"];
    return response::MarketSummary(sum[0]);
}


response::OrderBook Public::get_order_book(const string &market, const string &type) {
    json res = _api_call->dispatch("public/getorderbook?", ApiType::PUBLIC, "market=", market, "type=", type);
    auto o_book = res["result"];
    return response::OrderBook(o_book, type);
}


List<response::Trade> Public::get_market_history(const string &market) {
    List<response::Trade> trades;

    json res = _api_call->dispatch("public/getmarkethistory?", ApiType::PUBLIC, "market=", market);

    auto market_hist = res["result"];
    for (auto const &j_trade:market_hist) {
        trades.emplace_back(response::Trade(j_trade));
    }
    return trades;
}
