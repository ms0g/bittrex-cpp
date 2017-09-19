#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <sstream>

#include "request.h"

using namespace bittrex;

std::string Request::get(std::string uri) {
    std::stringstream res;
    try {
        curlpp::Cleanup cleanup;
        curlpp::Easy r;

        r.setOpt(cURLpp::Options::WriteStream(&res));
        r.setOpt(curlpp::options::Url(BASE_URL + uri));
        r.perform();
    }
    catch (curlpp::RuntimeError &e) {
        std::cout << e.what() << std::endl;
    }

    catch (curlpp::LogicError &e) {
        std::cout << e.what() << std::endl;
    }
    return res.str();
}
