#pragma once

namespace OpenSSL {
	unsigned char* hash256(unsigned char* str, const unsigned short& len);
	void encriptar(char* key, char* str, char* tag);
	void desencriptar(char* key, char* str, char* tag);
}