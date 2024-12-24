#pragma once
#include <cstdint>

struct MensajeEncriptado {
	unsigned char id[256];
	uint8_t lenID;

	unsigned char mail[256];
	uint8_t lenMail;

	unsigned char nombreUsuario[256];
	uint8_t lenNombreUsuario;

	unsigned char contra[256];
	uint8_t lenContra;

	unsigned char add[65536];
	unsigned short lenAdd;

	unsigned char tag[16];

	void encriptar();
	void desencriptar();
};