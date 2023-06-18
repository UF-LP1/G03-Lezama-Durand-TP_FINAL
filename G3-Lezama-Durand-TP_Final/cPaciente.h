#pragma once
#include "cFluidos.h"
#include "Header.h"

class cPaciente {

private:
	char estado;
protected:
	string nombre, fecha_nac, telefono, DNI;
	char sexo;
	cFluidos* fluido;
public:
	cPaciente(string nombre, string fecha, string tel, string dni, char sexo, cFluidos* fluido);
	~cPaciente();
	virtual void hola()=0;
	cFluidos* get_fluido();
	bool operator==(cPaciente* element);
	string get_nombre();
	string get_DNI();
};