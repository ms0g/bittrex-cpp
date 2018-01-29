#ifndef BITTREX_UTILS_H
#define BITTREX_UTILS_H

#include <string>
#include <sstream>
#include <openssl/hmac.h> //HMAC
#include "json.hpp"

using json=nlohmann::json;

namespace bittrex {
    namespace lib {


        enum class ApiType : int {
            PUBLIC, MARKET, ACCOUNT
        };

        /**
         * Generic list implementation
         */
        template <typename T>
        using List = std::vector<T>;

        /**
         * Functions to make payloads
         */
        template<typename T>
        std::string make_params(const T &t) {
            std::stringstream ss;

            ss << t;
            if (ss.str().empty())
                return std::string("");

            size_t found = ss.str().find('=');
            if (found == std::string::npos)
                ss << "&";
            return ss.str();
        }

        template<typename First, typename ... Strings>
        std::string make_params(First arg, const Strings &... rest) {
            return make_params(arg) + make_params(rest...);
        };

        /**
         * Create Hash-based Message Authentication Code.It is a type of message authentication code (MAC)
         * involving a hash function in combination with a key.
         * HMAC can be used to verify the integrity of a message as well as the authenticity.
         */
        std::string hmac_sha512(const std::string &uri, const std::string &secret);
    }
}
#endif //BITTREX_UTILS_H
