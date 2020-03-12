#ifndef BITTREX_CPP_RES_MARKET_SUMMARY_H
#define BITTREX_CPP_RES_MARKET_SUMMARY_H

#include <boost/property_tree/ptree.hpp>

namespace bittrex {
    namespace model {

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
            };

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
    } //Namespace model
} //Namespace bittrex

#endif //BITTREX_CPP_MARKET_SUMMARY_H
