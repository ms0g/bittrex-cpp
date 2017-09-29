#include "account.h"

using namespace bittrex::api;
using json = nlohmann::json;


VecBalance Account::get_balances() {
    VecBalance balances;

    json res = dispatch("account/getbalances?", ACCOUNT, "");

    auto j_balances = res["result"];
    for (auto const &balance:j_balances) {
        balances.emplace_back(response::Balance(balance));
    }
    return balances;
}


response::Balance Account::get_balance(const std::string& currency) {
    json res = dispatch("account/getbalance?", ACCOUNT, "currency=", currency);
    auto balance = res["result"];
    return response::Balance(balance);

}


response::DepositAddress Account::get_deposit_address(const std::string &currency) {
    json res = dispatch("account/getdepositaddress?", ACCOUNT, "currency=", currency);
    auto dep_addr = res["result"];
    return response::DepositAddress(dep_addr);

}


std::string Account::withdraw(const std::string &currency, float quantity, const std::string &address) {
    json res = dispatch("account/withdraw?", ACCOUNT, "currency=", currency,"quantity=",quantity,"address=",address);
    return res["result"];
}


response::Order Account::get_order(const std::string &uuid) {
    json res = dispatch("account/getorder", ACCOUNT, "uuid=", uuid);
    auto order = res["result"];
    return response::Order(order);
}


VecOrderHistoryEnt Account::get_order_history(const string &market) {
    VecOrderHistoryEnt order_history;

    json res = dispatch("account/getorderhistory", ACCOUNT, "market=", market);

    auto order_his = res["result"];
    for (auto const &or_his:order_history) {
        order_history.emplace_back(response::OrderHistoryEntry(or_his));
    }
    return order_history;
}


VecWithdHisEnt Account::get_withdrawal_history(const string &currency) {
    VecWithdHisEnt withd_history;

    json res = dispatch("account/getwithdrawalhistory?", ACCOUNT, "currency=", currency);
    auto withd_his = res["result"];
    for (auto const &withd_his_ent:withd_his){
        withd_history.emplace_back(response::WithdrawalHistoryEntry(withd_his_ent));
    }
    return withd_history;
}


