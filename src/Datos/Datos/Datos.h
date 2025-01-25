#pragma once
#include "../Cuenta/Cuenta.h"

class Datos {
private:
	const static std::string NOMBRE_ARCHIVO;
	std::vector<Cuenta> cuentas;

	bool idUnico(const std::string id) const;

public:
	Datos(const std::string KEY);
	~Datos();

	int getIndex(const std::string ID) const;
	std::vector<Cuenta> getCuentas() const;
	void setCuentas(const std::vector<Cuenta>& cuentas);

	void agregarCuenta(const Cuenta& cuenta);
	void modificarCuenta(const Cuenta& cuenta);
	void eliminarCuenta(const std::string id);

	void cargarCuentas(const std::string KEY);
	void guardarCuentas(const std::string KEY);
};