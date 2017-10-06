#include "connection.h"
#include "request.h"

using namespace bittrex;

std::string Connection::execute_request(const std::string &endpoint, const std::string &payloads, int method) {
    return Request::get(key, secret, payloads, endpoint, method);
}
