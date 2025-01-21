#include <iostream>
#include "Generador/Generador.h"
#include "Seguridad/Seguridad.h"
#include "Seguridad/OpenSSL/OpenSSL.h"
#include <openssl/sha.h>
#include "aesgcm.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;

static void mostrarChar(const unsigned char* STR, const uint8_t CANT_CARACTERES) {
    for (unsigned short i = 0;i < CANT_CARACTERES;i++) cout << STR[i];
    cout << endl;
}

static void testGenerador(const uint8_t CANT_CARACTERES) {
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
}

static void testHasheo(const unsigned char* STR, const unsigned short& LEN_STR, const unsigned short& LEN_HASH) {
    cout << "Texto original: " << endl;
    mostrarChar(STR, LEN_STR);
    cout << "Test hasheo: " << endl;
    mostrarChar(OpenSSL::hash256(STR, LEN_STR), 32);
    cout << "Test hasheo x = " << LEN_HASH << ":" << endl;
    mostrarChar(OpenSSL::hash256_x(STR, LEN_STR, LEN_HASH), LEN_HASH);
    cout << endl;
}

static void testEncriptar(const unsigned char* KEY, const unsigned char* STR) {
    unsigned char* tag = nullptr;

    cout << "Texto original:" << endl;
    mostrarChar(STR, 38);

    cout << "Test encriptado:" << endl;
    unsigned int lenRta;
    unsigned char* cifrado = OpenSSL::encriptar(KEY, STR, 38, tag, lenRta);
    mostrarChar(cifrado, lenRta);

    cout << "Tag" << " -> " << (tag == nullptr);
    mostrarChar(tag, 16);

    cout << "Test desencriptado:" << endl;
    unsigned int lenRtaRta;
    unsigned char* descifrado = OpenSSL::desencriptar(KEY, STR, lenRta, tag, lenRtaRta);
    //mostrarChar(descifrado, lenRtaRta);

    cout << endl;
}

char** testDataType() {
    char** rta = new char* [10];
    for (int i = 1;i <= 10;i++) {
        rta[i] = new char[i];
        for (int j = 0;j < i;j++) rta[i][j] = '*';
    }
    return rta;
}

void shownTestDataType(char** matriz) {
    for (int i = 0;i < 10;i++) {
        for (int j = 0;j < i;j++) cout << matriz[i][j];
        cout << endl;
    }
}

int main()
{
    /*testGenerador(120);
    unsigned char* str = new unsigned char[38];
    for (int i = 0;i < 38;i++) str[i] = i + 64;
    testHasheo(str, 38, 10);
    const unsigned char* CLAVE = OpenSSL::hash256(Generador::generarContrasenia(120, Generador::TipoContrasenia::COMPLETA), 120);
    testEncriptar(CLAVE, str);*/
    //shownTestDataType(testDataType());
    return AES_GCM_EJEMPLO(NULL, nullptr);
}