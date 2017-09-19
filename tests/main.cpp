#include <iostream>
#include "../client.h"



int main(){
    std::string key="KMhfok8qMQLEkQxABnCWw";
    bittrex::Client cl(key);
    bittrex::api::Public p =  cl.get_public();
    //p.get_markets();
    //p.get_currencies();
    //p.get_ticker("BTC-LTC");
    //p.get_market_summaries();
    auto sum = p.get_market_history("BTC-LTC");


}
