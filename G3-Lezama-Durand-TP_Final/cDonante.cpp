#include "cDonante.h"

cDonante::cDonante(string nombre, string fecha, string tel, string dni, char sexo, unsigned int edad, unsigned int peso,
	bool enfermedad, bool tatuaje, cFluidos* fluido):
	cPaciente(nombre, fecha, tel, dni, sexo, fluido) {
	this->edad = edad;
	this->peso = peso;
	this->enfermedad = enfermedad;
	this->tatuaje = tatuaje;
}

cDonante::~cDonante()
{

}

unsigned int cDonante::get_edad()
{
	return this->edad;
}

unsigned int cDonante::get_peso()
{
	return this->peso;
}

bool cDonante::get_enfermedad()
{
	return this->enfermedad;
}

bool cDonante::get_tatuaje()
{
	return this->tatuaje;
}

time_t cDonante::get_fextraccion()
{
	return this->fecha_extraccion;
}

string cDonante::to_string() {
	stringstream ss;
	ss << this->nombre <<" "<< this->fecha_nac<<" "<< this->DNI<<" " << this->sexo<<" " << this->edad;
	return ss.str();
}

bool cDonante::operator==(cDonante* element)
{
	if (this->nombre == element->nombre && this->DNI == element->DNI)
	{
		return true;
	}
	else
		return false;

}

ostream& operator<<(ostream& out, const cDonante& element) {
	if (&element == nullptr)
	{
		//tirar excepcion 
	}

	out << element.nombre << " " << element.fecha_nac << " " << element.DNI << " " << element.sexo << " " << element.edad << endl;
	return out;
}
