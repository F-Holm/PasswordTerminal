#pragma once

namespace OpenSSL {
	unsigned char* hash256(const unsigned char* STR, const unsigned short& LEN_STR);
	unsigned char* hash256_x(const unsigned char* STR, const unsigned short& LEN_STR, const unsigned short& LEN_RTA);
	unsigned char* encriptar(const unsigned char* KEY, const unsigned char* STR, const unsigned short& LEN_STR, unsigned char*& tag, unsigned short& LEN_RTA);
	unsigned char* desencriptar(const unsigned char* KEY, const unsigned char* STR, const unsigned short& LEN_STR, const unsigned char* TAG, unsigned short& LEN_RTA);
}