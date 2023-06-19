#pragma once
#include "Header.h"

enum TipoS{A=0,AB,B,O};

class cFluidos{
protected:
	TipoS tipo;
	char RH;
public:
	cFluidos();
	cFluidos(TipoS tipo, char rh);
	~cFluidos();
	TipoS get_tipo();
	virtual bool tiempoMax(time_t extraccion) = 0;
	bool operator==(cFluidos* element);//para verificar compatibilidad
	virtual string to_string()=0;
};

