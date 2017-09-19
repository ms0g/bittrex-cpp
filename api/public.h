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
        class Public {
        public:
            explicit Public(shared_ptr<Connection> connection) :
                    connection(std::move(connection)) {};

            vector<response::Market> get_markets();

            vector<response::Currency> get_currencies();

            response::Ticker get_ticker(const string &market);

            vector<response::MarketSummary> get_market_summaries();

            response::MarketSummary get_market_summary(const string &market);

            response::OrderBook get_order_book(const string &market, const string &type);

            vector<response::Trade> get_market_history(const string &market);

        private:
            shared_ptr<Connection> connection;
        };
    }
}
#endif //BITTREX_CPP_PUBLIC_H
