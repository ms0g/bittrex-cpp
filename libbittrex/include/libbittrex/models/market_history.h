#ifndef BITTREX_CPP_RES_MARKET_HISTORY_H
#define BITTREX_CPP_RES_MARKET_HISTORY_H

#include <json.hpp>
#include <libbittrex/lib/wrappers.h>

using json=nlohmann::json;
using namespace bittrex::lib;

namespace bittrex {
namespace model {

struct Trade {
    explicit Trade(json j) {
        id = j["Id"];
        time_stamp = j["TimeStamp"];
        quantity = j["Quantity"];
        price = j["Price"];
        total = j["Total"];
        fill_type = j["FillType"];
        order_type = j["OrderType"];
    };

    Int id;
    String time_stamp;
    Double quantity;
    Double price;
    Double total;
    String fill_type;
    String order_type;
};
} //Namespace model
} //Namespace bittrex
#endif //BITTREX_CPP_MARKET_HISTORY_H
