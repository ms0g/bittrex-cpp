#ifndef BITTREX_CPP_RES_CURRENCY_H
#define BITTREX_CPP_RES_CURRENCY_H

#include <json.hpp>
#include <libbittrex/lib/wrappers.h>

using json=nlohmann::json;
using namespace bittrex::lib;

namespace bittrex {
namespace model {

struct Currency {
    explicit Currency(json j) {
        currency = j["Currency"];
        currency_long = j["CurrencyLong"];
        min_confirmation = j["MinConfirmation"];
        txfee = j["TxFee"];
        is_active = j["IsActive"];
        coin_type = j["CoinType"];
        base_address = j["BaseAddress"];
    };

    String currency;
    String currency_long;
    Int min_confirmation;
    Double txfee;
    bool is_active;
    String coin_type;
    String base_address;

};
} //Namespace model
} //Namespace bittrex

#endif //BITTREX_CPP_CURRENCY_H
