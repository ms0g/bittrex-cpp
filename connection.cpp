#include "connection.h"
#include "request.h"

using namespace bittrex;

std::string Connection::execute_request(const std::string &endpoint, const std::string &payloads, ApiType type) {
    return Request::get(m_key, m_secret, payloads, endpoint, type);
}
