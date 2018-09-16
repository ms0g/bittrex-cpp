#include "client.h"

using namespace bittrex;

api::Public Client::get_public_api() {
    return api::Public(std::move(m_connection));
}

api::Market Client::get_market_api() {
    return api::Market(std::move(m_connection));
}

api::Account Client::get_account_api() {
    return api::Account(std::move(m_connection));
}
