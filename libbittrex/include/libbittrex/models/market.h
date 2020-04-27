#pragma once

#include <boost/property_tree/ptree.hpp>

namespace bittrex {
namespace model {

struct Market {
    explicit Market(boost::property_tree::ptree &j) {
        market_currency = j.get<std::string>("MarketCurrency");
        base_currency = j.get<std::string>("BaseCurrency");
        market_currency_long = j.get<std::string>("MarketCurrencyLong");
        base_currency_long = j.get<std::string>("BaseCurrencyLong");
        min_trade_size = j.get<std::string>("MinTradeSize");
        market_name = j.get<std::string>("MarketName");
        is_active = j.get<std::string>("IsActive");
        created = j.get<std::string>("Created");
    };

    std::string market_currency;
    std::string base_currency;
    std::string market_currency_long;
    std::string base_currency_long;
    std::string min_trade_size;
    std::string market_name;
    std::string is_active;
    std::string created;
};
} //Namespace model
} //Namespace bittrex