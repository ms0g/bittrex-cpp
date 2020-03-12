#include <libbittrex/api/market.h>

using namespace bittrex::api;

uuid_t Market::buy_limit(const std::string &market, const float &quantity, const float &rate) {
    auto res = api_request<uuid_t, uuid_t>(BUYLIMIT_END_P, bittrex::api::Type::MARKET, "market=", market, "quantity=",
                                           quantity,
                                           "rate=", rate);
    return res;
}


uuid_t Market::sell_limit(const std::string &market, const float &quantity, const float &rate) {

    auto res = api_request<uuid_t, uuid_t>(SELLLIMIT_END_P, bittrex::api::Type::MARKET, "market=", market, "quantity=",
                                           quantity,
                                           "rate=", rate);
    return res;

}


uuid_t Market::cancel(const std::string &uuid) {
    auto res = api_request<uuid_t, uuid_t>(CANCEL_END_P, bittrex::api::Type::MARKET, "uuid=", uuid);
    return res;
}


open_order_list_t Market::get_open_orders(const std::string &market) {
    auto res = api_request<open_order_list_t, open_order_t>(OPEN_ORDERS_END_P, bittrex::api::Type::MARKET, "market=",
                                                            market);
    return res;
}



