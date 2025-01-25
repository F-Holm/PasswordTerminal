#include "DB.h"
#include <fstream>

using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;

DataBlock::DataBlock(const size_t largo, unsigned char* str) : largo(largo), str(new unsigned char[largo]) {
	std::memcpy(this->str, str, largo);
}
DataBlock::DataBlock(string str) : str(new unsigned char[largo]) {
	std::memcpy(this->str, str.c_str(), str.size());
}
DataBlock::DataBlock() {
	this->largo = 0;
	this->str = nullptr;
}
DataBlock::~DataBlock() {
	delete[] str;
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

		datos.push_back(DataBlock(largo, str));
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
		archivo.write(reinterpret_cast<const char*>(&dato.str), dato.largo);
	}

	archivo.close();
}