#include "connection.h"
#include "request.h"

using namespace bittrex;

std::string Connection::execute_request(const std::string &endpoint, const std::string& params, int method) {
    switch (method) {
        case PUBLIC:
            return Request::get(endpoint + params);
        case ACCOUNT:
        case MARKET:
            return Request::get(endpoint + params + "key=" + key);

        default:
            break;
    }


}

