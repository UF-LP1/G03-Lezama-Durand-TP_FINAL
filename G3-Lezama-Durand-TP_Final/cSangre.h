#pragma once
#include "cFluidos.h"

#define t_max 42

class cSangre : public cFluidos {

public:
	cSangre(TipoS tipo, char rh);
	~cSangre();
	bool tiempoMax(time_t extraccion); 
	string to_string();
	friend ostream& operator<<(ostream& out, cSangre& element);
};

