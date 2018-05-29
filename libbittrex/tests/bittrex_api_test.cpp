#define BOOST_TEST_MODULE BittrexApiTest
#include <iostream>
#include <vector>
#include <bittrex-cpp/client.h>
#include <boost/test/included/unit_test.hpp>



BOOST_AUTO_TEST_SUITE( PublicApiTest )
    bittrex::Client client("","");
    bittrex::api::Public aPublic = client.get_public();
    const std::string &MARKET = "BTC-LTC";

    BOOST_AUTO_TEST_CASE( TestingGetMarkets ){
        BOOST_REQUIRE_NO_THROW(aPublic.get_markets());
        auto markets = aPublic.get_markets();
        BOOST_CHECK(!markets.empty());
    }

    BOOST_AUTO_TEST_CASE( TestingGetCurrencies ){
        BOOST_REQUIRE_NO_THROW(aPublic.get_currencies());
        auto currencies = aPublic.get_currencies();
        BOOST_CHECK(!currencies.empty());

    }

    BOOST_AUTO_TEST_CASE( TestingGetTicker ){
        BOOST_CHECK_NO_THROW(aPublic.get_ticker(MARKET));
    }

    BOOST_AUTO_TEST_CASE( TestingGetMarketSummaries ){
        BOOST_REQUIRE_NO_THROW(aPublic.get_market_summaries());
        auto market_summaries = aPublic.get_market_summaries();
        BOOST_CHECK(!market_summaries.empty());
    }

    BOOST_AUTO_TEST_CASE( TestingGetMarketSummary ){
        BOOST_CHECK_NO_THROW(aPublic.get_market_summary(MARKET));
    }

    BOOST_AUTO_TEST_CASE( TestingGetOrderBook ){
        BOOST_REQUIRE_NO_THROW(aPublic.get_order_book(MARKET,"both"));
        auto order_book = aPublic.get_order_book(MARKET,"both");
        BOOST_CHECK(!order_book.buy.empty());
        BOOST_CHECK(!order_book.sell.empty());
    }

    BOOST_AUTO_TEST_CASE( TestingGetMarketHistory ){
        BOOST_REQUIRE_NO_THROW(aPublic.get_market_history(MARKET));
        auto market_history = aPublic.get_market_history(MARKET);
        BOOST_CHECK(!market_history.empty());
    }

BOOST_AUTO_TEST_SUITE_END()

