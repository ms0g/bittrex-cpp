#ifndef BITTREX_CPP_RES_WITHDRAWAL_HISTORY_H
#define BITTREX_CPP_RES_WITHDRAWAL_HISTORY_H
#include <iostream>
#include "../libs/json/json.hpp"

using json=nlohmann::json;

namespace bittrex {
    namespace response {
        struct WithdrawalHistoryEntry{
            explicit WithdrawalHistoryEntry(json wthe){
                 payment_uuid=wthe["PaymentUuid"];
                 currency=wthe["Currency"];
                 amount=wthe["Amount"];
                 address=wthe["Address"];
                 opened=wthe["Opened"];
                 authorized=wthe["Authorized"];
                 pending_payment=wthe["PendingPayment"];
                 tx_cost=wthe["TxCost"];
                 tx_id=wthe["TxId"];
                 canceled=wthe["TxId"];
                 invalid_address=wthe["InvalidAddress"];
            }
         std::string payment_uuid;
         std::string currency;
         std::string amount;
         std::string address;
         std::string opened;
         bool authorized;
         bool pending_payment;
         float tx_cost;
         std::string tx_id;
         bool canceled;
         bool invalid_address;
        };
    }
}
#endif //BITTREX_CPP_WITHDRAWAL_HISTORY_H
