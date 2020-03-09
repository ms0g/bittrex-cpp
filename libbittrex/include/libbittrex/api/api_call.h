#ifndef BITTREX_CPP_API_CALL_H
#define BITTREX_CPP_API_CALL_H

#include <memory>
#include <utility>
#include <sstream>
#include <future>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <libbittrex/lib/exceptions.h>
#include <libbittrex/api/api_type.h>
#include <libbittrex/lib/libcurlpp.h>
#include <libbittrex/lib/hmac.h>


namespace pt=boost::property_tree;
namespace btx=bittrex::lib;

template<typename T>
auto make_params(const T &t) {
    std::stringstream ss;

    ss << t;
    if (ss.str().empty())
        return std::string("");

    size_t found = ss.str().find('=');
    if (found == std::string::npos)
        ss << "&";
    return std::move(ss.str());
}

template<typename T, typename ... Args>
auto make_params(T arg, const Args &... rest) {
    return make_params(arg) + make_params(rest...);
}


namespace bittrex {

class ApiCall {
private:
    static constexpr const char *BASE_URL = "https://api.bittrex.com/api/v1.1/";
public:
    explicit ApiCall(const std::string &key, const std::string &secret) :
            m_key(key),
            m_secret(secret) {}


    static std::string get(const std::string &key, const std::string &secret, const std::string &payloads,
                           const std::string &endpoint, const Type &type) {
        std::string res;
        auto wd = std::make_shared<curl::options::WriteData>(res);

        std::string uri = BASE_URL + endpoint;

        if (type != Type::PUBLIC)
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

        return std::move(res);

    }

    template<typename ... Params>
    void dispatch(const std::string &endpoint, const Type &type, pt::ptree &json_tree, const Params &... rest) {
        // Create uri params
        std::string payloads = make_params(rest...);

        auto async_get = [&](const std::string &endpoint, const std::string &payloads, const Type &type) {
            auto fut = std::async(std::launch::async, get, m_key, m_secret, payloads, endpoint, type);
            return fut;
        };
        std::stringstream ss;
        ss << async_get(endpoint, payloads, type).get();
        try {
            pt::read_json(ss, json_tree);
        } catch (...) {
            throw fail("Failed json reading: " + ss.str());
        }

        auto success = json_tree.get<bool>("success");
        if (!success) {
            std::string msg = json_tree.get<std::string>("message");
            throw fail(msg);
        }

    }

private:
    const std::string &m_key;
    const std::string &m_secret;
};
} //Namespace Bittrex


#endif //BITTREX_CPP_API_CALL_H
