#include <libbittrex/api/public.h>

using namespace bittrex::api;

market_list_t Public::get_markets() {
    auto res = api_request<market_list_t, market_t>("public/getmarkets/", bittrex::api::Type::PUBLIC, "");
    return res;
}


currency_list_t Public::get_currencies() {
    auto res = api_request<currency_list_t, currency_t>("public/getcurrencies/", bittrex::api::Type::PUBLIC, "");
    return res;
}


ticker_t Public::get_ticker(const std::string &market) {
    auto res = api_request<ticker_t, ticker_t>("public/getticker?", bittrex::api::Type::PUBLIC, "market=", market);
    return res;
}


market_sum_list_t Public::get_market_summaries() {
    auto res = api_request<market_sum_list_t, market_sum_t>("public/getmarketsummaries/", bittrex::api::Type::PUBLIC,
                                                            "");
    return res;

}


market_sum_list_t Public::get_market_summary(const std::string &market) {
    auto res = api_request<market_sum_list_t, market_sum_t>("public/getmarketsummary?", bittrex::api::Type::PUBLIC,
                                                            "market=", market);
    return res;
}


order_book_t Public::get_order_book(const std::string &market, const std::string &type) {
    auto res = api_request<order_book_t, order_book_t>("public/getorderbook?", bittrex::api::Type::PUBLIC, "market=",
                                                       market,
                                                       "type=", type);
    return res;
}


trade_list_t Public::get_market_history(const std::string &market) {
    auto res = api_request<trade_list_t, trade_t>("public/getmarkethistory?", bittrex::api::Type::PUBLIC,
                                                  "market=", market);
    return res;

}
