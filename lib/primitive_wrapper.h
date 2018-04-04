#ifndef BITTREX_PRIMITIVE_WRAPPER_H
#define BITTREX_PRIMITIVE_WRAPPER_H

#include <string>
#include "json.hpp"

using json=nlohmann::json;

namespace bittrex {
    namespace lib {

        /**
         * Wrapper for string to check out null case
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

            /** cast operator */
            explicit operator const char *() const { return m_val.c_str(); }
            explicit operator std::string() const { return m_val; }

        private:
            std::string m_val;

        };

        /**
         * Wrapper for integer to check out null case
         */
        class Int {
        public:
            Int &operator=(const json &i) {
                m_val = i.is_null() ? 0 : i.get<int>();
                return *this;
            };

            friend std::ostream &operator<<(std::ostream &out, const Int &i) {
                return out << i.m_val;
            }

            /** cast operator */
            explicit operator int() const { return m_val; }

            constexpr int operator+(const Int &i) { return m_val + i.m_val; }
            constexpr int operator-(const Int &i) { return m_val - i.m_val; }
            constexpr int operator*(const Int &i) { return m_val * i.m_val; }

        private:
            int m_val;

        };

        /**
         * Wrapper for double to check out null case
         */
        class Double {
        public:
            Double &operator=(const json &d) {
                m_val = d.is_null() ? 0.0 : d.get<double>();
                return *this;
            };

            friend std::ostream &operator<<(std::ostream &out, const Double &d) {
                return out << d.m_val;
            }

            /** cast operator */
            explicit operator double() const { return m_val; }

            constexpr double operator+(const Double &d) { return m_val + d.m_val; }
            constexpr double operator-(const Double &d) { return m_val - d.m_val; }
            constexpr double operator*(const Double &d) { return m_val * d.m_val; }

        private:
            double m_val;

        };
    }
}
#endif //BITTREX_PRIMITIVE_WRAPPER_H
