#pragma once
#include <cstdint>

struct MensajeEncriptado {
	unsigned char id[256];
	unsigned int lenID;

	unsigned char mail[256];
	unsigned int lenMail;

	unsigned char nombreUsuario[256];
	unsigned int lenNombreUsuario;

	unsigned char contra[256];
	unsigned int lenContra;

	unsigned char add[65536];
	unsigned short lenAdd;

	unsigned char tag[16];

	void encriptar();
	void desencriptar();
};