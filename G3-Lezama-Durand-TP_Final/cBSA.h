#pragma once
#include "cVector.h"
#include "cDonante.h"
#include "cReceptor.h"
#include "cCentro.h" 

class cBSA{
	cVector<cCentro> lista_centro;
public:
	cBSA();
	~cBSA();
	void agregar_centro(cCentro centro);
};

