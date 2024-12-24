#include "OpenSSL.h"
#pragma comment (lib, "crypt32")
#pragma comment (lib, "Ws2_32")
#include <openssl/sha.h>
#include <string>

unsigned char* OpenSSL::hash256(unsigned char* str, const unsigned short& len) {
    unsigned char* rta = new unsigned char[256];
    SHA256(str, len, rta);
    return rta;
}