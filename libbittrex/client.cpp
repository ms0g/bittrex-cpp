#include "client.h"

using namespace bittrex;

api::Public Client::get_public() {
    return api::Public(std::move(m_connection));
}

api::Market Client::get_market() {
    return api::Market(std::move(m_connection));
}

api::Account Client::get_account() {
    return api::Account(std::move(m_connection));
}
