#ifndef BITTREX_CPP_RES_CURRENCY_H
#define BITTREX_CPP_RES_CURRENCY_H

#include <boost/property_tree/ptree.hpp>


namespace bittrex {
namespace model {

struct Currency {
    explicit Currency(boost::property_tree::ptree &j) {
        currency = j.get<std::string>("Currency");
        currency_long = j.get<std::string>("CurrencyLong");
        min_confirmation = j.get<std::string>("MinConfirmation");
        txfee = j.get<std::string>("TxFee");
        is_active = j.get<std::string>("IsActive");
        coin_type = j.get<std::string>("CoinType");
        base_address = j.get<std::string>("BaseAddress");
    };

    std::string currency;
    std::string currency_long;
    std::string min_confirmation;
    std::string txfee;
    std::string is_active;
    std::string coin_type;
    std::string base_address;

};
} //Namespace model
} //Namespace bittrex

#endif //BITTREX_CPP_CURRENCY_H
