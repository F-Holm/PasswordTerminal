#pragma once
#include <string>
#include <vector>

struct DataBlock {
	size_t largo;
	unsigned char* str;

	DataBlock (const size_t largo, unsigned char* str);
	DataBlock (std::string str);
	DataBlock ();
	~DataBlock();
};

namespace DB {
	std::vector<DataBlock> leer(const std::string nombreArchivo);
	void escribir(const std::string nombreArchivo, std::vector<DataBlock> datos);
}