#ifndef BITTREX_CPP_UUID_H
#define BITTREX_CPP_UUID_H
#include <json.hpp>
#include <libbittrex/lib/wrappers.h>

using json=nlohmann::json;
using namespace bittrex::lib;

namespace bittrex {
namespace model {

struct Uuid {
    explicit Uuid(json j) {
        uuid = j["uuid"];

    };

    String uuid;

};
} //Namespace model
} //Namespace bittrex
#endif //BITTREX_CPP_UUID_H
