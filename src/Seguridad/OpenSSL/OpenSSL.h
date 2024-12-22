#pragma once
#include <string>

using std::string;

namespace OpenSSL {
	string hashear256(string str);
	string encriptar(string key, const string STR, string& tag);
	string desencriptar(string key, const string STR, const string tag);
}