#pragma once
#include "cPaciente.h"
enum tipoE{estable=0, inestable, recibio};

class cReceptor : public cPaciente {
private:
	tipoE estado;
	time_t f_listaEsp;
	unsigned int prioridad;
public:
	cReceptor(string nombre, string fecha, string tel, string dni, char sexo, string estado, time_t f_listaEsp, unsigned int prioridad);
	~cReceptor();
	void hola() {}
	unsigned int get_prioridad();
	time_t get_fecha();
	tipoE get_estado();
	friend ostream& operator<<(ostream& out, const cReceptor& element);
};

