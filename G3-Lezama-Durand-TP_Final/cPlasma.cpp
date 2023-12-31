#include "cPlasma.h"

cPlasma::cPlasma(TipoS tipo, char rh) :cFluidos(tipo, rh,365)
{

}

cPlasma::~cPlasma()
{

}

bool cPlasma::tiempoMax(time_t extraccion)
{
	bool en_tiempo = false;

	time_t tiempo_actual = time(nullptr); // obtengo el tiempo actual.
	tm* fechaActual = new tm;
	localtime_s(fechaActual, &tiempo_actual);
	struct tm* FECHA = new tm;

	localtime_s(FECHA, &extraccion); // convierto la variable time_t a una estructura (tm) usando localtime para obtener dia,mes y anio. 

	double diferenciaSegundos = difftime(tiempo_actual, extraccion); // la funcion difftime calcula la diferencia entre dos fechas time_t y devuelve EN SEGUNDOS. 

	int diferenciaDias = static_cast<int>(diferenciaSegundos / (24 * 60 * 60)); // convierto la diferencia a dias

	if (diferenciaDias <= tiempo_max)
		en_tiempo = true;

	delete FECHA;
	delete fechaActual;
	return en_tiempo;
}

string cPlasma::to_string() {
	stringstream ss;
	char comma = ',';
	ss << "Tipo de sangre: " << this->tipo << comma << "Rh: " << this->RH << endl;
	return ss.str();
}

ostream& operator<<(ostream& out, cPlasma& plasma)
{
	if (&plasma == nullptr)
	{
		throw new exception{ "no se encontro paciente" };
	}

	out << plasma.to_string();
	return out;
}
