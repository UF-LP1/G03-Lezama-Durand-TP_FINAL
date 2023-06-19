#pragma once
#include "cPaciente.h"

enum tipoE{estable=0, inestable, recibio};

class cReceptor : public cPaciente {
private:
	tipoE estado;
	time_t f_listaEsp;
	unsigned int prioridad;

public:
	cReceptor(string nombre, string fecha, string tel, string dni, char sexo, tipoE estado, time_t f_listaEsp, unsigned int prioridad, cFluidos* fluido);
	~cReceptor();
	void hola() {}
	unsigned int get_prioridad();
	time_t get_fecha();
	tipoE get_estado();
	void set_estado(tipoE estado);
	void set_prioridad(unsigned int prioridad);
	friend ostream& operator<<(ostream& out, cReceptor& r);
	string to_string();
};

ostream& operator<<(ostream& out, cReceptor& r);