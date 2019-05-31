#include <libbittrex/api_call.h>
#include <future>

#include <libbittrex/lib/libcurlpp.h>

using namespace bittrex;

static const std::string BASE_URL = "https://api.bittrex.com/api/v1.1/";

std::string ApiCall::execute_request_async(const std::string &endpoint,
                                           const std::string &payloads,
                                           const ApiType &type) {

    auto fut = std::async(std::launch::async, ApiCall::get, m_key, m_secret, payloads, endpoint, type);
    return fut.get();
}

std::string ApiCall::get(const std::string &key, const std::string &secret,
                         const std::string &payloads, const std::string &endpoint, const ApiType &type) {
    std::string res;
    auto wd = std::make_shared<curl::options::WriteData>(res);

    std::string uri = BASE_URL + endpoint;

    if (type != ApiType::PUBLIC)
        uri += "apikey=" + key + "&nonce=" + std::to_string(std::time(nullptr)) + "&" + payloads;
    else uri += payloads;

    auto url = std::make_shared<curl::options::Url>(uri);

    std::string apisign = "apisign:" + hmac_sha512(uri, secret);
    auto hh = std::make_shared<curl::options::HttpHeader>(apisign);

    Curl curl;
    curl.setOpt(hh);
    curl.setOpt(wd);
    curl.setOpt(url);

    try {
        curl.perform();
    }
    catch (fail &e) {
        std::cout << e.what() << std::endl;
    }

    return res;
}

