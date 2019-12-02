#ifndef BITTREX_CPP_HMAC_H
#define BITTREX_CPP_HMAC_H

#include <openssl/hmac.h>
#include <string>

std::string hmac_sha512(const std::string &uri, const std::string &secret);

#endif //BITTREX_CPP_HMAC_H
