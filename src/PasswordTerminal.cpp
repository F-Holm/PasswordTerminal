#include <iostream>
/*#include "Generador/Generador.h"
#include "Seguridad/Seguridad.h"
#include "Seguridad/OpenSSL/OpenSSL.h"
#include <openssl/sha.h>*/
#include "aesgcm.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;

/*static void testGenerador(const uint8_t CANT_CARACTERES) {
    cout << "Test generador: " << endl;
    mostrarChar(Generador::generarContrasenia(CANT_CARACTERES, Generador::TipoContrasenia::COMPLETA), CANT_CARACTERES);
    mostrarChar(Generador::generarContrasenia(CANT_CARACTERES, Generador::TipoContrasenia::ALFANUMERICA), CANT_CARACTERES);
    mostrarChar(Generador::generarContrasenia(CANT_CARACTERES, Generador::TipoContrasenia::ALFANUMERICA_MAYUSCULA), CANT_CARACTERES);
    mostrarChar(Generador::generarContrasenia(CANT_CARACTERES, Generador::TipoContrasenia::ALFANUMERICA_MINUSCULA), CANT_CARACTERES);
    mostrarChar(Generador::generarContrasenia(CANT_CARACTERES, Generador::TipoContrasenia::ALFABETICA), CANT_CARACTERES);
    mostrarChar(Generador::generarContrasenia(CANT_CARACTERES, Generador::TipoContrasenia::ALFABETICA_MAYUSCULA), CANT_CARACTERES);
    mostrarChar(Generador::generarContrasenia(CANT_CARACTERES, Generador::TipoContrasenia::ALFABETICA_MINUSCULA), CANT_CARACTERES);
    mostrarChar(Generador::generarContrasenia(CANT_CARACTERES, Generador::TipoContrasenia::NUMERICA), CANT_CARACTERES);
    cout << endl;
}*/

/*static void testHasheo(const string STR, const size_t LEN_HASH) {
    cout << "Texto original: " << STR << endl;
    cout << "Test hasheo: " << OpenSSL::hash256(STR) << endl;
    cout << "Test hasheo x = " << LEN_HASH << ":" << OpenSSL::hash256_x(STR, LEN_HASH) << endl;
    cout << endl;
}

static void testEncriptar(const string KEY, const string STR) {
    string tag;

    cout << "Texto original: " << STR << endl;

    const string STR_ENC = OpenSSL::encriptar(STR, KEY, tag);
    cout << "Test encriptado: " << STR_ENC << endl;

    cout << "Tag: " << tag << endl;

    cout << "Test desencriptado: " << OpenSSL::desencriptar(STR_ENC, KEY, tag) << endl;
    cout << endl;
}*/

int main()
{
    /*testGenerador(120);
    unsigned char* str = new unsigned char[38];
    for (int i = 0;i < 38;i++) str[i] = i + 64;
    testHasheo(str, 38, 10);
    const unsigned char* CLAVE = OpenSSL::hash256(Generador::generarContrasenia(120, Generador::TipoContrasenia::COMPLETA), 120);
    testEncriptar(CLAVE, str);*/
    //return 0;
    return AES_GCM_EJEMPLO(NULL, nullptr);
}