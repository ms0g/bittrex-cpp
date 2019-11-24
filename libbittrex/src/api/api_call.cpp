#include <future>
#include <libbittrex/api/api_call.h>
#include <libbittrex/lib/hmac.h>
#include <libbittrex/lib/libcurlpp.h>

using namespace bittrex;
namespace btx=bittrex::lib;

std::string ApiCall::execute_request_async(const std::string &endpoint,
                                      const std::string &payloads,
                                      const Type &type) {

    auto fut = std::async(std::launch::async, ApiCall::get, m_key, m_secret, payloads, endpoint, type);
    return std::move(fut.get());
}

std::string ApiCall::get(const std::string &key, const std::string &secret, const std::string &payloads, const std::string &endpoint,
                    const Type &type) {
    std::string res;
    auto wd = std::make_shared<curl::options::WriteData>(res);

    std::string uri = BASE_URL + endpoint;

    if (type != Type::PUBLIC)
        uri += "apikey=" + key + "&nonce=" + std::to_string(std::time(nullptr)) + "&" + payloads;
    else uri += payloads;

    auto url = std::make_shared<curl::options::Url>(uri);

    std::string apisign = "apisign:" + hmac_sha512(uri, secret);
    auto hh = std::make_shared<curl::options::HttpHeader>(apisign);

    btx::Curl curl;
    curl.setOpt(hh);
    curl.setOpt(wd);
    curl.setOpt(url);

    try {
        curl.perform();
    }
    catch (fail &e) {
        std::cout << e.what() << std::endl;
    }

    return std::move(res);
}

