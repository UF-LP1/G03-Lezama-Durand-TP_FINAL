#pragma once
#include "cFluidos.h"

class cMedulaOsea : public cFluidos {
private:
	string HLA;

public:
	cMedulaOsea(TipoS tipo, char rh, string HLA);
	~cMedulaOsea();
	bool tiempoMax(time_t extraccion);
	string get_HLA();
	string to_string();
	friend ostream& operator<<(ostream& out, cMedulaOsea& med);
};

ostream& operator<<(ostream& out, cMedulaOsea& med);
