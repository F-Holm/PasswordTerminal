#include <iostream>
#include "Generador.h"

int main()
{
    std::cout << Generador::generarContrasenia(20) << std::endl;
    std::cout << Generador::generarContraseniaNumerica(20) << std::endl;
    system("pause");
    return 0;
}