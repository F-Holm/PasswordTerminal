#pragma once

namespace OpenSSL {
	unsigned char* hash256(const unsigned char* STR, const unsigned short& LEN_STR);
	unsigned char* hash256_x(const unsigned char* STR, const unsigned short& LEN_STR, const unsigned short& LEN_RTA);
	void encriptar(char* key, char* str, char* tag);
	void desencriptar(char* key, char* str, char* tag);
}