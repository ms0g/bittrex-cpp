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
        Request(std::string key, std::string secret, std::string payloads) :
                key(std::move(key)), secret(std::move(secret)), payloads(std::move(payloads)) {}

        std::string get(std::string endpoint, int method);

    private:
        const std::string key;
        const std::string secret;
        const std::string payloads;

    };
}
#endif //BITTREX_CPP_REQUEST_H
