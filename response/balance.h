#ifndef BITTREX_CPP_RES_BALANCE_H
#define BITTREX_CPP_RES_BALANCE_H
#include <iostream>
#include "../libs/json/json.hpp"

using json=nlohmann::json;

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
            std::string currency;
            float balance;
            float available;
            float pending;
            std::string crypto_address;
            float requested;
            std::string uuid;

        };
    }
}
#endif //BITTREX_CPP_BALANCE_H
