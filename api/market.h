#ifndef BITTREX_CPP_API_MARKET_H
#define BITTREX_CPP_API_MARKET_H

#include <memory>
#include <utility>
#include "../connection.h"
#include "../response/open_order.h"
#include "api_call.h"

using namespace bittrex;

namespace bittrex {
    namespace api {

        typedef vector<response::OpenOrder> VecOpenOrder;

        class Market:public ApiCall{
        public:
            explicit Market(const std::shared_ptr<Connection>& connection) :
                    ApiCall(connection) {};

            /**
             * Used to place a buy order in a specific market.
             * Use buylimit to place limit orders.
             * @param market a string literal for the market (ex: BTC-LTC)
             * @param quantity the amount to purchase
             * @param rate the rate at which to place the order.
             */
            std::string buy_limit(const std::string &market, float quantity, float rate);

            /**
             * Used to place an sell order in a specific market.
             * Use selllimit to place limit orders.
             * @param market a string literal for the market (ex: BTC-LTC)
             * @param quantity the amount to purchase
             * @param rate the rate at which to place the order.
             */
            std::string sell_limit(const std::string &market, float quantity, float rate);

            /**
             * Used to cancel a buy or sell order.
             * @param uuid uuid of buy or sell order
             */
            std::string cancel(const std::string &uuid);

            /**
             * Get all orders that you currently have opened. A specific market can be requested
             * @param market optional a string literal for the market (ie. BTC-LTC)
             * */
            VecOpenOrder get_open_orders(const std::string &market);
        };
    }
}
#endif //BITTREX_CPP_MARKET_H
