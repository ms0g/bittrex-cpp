#include <future>
#include "connection.h"
#include "request.h"

using namespace bittrex;

std::string Connection::execute_request_async(const std::string &endpoint,
                                              const std::string &payloads,
                                              ApiType type) {

    auto fut = std::async(std::launch::async, Request::get, m_key, m_secret, payloads, endpoint, type);
    return fut.get();
}
