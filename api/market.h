#ifndef BITTREX_CPP_API_MARKET_H
#define BITTREX_CPP_API_MARKET_H

#include <memory>
#include <utility>
#include "../connection.h"
#include "../response/open_order.h"
#include "api_call.h"

using namespace std;
using namespace bittrex;

namespace bittrex {
    namespace api {

        typedef vector<response::OpenOrder> VecOpenOrder;

        class Market:public ApiCall{
        public:
            explicit Market(shared_ptr<Connection> connection) :
                    ApiCall(move(connection)) {};

            /* Used to place a buy order in a specific market.
             * Use buylimit to place limit orders. */
            string buy_limit(const string &market, float quantity, float rate);

            /* Used to place an sell order in a specific market.
             * Use selllimit to place limit orders. */
            string sell_limit(const string &market, float quantity, float rate);

            /* Used to cancel a buy or sell order. */
            string cancel(const string &uuid);

            /* Get all orders that you currently have opened. A specific market can be requested */
            VecOpenOrder get_open_orders(const string &market);
        };
    }
}
#endif //BITTREX_CPP_MARKET_H
