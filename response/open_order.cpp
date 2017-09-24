#include "open_order.h"

using namespace bittrex::response;

OpenOrder::OpenOrder(json j_order) {
     uuid=j_order["Uuid"];
     order_uuid=j_order["OrderUuid"];
     exchange=j_order["Exchange"];
     order_type =j_order["OrderType"];
     quantity=j_order["Quantity"];
     quantity_remaining=j_order["QuantityRemaining"];
     limit=j_order["Limit"];
     commission_paid=j_order["CommissionPaid"];
     price=j_order["Price"];
     price_per_unit =j_order["PricePerUnit"];
     opened=j_order["Opened"];
     closed =j_order["Closed"];
     cancel_initiated =j_order["CancelInitiated"];
     immediate_or_cancel =j_order["ImmediateOrCancel"];
     is_conditional =j_order["IsConditional"];
     condition =j_order["Condition"];
     condition_target=j_order["ConditionTarget"];

}
