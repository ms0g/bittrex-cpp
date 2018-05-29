#ifndef BITTREX_CPP_RES_TICKER_H
#define BITTREX_CPP_RES_TICKER_H

#include "../lib/json.hpp"
#include "../lib/primitive_wrapper.h"

using json=nlohmann::json;
using namespace bittrex::lib;

namespace bittrex {
    namespace response {
        struct Ticker {
            explicit Ticker(json j_ticker) {
                bid = j_ticker["Bid"];
                ask = j_ticker["Ask"];
                last = j_ticker["Last"];
            };

            Double bid;
            Double ask;
            Double last;

        };
    }
}
#endif //BITTREX_CPP_TICKER_H
