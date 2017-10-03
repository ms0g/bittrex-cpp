#ifndef BITTREX_CPP_CONNECTION_H
#define BITTREX_CPP_CONNECTION_H

#include <iostream>
#include <utility>


namespace bittrex {

    /**
     * Connection class to Bittrex API
     */
    class Connection {
    public:
        explicit Connection(std::string key, std::string secret) :
                key(std::move(key)), secret(std::move(secret)) {};

        std::string execute_request(const std::string &endpoint, const std::string &params, int method);

    private:
        const std::string key;
        const std::string secret;

    };
}
#endif //BITTREX_CPP_CONNECTION_H
