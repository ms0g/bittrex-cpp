#ifndef BITTREX_CPP_API_PUBLIC_H
#define BITTREX_CPP_API_PUBLIC_H

#include <iostream>
#include <memory>
#include <utility>
#include "../models/market.h"
#include "../models/currency.h"
#include "../models/ticker.h"
#include "../models/market_summary.h"
#include "../models/order_book.h"
#include "../models/market_history.h"
#include "../api_call.h"

using namespace bittrex;

namespace bittrex {
namespace api {

class Public {
public:
    explicit Public(std::shared_ptr<ApiCall> &api_call) : _api_call(api_call) {}

    /**
     * Get the open and available trading markets at Bittrex along with other meta data
     * @param None
     */
    std::vector<model::Market> get_markets();

    /**
     * Get all supported currencies at Bittrex along with other meta data
     * @param None
     */
    std::vector<model::Currency> get_currencies();

    /**
     * Get the current tick values for a market
     * @param market a string literal for the market (ex: BTC-LTC)
     */
    model::Ticker get_ticker(const std::string &market);

    /**
     * Get the last 24 hour summary of all active exchanges
     * @param None
     */
    std::vector<model::MarketSummary> get_market_summaries();

    /**
     * Get the last 24 hour summary of all active exchanges
     * @param market a string literal for the market (ex: BTC-LTC)
     */
    model::MarketSummary get_market_summary(const std::string &market);

    /**
     * Get retrieve the orderbook for a given market
     * @param market a string literal for the market (ex: BTC-LTC)
     * @param type buy, sell or both to identify the type of orderbook to return
     */
    model::OrderBook get_order_book(const std::string &market, const std::string &type);

    /**
     * Retrieve the latest trades that have occured for a specific market
     * @param market a string literal for the market (ex: BTC-LTC)
     */
    std::vector<model::Trade> get_market_history(const std::string &market);

private:
    std::shared_ptr<ApiCall> _api_call;
};
} //Namespace Api
} //Namespace Bittrex
#endif //BITTREX_CPP_PUBLIC_H
