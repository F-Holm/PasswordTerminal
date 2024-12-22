#include "OpenSSL.h"
#include <iomanip>
#include <sstream>
#include <iostream>
//#include <windows.h>
//#include <wincrypt.h>
#pragma comment (lib, "crypt32")
#pragma comment (lib, "Ws2_32")
#include <openssl/sha.h>

std::string OpenSSL::hashear(std::string str) {
    unsigned char hash[SHA256_DIGEST_LENGTH];

    SHA256(reinterpret_cast<const unsigned char*>(str.c_str()), str.size(), hash);

    std::stringstream ss;

    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
    }
    return ss.str();



}