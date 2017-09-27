#ifndef BITTREX_CPP_RES_CURRENCY_H
#define BITTREX_CPP_RES_CURRENCY_H

#include <iostream>
#include "../libs/json/json.hpp"

using namespace std;
using json=nlohmann::json;

namespace bittrex {
    namespace response {
        struct Currency {
            explicit Currency(json j_currency){
                currency = j_currency["Currency"];
                currency_long = j_currency["CurrencyLong"];
                min_confirmation = j_currency["MinConfirmation"];
                txfee = j_currency["TxFee"];
                is_active = j_currency["IsActive"];
                coin_type = j_currency["CoinType"];

                auto cur = j_currency["BaseAddress"];
                base_address = (cur != nullptr) ? cur : "";
            };

            string currency;
            string currency_long;
            int min_confirmation;
            float txfee;
            bool is_active;
            string coin_type;
            string base_address;

        };
    }
}

#endif //BITTREX_CPP_CURRENCY_H
