#include <iostream>
#include <cstdlib>
#include <ctime>

std::string simbolosEspeciales = "";

char caracterRandom() {
    return (rand() % 94) + 33;//caracter random entre 33 y 126 ((94 - 1) + 33)
}

std::string generarContrasenia(unsigned int cantCaracteres) {
    std::string contra = "";
    for (;cantCaracteres != 0;cantCaracteres--) contra += caracterRandom();
    return contra;
}

void setRand() {
    srand(std::time(0));
}

int main()
{
    setRand();
    std::cout << generarContrasenia(10) << std::endl;
    system("pause");
    return 0;
}