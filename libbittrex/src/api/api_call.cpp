#include <libbittrex/api/api_call.h>

using namespace bittrex;

std::string ApiCall::make_request(const std::string &key, const std::string &secret, const std::string &payloads,
                                  const std::string &endpoint, const bittrex::api::Type &type) {
    std::string res;
    auto wd = std::make_shared<curl::options::WriteData>(res);

    std::string uri = BASE_URL + endpoint;

    if (type != bittrex::api::Type::PUBLIC)
        uri += "apikey=" + key + "&nonce=" + std::to_string(std::time(nullptr)) +
               "&" + payloads;
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

    return res;
}
