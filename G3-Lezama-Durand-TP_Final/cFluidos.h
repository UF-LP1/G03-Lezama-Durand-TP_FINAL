#pragma once
#include "Header.h"

enum TipoS{A=0,AB,B,O};

class cFluidos{
protected:
	const TipoS tipo;
	char RH;
	const int tiempo_max;

public:
	cFluidos();
	cFluidos(TipoS tipo, char rh, int tiempo_max);
	~cFluidos();
	TipoS get_tipo();
	virtual bool tiempoMax(time_t extraccion) = 0;
	bool operator==(cFluidos* element);//para verificar compatibilidad
	virtual string to_string()=0;
};

