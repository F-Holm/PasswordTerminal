#pragma once

namespace OpenSSL {
	unsigned char* hash256(const unsigned char* STR, const unsigned int& LEN_STR);
	unsigned char* hash256_x(const unsigned char* STR, const unsigned int& LEN_STR, const unsigned int& LEN_RTA);
	unsigned char* encriptar(const unsigned char* KEY, const unsigned char* STR, const unsigned int& LEN_STR, unsigned char*& tag, unsigned int& LEN_RTA);
	unsigned char* desencriptar(const unsigned char* KEY, const unsigned char* STR, const unsigned int& LEN_STR, const unsigned char* TAG, unsigned int& LEN_RTA);
}