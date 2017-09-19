#include "market_history.h"

using namespace bittrex::response;

Trade::Trade(json j_market_his) {
    id = j_market_his["Id"];
    time_stamp = j_market_his["TimeStamp"];
    quantity = j_market_his["Quantity"];
    price = j_market_his["Price"];
    total = j_market_his["Total"];
    fill_type = j_market_his["FillType"];
    order_type = j_market_his["OrderType"];

}
