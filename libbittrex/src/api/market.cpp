#include <libbittrex/api/market.h>

using namespace bittrex::api;

btx_uuid_t Market::buy_limit(const std::string &market, const float &quantity, const float &rate) {
    auto res = api_request<btx_uuid_t, btx_uuid_t>("market/buylimit?", bittrex::api::Type::MARKET, "market=", market,
                                                   "quantity=",
                                                   quantity,
                                                   "rate=", rate);
    return res;
}


btx_uuid_t Market::sell_limit(const std::string &market, const float &quantity, const float &rate) {

    auto res = api_request<btx_uuid_t, btx_uuid_t>("market/selllimit?", bittrex::api::Type::MARKET, "market=", market,
                                                   "quantity=",
                                                   quantity,
                                                   "rate=", rate);
    return res;

}


btx_uuid_t Market::cancel(const std::string &uuid) {
    auto res = api_request<btx_uuid_t, btx_uuid_t>("market/cancel?", bittrex::api::Type::MARKET, "uuid=", uuid);
    return res;
}


open_order_list_t Market::get_open_orders(const std::string &market) {
    auto res = api_request<open_order_list_t, open_order_t>("market/getopenorders?", bittrex::api::Type::MARKET,
                                                            "market=",
                                                            market);
    return res;
}



