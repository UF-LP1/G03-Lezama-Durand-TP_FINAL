#include "cReceptor.h"

cReceptor::cReceptor(string nombre, string fecha, string tel, string dni, char sexo, tipoE estado, time_t f_listaEsp, unsigned int 
		   prioridad, cFluidos* fluido): cPaciente(nombre, fecha, tel, dni, sexo, fluido)
{
    this->estado = estado;
    this->f_listaEsp = f_listaEsp;
    this->prioridad = prioridad;
}

cReceptor::~cReceptor()
{

}

unsigned int cReceptor::get_prioridad()
{
    return this->prioridad;
}

time_t cReceptor::get_fecha()
{
    return this->f_listaEsp;
}

tipoE cReceptor::get_estado()
{
    return this->estado;
}

void cReceptor::set_estado(tipoE estado)
{
	this->estado = estado;
	return;
}

void cReceptor::set_prioridad(unsigned int prioridad)
{
	this->prioridad = prioridad;
	return;
}

ostream& operator<<(ostream& out, cReceptor& r) {

	if (&r == nullptr)
	{
		throw new exception{ "no se encontro paciente" };
	}

	out << r.to_string();
	return out;
}

string cReceptor::to_string() {
	stringstream ss;
	char comma = ',';
	ss << "Nombre: " << this->nombre << comma << "DNI: " << this->DNI << comma << "Sexo: " << this->sexo
		<< comma << "Recibe: ";

	string fluido = " ";

	if (dynamic_cast<cSangre*>(this->fluido) != nullptr)
	{
		fluido = "Sangre";
	}
	else if (dynamic_cast<cPlasma*>(this->fluido) != nullptr)
	{
		fluido = "Plasma";
	}
	else if (dynamic_cast<cMedulaOsea*>(this->fluido) != nullptr)
	{
		fluido = "Medula Osea";
	}

	ss<< fluido << comma << "Prioridad: " << this->prioridad << comma << 
		"Estado: " << this->estado << "Fecha de entrada a la lista de espera: " << this->f_listaEsp <<
		comma << "Contacto: " << this->telefono << endl;
	return ss.str();
}

