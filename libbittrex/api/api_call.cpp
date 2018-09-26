#include <future>
#include "api_call.h"

using namespace bittrex::api;

std::string ApiCall::execute_request_async(const std::string &endpoint, const std::string &payloads, ApiType type) {

    auto fut = std::async(std::launch::async, ApiCall::get, m_key, m_secret, payloads, endpoint, type);
    return fut.get();
}

std::string ApiCall::get(const std::string &key, const std::string &secret,
                         const std::string &payloads, const std::string &endpoint, ApiType type) {

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

