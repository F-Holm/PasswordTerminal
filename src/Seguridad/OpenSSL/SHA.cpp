#include "OpenSSL.h"
#include <openssl/sha.h>
#include <string>

unsigned char* OpenSSL::hash256(const unsigned char* STR, const unsigned int& LEN_STR) {
    unsigned char* rta = new unsigned char[SHA256_DIGEST_LENGTH];
    SHA256(STR, LEN_STR, rta);
    return rta;
}

unsigned char* OpenSSL::hash256_x(const unsigned char* STR, const unsigned int& LEN_STR, const unsigned int& LEN_RTA) {
    unsigned char* TEMP = OpenSSL::hash256(STR, LEN_STR);
    unsigned char* RTA = new unsigned char[LEN_RTA];
    memcpy(RTA, TEMP, LEN_RTA);
    delete[] TEMP;
    return RTA;
}