#pragma once

#include <string>
#include <boost/property_tree/ptree.hpp>

namespace bittrex::model {

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
    }

    Market(const Market &other) {
        market_currency = other.market_currency;
        base_currency = other.base_currency;
        market_currency_long = other.market_currency_long;
        base_currency_long = other.base_currency_long;
        min_trade_size = other.min_trade_size;
        market_name = other.market_name;
        is_active = other.is_active;
        created = other.created;
    }

    Market &operator=(const Market &other) noexcept {
        if (this != &other) {
            market_currency = other.market_currency;
            base_currency = other.base_currency;
            market_currency_long = other.market_currency_long;
            base_currency_long = other.base_currency_long;
            min_trade_size = other.min_trade_size;
            market_name = other.market_name;
            is_active = other.is_active;
            created = other.created;
        }
        return *this;
    }

    Market(Market &&other) noexcept {
        market_currency = std::move(other.market_currency);
        base_currency = std::move(other.base_currency);
        market_currency_long = std::move(other.market_currency_long);
        base_currency_long = std::move(other.base_currency_long);
        min_trade_size = std::move(other.min_trade_size);
        market_name = std::move(other.market_name);
        is_active = std::move(other.is_active);
        created = std::move(other.created);
    }
    
    Market &operator=(Market &&other) noexcept {
        if (this != &other) {
            market_currency = std::move(other.market_currency);
            base_currency = std::move(other.base_currency);
            market_currency_long = std::move(other.market_currency_long);
            base_currency_long = std::move(other.base_currency_long);
            min_trade_size = std::move(other.min_trade_size);
            market_name = std::move(other.market_name);
            is_active = std::move(other.is_active);
            created = std::move(other.created);
        }
        return *this;
    }

    std::string market_currency;
    std::string base_currency;
    std::string market_currency_long;
    std::string base_currency_long;
    std::string min_trade_size;
    std::string market_name;
    std::string is_active;
    std::string created;
};
} //Namespace bittrex
