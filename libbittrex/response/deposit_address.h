#ifndef BITTREX_CPP_RES_DEPOSIT_ADDRESS_H
#define BITTREX_CPP_RES_DEPOSIT_ADDRESS_H

#include "../lib/json.hpp"
#include "../lib/wrappers.h"

using json=nlohmann::json;
using namespace bittrex::lib;

namespace bittrex {
namespace response {

struct DepositAddress {
    explicit DepositAddress(json j_deposit) {
        currency = j_deposit["Currency"];
        address = j_deposit["Address"];
    };

    String currency;
    String address;

};
} //Namespace Response
} //Namespace bittrex
#endif //BITTREX_CPP_DEPOSIT_ADDRESS_H
