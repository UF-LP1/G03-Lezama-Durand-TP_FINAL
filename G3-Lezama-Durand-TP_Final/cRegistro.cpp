#include "cRegistro.h"

cRegistro::cRegistro(string centro, time_t fecha_t, string donante, string receptor, string fluido, cFluidos* datos_fluidos,string provincia):datos_fluidos(datos_fluidos)
{
	this->centro=centro;
	this->fecha_t=fecha_t;
	this->donante=donante;
	this->receptor=receptor;
	this->fluido=fluido;
	this->provincia = provincia;
}

cRegistro::~cRegistro()
{
}
