#ifndef BITTREX_CPP_CONNECTION_H
#define BITTREX_CPP_CONNECTION_H

#include <iostream>
#include <utility>
#include "lib/utils.h"

using namespace bittrex::lib;


namespace bittrex {

/**
 * Connection class to Bittrex API
 */
class Connection {
public:
    explicit Connection(std::string key, std::string secret) :
            m_key(std::move(key)), m_secret(std::move(secret)) {};

    std::string execute_request(const std::string &endpoint, const std::string &paylods, ApiType type);

private:
    const std::string m_key;
    const std::string m_secret;

};
}
#endif //BITTREX_CPP_CONNECTION_H
