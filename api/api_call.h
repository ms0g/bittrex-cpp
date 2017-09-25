#ifndef BITTREX_CPP_API_CALL_H
#define BITTREX_CPP_API_CALL_H

#include <memory>
#include <utility>
#include <sstream>
#include "../connection.h"
#include "../libs/json/json.hpp"
#include "exceptions.h"

using namespace std;
using json = nlohmann::json;

namespace utils {

    /* Helper functions to make paramaters part of uri. */
    template<typename T>
    string make_params(const T &t) {
        stringstream ss;
        size_t found = string(t).find('=');
        if (found != string::npos)
            ss << t;
        else
            ss << t << "&";
        return ss.str();
    }

    template<typename First, typename ... Strings>
    string make_params(First arg, const Strings &... rest) {
        return make_params(arg) + make_params(rest...);
    };
}

namespace bittrex{
    namespace api{

        class ApiCall{
        public:
            explicit ApiCall(shared_ptr<Connection> connection):
                    connection(move(connection)){}

        protected:
            json dispatch(const string &endpoint, const char *params, int type){
                string res = connection->execute_request(endpoint, params, type);
                auto j_res = json::parse(res);
                if (!j_res["success"])
                    throw fail();
                return j_res;
            };

            shared_ptr<Connection> connection;
        };
    }
}



#endif //BITTREX_CPP_API_CALL_H
