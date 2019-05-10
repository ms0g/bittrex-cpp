#include "utils.h"

namespace bittrex {
namespace lib {

std::string hmac_sha512(const std::string &uri, const std::string &secret) {
    unsigned char *digest;
    digest = HMAC(EVP_sha512(),
                  reinterpret_cast<const unsigned char *>(secret.c_str()), secret.length(),
                  reinterpret_cast<const unsigned char *>(uri.c_str()), uri.length(),
                  NULL, NULL);

    char sha512_str[HMAC_MAX_MD_CBLOCK];
    for (int i = 0; i < 64; i++)
        sprintf(&sha512_str[i * 2], "%02x", (unsigned int) digest[i]);

    return std::move(std::string(sha512_str));
}
}
}