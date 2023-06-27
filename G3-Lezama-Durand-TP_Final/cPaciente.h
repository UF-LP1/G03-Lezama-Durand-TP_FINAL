#pragma once
#include "cSangre.h"
#include "cMedulaOsea.h"
#include "cPlasma.h"
#include "Header.h"

class cPaciente {
protected:
	string nombre, fecha_nac, telefono;
	const string DNI;
	char sexo;
	cFluidos* fluido;
public:
	cPaciente();
	cPaciente(string nombre, string fecha, string tel, string DNI, char sexo, cFluidos* fluido);
	~cPaciente();
	virtual string to_string() = 0;
	cFluidos* get_fluido();
	string get_nombre();
	string get_DNI();
	void set_nombre(string s);
	void set_fecha_nac(string s);
	void set_telefono(string s);
	void set_sexo(char s);
	void set_fluido(cFluidos* s);

	friend ostream& operator<<(ostream& out, cPaciente* element);
	bool operator==(cPaciente* P1);
};
ostream& operator<<(ostream& out, cPaciente* element);