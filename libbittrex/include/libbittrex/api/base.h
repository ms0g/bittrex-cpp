#pragma once

#include <type_traits>
#include <boost/foreach.hpp>
#include <libbittrex/api/api_call.h>
#include <libbittrex/api/api_type.h>

namespace bittrex {
namespace util {

template<typename T>
struct is_std_vector : std::false_type {
};

template<typename T>
struct is_std_vector<std::vector<T>> : std::true_type {
};
}

namespace api {

class Base {
public:
    explicit Base(const std::shared_ptr<ApiCall> &api_call) : _api_call(api_call) {}

    template<typename T, typename M, typename ... Params>
    typename std::enable_if<util::is_std_vector<T>::value, T>::type
    api_request(const char *endpoint, const Type &type, Params &&... rest) {
        T res_arr;
        pt::ptree json_tree;

        _api_call->dispatch(endpoint, type, json_tree, std::forward<Params>(rest)...);

        BOOST_FOREACH(pt::ptree::value_type &child,
                      json_tree.get_child("result")) {
                        res_arr.emplace_back(M(child.second));
                    }

        return res_arr;
    }

    template<typename T, typename M, typename ... Params>
    typename std::enable_if<!util::is_std_vector<T>::value, M>::type
    api_request(const char *endpoint, const Type &type, Params &&... rest) {
        pt::ptree json_tree;
        _api_call->dispatch(endpoint, type, json_tree, std::forward<Params>(rest)...);
        auto res = json_tree.get_child("result");

        return M(res);
    }


private:
    const std::shared_ptr<ApiCall> &_api_call;


};
}
}//Namespace bittrex
