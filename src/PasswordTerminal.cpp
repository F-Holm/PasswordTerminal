#include <iostream>
#include "Generador/Generador.h"
#include "Seguridad/Seguridad.h"
#include "Seguridad/OpenSSL/OpenSSL.h"
#include <openssl/sha.h>

using std::string;
using std::cout;
using std::cin;
using std::endl;

static void testGenerador(const unsigned int CANT_CARACTERES) {
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

static void testHasheo(string str) {
    cout << "Test hasheo: " << endl;
    cout << OpenSSL::hashear256(str) << endl;
    cout << OpenSSL::hashear256(str).size() << endl;
    cout << endl;
}

static void testEncriptar(const string KEY, const string STR, string& tag) {
    cout << "Test encriptación: " << endl;
    cout << STR << endl;
    cout << OpenSSL::encriptar(KEY, STR, tag) << endl;
    cout << tag << endl;
    cout << endl;
}

int main()
{
    testGenerador(120);
    testHasheo("Este es un mensaje super ultra secreto");
    string tag = "";
    testEncriptar("Clave super ultra mega secreta", "Este es un mensaje super ultra mega secreto", tag);
    return 0;
}