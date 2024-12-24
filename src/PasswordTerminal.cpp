#include <iostream>
#include "Generador/Generador.h"
#include "Seguridad/Seguridad.h"
#include "Seguridad/OpenSSL/OpenSSL.h"
#include <openssl/sha.h>

using std::string;
using std::cout;
using std::cin;
using std::endl;

void mostrarChar(const unsigned char* str, const uint8_t CANT_CARACTERES) {
    for (unsigned short i = 0;i < CANT_CARACTERES;i++) cout << str[i];
    cout << endl;
}

static void testGenerador(const uint8_t CANT_CARACTERES) {
    cout << "Test generador: " << endl;
    mostrarChar(Generador::generarContrasenia(CANT_CARACTERES, Generador::TipoContrasenia::COMPLETA), CANT_CARACTERES);
    mostrarChar(Generador::generarContrasenia(CANT_CARACTERES, Generador::TipoContrasenia::ALFANUMERICA), CANT_CARACTERES);
    mostrarChar( Generador::generarContrasenia(CANT_CARACTERES, Generador::TipoContrasenia::ALFANUMERICA_MAYUSCULA), CANT_CARACTERES);
    mostrarChar( Generador::generarContrasenia(CANT_CARACTERES, Generador::TipoContrasenia::ALFANUMERICA_MINUSCULA), CANT_CARACTERES);
    mostrarChar( Generador::generarContrasenia(CANT_CARACTERES, Generador::TipoContrasenia::ALFABETICA), CANT_CARACTERES);
    mostrarChar( Generador::generarContrasenia(CANT_CARACTERES, Generador::TipoContrasenia::ALFABETICA_MAYUSCULA), CANT_CARACTERES);
    mostrarChar( Generador::generarContrasenia(CANT_CARACTERES, Generador::TipoContrasenia::ALFABETICA_MINUSCULA), CANT_CARACTERES);
    mostrarChar( Generador::generarContrasenia(CANT_CARACTERES, Generador::TipoContrasenia::NUMERICA), CANT_CARACTERES);
    cout << endl;
}

/*static void testHasheo(string str) {
    cout << "Test hasheo: " << endl;
    cout << OpenSSL::hash256(str) << endl;
    cout << OpenSSL::hash256(str).size() << " Bytes" << endl;
    cout << OpenSSL::hash256(str).size() * 8 << " bits" << endl;
    cout << endl;
}*/

/*static void testEncriptar(const string KEY, const string STR) {
    string tag = "";
    cout << "Test encriptación: " << endl;
    cout << STR << endl;
    cout << OpenSSL::encriptar(KEY, STR, tag) << endl;
    cout << tag << endl;
    cout << OpenSSL::desencriptar(KEY, STR, tag);
    cout << endl;
}*/

int main()
{
    testGenerador(120);
    //testHasheo("Este es un mensaje super ultra secreto");
    //testEncriptar("Clave super ultra mega secreta", "Este es un mensaje super ultra mega secreto");
    return 0;
}