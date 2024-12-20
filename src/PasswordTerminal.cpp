#include <iostream>
#include "Generador.h"

int main()
{
    int cant = 50;
    std::cout << Generador::generarContrasenia(cant, Generador::TipoContrasenia::COMPLETA) << std::endl;
    std::cout << Generador::generarContrasenia(cant, Generador::TipoContrasenia::ALFANUMERICA) << std::endl;
    std::cout << Generador::generarContrasenia(cant, Generador::TipoContrasenia::ALFANUMERICA_MAYUSCULA) << std::endl;
    std::cout << Generador::generarContrasenia(cant, Generador::TipoContrasenia::ALFANUMERICA_MINUSCULA) << std::endl;
    std::cout << Generador::generarContrasenia(cant, Generador::TipoContrasenia::ALFABETICA) << std::endl;
    std::cout << Generador::generarContrasenia(cant, Generador::TipoContrasenia::ALFABETICA_MAYUSCULA) << std::endl;
    std::cout << Generador::generarContrasenia(cant, Generador::TipoContrasenia::ALFABETICA_MINUSCULA) << std::endl;
    std::cout << Generador::generarContrasenia(cant, Generador::TipoContrasenia::NUMERICA) << std::endl;
    return 0;
}