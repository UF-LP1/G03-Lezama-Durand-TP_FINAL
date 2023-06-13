#include "cPaciente.h"

cPaciente::cPaciente(string nombre, string fecha, string tel, string dni, char sexo) 
{
	this->nombre = nombre;
	this->DNI = dni;
	this->fecha_nac = fecha;
	this->telefono = tel;
}


cPaciente::~cPaciente()
{
}
