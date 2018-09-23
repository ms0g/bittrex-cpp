#include "account.h"


using namespace bittrex::api;
using json = nlohmann::json;


List<response::Balance> Account::get_balances() {
    List<response::Balance> balances;

    json res = _api_call->dispatch("account/getbalances?", ApiType::ACCOUNT, "");

    auto j_balances = res["result"];
    for (auto const &balance:j_balances) {
        balances.emplace_back(response::Balance(balance));
    }
    return balances;
}


response::Balance Account::get_balance(const std::string &currency) {
    json res = _api_call->dispatch("account/getbalance?", ApiType::ACCOUNT, "currency=", currency);
    auto balance = res["result"];
    return response::Balance(balance);

}


response::DepositAddress Account::get_deposit_address(const std::string &currency) {
    json res = _api_call->dispatch("account/getdepositaddress?", ApiType::ACCOUNT, "currency=", currency);
    auto dep_addr = res["result"];
    return response::DepositAddress(dep_addr);

}


std::string Account::withdraw(const std::string &currency, float quantity,
                              const std::string &address, int payment_id) {
    json res = _api_call->dispatch("account/withdraw?", ApiType::ACCOUNT,
                                   "currency=", currency, "quantity=", quantity,
                                   "address=", address, "paymentid=", payment_id);
    return res["result"];
}


response::Order Account::get_order(const std::string &uuid) {
    json res = _api_call->dispatch("account/getorder?", ApiType::ACCOUNT, "uuid=", uuid);
    auto order = res["result"];
    return response::Order(order);
}


List<response::OrderHistoryEntry> Account::get_order_history(const string &market) {
    List<response::OrderHistoryEntry> order_history;

    json res = (!market.empty()) ?
               _api_call->dispatch("account/getorderhistory?", ApiType::ACCOUNT, "market=", market):
               _api_call->dispatch("account/getorderhistory?", ApiType::ACCOUNT, "");

    auto order_his = res["result"];
    for (auto const &or_his:order_history) {
        order_history.emplace_back(response::OrderHistoryEntry(or_his));
    }
    return order_history;
}


List<response::WithdrawalHistoryEntry> Account::get_withdrawal_history(const string &currency) {
    List<response::WithdrawalHistoryEntry> withd_history;

    json res = _api_call->dispatch("account/getwithdrawalhistory?", ApiType::ACCOUNT, "currency=", currency);
    auto withd_his = res["result"];
    for (auto const &withd_his_ent:withd_his) {
        withd_history.emplace_back(response::WithdrawalHistoryEntry(withd_his_ent));
    }
    return withd_history;
}


