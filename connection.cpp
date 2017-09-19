#include "connection.h"
#include "request.h"

using namespace bittrex;

std::string Connection::execute_request(std::string endpoint, const char *params, int method) {
    switch (method) {
        case PUBLIC:
            if (params == nullptr)
                return Request::get(endpoint);
            return Request::get(endpoint + params);
        case ACCOUNT:
        case MARKET:
            if (params == nullptr)
                return Request::get(endpoint + "key=" + key);
            return Request::get(endpoint + params + "key=" + key);

        default:
            break;
    }


}

