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

void cPaciente::set_nombre(string s)
{
	this->nombre = s;
	return;
}

void cPaciente::set_fecha_nac(string s)
{
	this->fecha_nac = s;
	return;
}

void cPaciente::set_telefono(string s)
{
	this->telefono = s;
	return;
}

void cPaciente::set_dni(string s)
{
	this->DNI = s;
	return;
}

void cPaciente::set_sexo(char s)
{
	this->sexo = s;
	return;
}

void cPaciente::set_fluido(cFluidos* s)
{
	this->fluido = s;
	return;
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
