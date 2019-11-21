#include <libbittrex/api/public.h>


using namespace bittrex::api;
using json = nlohmann::json;

std::vector<model::Market> Public::get_markets() {
    auto res = api_request<std::vector<model::Market>, model::Market>("public/getmarkets/", ApiType::PUBLIC, "");
    return res;
}


std::vector<model::Currency> Public::get_currencies() {
    auto res = api_request<std::vector<model::Currency>, model::Currency>("public/getcurrencies/", ApiType::PUBLIC, "");
    return res;
}


model::Ticker Public::get_ticker(const string &market) {
    auto res = api_request<model::Ticker, model::Ticker>("public/getticker?", ApiType::PUBLIC, "market=", market);
    return res;
}


std::vector<model::MarketSummary> Public::get_market_summaries() {
    auto res = api_request<std::vector<model::MarketSummary>, model::MarketSummary>("public/getmarketsummaries/",
                                                                                    ApiType::PUBLIC, "");
    return res;

}


model::MarketSummary Public::get_market_summary(const string &market) {
    auto res = api_request<model::MarketSummary, model::MarketSummary>("public/getmarketsummary?", ApiType::PUBLIC,
                                                                       "market=", market);
    return res;
}


//model::OrderBook Public::get_order_book(const string &market, const string &type) {
//    auto res = api_call<model::OrderBook, model::OrderBook>("public/getorderbook?", ApiType::PUBLIC, "market=", market, "type=", type);
//    return res;
//}


std::vector<model::Trade> Public::get_market_history(const string &market) {
    auto res = api_request<std::vector<model::Trade>, model::Trade>("public/getmarkethistory?", ApiType::PUBLIC,
                                                                    "market=", market);
    return res;

}
