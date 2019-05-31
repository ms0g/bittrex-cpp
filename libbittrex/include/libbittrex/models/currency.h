#ifndef BITTREX_CPP_RES_CURRENCY_H
#define BITTREX_CPP_RES_CURRENCY_H

#include <json.hpp>
#include <libbittrex/lib/wrappers.h>

using json=nlohmann::json;
using namespace bittrex::lib;

namespace bittrex {
namespace model {

struct Currency {
    explicit Currency(json j_currency) {
        currency = j_currency["Currency"];
        currency_long = j_currency["CurrencyLong"];
        min_confirmation = j_currency["MinConfirmation"];
        txfee = j_currency["TxFee"];
        is_active = j_currency["IsActive"];
        coin_type = j_currency["CoinType"];
        base_address = j_currency["BaseAddress"];
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
