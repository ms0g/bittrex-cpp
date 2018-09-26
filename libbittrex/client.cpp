#include "client.h"

using namespace bittrex;

api::Public Client::public_api() {
    return api::Public(m_api_call);
}

api::Market Client::market_api() {
    return api::Market(m_api_call);
}

api::Account Client::account_api() {
    return api::Account(m_api_call);
}
