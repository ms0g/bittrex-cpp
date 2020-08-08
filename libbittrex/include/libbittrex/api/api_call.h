#pragma once

#include <memory>
#include <utility>
#include <sstream>
#include <future>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <libbittrex/lib/exceptions.h>
#include <libbittrex/api/api_type.h>
#include <libbittrex/lib/libcurlpp.hpp>
#include <libbittrex/lib/hmac.h>


namespace pt = boost::property_tree;
namespace btx = bittrex::lib;

using payload_t = std::optional<std::string>;

namespace bittrex::util {

template<typename T>
payload_t make_params(T &&t) {
    std::stringstream ss;
    
    ss << std::forward<T>(t);
    if (ss.str().empty())
        return std::nullopt;
    
    size_t found = ss.str().find('=');
    if (found == std::string::npos)
        ss << "&";
    return ss.str();
}

template<typename T, typename ... Args>
payload_t make_params(T &&arg, Args &&... rest) {
    return make_params(std::forward<T>(arg)).value_or("") + make_params(std::forward<Args>(rest)...).value_or("");
}
} //Namespace util

namespace bittrex {
class ApiCall {
private:
    static constexpr char const *BASE_URL = "https://api.bittrex.com/api/v1.1/";
public:
    explicit ApiCall(std::string key, std::string secret) :
    m_key(std::move(key)),
    m_secret(std::move(secret)) {}
    
    template<typename ... Params>
    void dispatch(const char *endpoint, const bittrex::api::Type &type, pt::ptree &json_tree, Params &&... rest) {
        /* Create uri params */
        auto payloads = util::make_params(std::forward<Params>(rest)...);
        
        auto fut = std::async(std::launch::async, [&](){
            std::string res;
            btx::Curl curl;
            
            curl.setOpt<curl::options::WriteData>(res);
            
            auto &&uri = BASE_URL + std::string{endpoint};
            
            if (type != bittrex::api::Type::PUBLIC) {
                uri += "apikey=" + m_key + "&nonce=" + std::to_string(std::time(nullptr)) + "&" + payloads.value_or("");
            }else {
                uri += payloads.value_or("");
                
            }
            
            curl.setOpt<curl::options::Url>(std::move(uri));
            
            auto &&apisign = "apisign:" + hmac_sha512(uri, m_secret);
            curl.setOpt<curl::options::HttpHeader>(std::move(apisign));
            
            
            try {
                curl.perform();
            }
            catch (fail &e) {
                std::cout << e.what() << std::endl;
            }
            
            return res;
            
        });
        
        std::stringstream ss;
        ss << fut.get();
        try {
            pt::read_json(ss, json_tree);
        } catch (...) {
            throw fail("Failed json reading: " + ss.str());
        }
        
        if (auto success = json_tree.get<bool>("success"); !success) {
            auto &&msg = json_tree.get<std::string>("message");
            throw fail(msg);
        }
    }
    
    
private:
    std::string m_key;
    std::string m_secret;
};
} //Namespace Bittrex
