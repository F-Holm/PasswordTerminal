#include "OpenSSL.h"
#pragma comment (lib, "crypt32")
#pragma comment (lib, "Ws2_32")
#include <openssl/sha.h>

std::string OpenSSL::hashear(std::string str) {
    unsigned char hash[SHA256_DIGEST_LENGTH];

    SHA256(reinterpret_cast<const unsigned char*>(str.c_str()), str.size(), hash);

    std::string rta(reinterpret_cast<const char*>(hash), SHA256_DIGEST_LENGTH);

    return rta;
}