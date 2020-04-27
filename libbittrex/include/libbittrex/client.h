#pragma once

#include <iostream>
#include <memory>
#include <libbittrex/api/public.h>
#include <libbittrex/api/market.h>
#include <libbittrex/api/account.h>
#include <libbittrex/api/api_call.h>


namespace bittrex {

class Client {
public:
    explicit Client(const std::string& key, const std::string& secret) :
            m_api_call(std::make_shared<bittrex::ApiCall>(key, secret)) {}

    Client(const char *key, const char *secret) :
            m_api_call(std::make_shared<bittrex::ApiCall>(std::string(key),
                                                          std::string(secret))) {}

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
    std::shared_ptr<bittrex::ApiCall> m_api_call;
};
} //Namespace Bittrex
