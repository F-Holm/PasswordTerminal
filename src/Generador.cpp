#include "Generador.h"
#include <iostream>

void setRand() {
    srand(std::time(0));
}

char caracterRandom() {
    return (rand() % 94) + '!';//caracter random entre 33 y 126 ((94 - 1) + 33)
}

bool contraFacil(std::string contra) {
    bool minuscula = false, mayuscula = false, numero = false, simbolo = false;
    for (unsigned int i = 0;i < contra.size();i++) {
        if (islower(contra[i])) minuscula = true;
        else if (isupper(contra[i])) mayuscula = true;
        else if (isdigit(contra[i])) numero = true;
        else simbolo = true;
    }
    return !(minuscula && mayuscula && numero && simbolo);
}

std::string Generador::generarContrasenia(const unsigned int CANT_CARACTERES) {
    setRand();
    std::string contra;
    do {
        contra = "";
        for (unsigned int i = 0;i < CANT_CARACTERES;i++) contra += caracterRandom();
    } while (contraFacil(contra));
    return contra;
}

std::string Generador::generarContraseniaNumerica(const unsigned int CANT_CARACTERES) {
    setRand();
    std::string contra = "";
    for (unsigned int i = 0;i < CANT_CARACTERES;i++) contra += (rand() % 10) + '0';
    return contra;
}