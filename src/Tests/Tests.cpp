#include "Tests.h"
#include <iostream>
#include "../Generador/Generador.h"
#include "../Seguridad/Seguridad.h"
#include "../DB/DB.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::flush;
using std::vector;
using std::array;

void Tests::generador() {
    const size_t CANT_CARACTERES = 120;
    cout << "Test generador: " << endl;
    cout << Generador::generarContrasenia(CANT_CARACTERES, Generador::TipoContrasenia::COMPLETA) << endl;
    cout << Generador::generarContrasenia(CANT_CARACTERES, Generador::TipoContrasenia::ALFANUMERICA) << endl;
    cout << Generador::generarContrasenia(CANT_CARACTERES, Generador::TipoContrasenia::ALFANUMERICA_MAYUSCULA) << endl;
    cout << Generador::generarContrasenia(CANT_CARACTERES, Generador::TipoContrasenia::ALFANUMERICA_MINUSCULA) << endl;
    cout << Generador::generarContrasenia(CANT_CARACTERES, Generador::TipoContrasenia::ALFABETICA) << endl;
    cout << Generador::generarContrasenia(CANT_CARACTERES, Generador::TipoContrasenia::ALFABETICA_MAYUSCULA) << endl;
    cout << Generador::generarContrasenia(CANT_CARACTERES, Generador::TipoContrasenia::ALFABETICA_MINUSCULA) << endl;
    cout << Generador::generarContrasenia(CANT_CARACTERES, Generador::TipoContrasenia::NUMERICA) << endl;
    cout << endl;
}

void Tests::hash() {
    const string STR = "TESTEANDO...";
    const size_t LEN_HASH = 12;
    cout << "Texto original: " << STR << endl;
    cout << "Test hasheo: " << Seguridad::hash256(STR) << endl;
    cout << "Test hasheo x = " << LEN_HASH << " -> " << Seguridad::hash256_x(STR, LEN_HASH) << endl;
    cout << endl;
}

void Tests::enc() {
    const string KEY = "Clave super ultra mega secreta";
    const string STR = "Esto es un mensaje super ultra mega secreto";
    string tag;

    cout << "Texto original: " << STR << endl;
    const string STR_ENC = Seguridad::encriptar(STR, KEY, tag);
    cout << "Test encriptado: " << STR_ENC << endl;
    cout << "Tag: " << tag << endl;
    cout << "Test desencriptado: " << Seguridad::desencriptar(STR_ENC, KEY, tag) << endl;
    cout << endl;
}

void Tests::enc_x(const size_t x) {
    cout << endl;
    for (size_t i = 0;i < x;i++) {
        const string STR = Generador::generarContrasenia(x, Generador::TipoContrasenia::COMPLETA);
        const string KEY = Generador::generarContrasenia(x, Generador::TipoContrasenia::COMPLETA);
        string tag;
        const string ENC = Seguridad::encriptar(STR, KEY, tag);
        const string RTA = Seguridad::desencriptar(ENC, KEY, tag);
        if (STR != RTA) {
            cout << "Encriptación fallida\n" << STR << "\n!=\n" << RTA << "\n\n";
            return;
        }
        else cout << '\r' << i+1 << " de " << x << " encriptaciones exitosas" << flush;
    }
    cout << "\n\n";
}

void Tests::db() {
    const string n = "k.k";
    vector<DataBlock> datos = DB::leer(n);
    cout << datos.size() << " -> ";
    datos.emplace_back("Zlatan");
    datos.emplace_back("Ibrahimovic");
    DB::escribir(n, datos);
    datos = DB::leer(n);
    cout << datos.size() << endl;
    for (DataBlock dato : datos) {
        cout << dato.largo << " -> ";
        for (int j = 0;j < dato.largo;j++)
            cout << dato.str[j];
        cout << endl;
    }
    std::remove(n.c_str());
}