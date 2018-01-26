#ifndef BITTREX_BITTLIB_H
#define BITTREX_BITTLIB_H

#include <string>
#include "json.hpp"

using json=nlohmann::json;

namespace bittrex {
    namespace lib {

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

            int operator+(const Int &i) const { return m_val + i.m_val; }
            int operator-(const Int &i) const { return m_val - i.m_val; }
            int operator*(const Int &i) const { return m_val * i.m_val; }

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

            double operator+(const Double &d) const { return m_val + d.m_val; }
            double operator-(const Double &d) const { return m_val - d.m_val; }
            double operator*(const Double &d) const { return m_val * d.m_val; }

        private:
            double m_val;

        };
    }
}
#endif //BITTREX_BITTLIB_H
