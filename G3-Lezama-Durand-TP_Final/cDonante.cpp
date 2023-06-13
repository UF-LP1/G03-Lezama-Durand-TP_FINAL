#include "cDonante.h"

cDonante::cDonante(string nombre, string fecha, string tel, string dni, char sexo, unsigned int edad, unsigned int peso, bool enfermedad, bool tatuaje) :
	cPaciente(nombre, fecha, tel, dni, sexo) {
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

string cDonante::to_string() {
	stringstream ss;
	ss << this->nombre <<" "<< this->fecha_nac<<" "<< this->DNI<<" " << this->sexo<<" " << this->edad;
	return ss.str();
}

ostream& operator<<(ostream& out, const cDonante& element) {
	if (&element == nullptr)
	{
		//tirar excepcion 
	}

	out << element.nombre << " " << element.fecha_nac << " " << element.DNI << " " << element.sexo << " " << element.edad << endl;
	return out;
}
