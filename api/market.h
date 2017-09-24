#ifndef BITTREX_CPP_API_MARKET_H
#define BITTREX_CPP_API_MARKET_H

#include <memory>
#include "../connection.h"
#include "../response/open_order.h"

using namespace std;
using namespace bittrex;

namespace bittrex {
    namespace api{

        typedef vector<response::OpenOrder> VecOpenOrder;

        class Market{
        public:
            explicit Market(shared_ptr<Connection> connection) :
                    connection(move(connection)) {};
            string buy_limit(const string &market, float quantity, float rate);
            string sell_limit(const string &market, float quantity, float rate);
            string cancel(const string &uuid);
            VecOpenOrder get_open_orders(const string &market);

        private:
            shared_ptr<Connection> connection;


        };


    }
}
#endif //BITTREX_CPP_MARKET_H
