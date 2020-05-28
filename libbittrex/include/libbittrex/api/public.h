#pragma once

#include <iostream>
#include <memory>
#include <utility>
#include <libbittrex/models/market.h>
#include <libbittrex/models/currency.h>
#include <libbittrex/models/ticker.h>
#include <libbittrex/models/market_summary.h>
#include <libbittrex/models/order_book.h>
#include <libbittrex/models/trade.h>
#include <libbittrex/api/base.h>

using namespace bittrex::api;

namespace bittrex {
namespace api {

using market_t = model::Market;
using market_list_t = std::vector<market_t>;
using currency_t = model::Currency;
using currency_list_t = std::vector<currency_t>;
using ticker_t = model::Ticker;
using market_sum_t = model::MarketSummary;
using market_sum_list_t = std::vector<market_sum_t>;
using order_book_t = model::OrderBook;
using trade_t = model::Trade;
using trade_list_t = std::vector<trade_t>;

class Public : Base {
public:
    explicit Public(const std::shared_ptr<ApiCall> &api_call) : Base(api_call) {}

    /**
     * Get the open and available trading markets at Bittrex along with other meta data
     * @param None
     */
    market_list_t get_markets();

    /**
     * Get all supported currencies at Bittrex along with other meta data
     * @param None
     */
    currency_list_t get_currencies();

    /**
     * Get the current tick values for a market
     * @param market a string literal for the market (ex: BTC-LTC)
     */
    ticker_t get_ticker(const std::string &market);

    /**
     * Get the last 24 hour summary of all active exchanges
     * @param None
     */
    market_sum_list_t get_market_summaries();

    /**
     * Get the last 24 hour summary of all active exchanges
     * @param market a string literal for the market (ex: BTC-LTC)
     */
    market_sum_list_t get_market_summary(const std::string &market);

    /**
     * Get retrieve the orderbook for a given market
     * @param market a string literal for the market (ex: BTC-LTC)
     * @param type buy, sell or both to identify the type of orderbook to return
     */
    order_book_t get_order_book(const std::string &market, const std::string &type);

    /**
     * Retrieve the latest trades that have occured for a specific market
     * @param market a string literal for the market (ex: BTC-LTC)
     */
    trade_list_t get_market_history(const std::string &market);

};
} //Namespace Api
} //Namespace Bittrex
