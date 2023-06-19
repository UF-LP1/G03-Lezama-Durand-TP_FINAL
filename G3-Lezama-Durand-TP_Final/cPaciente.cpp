#include "cPaciente.h"

cPaciente::cPaciente()
{
	this->nombre=" ";
	this->fecha_nac = " ";
	this->telefono = ""; 
	this->DNI=" ";
}

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


string cPaciente::get_nombre()
{
	return this->nombre;
}

string cPaciente::get_DNI()
{
	return this->DNI;
}

bool cPaciente::operator==(cPaciente* P1)
{
	if (this->nombre == P1->nombre && this->DNI == P1->DNI)
	{
		return true;
	}
	else
		return false;
}
