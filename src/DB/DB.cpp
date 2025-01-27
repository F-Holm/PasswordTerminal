#include "DB.h"
#include <fstream>

using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;

DataBlock::DataBlock(const size_t largo, unsigned char* str) : largo(largo), str(new unsigned char[largo]) {
	std::memcpy(this->str, str, largo);
}
DataBlock::DataBlock(string str) : largo(str.size()), str(new unsigned char[largo]) {
	std::memcpy(this->str, reinterpret_cast<unsigned char*>(&str[0]), str.size());
}
DataBlock::DataBlock(const DataBlock& other) : largo(other.largo), str(new unsigned char[largo]) {
	std::memcpy(this->str, other.str, largo);
}
DataBlock::DataBlock() : largo(0), str(nullptr) {}
DataBlock::~DataBlock() {
	delete[] str;
}

DataBlock& DataBlock::operator=(const DataBlock& other) {
	if (this != &other) {
		delete[] str;
		largo = other.largo;
		str = new unsigned char[largo];
		memcpy(this->str, other.str, largo);
	}
	return *this;
}



vector<DataBlock> DB::leer(const string nombreArchivo) {
	vector<DataBlock> datos;
	ifstream archivo(nombreArchivo, std::ios::binary);
	if (!archivo)
		return datos;

	while (archivo) {
		size_t largo;
		archivo.read(reinterpret_cast<char*>(&largo), sizeof(size_t));
		if (!archivo)
			break;

		unsigned char* str = new unsigned char[largo];
		archivo.read(reinterpret_cast<char*>(str), largo);
		if (!archivo) {
			delete[] str;
			break;
		}

		datos.emplace_back(largo, str);
		delete[] str;
	}
	return datos;

}
void DB::escribir(const string nombreArchivo, vector<DataBlock> datos) {
	ofstream archivo(nombreArchivo, std::ios::binary);
	if (!archivo)
		return;

	for (DataBlock dato : datos) {
		archivo.write(reinterpret_cast<const char*>(&dato.largo), sizeof(size_t));
		archivo.write(reinterpret_cast<const char*>(dato.str), dato.largo);
	}

	archivo.close();
}