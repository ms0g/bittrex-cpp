#include <sstream>
#include "market.h"

using namespace bittrex::api;
using json = nlohmann::json;


std::string Market::buy_limit(const string &market, const float &quantity, const float &rate) {
    auto res = _api_call->dispatch("market/buylimit?", ApiType::MARKET, "market=", market, "quantity=", quantity,
                                   "rate=", rate);
    return res["result"];
}


std::string Market::sell_limit(const string &market, const float &quantity, const float &rate) {
    auto res = _api_call->dispatch("market/selllimit?", ApiType::MARKET, "market=", market, "quantity=", quantity,
                                   "rate=", rate);
    return res["result"];

}


std::string Market::cancel(const string &uuid) {
    auto res = _api_call->dispatch("market/cancel?", ApiType::MARKET, "uuid=", uuid);
    return res["result"];
}


std::vector<response::OpenOrder> Market::get_open_orders(const string &market) {
    std::vector<response::OpenOrder> open_orders;

    auto res = _api_call->dispatch("market/getopenorders?", ApiType::MARKET, "market=", market);

    auto j_o_orders = res["result"];
    for (auto const &order:j_o_orders) {
        open_orders.emplace_back(response::OpenOrder(order));
    }
    return open_orders;
}



