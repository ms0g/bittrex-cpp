#include <libbittrex/api/public.h>

using namespace bittrex::api;

market_list_t Public::get_markets() {
    auto res = api_request<market_list_t, market_t>(MARKET_END_P, btx::ApiType::PUBLIC, "");
    return res;
}


currency_list_t Public::get_currencies() {
    auto res = api_request<currency_list_t, currency_t>(CURRENCY_END_P, btx::ApiType::PUBLIC, "");
    return res;
}


ticker_t Public::get_ticker(const string &market) {
    auto res = api_request<ticker_t, ticker_t>(TICKER_END_P, btx::ApiType::PUBLIC, "market=", market);
    return res;
}


market_sum_list_t Public::get_market_summaries() {
    auto res = api_request<market_sum_list_t, market_sum_t>(MARKET_SUMS_END_P,
                                                            btx::ApiType::PUBLIC, "");
    return res;

}


market_sum_list_t Public::get_market_summary(const string &market) {
    auto res = api_request<market_sum_list_t, market_sum_t>(MARKET_SUM_END_P, btx::ApiType::PUBLIC,
                                                            "market=", market);
    return res;
}


order_book_t Public::get_order_book(const string &market, const string &type) {
    auto res = api_request<order_book_t, order_book_t>("public/getorderbook?", btx::ApiType::PUBLIC, "market=", market,
                                                       "type=", type);
    return res;
}


trade_list_t Public::get_market_history(const string &market) {
    auto res = api_request<trade_list_t, trade_t>(MARKET_HIS_END_P, btx::ApiType::PUBLIC,
                                                  "market=", market);
    return res;

}
