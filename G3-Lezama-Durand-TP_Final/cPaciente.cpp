#include "cPaciente.h"

cPaciente::cPaciente()
{
	this->nombre=" ";
	this->fecha_nac = " ";
	this->telefono = ""; 
}

cPaciente::cPaciente(string nombre, string fecha, string tel, string DNI, char sexo, cFluidos* fluido): fluido(fluido), DNI(DNI)
{
	this->nombre = nombre;
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

ostream& operator<<(ostream& out, cPaciente* element) {
	if (element == nullptr)
	{
		throw new exception{ "no se encontro paciente" };
	}

	out << element->to_string()<<endl;
	return out;
}