#include "client.h"

using namespace bittrex;

api::Public Client::get_public() {
    return api::Public(connection);
}

api::Market Client::get_market() {
    return api::Market(connection);
}
