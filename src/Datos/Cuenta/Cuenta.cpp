#include "Cuenta.h"
#include "../../Seguridad/Seguridad.h"

using std::string;
using std::array;

Cuenta::Cuenta(array<DataBlock, Cuenta::cantAtributos> datos, const string KEY) {
	this->id = string(reinterpret_cast<const char*>(datos[0].str), datos[0].largo);
	this->descripcion = string(reinterpret_cast<const char*>(datos[1].str), datos[1].largo);
	this->email = string(reinterpret_cast<const char*>(datos[2].str), datos[2].largo);
	this->nombreUsuario = string(reinterpret_cast<const char*>(datos[3].str), datos[3].largo);
	this->contra = string(reinterpret_cast<const char*>(datos[4].str), datos[4].largo);
	this->extra = string(reinterpret_cast<const char*>(datos[5].str), datos[5].largo);

	this->idTag = string(reinterpret_cast<const char*>(datos[6].str), datos[6].largo);
	this->descripcionTag = string(reinterpret_cast<const char*>(datos[7].str), datos[7].largo);
	this->emailTag = string(reinterpret_cast<const char*>(datos[8].str), datos[8].largo);
	this->nombreUsuarioTag = string(reinterpret_cast<const char*>(datos[9].str), datos[9].largo);
	this->contraTag = string(reinterpret_cast<const char*>(datos[10].str), datos[10].largo);
	this->extraTag = string(reinterpret_cast<const char*>(datos[11].str), datos[11].largo);

	desencriptar(KEY);
}
Cuenta::Cuenta(array<string, Cuenta::cantAtributos> datos, const string KEY) {
	this->id = datos[0];
	this->descripcion = datos[1];
	this->email = datos[2];
	this->nombreUsuario = datos[3];
	this->contra = datos[4];
	this->extra = datos[5];

	this->idTag = datos[6];
	this->descripcionTag = datos[7];
	this->emailTag = datos[8];
	this->nombreUsuarioTag = datos[9];
	this->contraTag = datos[10];
	this->extraTag = datos[11];

	desencriptar(KEY);
}
Cuenta::~Cuenta() {}

std::string Cuenta::getId() const {
	return this->id;
}
void Cuenta::setId(const std::string& id) {
	this->id = id;
}

std::string Cuenta::getDescripcion() const {
	return this->descripcion;
}
void Cuenta::setDescripcion(const std::string& descripcion) {
	this->descripcion = descripcion;
}

std::string Cuenta::getEmail() const {
	return this->email;
}
void Cuenta::setEmail(const std::string& email) {
	this->email = email;
}

std::string Cuenta::getNombreUsuario() const {
	return this->nombreUsuario;
}
void Cuenta::setNombreUsuario(const std::string& nombreUsuario) {
	this->nombreUsuario = nombreUsuario;
}

std::string Cuenta::getContra() const {
	return this->contra;
}
void Cuenta::setContra(const std::string& contra) {
	this->contra = contra;
}

std::string Cuenta::getExtra() const {
	return this->extra;
}
void Cuenta::setExtra(const std::string& extra) {
	this->extra = extra;
}

std::string Cuenta::getIdTag() const {
	return this->idTag;
}
std::string Cuenta::getDescripcionTag() const {
	return this->descripcionTag;
}
std::string Cuenta::getEmailTag() const {
	return this->emailTag;
}
std::string Cuenta::getNombreUsuarioTag() const {
	return this->nombreUsuarioTag;
}
std::string Cuenta::getContraTag() const {
	return this->contraTag;
}
std::string Cuenta::getExtraTag() const {
	return this->extraTag;
}

void Cuenta::setIdTag(const std::string& idTag) {
	this->idTag = idTag;
}
void Cuenta::setDescripcionTag(const std::string& descripcionTag) {
	this->descripcionTag = descripcionTag;
}
void Cuenta::setEmailTag(const std::string& emailTag) {
	this->emailTag = emailTag;
}
void Cuenta::setNombreUsuarioTag(const std::string& nombreUsuarioTag) {
	this->nombreUsuarioTag = nombreUsuarioTag;
}
void Cuenta::setContraTag(const std::string& contraTag) {
	this->contraTag = contraTag;
}
void Cuenta::setExtraTag(const std::string& extraTag) {
	this->extraTag = extraTag;
}

void Cuenta::encriptar(const std::string KEY) {
	Seguridad::encriptar(KEY, id, idTag);
	Seguridad::encriptar(KEY, descripcion, descripcionTag);
	Seguridad::encriptar(KEY, email, emailTag);
	Seguridad::encriptar(KEY, nombreUsuario, nombreUsuarioTag);
	Seguridad::encriptar(KEY, contra, contraTag);
	Seguridad::encriptar(KEY, extra, extraTag);
}
void Cuenta::desencriptar(const std::string KEY) {
	Seguridad::desencriptar(KEY, id, idTag);
	Seguridad::desencriptar(KEY, descripcion, descripcionTag);
	Seguridad::desencriptar(KEY, email, emailTag);
	Seguridad::desencriptar(KEY, nombreUsuario, nombreUsuarioTag);
	Seguridad::desencriptar(KEY, contra, contraTag);
	Seguridad::desencriptar(KEY, extra, extraTag);
}

array<DataBlock, Cuenta::cantAtributos> Cuenta::escribirDataBlocks() {
	Seguridad::desencriptar;
	array<DataBlock, Cuenta::cantAtributos> cuentas;

	cuentas[0] = DataBlock(id.size(), id);
	cuentas[1] = DataBlock(descripcion.size(), descripcion);
	cuentas[2] = DataBlock(email.size(), email);
	cuentas[3] = DataBlock(nombreUsuario.size(), nombreUsuario);
	cuentas[4] = DataBlock(contra.size(), contra);
	cuentas[5] = DataBlock(extra.size(), extra);

	cuentas[6] = DataBlock(idTag.size(), idTag);
	cuentas[7] = DataBlock(descripcionTag.size(), descripcionTag);
	cuentas[8] = DataBlock(emailTag.size(), emailTag);
	cuentas[9] = DataBlock(nombreUsuarioTag.size(), nombreUsuarioTag);
	cuentas[10] = DataBlock(contraTag.size(), contraTag);
	cuentas[11] = DataBlock(extraTag.size(), extraTag);

	return cuentas;
}