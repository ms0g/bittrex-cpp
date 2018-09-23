#ifndef BITTREX_CPP_CLIENT_H
#define BITTREX_CPP_CLIENT_H

#include <iostream>
#include <memory>
#include "api/public.h"
#include "api/market.h"
#include "api/account.h"
#include "api/api_call.h"

namespace bittrex {

class Client {
public:
    explicit Client(std::string &key, std::string &secret) :
            m_api_call(make_unique<bittrex::api::ApiCall>(key, secret)) {}

    /**
     * Used for public information available without an API key
     */
    api::Public public_api();

    /**
     * Used for programatic trading of crypto currencies
     */
    api::Market market_api();

    /**
     * Used for managing your account
     */
    api::Account account_api();


private:
    std::unique_ptr<bittrex::api::ApiCall> m_api_call;
};
}
#endif //BITTREX_CPP_CLIENT_H
