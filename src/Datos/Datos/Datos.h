#pragma once
#include "../Cuenta/Cuenta.h"
#include <vector>

class Datos {
private:
	const static std::string NOMBRE_ARCHIVO;
	std::vector<Cuenta> cuentas;
public:
	std::vector<Cuenta> getCuentas() const;
	void setCuentas(const std::vector<Cuenta>& cuentas);

};