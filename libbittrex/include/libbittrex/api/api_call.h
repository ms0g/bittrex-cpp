#ifndef BITTREX_CPP_API_CALL_H
#define BITTREX_CPP_API_CALL_H

#include <memory>
#include <utility>
#include <sstream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <libbittrex/lib/utils.h>
#include <libbittrex/lib/exceptions.h>



namespace btx=bittrex::lib;
namespace pt=boost::property_tree;


namespace bittrex {

class ApiCall {
private:
    static constexpr const char* BASE_URL = "https://api.bittrex.com/api/v1.1/";
public:
    explicit ApiCall(const string &key, const string &secret) :
            m_key(key),
            m_secret(secret) {}

    template<typename ... Params>
    void dispatch(const string &endpoint, const btx::ApiType &type,pt::ptree &json_tree, const Params &... rest) {
        stringstream ss;
        // Create uri params
        string payloads = btx::make_params(rest...);

        // execute request
        auto res = execute_request_async(endpoint, payloads, type);
        
        ss << res;
        pt::read_json(ss,json_tree);
        
        auto success = json_tree.get<bool>("success");
        if (!success) {
            string msg = json_tree.get<string>("message");
            throw fail(msg);
        }
       
    }

    static string get(const string &, const string &, const string &, const string &, const btx::ApiType &);

private:
    string execute_request_async(const string &, const string &, const btx::ApiType &);

    const string &m_key;
    const string &m_secret;
};
} //Namespace Bittrex


#endif //BITTREX_CPP_API_CALL_H
