#pragma once

#include <string>
#include <boost/property_tree/ptree.hpp>

namespace bittrex::model {

struct MarketSummary {
    explicit MarketSummary(boost::property_tree::ptree &j) {
        market_name = j.get<std::string>("MarketName");
        high = j.get<std::string>("High");
        low = j.get<std::string>("Low");
        volume = j.get<std::string>("Volume");
        last = j.get<std::string>("Last");
        base_volume = j.get<std::string>("BaseVolume");
        time_stamp = j.get<std::string>("TimeStamp");
        bid = j.get<std::string>("Bid");
        ask = j.get<std::string>("Ask");
        open_buy_orders = j.get<std::string>("OpenBuyOrders");
        open_sell_orders = j.get<std::string>("OpenSellOrders");
        prev_day = j.get<std::string>("PrevDay");
        created = j.get<std::string>("Created");
    }

    MarketSummary(const MarketSummary &other) {
        market_name = other.market_name;
        high = other.high;
        low = other.low;
        volume = other.volume;
        last = other.last;
        base_volume = other.base_volume;
        time_stamp = other.time_stamp;
        bid = other.bid;
        ask = other.ask;
        open_buy_orders = other.open_buy_orders;
        open_sell_orders = other.open_sell_orders;
        prev_day = other.prev_day;
        created = other.created;
    }

    MarketSummary(MarketSummary &&other) noexcept {
        market_name = std::move(other.market_name);
        high = std::move(other.high);
        low = std::move(other.low);
        volume = std::move(other.volume);
        last = std::move(other.last);
        base_volume = std::move(other.base_volume);
        time_stamp = std::move(other.time_stamp);
        bid = std::move(other.bid);
        ask = std::move(other.ask);
        open_buy_orders = std::move(other.open_buy_orders);
        open_sell_orders = std::move(other.open_sell_orders);
        prev_day = std::move(other.prev_day);
        created = std::move(other.created);
    }

    MarketSummary &operator=(MarketSummary &&other) noexcept {
        if (this != &other) {
            market_name = std::move(other.market_name);
            high = std::move(other.high);
            low = std::move(other.low);
            volume = std::move(other.volume);
            last = std::move(other.last);
            base_volume = std::move(other.base_volume);
            time_stamp = std::move(other.time_stamp);
            bid = std::move(other.bid);
            ask = std::move(other.ask);
            open_buy_orders = std::move(other.open_buy_orders);
            open_sell_orders = std::move(other.open_sell_orders);
            prev_day = std::move(other.prev_day);
            created = std::move(other.created);
        }
        return *this;
    }

    std::string market_name;
    std::string high;
    std::string low;
    std::string volume;
    std::string last;
    std::string base_volume;
    std::string time_stamp;
    std::string bid;
    std::string ask;
    std::string open_buy_orders;
    std::string open_sell_orders;
    std::string prev_day;
    std::string created;

};
} //Namespace bittrex
