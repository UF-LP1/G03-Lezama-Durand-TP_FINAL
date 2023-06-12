#pragma once
#include "cPaciente.h"
class cDonante : public cPaciente{
private: 
	unsigned int edad, peso;
	bool enfermedad, tatuaje;
public:
	cDonante();
	~cDonante();
};

