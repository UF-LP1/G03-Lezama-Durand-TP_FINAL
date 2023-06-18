#pragma once
#include "cFluidos.h"

#define t_med 1

class cMedulaOsea : public cFluidos {
private:
	string HLA;
public:
	cMedulaOsea(TipoS tipo, char rh, string HLA);
	~cMedulaOsea();
	bool tiempoMax(time_t extraccion);
	string get_HLA();
};

