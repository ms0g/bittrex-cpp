#ifndef BITTREX_CPP_RES_BALANCE_H
#define BITTREX_CPP_RES_BALANCE_H
#include <iostream>
#include "../lib/json.hpp"
#include "../lib/utils.h"
#include "../lib/primitive_wrapper.h"

using json=nlohmann::json;
using namespace bittrex::lib;

namespace bittrex {
    namespace response {
        struct Balance {
            explicit Balance(json j_balance){
                currency=j_balance["Currency"];
                balance=j_balance["Balance"];
                available=j_balance["Available"];
                pending=j_balance["Pending"];
                crypto_address=j_balance["CryptoAddress"];
                requested=j_balance["Requested"];
                uuid=j_balance["Uuid"];
            };
            String currency;
            Double balance;
            Double available;
            Double pending;
            String crypto_address;
            Double requested;
            String uuid;

        };
    }
}
#endif //BITTREX_CPP_BALANCE_H
