#ifndef BITTREX_CPP_API_PUBLIC_H
#define BITTREX_CPP_API_PUBLIC_H

#include <iostream>
#include <memory>
#include <utility>
#include "../connection.h"
#include "../response/market.h"
#include "../response/currency.h"
#include "../response/ticker.h"
#include "../response/market_summary.h"
#include "../response/order_book.h"
#include "../response/market_history.h"
#include "api_call.h"

using namespace bittrex;
using namespace utils;

namespace bittrex {
    namespace api {

        class Public : public ApiCall {
        public:
            explicit Public(const std::shared_ptr<Connection> &connection) :
                    ApiCall(connection) {}

            /**
             * Get the open and available trading markets at Bittrex along with other meta data
             * @param None
             */
            List<response::Market> get_markets();

            /**
             * Get all supported currencies at Bittrex along with other meta data
             * @param None
             */
            List<response::Currency> get_currencies();

            /**
             * Get the current tick values for a market
             * @param market a string literal for the market (ex: BTC-LTC)
             */
            response::Ticker get_ticker(const std::string &market);

            /**
             * Get the last 24 hour summary of all active exchanges
             * @param None
             */
            List<response::MarketSummary> get_market_summaries();

            /**
             * Get the last 24 hour summary of all active exchanges
             * @param market a string literal for the market (ex: BTC-LTC)
             */
            response::MarketSummary get_market_summary(const std::string &market);

            /**
             * Get retrieve the orderbook for a given market
             * @param market a string literal for the market (ex: BTC-LTC)
             * @param type buy, sell or both to identify the type of orderbook to return
             */
            response::OrderBook get_order_book(const std::string &market, const std::string &type);

            /**
             * Retrieve the latest trades that have occured for a specific market
             * @param market a string literal for the market (ex: BTC-LTC)
             */
            List<response::Trade> get_market_history(const std::string &market);

        };
    }
}
#endif //BITTREX_CPP_PUBLIC_H
