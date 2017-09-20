#ifndef BITTREX_CPP_CLIENT_H
#define BITTREX_CPP_CLIENT_H

#include <iostream>
#include <memory>
#include "connection.h"
#include "api/public.h"

namespace bittrex {
    class Client {
    public:
        explicit Client(const std::string &key) {
            connection = std::make_shared<Connection>(key);
        }
        /* Public information available without an API key */
        api::Public get_public();


    private:
        std::shared_ptr<Connection> connection;
    };
}
#endif //BITTREX_CPP_CLIENT_H
