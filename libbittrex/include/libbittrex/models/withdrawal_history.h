#ifndef BITTREX_CPP_RES_WITHDRAWAL_HISTORY_H
#define BITTREX_CPP_RES_WITHDRAWAL_HISTORY_H

#include <json.hpp>
#include <libbittrex/lib/wrappers.h>

using json=nlohmann::json;
using namespace bittrex::lib;

namespace bittrex {
namespace model {

struct WithdrawalHistoryEntry {
    explicit WithdrawalHistoryEntry(json j) {
        payment_uuid = j["PaymentUuid"];
        currency = j["Currency"];
        amount = j["Amount"];
        address = j["Address"];
        opened = j["Opened"];
        authorized = j["Authorized"];
        pending_payment = j["PendingPayment"];
        tx_cost = j["TxCost"];
        tx_id = j["TxId"];
        canceled = j["TxId"];
        invalid_address = j["InvalidAddress"];
    }

    String payment_uuid;
    String currency;
    Int amount;
    String address;
    String opened;
    bool authorized;
    bool pending_payment;
    Double tx_cost;
    String tx_id;
    String canceled;
    bool invalid_address;
};
} //Namespace model
} //Namespace bittrex
#endif //BITTREX_CPP_WITHDRAWAL_HISTORY_H
