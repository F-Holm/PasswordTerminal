#include <iostream>
#include "Generador/Generador.h"
#include "Seguridad/Seguridad.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

static void testGenerador(const size_t CANT_CARACTERES) {
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

static void testHasheo(const string STR, const size_t LEN_HASH) {
    cout << "Texto original: " << STR << endl;
    cout << "Test hasheo: " << Seguridad::hash256(STR) << endl;
    cout << "Test hasheo x = " << LEN_HASH << " -> " << Seguridad::hash256_x(STR, LEN_HASH) << endl;
    cout << endl;
}

static void testEncriptar(const string KEY, const string STR) {
    string tag;
    cout << "Texto original: " << STR << endl;
    const string STR_ENC = Seguridad::encriptar(STR, KEY, tag);
    cout << "Test encriptado: " << STR_ENC << endl;
    cout << "Tag: " << tag << endl;
    cout << "Test desencriptado: " << Seguridad::desencriptar(STR_ENC, KEY, tag) << endl;
    cout << endl;
}

int main()
{
    testGenerador(120);
    testHasheo("TESTEANDO...", 12);
    testEncriptar("CLAVE", "Esto es un mensaje super ultra mega secreto");
    return 0;
}