#pragma once

#include <string>
#include <boost/property_tree/ptree.hpp>

namespace bittrex::model {

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

    WithdrawalHistoryEntry(const WithdrawalHistoryEntry &other){
        payment_uuid = other.payment_uuid;
        currency = other.currency;
        amount = other.amount;
        address = other.address;
        opened = other.opened;
        authorized = other.authorized;
        pending_payment = other.pending_payment;
        tx_cost = other.tx_cost;
        tx_id = other.tx_id;
        canceled = other.canceled;
        invalid_address = other.invalid_address;
    }

    WithdrawalHistoryEntry &operator=(const WithdrawalHistoryEntry &other) noexcept {
        if (this != &other) {
            payment_uuid = other.payment_uuid;
            currency = other.currency;
            amount = other.amount;
            address = other.address;
            opened = other.opened;
            authorized = other.authorized;
            pending_payment = other.pending_payment;
            tx_cost = other.tx_cost;
            tx_id = other.tx_id;
            canceled = other.canceled;
            invalid_address = other.invalid_address;
        }
        return *this;
    }

    WithdrawalHistoryEntry(WithdrawalHistoryEntry &&other) noexcept {
        payment_uuid = std::move(other.payment_uuid);
        currency = std::move(other.currency);
        amount = std::move(other.amount);
        address = std::move(other.address);
        opened = std::move(other.opened);
        authorized = std::move(other.authorized);
        pending_payment = std::move(other.pending_payment);
        tx_cost = std::move(other.tx_cost);
        tx_id = std::move(other.tx_id);
        canceled = std::move(other.canceled);
        invalid_address = std::move(other.invalid_address);
    }

    WithdrawalHistoryEntry &operator=(WithdrawalHistoryEntry &&other) noexcept {
        if (this != &other) {
            payment_uuid = std::move(other.payment_uuid);
            currency = std::move(other.currency);
            amount = std::move(other.amount);
            address = std::move(other.address);
            opened = std::move(other.opened);
            authorized = std::move(other.authorized);
            pending_payment = std::move(other.pending_payment);
            tx_cost = std::move(other.tx_cost);
            tx_id = std::move(other.tx_id);
            canceled = std::move(other.canceled);
            invalid_address = std::move(other.invalid_address);
        }
        return *this;
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
} //Namespace bittrex
