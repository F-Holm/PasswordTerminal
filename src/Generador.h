#pragma once
#ifndef GENERAR_H
#define GENERAR_H

#include <string>

namespace Generador{
    std::string generarContrasenia(const unsigned int CANT_CARACTERES);
    std::string generarContraseniaNumerica(const unsigned int CANT_CARACTERES);
}

#endif