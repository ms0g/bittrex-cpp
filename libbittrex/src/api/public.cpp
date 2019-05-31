#include <libbittrex/api/public.h>


using namespace bittrex::api;
using json = nlohmann::json;


std::vector<model::Market> Public::get_markets() {
    std::vector<model::Market> markets;

    json res = _api_call->dispatch("public/getmarkets/", ApiType::PUBLIC, "");

    auto j_markets = res["result"];
    for (auto const &market:j_markets) {
        markets.emplace_back(model::Market(market));
    }
    return markets;
}


std::vector<model::Currency> Public::get_currencies() {
    std::vector<model::Currency> currencies;

    json res = _api_call->dispatch("public/getcurrencies/", ApiType::PUBLIC, "");

    auto j_currencies = res["result"];
    for (auto const &currency:j_currencies) {
        currencies.emplace_back(model::Currency(currency));
    }
    return currencies;
}


model::Ticker Public::get_ticker(const string &market) {
    json res = _api_call->dispatch("public/getticker?", ApiType::PUBLIC, "market=", market);
    auto ticker = res["result"];
    return model::Ticker(ticker);
}


std::vector<model::MarketSummary> Public::get_market_summaries() {
    std::vector<model::MarketSummary> market_summaries;

    json res = _api_call->dispatch("public/getmarketsummaries/", ApiType::PUBLIC, "");

    auto j_summaries = res["result"];
    for (auto const &sum:j_summaries) {
        market_summaries.emplace_back(model::MarketSummary(sum));
    }
    return market_summaries;
}


model::MarketSummary Public::get_market_summary(const string &market) {
    json res = _api_call->dispatch("public/getmarketsummary?", ApiType::PUBLIC, "market=", market);
    auto sum = res["result"];
    return model::MarketSummary(sum[0]);
}


model::OrderBook Public::get_order_book(const string &market, const string &type) {
    json res = _api_call->dispatch("public/getorderbook?", ApiType::PUBLIC, "market=", market, "type=", type);
    auto o_book = res["result"];
    return model::OrderBook(o_book, type);
}


std::vector<model::Trade> Public::get_market_history(const string &market) {
    std::vector<model::Trade> trades;

    json res = _api_call->dispatch("public/getmarkethistory?", ApiType::PUBLIC, "market=", market);

    auto market_hist = res["result"];
    for (auto const &j_trade:market_hist) {
        trades.emplace_back(model::Trade(j_trade));
    }
    return trades;
}
