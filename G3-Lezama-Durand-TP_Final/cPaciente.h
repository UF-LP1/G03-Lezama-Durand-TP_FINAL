#pragma once
#include "Header.h"

class cPaciente {

private:
	char estado;
protected:
	string nombre, fecha_nac, telefono, DNI;
	char sexo;
public:
	cPaciente(string nombre, string fecha, string tel, string dni, char sexo);
	~cPaciente();
	virtual void hola()=0;

};

