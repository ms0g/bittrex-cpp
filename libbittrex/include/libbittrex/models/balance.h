#ifndef BITTREX_CPP_RES_BALANCE_H
#define BITTREX_CPP_RES_BALANCE_H

#include <json.hpp>
#include <libbittrex/lib/wrappers.h>

using json=nlohmann::json;
using namespace bittrex::lib;

namespace bittrex {
namespace model {

struct Balance {
    explicit Balance(json j) {
        currency = j["Currency"];
        balance = j["Balance"];
        available = j["Available"];
        pending = j["Pending"];
        crypto_address = j["CryptoAddress"];
        requested = j["Requested"];
        uuid = j["Uuid"];
    };

    String currency;
    Double balance;
    Double available;
    Double pending;
    String crypto_address;
    Double requested;
    String uuid;

};
} //Namespace model
} //Namespace bittrex
#endif //BITTREX_CPP_BALANCE_H
