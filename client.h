#ifndef BITTREX_CPP_CLIENT_H
#define BITTREX_CPP_CLIENT_H

#include <iostream>
#include <memory>
#include "connection.h"
#include "api/public.h"
#include "api/market.h"
#include "api/account.h"

namespace bittrex {
    class Client {
    public:
        explicit Client(const std::string &key, const std::string &secret) :
                m_connection(make_shared<Connection>(key, secret)) {}

        /**
         * Used for public information available without an API key
         */
        api::Public get_public();

        /**
         * Used for programatic trading of crypto currencies
         */
        api::Market get_market();

        /**
         * Used for managing your account
         */
        api::Account get_account();


    private:
        std::shared_ptr<Connection> m_connection;
    };
}
#endif //BITTREX_CPP_CLIENT_H
