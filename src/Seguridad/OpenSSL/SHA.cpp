#include "OpenSSL.h"
#pragma comment (lib, "crypt32")
#pragma comment (lib, "Ws2_32")
#include <openssl/sha.h>

string OpenSSL::hashear256(string str) {
    unsigned char hash[SHA256_DIGEST_LENGTH];

    SHA256(reinterpret_cast<const unsigned char*>(str.c_str()), str.size(), hash);

    string rta(reinterpret_cast<const char*>(hash), SHA256_DIGEST_LENGTH);

    return rta;
}