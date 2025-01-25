#include "DB.h"

using std::string;
using std::vector;

DataBlock::DataBlock(const unsigned int largo, unsigned char* str) {
	this->largo = largo;
	this->str = str;
}
DataBlock::DataBlock(const unsigned int largo, string str) {
	this->largo = largo;
	this->str = reinterpret_cast<unsigned char*>(&str[0]);
}
DataBlock::DataBlock() {
	this->largo = 0;
	this->str = nullptr;
}
DataBlock::~DataBlock() {}

vector<DataBlock> DB::leer(const string nombreArchivo) {
	return vector<DataBlock>();
}
void DB::escribir(const string nombreArchivo, vector<DataBlock> datos) {
	return;
}