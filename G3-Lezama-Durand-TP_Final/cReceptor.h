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
	cReceptor();
	~cReceptor();
	unsigned int get_prioridad();
	time_t get_fecha();
	tipoE get_estado();
	void set_estado(tipoE estado);
	void set_prioridad(unsigned int prioridad);
	void set_fechaLE(time_t s);
	friend istream& operator>>(istream& in, cReceptor& r);
	string to_string();
};

istream& operator>>(istream& in, cReceptor& r);