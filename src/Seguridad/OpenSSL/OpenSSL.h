#pragma once
#include <string>

namespace OpenSSL {
	std::string hashear(std::string str);
	std::string encriptar(std::string key, std::string str);
	std::string desencriptar(std::string key, std::string str);
}