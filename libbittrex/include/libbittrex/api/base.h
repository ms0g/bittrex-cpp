#ifndef BITTREX_CPP_BASE_H
#define BITTREX_CPP_BASE_H

#include <type_traits>

using namespace std;

template<typename T>
struct is_std_vector : false_type {
};

template<typename T>
struct is_std_vector<std::vector<T>> : true_type {
};


namespace bittrex {
namespace api {

class Base {
public:
    explicit Base(std::shared_ptr<ApiCall> &api_call) : _api_call(api_call) {}

    template<typename T, typename M, typename ... Params>
    typename std::enable_if<is_std_vector<T>::value, T>::type
    api_request(const std::string &endpoint, ApiType type, const Params &... rest) {
        T res_arr;
        json res = _api_call->dispatch(endpoint, type, rest...);
        auto j_res = res["result"];

        for (auto const &e:j_res) {
            res_arr.emplace_back(M(e));
        }
        return res_arr;

    }

    template<typename T, typename M, typename ... Params>
    typename std::enable_if<!is_std_vector<T>::value, T>::type
    api_request(const std::string &endpoint, ApiType type, const Params &... rest) {
        json res = _api_call->dispatch(endpoint, type, rest...);
        auto j_res = res["result"];
        try {
            return M(j_res);
        } catch (...) {
            return M(j_res[0]);
        }


    }

private:
    std::shared_ptr<ApiCall> &_api_call;


};
}
}
#endif //BITTREX_CPP_BASE_H
