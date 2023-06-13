#pragma once
#include "Header.h"

enum TipoS{A=0,AB,B,O};

class cFluidos{
protected:
	time_t fecha_max;
	TipoS tipo;
public:
	cFluidos();
	~cFluidos();
	TipoS get_tipo();
};

