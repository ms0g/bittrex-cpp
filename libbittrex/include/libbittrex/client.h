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
    template <typename T>
    explicit Client(T&& key, T&& secret) :
            m_api_call(std::make_shared<bittrex::ApiCall>(std::forward<T>(key), std::forward<T>(secret))) {}


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
