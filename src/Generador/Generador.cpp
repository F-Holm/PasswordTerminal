#include "Generador.h"
#include <iostream>
#include <cstdint>

static void setRand() {
    srand(std::time(0));
}

static char caracterRandom(const char BASE, const uint8_t RANGO) {
    return (rand() % RANGO) + BASE;
}

static bool contraFacil(std::string contra, const Generador::TipoContrasenia tipo) {
    bool minuscula = false, mayuscula = false, numero = false, simbolo = false;
    for (unsigned int i = 0;i < contra.size();i++) {
        if (islower(contra[i])) minuscula = true;
        else if (isupper(contra[i])) mayuscula = true;
        else if (isdigit(contra[i])) numero = true;
        else simbolo = true;
    }

    switch (tipo) {
    case Generador::TipoContrasenia::COMPLETA:
        return !(minuscula && mayuscula && numero && simbolo);
        break;
    case Generador::TipoContrasenia::ALFANUMERICA:
        return !(minuscula && mayuscula && numero);
        break;
    case Generador::TipoContrasenia::ALFANUMERICA_MAYUSCULA:
        return !(mayuscula && numero);
        break;
    case Generador::TipoContrasenia::ALFANUMERICA_MINUSCULA:
        return !(minuscula && numero);
        break;
    case Generador::TipoContrasenia::ALFABETICA:
        return !(minuscula && mayuscula);
        break;
    case Generador::TipoContrasenia::ALFABETICA_MAYUSCULA:
    case Generador::TipoContrasenia::ALFABETICA_MINUSCULA:
    case Generador::TipoContrasenia::NUMERICA:
    default:
        return false;
        break;
    }
}

static char caracter(const Generador::TipoContrasenia tipo) {
    char caracteres[3] = { 'X', 'X', 'X' };
    switch (tipo) {
    case Generador::TipoContrasenia::COMPLETA:
        return caracterRandom('!', 94);
        break;
    case Generador::TipoContrasenia::ALFANUMERICA:
        caracteres[0] = caracterRandom('a', 26);
        caracteres[1] = caracterRandom('A', 26);
        caracteres[2] = caracterRandom('0', 10);
        return caracteres[rand() % 3];
        break;
    case Generador::TipoContrasenia::ALFANUMERICA_MAYUSCULA:
        caracteres[0] = caracterRandom('A', 26);
        caracteres[1] = caracterRandom('0', 10);
        return caracteres[rand() % 2];
        break;
    case Generador::TipoContrasenia::ALFANUMERICA_MINUSCULA:
        caracteres[0] = caracterRandom('a', 26);
        caracteres[1] = caracterRandom('0', 10);
        return caracteres[rand() % 2];
        break;
    case Generador::TipoContrasenia::ALFABETICA:
        caracteres[0] = caracterRandom('a', 26);
        caracteres[1] = caracterRandom('A', 26);
        return caracteres[rand() % 2];
        break;
    case Generador::TipoContrasenia::ALFABETICA_MAYUSCULA:
        return caracterRandom('A', 26);
        break;
    case Generador::TipoContrasenia::ALFABETICA_MINUSCULA:
        return caracterRandom('a', 26);
        break;
    case Generador::TipoContrasenia::NUMERICA:
        return caracterRandom('0', 10);
        break;
    default:
        return 'X';
        break;
    }
}

std::string Generador::generarContrasenia(const unsigned int CANT_CARACTERES, const Generador::TipoContrasenia tipo) {
    std::string contra;
    do {
        contra = "";
        for (unsigned int i = 0;i < CANT_CARACTERES;i++) contra += caracter(tipo);
    } while (contraFacil(contra, tipo));
    return contra;
}