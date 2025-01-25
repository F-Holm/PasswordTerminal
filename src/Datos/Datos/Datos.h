#pragma once
#include "../Cuenta/Cuenta.h"

class Datos {
private:
	const static std::string NOMBRE_ARCHIVO;
	std::vector<Cuenta> cuentas;

	bool idUnico(const std::string id) const;

public:
	Datos();
	~Datos();

	std::vector<Cuenta> getCuentas() const;
	void setCuentas(const std::vector<Cuenta>& cuentas);
	void agregarCuentas(const Cuenta& cuenta);
	void modificarCuentas(const std::string, const Cuenta& cuenta);
	void eliminarCuentas(const std::string id);
};