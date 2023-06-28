#include "cDonante.h"

cDonante::cDonante(string nombre, string fecha, string tel, string dni, char sexo, unsigned int edad, unsigned int peso,
	bool enfermedad, bool tatuaje, cFluidos* fluido, time_t fecha_extraccion):
	cPaciente(nombre, fecha, tel, dni, sexo, fluido) {
	this->edad = edad;
	this->peso = peso;
	this->enfermedad = enfermedad;
	this->tatuaje = tatuaje;
	this->fecha_extraccion = fecha_extraccion;
}

cDonante::cDonante()
{
	this->edad =0;
	this->peso = 0;
	this->enfermedad = false;
	this->tatuaje = false;
	this->fecha_extraccion = 0;
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

istream& operator>>(istream& in, cDonante& d)
{
		string nombre, fecha, telefono, fluido, opcion;
		char sexo=' ';
		unsigned int edad, peso=0;
		int e=0;
		int tipo_sangre=0;
		char rh=' ';
		bool enfermedad, tatoo;

		cout << "Ingrese el nombre del donante" << endl;
		in >> nombre;

		cout << "Ingrese la fecha de nacimiento del donante" << endl;
		in >> fecha;

		cout << "Ingrese el telefono del donante" << endl;
		in >> telefono;

		cout << "Ingrese el sexo del donante" << endl;
		in >> sexo;
		
		cout << "Ingrese la edad del donante" << endl;
		in >> edad;

		cout << "Ingrese el peso del donante" << endl;
		in >> peso;

		cout << "Ingrese si el donante tiene una enfermedad: " << endl;
		in >> opcion;
		
		if (opcion == "si")
		{
			enfermedad = true;
		}
		else
		{
			enfermedad = false;
		}

		cout << "Ingrese si el donante se realizo un tatuaje en los ultimos dos meses: " << endl;
		in >> opcion;

		if (opcion == "si")
		{
			tatoo = true;
		}
		else
		{
			tatoo = false;
		}

		cout << "ingrese que fluido necesita recibir: sangre/Medula Osea/Plasma " << endl;
		in >> fluido;

		if (fluido == "sangre")
		{
			cout << "ingrese su tipo de sangre y rh: " << endl;
			in >> tipo_sangre >> rh;
			cSangre sangre(TipoS(tipo_sangre), rh);
			d.set_fluido(&sangre);
		}
		else if(fluido == "Plasma")
		{
			cout << "ingrese su tipo de sangre y rh: " << endl;
			in >> tipo_sangre >> rh;

			cPlasma Plasma(TipoS(tipo_sangre), rh);
			d.set_fluido(&Plasma);
		}
		else
		{
			cout << "ingrese su tipo de sangre y rh: " << endl;
			cMedulaOsea Med(TipoS(tipo_sangre), rh, "HLA-A");
			d.set_fluido(&Med);
		}

		d.set_nombre(nombre);
		d.set_fecha_nac(fecha);
		d.set_telefono(telefono);
		d.set_sexo(sexo);
		d.set_edad(edad);
		d.set_peso(peso);
		d.set_enfermedad(enfermedad);
		d.set_tatuaje(tatoo);

		return in;
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

void cDonante::set_edad(unsigned int s)
{
	this->edad = s;
	return;
}

void cDonante::set_peso(unsigned int s)
{
	this->peso = s;
	return;
}

void cDonante::set_enfermedad(bool s)
{
	this->enfermedad = s;
	return;
}

void cDonante::set_tatuaje(bool s)
{
	this->tatuaje = s;
	return;
}


