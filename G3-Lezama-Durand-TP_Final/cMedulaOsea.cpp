#include "cMedulaOsea.h"

cMedulaOsea::cMedulaOsea(TipoS tipo, char rh, string HLA):cFluidos(tipo,rh)
{
	this->HLA = HLA;
}

cMedulaOsea::~cMedulaOsea()
{

}

bool cMedulaOsea::tiempoMax(time_t extraccion)
{
	bool en_tiempo = false;

	time_t tiempo_actual = time(nullptr); // obtengo el tiempo actual.
	tm* fechaActual = new tm;
	localtime_s(fechaActual, &tiempo_actual);
	struct tm* FECHA = new tm;

	localtime_s(FECHA, &extraccion); // convierto la variable time_t a una estructura (tm) usando localtime para obtener dia,mes y anio. 

	double diferenciaSegundos = difftime(tiempo_actual, extraccion); // la funcion difftime calcula la diferencia entre dos fechas time_t y devuelve EN SEGUNDOS. 

	int diferenciaDias = static_cast<int>(diferenciaSegundos / (24 * 60 * 60)); // convierto la diferencia a dias

	if (diferenciaDias <= t_med)
		en_tiempo = true;

	delete FECHA;
	delete fechaActual;
	return en_tiempo;
}

string cMedulaOsea::get_HLA()
{
	return this->HLA;
}

string cMedulaOsea::to_string() {
	stringstream ss;
	char comma = ',';
	ss << "Tipo de sangre: " << this->tipo << comma << "Rh: " << this->RH << "HLA: 	" << this->HLA << endl;
	return ss.str();
}

ostream& operator<<(ostream& out, cMedulaOsea& element) {

	if (&element == nullptr)
	{
		throw new exception{ "no se encontro paciente" };
	}

	out << element.to_string();
	return out;
}