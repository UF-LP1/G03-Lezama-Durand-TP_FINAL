#pragma once
#include "cSangre.h"
#include "cMedulaOsea.h"
#include "cPlasma.h"
#include "Header.h"

class cPaciente {
protected:
	string nombre, fecha_nac, telefono, DNI;
	char sexo;
	cFluidos* fluido;
public:
	cPaciente();
	cPaciente(string nombre, string fecha, string tel, string dni, char sexo, cFluidos* fluido);
	~cPaciente();
	virtual string to_string() = 0;
	cFluidos* get_fluido();
	bool operator==(cPaciente* element);
	string get_nombre();
	string get_DNI();
};