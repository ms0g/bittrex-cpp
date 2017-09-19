#include "ticker.h"

using namespace bittrex::response;

Ticker::Ticker(json j_ticker) {
    bid = j_ticker["Bid"];
    ask = j_ticker["Ask"];
    last = j_ticker["Last"];
}
