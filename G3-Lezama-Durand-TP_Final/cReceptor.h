#pragma once
#include "cPaciente.h"
class cReceptor : public cPaciente {
private:
	string estado, f_listaEsp;
public:
	cReceptor();
	~cReceptor();
};

