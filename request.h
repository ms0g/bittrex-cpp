#ifndef BITTREX_CPP_REQUEST_H
#define BITTREX_CPP_REQUEST_H

#include <iostream>
#include <utility>

static const std::string BASE_URL = "https://bittrex.com/api/v1.1/";

namespace utils {
    std::string hmac_sha512(const std::string &uri, const std::string &secret);
}

namespace bittrex {

    class Request {
    public:
        static std::string get(const std::string &key,
                               const std::string &secret,
                               const std::string &payloads,
                               const std::string &endpoint,
                               int method);
    };
}
#endif //BITTREX_CPP_REQUEST_H
