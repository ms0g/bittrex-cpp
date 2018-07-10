#ifndef BITTREX_CPP_RES_WITHDRAWAL_HISTORY_H
#define BITTREX_CPP_RES_WITHDRAWAL_HISTORY_H

#include "../lib/json.hpp"
#include "../lib/wrappers.h"

using json=nlohmann::json;
using namespace bittrex::lib;

namespace bittrex {
namespace response {

struct WithdrawalHistoryEntry {
    explicit WithdrawalHistoryEntry(json wthe) {
        payment_uuid = wthe["PaymentUuid"];
        currency = wthe["Currency"];
        amount = wthe["Amount"];
        address = wthe["Address"];
        opened = wthe["Opened"];
        authorized = wthe["Authorized"];
        pending_payment = wthe["PendingPayment"];
        tx_cost = wthe["TxCost"];
        tx_id = wthe["TxId"];
        canceled = wthe["TxId"];
        invalid_address = wthe["InvalidAddress"];
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
}
}
#endif //BITTREX_CPP_WITHDRAWAL_HISTORY_H
