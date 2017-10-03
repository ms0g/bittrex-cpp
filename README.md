# bittrex-cpp
Bittrex C++ API Client Library

### Prerequisites
+ [CMake](http://www.cmake.org "CMake project page") (>= 3.8)
+ [CURLpp](http://www.curlpp.org "Curlpp home page") (>= 0.8.1)
+ [Crypto](https://www.openssl.org/docs/man1.0.2/crypto/crypto.html "Openssl home page") (HMAC)
+ [GCC](http://gcc.gnu.org "GCC home") (tested with 5.4.0)

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
#include "../client.h"

int main(){
    std::string key="xxxxx";
    std::string secret="xxxxx"
    
    bittrex::Client cl(key,secret);
    bittrex::api::Public p =  cl.get_public();
    
    auto markets = p.get_markets();
    std::cout << markets.at(0).market_name << std::endl;
}
>> BTC-LTC
```
