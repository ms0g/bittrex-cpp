#ifndef BITTREX_CPP_EXCEPTIONS_H
#define BITTREX_CPP_EXCEPTIONS_H

#include <iostream>
#include <exception>
#include <utility>

using namespace std;

class fail:public exception{
public:
    explicit fail(std::string msg ): msg(std::move(msg)){}

    const char* what() const throw() override {
        return msg.c_str();
    }

private:
    std::string msg;

};
#endif //BITTREX_CPP_EXCEPTIONS_H
