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
	bool operator==(cPaciente* P1);
	string get_nombre();
	string get_DNI();
	void set_nombre(string s);
	void set_fecha_nac(string s);
	void set_telefono(string s);
	void set_dni(string s);
	void set_sexo(char s);
	void set_fluido(cFluidos* s);
};
