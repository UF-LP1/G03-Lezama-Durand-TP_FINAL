#pragma once
#include "cFluidos.h"

class cSangre : public cFluidos {

public:
	cSangre(TipoS tipo, char rh);
	~cSangre();
	bool tiempoMax(time_t extraccion); 
	string to_string();
	friend ostream& operator<<(ostream& out, cSangre& element);
};

ostream& operator<<(ostream& out, cSangre& s);