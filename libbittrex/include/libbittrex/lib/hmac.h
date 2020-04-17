#ifndef BITTREX_CPP_HMAC_H
#define BITTREX_CPP_HMAC_H

#ifdef __APPLE__
    #include <CommonCrypto/CommonHMAC.h>
    #define HMAC_MAX_MD_CBLOCK 128
#elif __linux__
    #include <openssl/hmac.h>
#endif

#include <string>

std::string hmac_sha512(const std::string &uri, const std::string &secret);

#endif //BITTREX_CPP_HMAC_H
