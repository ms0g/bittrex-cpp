#ifndef BITTREX_CPP_API_CALL_H
#define BITTREX_CPP_API_CALL_H

#include <memory>
#include <utility>
#include <sstream>
#include <json.hpp>
#include <libbittrex/lib/utils.h>
#include <libbittrex/lib/exceptions.h>


using json = nlohmann::json;
using namespace bittrex::lib;


namespace bittrex {

class ApiCall {
public:
    explicit ApiCall(const std::string &key, const std::string &secret) :
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

    static std::string get(const std::string &, const std::string &,
                           const std::string &, const std::string &,
                           const ApiType &);

private:
    std::string execute_request_async(const std::string &, const std::string &, const ApiType &);

    const std::string &m_key;
    const std::string &m_secret;
};
} //Namespace Bittrex


#endif //BITTREX_CPP_API_CALL_H
