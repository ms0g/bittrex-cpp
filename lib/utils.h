#ifndef BITTREX_BITTLIB_H
#define BITTREX_BITTLIB_H

#include <string>
#include <sstream>
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
         * Wrapper for primitive types
         */
        class String {
        public:
            String &operator=(const json &s) {
                m_val = s.is_null() ? "" : s.get<std::string>();
                return *this;
            }

            friend std::ostream &operator<<(std::ostream &out, const String &s) {
                return out << s.m_val;
            }

        private:
            std::string m_val;

        };


        class Int {
        public:
            Int &operator=(const json &i) {
                m_val = i.is_null() ? 0 : i.get<int>();
                return *this;
            };

            friend std::ostream &operator<<(std::ostream &out, const Int &i) {
                return out << i.m_val;
            }

            constexpr int operator+(const Int &i) { return m_val + i.m_val; }
            constexpr int operator-(const Int &i) { return m_val - i.m_val; }
            constexpr int operator*(const Int &i) { return m_val * i.m_val; }

        private:
            int m_val;

        };


        class Double {
        public:
            Double &operator=(const json &d) {
                m_val = d.is_null() ? 0.0 : d.get<double>();
                return *this;
            };

            friend std::ostream &operator<<(std::ostream &out, const Double &d) {
                return out << d.m_val;
            }

            constexpr double operator+(const Double &d) { return m_val + d.m_val; }
            constexpr double operator-(const Double &d) { return m_val - d.m_val; }
            constexpr double operator*(const Double &d) { return m_val * d.m_val; }

        private:
            double m_val;

        };
    }
}
#endif //BITTREX_BITTLIB_H
