#ifndef BITTREX_PRIMITIVES_H
#define BITTREX_PRIMITIVES_H

#include <string>
#include <utility>
#include <json.hpp>


using json=nlohmann::json;

namespace bittrex {
namespace lib {

/**
 * Wrapper for string
 */
class String {
public:
    String() {}
    String(const String &other):_s(other._s) {}
    String(String &&rhs) noexcept: _s(std::move(rhs._s)) { rhs.reset(); }
    explicit String(std::string &other):_s(other) {}
    explicit String(std::string &&rhs):_s(std::move(rhs)) {}
    explicit String(const char *s):_s(s) {}


    String &operator=(const json &);
    String &operator=(const String &);
    String &operator=(String &&) noexcept;
    String &operator+(String &);
    String &operator+=(String &);

    friend std::ostream &operator<<(std::ostream &out, const String &s) { return out << s._s; }

    void reset() {_s.clear();}

    /** cast operator */
    explicit operator const char *() const { return _s.c_str(); }
    explicit operator std::string() const { return _s; }

private:
    std::string _s;

};

/**
 * Wrapper for integer
 */
class Int {
public:
    Int() {}
    Int(const Int &other):_i(other._i) {}
    explicit Int(const int &other):_i(other) {}

    Int &operator=(const json &);
    Int &operator=(const Int &);
    Int &operator+(const Int &);
    Int &operator-(const Int &);
    Int &operator*(const Int &);

    friend std::ostream &operator<<(std::ostream &out, const Int &other) { return out << other._i; }

    /** cast operator */
    explicit operator int() const { return _i; }

private:
    int _i;

};

/**
 * Wrapper for double
 */
class Double {
public:
    Double() {}
    Double(const Double &other):_d(other._d) {}
    explicit Double(const double &other):_d(other) {}

    Double &operator=(const json &);
    Double &operator=(const Double &);
    Double &operator+(const Double &);
    Double &operator-(const Double &);
    Double &operator*(const Double &);

    friend std::ostream &operator<<(std::ostream &out, const Double &d) { return out << d._d; }

    /** cast operator */
    explicit operator double() const { return _d; }

private:
    double _d;

};
} //Namespace Lib
} //Namespace Bittrex


#endif //BITTREX_PRIMITIVES_H
