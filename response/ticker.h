#ifndef BITTREX_CPP_RES_TICKER_H
#define BITTREX_CPP_RES_TICKER_H

#include "../libs/json/json.hpp"


using json=nlohmann::json;

namespace bittrex {
    namespace response {
        struct Ticker {
            explicit Ticker(json j_ticker);

            float bid;
            float ask;
            float last;

        };
    }
}
#endif //BITTREX_CPP_TICKER_H
