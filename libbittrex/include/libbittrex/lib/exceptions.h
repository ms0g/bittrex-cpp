#pragma once

#include <iostream>
#include <exception>
#include <utility>

namespace bittrex {

class fail : public std::exception {
public:
    explicit fail(std::string &msg) : msg(msg) {}

    explicit fail(std::string &&msg) : msg(std::move(msg)) {}

    const char *what() const noexcept override {
        return msg.c_str();
    }

private:
    std::string msg;

};
}
