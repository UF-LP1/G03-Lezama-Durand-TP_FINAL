#pragma once
#include "Header.h"
#include "cFluidos.h"

class cRegistro
{
	string centro, provincia;
	time_t fecha_t;
	string donante;
	string receptor;
	string fluido;
	cFluidos* datos_fluidos;

public:
	cRegistro(string centro, time_t fecha_t, string donante, string receptor, string fluido, cFluidos* datos_fluidos, string provincnia);
	~cRegistro();
};

