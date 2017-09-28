#ifndef BITTREX_CPP_API_ACCOUNT_H
#define BITTREX_CPP_API_ACCOUNT_H

#include <utility>
#include <vector>
#include "api_call.h"
#include "../response/balance.h"
#include "../response/deposit_address.h"
#include "../response/order.h"
#include "../response/order_history.h"
#include "../response/withdrawal_history.h"

using namespace bittrex;

namespace bittrex{
    namespace api{

        typedef vector<response::Balance> VecBalance;
        typedef vector<response::OrderHistoryEntry> VecOrderHistoryEnt;
        typedef vector<response::WithdrawalHistoryEntry> VecWithdHisEnt;

        class Account:public ApiCall{
        public:
            explicit Account(std::unique_ptr<Connection> connection):ApiCall(std::move(connection)){}

            /* Used to retrieve all balances from your account */
            VecBalance get_balances();

            /* Used to retrieve the balance from your account for a specific currency. */
            response::Balance get_balance(const std::string& currency);

            /* Used to retrieve or generate an address for a specific currency.
             * If one does not exist, the call will fail and return ADDRESS_GENERATING until one is available. */
            response::DepositAddress get_deposit_address(const std::string& currency);

            /* Used to withdraw funds from your account. note: please account for txfee. */
            std::string withdraw(const std::string& currency,float quantity, const std::string& address);

            /* Used to retrieve a single order by uuid. */
            response::Order get_order(const std::string& uuid);

            /* Used to retrieve your order history. */
            VecOrderHistoryEnt get_order_history(const std::string& market="");

            /* Used to retrieve your withdrawal history. */
            VecWithdHisEnt get_withdrawal_history(const std::string& currency="");

            //void get_deposit_history();

        };
    }
}
#endif //BITTREX_CPP_ACCOUNT_H
