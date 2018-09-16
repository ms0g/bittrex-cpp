# bittrex-cpp
[![Build Status](https://travis-ci.org/gurpinars/bittrex-cpp.svg?branch=master)](https://travis-ci.org/gurpinars/bittrex-cpp)

Bittrex C++ API Client Library

**WARNING:** Market buy/sells are extremely dangerous.You are at your own risk.

### Prerequisites
+ [CMake](http://www.cmake.org "CMake project page") (>= 3.8)
+ [Libcurl](https://curl.haxx.se/libcurl/ "LibCurl home page")
+ [Crypto](https://www.openssl.org/docs/man1.0.2/crypto/crypto.html "Openssl home page") (HMAC)
+ [GCC](http://gcc.gnu.org "GCC home") (>= 5.4.0)
+ [Boost](http://www.boost.org/ "Boost project page") (>= 1.58.0) (optional)

### Building
```bash
mkdir build && cd build
cmake .. && cmake --build .
```
### Installation
```bash
sudo make install
```
### Usage
```bash 
#include <iostream>
#include <libbittrex/client.h>

int main(){
    std::string key="xxxxx";
    std::string secret="xxxxx";
    
    bittrex::Client btxcli(key,secret);
    auto markets =  btxcli.get_public_api().get_markets();

    std::cout << markets.at(0).market_name << std::endl;
}
>> BTC-LTC
```
