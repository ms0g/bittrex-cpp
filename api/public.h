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

using namespace std;
using namespace bittrex;

namespace bittrex {
    namespace api {
        typedef vector<response::Market> VecMarket;
        typedef vector<response::Currency> VecCurrency;
        typedef vector<response::MarketSummary> VecMarketSum;
        typedef vector<response::Trade> VecTrade;

        class Public {
        public:
            explicit Public(shared_ptr<Connection> connection) :
                    connection(move(connection)) {};

            /* Get the open and available trading markets at Bittrex along with other meta data */
            VecMarket get_markets();

            /* Get all supported currencies at Bittrex along with other meta data */
            VecCurrency get_currencies();

            /* Get the current tick values for a market */
            response::Ticker get_ticker(const string &market);

            /* Get the last 24 hour summary of all active exchanges */
            VecMarketSum get_market_summaries();

            /* Get the last 24 hour summary of all active exchanges */
            response::MarketSummary get_market_summary(const string &market);

            /* Get retrieve the orderbook for a given market */
            response::OrderBook get_order_book(const string &market, const string &type);

            /* Retrieve the latest trades that have occured for a specific market */
            VecTrade get_market_history(const string &market);

        private:
            shared_ptr<Connection> connection;
        };
    }
}
#endif //BITTREX_CPP_PUBLIC_H
