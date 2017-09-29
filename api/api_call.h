#ifndef BITTREX_CPP_API_CALL_H
#define BITTREX_CPP_API_CALL_H

#include <memory>
#include <utility>
#include <sstream>
#include "../connection.h"
#include "../libs/json/json.hpp"
#include "exceptions.h"

using json = nlohmann::json;

namespace utils {

    /* Helper functions */
    template<typename T>
    std::string make_params(const T& t) {
        stringstream ss;

        ss << t;
        if (ss.str().empty())
            return string("");

        size_t found = ss.str().find('=');
        if (found == std::string::npos)
            ss << "&";
        return ss.str();
    }

    template<typename First, typename ... Strings>
    std::string make_params(First arg, const Strings &... rest) {
        return make_params(arg) + make_params(rest...);
    };
}

namespace bittrex{
    namespace api{

        class ApiCall{
        public:
            explicit ApiCall(const std::shared_ptr<Connection>& connection):
                    connection(connection){}

        protected:
            template <typename ... Params>
            json dispatch(const std::string &endpoint, int type, const Params&... rest){
                std::string parameters = utils::make_params(rest...);

                auto res = connection->execute_request(endpoint, parameters, type);
                auto j_res = json::parse(res);

                if (!j_res["success"]){
                    std::string msg = j_res["message"];
                    throw fail(msg);
                }
                return j_res;
            };

            std::shared_ptr<Connection> connection;
        };
    }
}



#endif //BITTREX_CPP_API_CALL_H
