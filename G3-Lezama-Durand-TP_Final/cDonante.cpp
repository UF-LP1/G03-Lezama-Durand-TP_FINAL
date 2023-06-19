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

bool cDonante::operator==(cDonante* element)
{
	if (this->nombre == element->nombre && this->DNI == element->DNI)
	{
		return true;
	}
	else
		return false;

}

ostream& operator<<(ostream& out, cDonante& element) {
	if (&element == nullptr)
	{
		throw new exception{ "no se encontro paciente" };
	}

	out << element.to_string();
	return out;
}

string cDonante::to_string() {
	stringstream ss;
	char comma = ',';
	ss << "Nombre: " << this->nombre << comma << "DNI: " << this->DNI << comma << "Edad:"
		<< this->edad << comma << "Sexo: " << this->sexo << comma << "Peso: " << this->peso
		<< comma << "Contacto: " << this->telefono << comma;

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

	ss << "Dona: " << fluido << endl;
	return ss.str();
}