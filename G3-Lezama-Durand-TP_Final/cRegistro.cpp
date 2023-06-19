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

string cRegistro::to_string() {
	stringstream ss;
	char comma = ',';
	ss << "Centro: " << this->centro << comma << "Provincia: " << this->provincia << "Fecha de transfucion: " 
		<< this->fecha_t << comma << "Donante: " << this->donante << comma << "Receptor: " << this->receptor 
		<< comma << "Fluido: " << this->fluido << endl;
	return ss.str();
}
