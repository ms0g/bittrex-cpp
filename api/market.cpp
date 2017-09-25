#include <sstream>
#include "market.h"
#include "../libs/json/json.hpp"

using namespace bittrex::api;
using json = nlohmann::json;

string Market::buy_limit(const string &market, float quantity, float rate) {
    string parameters = utils::make_params("market=",market,"quantity=",quantity,"rate=",rate);
    auto res = dispatch("market/buylimit?",parameters.c_str(), MARKET);
    return res["result"];
}

string Market::sell_limit(const string &market, float quantity, float rate) {
    string parameters = utils::make_params("market=",market,"quantity=",quantity,"rate=",rate);
    auto res = dispatch("market/selllimit?",parameters.c_str(), MARKET);
    return res["result"];

}

string Market::cancel(const string &uuid) {
    string parameters = utils::make_params("uuid=", uuid);
    auto res = dispatch("market/cancel?",parameters.c_str(), MARKET);
    return res["result"];
}

VecOpenOrder Market::get_open_orders(const string &market) {
    VecOpenOrder open_orders;

    string parameters = utils::make_params("market=", market);
    auto res = dispatch("market/getopenorders?",parameters.c_str(), MARKET);

    auto j_o_orders = res["result"];
    for (auto &order:j_o_orders) {
        open_orders.emplace_back(response::OpenOrder(order));
    }
    return open_orders;


}



