#include <libbittrex/api/market.h>

using namespace bittrex::api;

uuid_t Market::buy_limit(const string &market, const float &quantity, const float &rate) {
    auto res = api_request<uuid_t, uuid_t>(BUYLIMIT_END_P, ApiType::MARKET, "market=", market, "quantity=",
                                           quantity,
                                           "rate=", rate);
    return res;
}


uuid_t Market::sell_limit(const string &market, const float &quantity, const float &rate) {

    auto res = api_request<uuid_t, uuid_t>(SELLLIMIT_END_P, ApiType::MARKET, "market=", market, "quantity=",
                                           quantity,
                                           "rate=", rate);
    return res;

}


uuid_t Market::cancel(const string &uuid) {
    auto res = api_request<uuid_t, uuid_t>(CANCEL_END_P, ApiType::MARKET, "uuid=", uuid);
    return res;
}


open_order_list_t Market::get_open_orders(const string &market) {
    auto res = api_request<open_order_list_t, open_order_t>(OPEN_ORDERS_END_P, ApiType::MARKET, "market=",
                                                            market);
    return res;
}



