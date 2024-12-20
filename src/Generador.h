#pragma once
#ifndef GENERAR_H
#define GENERAR_H

#include <string>

namespace Generador{
    enum class TipoContrasenia : int {
        COMPLETA = 0,
        ALFANUMERICA = 1,
        ALFANUMERICA_MAYUSCULA = 2,
        ALFANUMERICA_MINUSCULA = 3,
        ALFABETICA = 4,
        ALFABETICA_MAYUSCULA = 5,
        ALFABETICA_MINUSCULA = 6,
        NUMERICA = 7
    };
    std::string generarContrasenia(const unsigned int CANT_CARACTERES, const TipoContrasenia tipo);
}

#endif