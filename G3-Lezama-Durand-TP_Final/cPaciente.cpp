#include "cPaciente.h"

cPaciente::cPaciente(string nombre, string fecha, string tel, string dni, char sexo, cFluidos* fluido): fluido(fluido)
{
	this->nombre = nombre;
	this->DNI = dni;
	this->fecha_nac = fecha;
	this->telefono = tel;
}

cPaciente::~cPaciente()
{
}

cFluidos* cPaciente::get_fluido()
{
	return this->fluido;
}

bool cPaciente::operator==(cPaciente* element)
{
	if (this->nombre == element->nombre && this->DNI == element->DNI)
	{
		return true;
	}
	else
		return false;
}

string cPaciente::get_nombre()
{
	return this->nombre;
}

string cPaciente::get_DNI()
{
	return this->DNI;
}
