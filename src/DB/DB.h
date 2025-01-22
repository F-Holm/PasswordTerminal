#pragma once
#include <string>
#include <vector>

struct DataBlock {
	unsigned int largo;
	unsigned char* str;
};

namespace DB {
	std::vector<DataBlock> leer(const std::string nombreArchivo);
	void escribir(const std::string nombreArchivo, std::vector<DataBlock> datos);
}