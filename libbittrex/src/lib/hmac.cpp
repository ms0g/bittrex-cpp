#include <libbittrex/lib/hmac.h>

std::string hmac_sha512(const std::string &uri, const std::string &secret) {
#ifdef __APPLE__
    unsigned char digest[CC_SHA512_DIGEST_LENGTH];
#elif __linux__
    unsigned char *digest;
#endif

#ifdef __APPLE__
    CCHmac(kCCHmacAlgSHA512, secret.c_str(), secret.length(), uri.c_str(), uri.length(), digest);
#elif __linux__
    digest = HMAC(EVP_sha512(),
                  reinterpret_cast<const unsigned char *>(secret.c_str()), secret.length(),
                  reinterpret_cast<const unsigned char *>(uri.c_str()), uri.length(),
                  nullptr, nullptr);
#endif

    char sha512_str[HMAC_MAX_MD_CBLOCK];
    for (int i = 0; i < 64; i++)
        sprintf(&sha512_str[i * 2], "%02x", (unsigned int) digest[i]);

    return std::string(sha512_str);
}

