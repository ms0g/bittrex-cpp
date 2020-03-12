#ifndef BITTREX_CPP_RES_DEPOSIT_ADDRESS_H
#define BITTREX_CPP_RES_DEPOSIT_ADDRESS_H

#include <boost/property_tree/ptree.hpp>


namespace bittrex {
    namespace model {

        struct DepositAddress {
            explicit DepositAddress(boost::property_tree::ptree &j) {
                currency = j.get<std::string>("Currency");
                address = j.get<std::string>("Address");
            };

            std::string currency;
            std::string address;

        };
    } //Namespace model
} //Namespace bittrex
#endif //BITTREX_CPP_DEPOSIT_ADDRESS_H
