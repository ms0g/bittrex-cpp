#include <libbittrex/api/public.h>

using namespace bittrex::api;

market_list_t Public::get_markets() {
    return api_request<market_list_t, market_t>("public/getmarkets/", bittrex::api::Type::PUBLIC, "");
}


currency_list_t Public::get_currencies() {
    return api_request<currency_list_t, currency_t>("public/getcurrencies/", bittrex::api::Type::PUBLIC, "");
}


ticker_t Public::get_ticker(const std::string &market) {
    return api_request<ticker_t, ticker_t>("public/getticker?", bittrex::api::Type::PUBLIC, "market=", market);
}


market_sum_list_t Public::get_market_summaries() {
    return api_request<market_sum_list_t, market_sum_t>("public/getmarketsummaries/", bittrex::api::Type::PUBLIC, "");
    
}


market_sum_list_t Public::get_market_summary(const std::string &market) {
    return api_request<market_sum_list_t, market_sum_t>("public/getmarketsummary?", bittrex::api::Type::PUBLIC, "market=", market);
}


order_book_t Public::get_order_book(const std::string &market, const std::string &type) {
    return api_request<order_book_t, order_book_t>(
        "public/getorderbook?", bittrex::api::Type::PUBLIC, "market=", market, "type=", type);
}


trade_list_t Public::get_market_history(const std::string &market) {
    return api_request<trade_list_t, trade_t>("public/getmarkethistory?", bittrex::api::Type::PUBLIC, "market=", market);
}
