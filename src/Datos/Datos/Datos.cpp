#include "Datos.h"

using std::string;
using std::vector;
using std::array;

const string Datos::NOMBRE_ARCHIVO = "FEDERICO.HOLM";

Datos::Datos(const string KEY) {
    cargarCuentas(KEY);
}
Datos::~Datos() {}

int Datos::getIndex(const string ID) const {
    for (int i = 0;i < cuentas.size();i++)
        if (cuentas[i].getId() == ID)
            return i;
}

vector<Cuenta> Datos::getCuentas() const {
    return cuentas;
}

void Datos::setCuentas(const vector<Cuenta>& nuevasCuentas) {
    cuentas = nuevasCuentas;
}

void Datos::agregarCuenta(const Cuenta& cuenta) {
    if (idUnico(cuenta.getId()))
        cuentas.push_back(cuenta);
}

void Datos::modificarCuenta(const Cuenta& cuenta) {
    cuentas[getIndex(cuenta.getId())] = cuenta;
}

void Datos::eliminarCuenta(const std::string id) {
    cuentas.erase(cuentas.begin() + getIndex(id));
}

void Datos::cargarCuentas(const string KEY) {
    vector<DataBlock> datos = DB::leer(Datos::NOMBRE_ARCHIVO);

    for (int i = 0;i < datos.size();i += Cuenta::cantAtributos) {
        array<DataBlock, Cuenta::cantAtributos> c;
        for (int j = i;j < i + Cuenta::cantAtributos;j++)
            c[j] = datos[j - i];
        cuentas.push_back(Cuenta(c, KEY));
    }
}

void Datos::guardarCuentas(const string KEY) {
    vector<DataBlock> datos;
    for (Cuenta cuenta : cuentas) {
        array<DataBlock, Cuenta::cantAtributos> arr;
        arr = cuenta.escribirDataBlocks(KEY);
        datos.insert(datos.end(), begin(arr), end(arr));
    }
    DB::escribir(Datos::NOMBRE_ARCHIVO, datos);
}

bool Datos::idUnico(const string ID) const {
    for (int i = 0;i < cuentas.size();i++)
        if (cuentas[i].getId() == ID)
            return false;
    return true;
}
