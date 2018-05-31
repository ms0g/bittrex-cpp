#ifndef BITTREX_CPP_REQUEST_H
#define BITTREX_CPP_REQUEST_H

#include <iostream>
#include <utility>
#include "lib/utils.h"

using namespace bittrex::lib;

static const std::string BASE_URL = "https://bittrex.com/api/v1.1/";

namespace bittrex {

class Request {
public:
    static std::string get(const std::string &key,
                           const std::string &secret,
                           const std::string &payloads,
                           const std::string &endpoint,
                           ApiType type);
};
}
#endif //BITTREX_CPP_REQUEST_H
