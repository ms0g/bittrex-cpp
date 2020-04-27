#pragma once

#include <boost/property_tree/ptree.hpp>

namespace bittrex {
namespace model {

struct WithdrawalHistoryEntry {
    explicit WithdrawalHistoryEntry(boost::property_tree::ptree &j) {
        payment_uuid = j.get<std::string>("PaymentUuid");
        currency = j.get<std::string>("Currency");
        amount = j.get<std::string>("Amount");
        address = j.get<std::string>("Address");
        opened = j.get<std::string>("Opened");
        authorized = j.get<std::string>("Authorized");
        pending_payment = j.get<std::string>("PendingPayment");
        tx_cost = j.get<std::string>("TxCost");
        tx_id = j.get<std::string>("TxId");
        canceled = j.get<std::string>("TxId");
        invalid_address = j.get<std::string>("InvalidAddress");
    }

    std::string payment_uuid;
    std::string currency;
    std::string amount;
    std::string address;
    std::string opened;
    std::string authorized;
    std::string pending_payment;
    std::string tx_cost;
    std::string tx_id;
    std::string canceled;
    std::string invalid_address;
};
} //Namespace model
} //Namespace bittrex
