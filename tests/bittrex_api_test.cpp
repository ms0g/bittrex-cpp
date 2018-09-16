#define BOOST_TEST_MODULE BittrexApiTest
#include <iostream>
#include <vector>
#include <libbittrex/client.h>
#include <boost/test/included/unit_test.hpp>


namespace bittrex {
namespace test {

bittrex::Client btxcli("", "");
auto p = btxcli.get_public_api();
const std::string &MARKET = "BTC-LTC";


BOOST_AUTO_TEST_SUITE(PublicApiTest)
BOOST_AUTO_TEST_CASE(TestingGetMarkets) {
    BOOST_REQUIRE_NO_THROW(p.get_markets());
    auto markets = p.get_markets();
    BOOST_CHECK(!markets.empty());
}

BOOST_AUTO_TEST_CASE(TestingGetCurrencies) {
    BOOST_REQUIRE_NO_THROW(p.get_currencies());
    auto currencies = p.get_currencies();
    BOOST_CHECK(!currencies.empty());

}

BOOST_AUTO_TEST_CASE(TestingGetTicker) {
    BOOST_CHECK_NO_THROW(p.get_ticker(MARKET));
}

BOOST_AUTO_TEST_CASE(TestingGetMarketSummaries) {
    BOOST_REQUIRE_NO_THROW(p.get_market_summaries());
    auto market_summaries = p.get_market_summaries();
    BOOST_CHECK(!market_summaries.empty());
}

BOOST_AUTO_TEST_CASE(TestingGetMarketSummary) {
    BOOST_CHECK_NO_THROW(p.get_market_summary(MARKET));
}

BOOST_AUTO_TEST_CASE(TestingGetOrderBook) {
    BOOST_REQUIRE_NO_THROW(p.get_order_book(MARKET, "both"));
    auto order_book = p.get_order_book(MARKET, "both");
    BOOST_CHECK(!order_book.buy.empty());
    BOOST_CHECK(!order_book.sell.empty());
}

BOOST_AUTO_TEST_CASE(TestingGetMarketHistory) {
    BOOST_REQUIRE_NO_THROW(p.get_market_history(MARKET));
    auto market_history = p.get_market_history(MARKET);
    BOOST_CHECK(!market_history.empty());
}

BOOST_AUTO_TEST_SUITE_END()
}
}
