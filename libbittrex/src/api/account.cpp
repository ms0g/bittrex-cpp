#include <libbittrex/api/account.h>

using namespace bittrex::api;

balance_list_t Account::get_balances() {
    auto res = api_request<balance_list_t, balance_t>(BALANCES_END_P, bittrex::api::Type::ACCOUNT, "");
    return res;
}


balance_t Account::get_balance(const std::string &currency) {
    auto res = api_request<balance_t, balance_t>(BALANCE_END_P, bittrex::api::Type::ACCOUNT, "currency=",
                                                 currency);
    return res;

}


deposit_address_t Account::get_deposit_address(const std::string &currency) {
    auto res = api_request<deposit_address_t, deposit_address_t>(DEPOSITADDR_END_P, bittrex::api::Type::ACCOUNT,
                                                                 "currency=", currency);
    return res;

}


uuid_t Account::withdraw(const std::string &currency, const float &quantity,
                         const std::string &address, const int &payment_id) {

    auto res = api_request<uuid_t, uuid_t>(WITHDRAW_END_P, bittrex::api::Type::ACCOUNT,
                                           "currency=", currency, "quantity=", quantity,
                                           "address=", address, "paymentid=", payment_id);
    return res;
}


order_t Account::get_order(const std::string &uuid) {
    auto res = api_request<order_t, order_t>(ORDER_END_P, bittrex::api::Type::ACCOUNT, "uuid=", uuid);
    return res;
}


order_history_ent_list_t Account::get_order_history(const std::string &market) {
    //    json res = (!market.empty()) ?
//               _api_call->dispatch("account/getorderhistory?", bittrex::api::Type::ACCOUNT, "market=", market):
//               _api_call->dispatch("account/getorderhistory?", bittrex::api::Type::ACCOUNT, "");

    auto res = api_request<order_history_ent_list_t, order_history_ent_t>(ORDER_HIS_END_P,
                                                                          bittrex::api::Type::ACCOUNT, "market=",
                                                                          market);
    return res;
}


withdrawal_history_ent_list_t Account::get_withdrawal_history(const std::string &currency) {
    auto res = api_request<withdrawal_history_ent_list_t, withdrawal_history_ent_t>(
            WITHDRAWAL_HIS_END_P, bittrex::api::Type::ACCOUNT, "currency=", currency);
    return res;
}


