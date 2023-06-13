#include "cReceptor.h"

cReceptor::cReceptor(string nombre, string fecha, string tel, string dni, char sexo, string estado, time_t f_listaEsp, unsigned int prioridad):
    cPaciente(nombre, fecha, tel, dni, sexo)
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

string cReceptor::get_estado()
{
    return this->estado;
}

ostream& operator<<(ostream& out, const cReceptor& element) {
	if (&element == nullptr)
	{
		//tirar excepcion 
	}

	out << element.nombre << " " << element.fecha_nac << " " << element.DNI
		<< " " << element.sexo << " " << element.estado << " " << element.prioridad << endl;
	return out;
}