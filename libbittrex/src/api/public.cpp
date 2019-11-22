#include <libbittrex/api/public.h>

using namespace bittrex::api;

market_list_t Public::get_markets() {
    auto res = api_request<market_list_t, market_t>("public/getmarkets/", ApiType::PUBLIC, "");
    return res;
}


currency_list_t Public::get_currencies() {
    auto res = api_request<currency_list_t, currency_t>("public/getcurrencies/", ApiType::PUBLIC, "");
    return res;
}


ticker_t Public::get_ticker(const string &market) {
    auto res = api_request<ticker_t, ticker_t>("public/getticker?", ApiType::PUBLIC, "market=", market);
    return res;
}


market_sum_list_t Public::get_market_summaries() {
    auto res = api_request<market_sum_list_t, market_summary_t>("public/getmarketsummaries/",
                                                                ApiType::PUBLIC, "");
    return res;

}


market_sum_list_t Public::get_market_summary(const string &market) {
    auto res = api_request<market_sum_list_t, market_summary_t>("public/getmarketsummary?", ApiType::PUBLIC,
                                                                "market=", market);
    return res;
}


//model::OrderBook Public::get_order_book(const string &market, const string &type) {
//    auto res = api_call<model::OrderBook, model::OrderBook>("public/getorderbook?", ApiType::PUBLIC, "market=", market, "type=", type);
//    return res;
//}


trade_list_t Public::get_market_history(const string &market) {
    auto res = api_request<trade_list_t, trade_t>("public/getmarkethistory?", ApiType::PUBLIC,
                                                  "market=", market);
    return res;

}
