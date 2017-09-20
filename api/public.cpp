#include "../libs/json/json.hpp"
#include "../api/exceptions.h"
#include "public.h"


using namespace bittrex::api;
using json = nlohmann::json;

VecMarket Public::get_markets() {
    VecMarket markets;
    string res = connection->execute_request("public/getmarkets/", nullptr, PUBLIC);
    auto j_res = json::parse(res);
    if (!j_res["success"]) {
        throw fail();
    }

    auto j_markets = j_res["result"];
    for (auto &market:j_markets) {
        markets.emplace_back(market);
    }
    return markets;

}

VecCurrency Public::get_currencies() {
    VecCurrency currencies;
    string res = connection->execute_request("public/getcurrencies/", nullptr, PUBLIC);
    auto j_res = json::parse(res);
    if (!j_res["success"])
        throw fail();

    auto j_currencies = j_res["result"];
    for (auto &currency:j_currencies) {
        currencies.emplace_back(currency);
    }
    return currencies;


}

response::Ticker Public::get_ticker(const string &market) {
    stringstream params;
    params << "market=" << market;
    string res = connection->execute_request("public/getticker?", params.str().c_str(), PUBLIC);
    auto j_res = json::parse(res);
    if (!j_res["success"])
        throw fail();
    auto ticker = j_res["result"];
    return response::Ticker(ticker);

}

VecMarketSum Public::get_market_summaries() {
    VecMarketSum market_summaries;
    string res = connection->execute_request("public/getmarketsummaries/", nullptr, PUBLIC);
    auto j_res = json::parse(res);
    if (!j_res["success"])
        throw fail();

    auto j_summaries = j_res["result"];
    for (auto &sum:j_summaries) {
        market_summaries.emplace_back(sum);
    }
    return market_summaries;
}

response::MarketSummary Public::get_market_summary(const string &market) {
    stringstream params;
    params << "market=" << market;
    string res = connection->execute_request("public/getmarketsummary?", params.str().c_str(), PUBLIC);

    auto j_res = json::parse(res);
    if (!j_res["success"])
        throw fail();

    auto sum = j_res["result"];
    return response::MarketSummary(sum[0]);

}

response::OrderBook Public::get_order_book(const string &market, const string &type) {
    stringstream params;
    params << "market=" << market << "&" << "type=" << type;
    string res = connection->execute_request("public/getorderbook?", params.str().c_str(), PUBLIC);

    auto j_res = json::parse(res);
    if (!j_res["success"])
        throw fail();
    auto o_book = j_res["result"];
    return response::OrderBook(o_book, type);

}

VecTrade Public::get_market_history(const string &market) {
    stringstream params;
    VecTrade trades;
    params << "market=" << market;
    string res = connection->execute_request("public/getmarkethistory?", params.str().c_str(), PUBLIC);

    auto j_res = json::parse(res);
    if (!j_res["success"])
        throw fail();

    auto market_his = j_res["result"];
    for (auto &j_trade:market_his) {
        trades.emplace_back(response::Trade(j_trade));
    }
    return trades;
}
