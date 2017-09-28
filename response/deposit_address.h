#ifndef BITTREX_CPP_RES_DEPOSIT_ADDRESS_H
#define BITTREX_CPP_RES_DEPOSIT_ADDRESS_H
#include <iostream>
#include "../libs/json/json.hpp"

using json=nlohmann::json;

namespace bittrex {
    namespace response {
        struct DepositAddress {
            explicit DepositAddress(json j_deposit){
                currency=j_deposit["Currency"];
                address=j_deposit["Address"];
            };
            std::string currency;
            std::string address;

        };
    }
}
#endif //BITTREX_CPP_DEPOSIT_ADDRESS_H
