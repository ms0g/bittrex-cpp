#ifndef BITTREX_CPP_API_CALL_H
#define BITTREX_CPP_API_CALL_H

#include <memory>
#include <utility>
#include <sstream>
#include <future>
#include "../lib/json.hpp"
#include "../lib/utils.h"
#include "../lib/exceptions.h"
#include "../lib/libcurlpp.h"

using json = nlohmann::json;
using namespace bittrex::lib;

static const std::string BASE_URL = "https://bittrex.com/api/v1.1/";


namespace bittrex {
namespace Request {

std::string get(const std::string &key,
                const std::string &secret,
                const std::string &payloads,
                const std::string &endpoint,
                ApiType type) {

    std::string res;
    auto uri = BASE_URL + endpoint;

    try {
        Curl curl;
        auto nonce = std::time(nullptr);
        (type != ApiType::PUBLIC) ?
                uri += "apikey=" + key + "&nonce=" + std::to_string(nonce) + "&" + payloads :
                uri += payloads;

        std::string apisign = "apisign:" + hmac_sha512(uri, secret);
        curl.setOpt(new curl::options::HttpHeader(apisign));
        curl.setOpt(new curl::options::WriteData(res));
        curl.setOpt(new curl::options::Url(uri));

        curl.perform();
    }
    catch (fail &e) {
        std::cout << e.what() << std::endl;
    }
    return res;
}
} //Namespace Request

namespace api {

class ApiCall {
public:
    explicit ApiCall(std::string &key, std::string &secret) :
            m_key(key),
            m_secret(secret) {}

    template<typename ... Params>
    json dispatch(const std::string &endpoint, ApiType type, const Params &... rest) {
        // Create uri params
        std::string payloads = make_params(rest...);

        // execute request
        auto res = execute_request_async(endpoint, payloads, type);
        auto j_res = json::parse(res);

        if (!j_res["success"]) {
            std::string msg = j_res["message"];
            throw fail(msg);
        }
        return j_res;
    }

private:
    std::string execute_request_async(const std::string &endpoint,
                                      const std::string &payloads,
                                      ApiType type) {

        auto fut = std::async(std::launch::async, Request::get, m_key, m_secret, payloads, endpoint, type);
        return fut.get();
    }

    std::string &m_key;
    std::string &m_secret;
};
} //Namespace Api
} //Namespace Bittrex


#endif //BITTREX_CPP_API_CALL_H
