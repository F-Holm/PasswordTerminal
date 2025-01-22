#pragma once
#include "../../DB/DB.h"

class Cuenta {
private:
	std::string id;
	std::string email;
	std::string nombreUsuario;
	std::string contra;
	std::string extra;

	std::string idTag;
	std::string emailTag;
	std::string nombreUsuarioTag;
	std::string contraTag;
	std::string extraTag;

	void encriptar(const std::string KEY, std::string& str, std::string& tag);
	void desencriptar(const std::string KEY, std::string& str, std::string& tag);

	void setIdTag(const std::string& idTag);
	void setEmailTag(const std::string& emailTag);
	void setNombreUsuarioTag(const std::string& nombreUsuarioTag);
	void setContraTag(const std::string& contraTag);
	void setExtraTag(const std::string& extraTag);

public:

	std::string getId() const;
	void setId(const std::string& id);

	std::string getEmail() const;
	void setEmail(const std::string& email);

	std::string getNombreUsuario() const;
	void setNombreUsuario(const std::string& nombreUsuario);

	std::string getContra() const;
	void setContra(const std::string& contra);

	std::string getExtra() const;
	void setExtra(const std::string& extra);

	std::string getIdTag() const;
	std::string getEmailTag() const;
	std::string getNombreUsuarioTag() const;
	std::string getContraTag() const;
	std::string getExtraTag() const;


	void leerDataBlocks(DataBlock datos[5]);
	DataBlock* escribirDataBlocks();
};