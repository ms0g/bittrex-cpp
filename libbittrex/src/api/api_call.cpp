#include <future>
#include <libbittrex/api/api_call.h>
#include <libbittrex/lib/libcurlpp.h>

using namespace bittrex;

string ApiCall::execute_request_async(const string &endpoint,
                                      const string &payloads,
                                      const btx::ApiType &type) {

    auto fut = std::async(std::launch::async, ApiCall::get, m_key, m_secret, payloads, endpoint, type);
    return std::move(fut.get());
}

string ApiCall::get(const string &key, const string &secret, const string &payloads, const string &endpoint,
                    const btx::ApiType &type) {
    string res;
    auto wd = std::make_shared<curl::options::WriteData>(res);

    string uri = BASE_URL + endpoint;

    if (type != btx::ApiType::PUBLIC)
        uri += "apikey=" + key + "&nonce=" + std::to_string(std::time(nullptr)) + "&" + payloads;
    else uri += payloads;

    auto url = std::make_shared<curl::options::Url>(uri);

    string apisign = "apisign:" + btx::hmac_sha512(uri, secret);
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

