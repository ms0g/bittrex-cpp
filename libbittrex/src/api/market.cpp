#include <libbittrex/api/market.h>

using namespace bittrex::api;

btx_uuid_t Market::buy_limit(const std::string &market, const float &quantity, const float &rate) {
    return api_request<btx_uuid_t, btx_uuid_t>(
        "market/buylimit?", bittrex::api::Type::MARKET, 
        "market=", market, "quantity=", quantity, "rate=", rate);
}


btx_uuid_t Market::sell_limit(const std::string &market, const float &quantity, const float &rate) {
    return api_request<btx_uuid_t, btx_uuid_t>(
        "market/selllimit?", bittrex::api::Type::MARKET, 
        "market=", market, "quantity=", quantity, "rate=", rate);

}


btx_uuid_t Market::cancel(const std::string &uuid) {
    return api_request<btx_uuid_t, btx_uuid_t>("market/cancel?", bittrex::api::Type::MARKET, "uuid=", uuid);
}


open_order_list_t Market::get_open_orders(const std::string &market) {
    return api_request<open_order_list_t, open_order_t>(
        "market/getopenorders?", bittrex::api::Type::MARKET, "market=", market);
}



