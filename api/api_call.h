#ifndef BITTREX_CPP_API_CALL_H
#define BITTREX_CPP_API_CALL_H

#include <memory>
#include <utility>
#include <sstream>
#include "../connection.h"
#include "../lib/json.hpp"
#include "../lib/utils.h"
#include "exceptions.h"

using json = nlohmann::json;
using namespace bittrex::lib;



namespace bittrex {
    namespace api {
        /**
         * parent class to bittrex's API
         */
        class ApiCall {
        public:
            explicit ApiCall(std::shared_ptr<Connection> connection) :
                    m_connection(std::move(connection)) {}

        protected:
            const std::shared_ptr<Connection> m_connection;

            template<typename ... Params>
            json dispatch(const std::string &endpoint, ApiType type, const Params &... rest) {
                // Create uri params
                std::string payloads = make_params(rest...);

                // execute request
                auto res = m_connection->execute_request(endpoint, payloads, type);
                auto j_res = json::parse(res);

                if (!j_res["success"]) {
                    std::string msg = j_res["message"];
                    throw fail(msg);
                }
                return j_res;
            };


        };
    }
}


#endif //BITTREX_CPP_API_CALL_H
