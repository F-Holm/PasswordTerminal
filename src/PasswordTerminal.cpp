#include <iostream>
#include "Generador/Generador.h"
#include "Seguridad/Seguridad.h"
#include "Seguridad/OpenSSL/OpenSSL.h"
#include <openssl/sha.h>

using std::string;
using std::cout;
using std::cin;
using std::endl;

void static testGenerador(const unsigned int CANT_CARACTERES) {
    cout << Generador::generarContrasenia(CANT_CARACTERES, Generador::TipoContrasenia::COMPLETA) << endl;
    cout << Generador::generarContrasenia(CANT_CARACTERES, Generador::TipoContrasenia::ALFANUMERICA) << endl;
    cout << Generador::generarContrasenia(CANT_CARACTERES, Generador::TipoContrasenia::ALFANUMERICA_MAYUSCULA) << endl;
    cout << Generador::generarContrasenia(CANT_CARACTERES, Generador::TipoContrasenia::ALFANUMERICA_MINUSCULA) << endl;
    cout << Generador::generarContrasenia(CANT_CARACTERES, Generador::TipoContrasenia::ALFABETICA) << endl;
    cout << Generador::generarContrasenia(CANT_CARACTERES, Generador::TipoContrasenia::ALFABETICA_MAYUSCULA) << endl;
    cout << Generador::generarContrasenia(CANT_CARACTERES, Generador::TipoContrasenia::ALFABETICA_MINUSCULA) << endl;
    cout << Generador::generarContrasenia(CANT_CARACTERES, Generador::TipoContrasenia::NUMERICA) << endl;
}

void static testHasheo(string str) {
    cout << OpenSSL::hashear(str) << endl;
    cout << OpenSSL::hashear(str).size() << endl;
}

int main()
{
    testGenerador(120);
    testHasheo("Este es un mensaje super ultra secreto");
    return 0;
}