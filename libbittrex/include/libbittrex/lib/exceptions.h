#pragma once

#include <iostream>
#include <exception>
#include <utility>

namespace bittrex {

class fail : public std::exception {
public:
    template <typename T>
    explicit fail(T &&msg) : _msg(std::forward<T>(msg)) {}

    const char *what() const noexcept override {
        return _msg.c_str();
    }

private:
    std::string _msg;

};
}
