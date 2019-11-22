#include <libbittrex/api/market.h>

using namespace bittrex::api;

uuid_t Market::buy_limit(const string &market, const float &quantity, const float &rate) {
    auto res = api_request<uuid_t, uuid_t>("market/buylimit?", ApiType::MARKET, "market=", market, "quantity=",
                                           quantity,
                                           "rate=", rate);
    return res;
}


uuid_t Market::sell_limit(const string &market, const float &quantity, const float &rate) {

    auto res = api_request<uuid_t, uuid_t>("market/selllimit?", ApiType::MARKET, "market=", market, "quantity=",
                                           quantity,
                                           "rate=", rate);
    return res;

}


uuid_t Market::cancel(const string &uuid) {
    auto res = api_request<uuid_t, uuid_t>("market/cancel?", ApiType::MARKET, "uuid=", uuid);
    return res;
}


open_order_list_t Market::get_open_orders(const string &market) {
    auto res = api_request<open_order_list_t, open_order_t>("market/getopenorders?", ApiType::MARKET, "market=",
                                                            market);
    return res;
}



