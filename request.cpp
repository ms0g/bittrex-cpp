#include <curlpp/cURLpp.hpp> //curlpp::cleanup
#include <curlpp/Options.hpp> //curlpp::Options
#include <curlpp/Easy.hpp> //curlpp::Easy
#include <openssl/hmac.h> //HMAC
#include <sstream> //std::stringstream
#include <ctime> //std::time
#include "request.h"

#define PUBLIC 0

using namespace bittrex;

std::string Request::get(const std::string &key,
                         const std::string &secret,
                         const std::string &payloads,
                         const std::string &endpoint,
                         int method) {

    std::stringstream res;
    auto uri = BASE_URL + endpoint;

    try {
        curlpp::Cleanup cleanup;
        std::list<std::string> headers;
        curlpp::Easy r;

        auto nonce = std::time(nullptr);
        if (method != PUBLIC)
            uri += "apikey=" + key + "&nonce=" + std::to_string(nonce) + "&" + payloads;
        else
            uri += payloads;

        std::string apisign = "apisign:" + utils::hmac_sha512(uri, secret);
        headers.push_back(apisign);

        r.setOpt(cURLpp::options::HttpHeader(headers));
        r.setOpt(cURLpp::Options::WriteStream(&res));
        r.setOpt(curlpp::options::Url(uri));
        r.perform();
    }
    catch (curlpp::RuntimeError &e) {
        std::cout << e.what() << std::endl;
    }

    catch (curlpp::LogicError &e) {
        std::cout << e.what() << std::endl;
    }
    return res.str();
}


std::string utils::hmac_sha512(const std::string &uri, const std::string &secret) {
    unsigned char *digest;
    digest = HMAC(EVP_sha512(),
                  reinterpret_cast<const unsigned char *>(secret.c_str()), secret.length(),
                  reinterpret_cast<const unsigned char *>(uri.c_str()), uri.length(),
                  NULL, NULL);

    char sha512_str[HMAC_MAX_MD_CBLOCK];
    for (int i = 0; i < 64; i++)
        sprintf(&sha512_str[i * 2], "%02x", (unsigned int) digest[i]);

    return std::string(sha512_str);
}
