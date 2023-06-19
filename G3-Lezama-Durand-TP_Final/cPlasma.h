#pragma once
#include "cFluidos.h"

#define t_Plasma 365

class cPlasma : public cFluidos{

public:
	cPlasma(TipoS tipo, char rh);
	~cPlasma();
	bool tiempoMax(time_t extraccion);
	string to_string();
	friend ostream& operator<<(ostream& out, cPlasma& plasma);
};

ostream& operator<<(ostream& out, cPlasma& plasma);