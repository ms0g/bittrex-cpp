#include <sstream>
#include "market.h"
#include "exceptions.h"
#include "../libs/json/json.hpp"

using namespace bittrex::api;
using json = nlohmann::json;

string Market::buy_limit(const string &market, float quantity, float rate) {
    stringstream params;
    params << "market=" << market << "&" << "quantity=" << quantity << "&" << "rate=" << rate;
    string res = connection->execute_request("market/buylimit?", params.str().c_str(), MARKET);

    auto j_res = json::parse(res);
    if (!j_res["success"])
        throw fail();
    return j_res["result"];
}

string Market::sell_limit(const string &market, float quantity, float rate) {
    stringstream params;
    params << "market=" << market << "&" << "quantity=" << quantity << "&" << "rate=" << rate;
    string res = connection->execute_request("market/selllimit?", params.str().c_str(), MARKET);

    auto j_res = json::parse(res);
    if (!j_res["success"])
        throw fail();
    return j_res["result"];
}

string Market::cancel(const string &uuid) {
    stringstream params;
    params << "uuid=" << uuid;
    string res = connection->execute_request("market/cancel?", params.str().c_str(), MARKET);

    auto j_res = json::parse(res);
    if (!j_res["success"])
        throw fail();
    return j_res["result"];
}

VecOpenOrder Market::get_open_orders(const string &market) {
    VecOpenOrder open_orders;
    stringstream params;
    params << "market=" << market;
    string res = connection->execute_request("/getopenorders?", params.str().c_str(), MARKET);

    auto j_res = json::parse(res);
    if (!j_res["success"]) {
        throw fail();
    }

    auto j_o_orders = j_res["result"];
    for (auto &order:j_o_orders) {
        open_orders.emplace_back(response::OpenOrder(order));
    }
    return open_orders;


}



