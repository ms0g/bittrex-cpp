#include "currency.h"

using namespace bittrex::response;

Currency::Currency(json j_currency) {
    currency = j_currency["Currency"];
    currency_long = j_currency["CurrencyLong"];
    min_confirmation = j_currency["MinConfirmation"];
    txfee = j_currency["TxFee"];
    is_active = j_currency["IsActive"];
    coin_type = j_currency["CoinType"];

    auto cur = j_currency["BaseAddress"];
    base_address = (cur != nullptr) ? cur : "";

}
