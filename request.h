#ifndef BITTREX_CPP_REQUEST_H
#define BITTREX_CPP_REQUEST_H

#include <iostream>

static const std::string BASE_URL = "https://bittrex.com/api/v1.1/";

namespace bittrex {
    class Request {
    public:
        static std::string get(std::string uri);

    };
}
#endif //BITTREX_CPP_REQUEST_H
