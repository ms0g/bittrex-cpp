#ifndef BITTREX_CPP_EXCEPTIONS_H
#define BITTREX_CPP_EXCEPTIONS_H

#include <iostream>
#include <exception>
#include <utility>


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

#endif //BITTREX_CPP_EXCEPTIONS_H
