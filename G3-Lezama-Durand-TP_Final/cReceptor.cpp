#include "cReceptor.h"

cReceptor::cReceptor(string nombre, string fecha, string tel, string dni, char sexo, tipoE estado, time_t f_listaEsp, unsigned int 
		   prioridad, cFluidos* fluido): cPaciente(nombre, fecha, tel, dni, sexo, fluido)
{
    this->estado = estado;
    this->f_listaEsp = f_listaEsp;
    this->prioridad = prioridad;
}

cReceptor::cReceptor()
{
	this->estado = estable;
	this->f_listaEsp = 0;
	this->prioridad = 5;
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

void cReceptor::set_fechaLE(time_t s)
{
	this->f_listaEsp = s;
	return;
}


istream& operator>>(istream& in, cReceptor& r)
{
	string nombre, fecha, telefono, fluido, opcion;
	char sexo;
	int estado, prioridad = 0;
	int tipo_sangre = 0;
	char rh = ' ';

	cout << "Ingrese el nombre del receptor" << endl;
	in >> nombre;

	cout << "Ingrese la fecha de nacimiento del receptor" << endl;
	in >> fecha;

	cout << "Ingrese el telefono del receptor" << endl;
	in >> telefono;

	cout << "Ingrese el sexo del receptor" << endl;
	in >> sexo;

	cout << "Ingrese el estado del receptor" << endl;
	in >> estado;

	cout << "Ingrese la prioridad del receptor" << endl;
	in >> prioridad;

	cout << "ingrese que fluido necesita recibir: sangre/Medula Osea/Plasma " << endl;
	in >> fluido;

	if (fluido == "sangre")
	{
		cout << "ingrese su tipo de sangre y rh: " << endl;
		in >>tipo_sangre>>rh;

		cSangre sangre(TipoS(tipo_sangre), rh);
		r.set_fluido(&sangre);
	}
	else if (fluido == "Plasma")
	{
		cout << "ingrese su tipo de sangre y rh: " << endl;
		in >> tipo_sangre >> rh;

		cPlasma Plasma(TipoS(tipo_sangre), rh);
		r.set_fluido(&Plasma);
	}else
	{
		cout << "ingrese su tipo de sangre y rh: " << endl;
		cMedulaOsea Med(TipoS(tipo_sangre), rh,"HLA-A");
		r.set_fluido(&Med);
	}

	r.set_nombre(nombre);
	r.set_fecha_nac(fecha);
	r.set_telefono(telefono);
	r.set_sexo(sexo);
	r.set_estado(tipoE(estado));
	r.set_prioridad(prioridad);

	return in;
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

