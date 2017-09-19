#ifndef BITTREX_CPP_EXCEPTIONS_H
#define BITTREX_CPP_EXCEPTIONS_H

#include <iostream>
#include <exception>
#include <utility>

using namespace std;

class fail:public exception{
    const char* what() const throw() override {
        return "Api call failed!";
    }

};
#endif //BITTREX_CPP_EXCEPTIONS_H
