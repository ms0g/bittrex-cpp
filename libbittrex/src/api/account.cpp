#include <libbittrex/api/account.h>

using namespace bittrex::api;

balance_list_t Account::get_balances() {
    return api_request<balance_list_t, balance_t>("account/getbalances?", bittrex::api::Type::ACCOUNT, "");
}


balance_t Account::get_balance(const std::string &currency) {
    return api_request<balance_t, balance_t>("account/getbalance?", bittrex::api::Type::ACCOUNT, "currency=", currency);
}


deposit_address_t Account::get_deposit_address(const std::string &currency) {
    return api_request<deposit_address_t, deposit_address_t>(
        "account/getdepositaddress?", bittrex::api::Type::ACCOUNT, "currency=", currency);

}


btx_uuid_t Account::withdraw(
    const std::string &currency, const float &quantity, const std::string &address, const int &payment_id) {
        return api_request<btx_uuid_t, btx_uuid_t>(
            "account/withdraw?", bittrex::api::Type::ACCOUNT, 
            "currency=", currency, "quantity=", quantity, "address=", address, "paymentid=", payment_id);
}


order_t Account::get_order(const std::string &uuid) {
    return api_request<order_t, order_t>("account/getorder?", bittrex::api::Type::ACCOUNT, "uuid=", uuid);
}


order_history_ent_list_t Account::get_order_history(const std::string &market) {
    return api_request<order_history_ent_list_t, order_history_ent_t>(
        "account/getorderhistory?", bittrex::api::Type::ACCOUNT, "market=", market);
}


withdrawal_history_ent_list_t Account::get_withdrawal_history(const std::string &currency) {
    return api_request<withdrawal_history_ent_list_t, withdrawal_history_ent_t>(
        "account/getwithdrawalhistory?", bittrex::api::Type::ACCOUNT, "currency=", currency);
}


