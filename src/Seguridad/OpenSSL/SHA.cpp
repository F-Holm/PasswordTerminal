#include "OpenSSL.h"
#include <openssl/sha.h>

using std::string;

string OpenSSL::hash256(string str) {
    unsigned char rta[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<unsigned char*>(&str[0]), str.size(), rta);
    string rta_str = string(*rta, 32);
    return rta_str;
}

string OpenSSL::hash256_x(string str, const size_t& LEN_RTA) {
    return OpenSSL::hash256(str).substr(0, LEN_RTA);
}