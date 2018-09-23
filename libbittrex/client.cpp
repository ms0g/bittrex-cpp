#include "client.h"

using namespace bittrex;

api::Public Client::public_api() {
    return api::Public(std::move(m_api_call));
}

api::Market Client::market_api() {
    return api::Market(std::move(m_api_call));
}

api::Account Client::account_api() {
    return api::Account(std::move(m_api_call));
}
