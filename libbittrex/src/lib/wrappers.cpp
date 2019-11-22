#include <libbittrex/lib/wrappers.h>

using namespace bittrex::lib;

String &String::operator=(const json &s) {
    _s = s.is_null() ? "" : s.get<std::string>();
    return *this;
}

String &String::operator=(const String &other) {
    _s = this != &other ? other._s : _s;
    return *this;
}

String &String::operator=(String &&other) noexcept {
    _s = this != &other ? std::move(other._s) : _s;
    other.reset();
    return *this;
}

String &String::operator+(String &other) {
    _s += other._s;
    return *this;
}

String &String::operator+=(String &other) {
    _s += other._s;
    return *this;
}


Int &Int::operator=(const json &other) {
    _i = other.is_null() ? 0 : other.get<int>();
    return *this;
}

Int &Int::operator=(const Int &other) {
    _i = this != &other ? other._i : _i;
    return *this;
}

Int &Int::operator+(const Int &other) {
    _i += other._i;
    return *this;
}

Int &Int::operator-(const Int &other) {
    _i -= other._i;
    return *this;
}

Int &Int::operator*(const Int &other) {
    _i *= other._i;
    return *this;
}


Double &Double::operator=(const json &other) {
    _d = other.is_null() ? 0.0 : other.get<double>();
    return *this;
}

Double &Double::operator=(const Double &other) {
    _d = this != &other ? other._d : _d;
    return *this;
}

Double &Double::operator+(const Double &other) {
    _d += other._d;
    return *this;
}

Double &Double::operator-(const Double &other) {
    _d -= other._d;
    return *this;
}

Double &Double::operator*(const Double &other) {
    _d *= other._d;
    return *this;
}


