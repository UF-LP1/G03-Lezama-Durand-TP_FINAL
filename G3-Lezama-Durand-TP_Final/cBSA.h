#pragma once
#include "cVector.h"
#include "cDonante.h"
#include "cReceptor.h"
#include "cCentro.h"
#include "cSangre.h"
#include "cPlasma.h"
#include "cMedulaOsea.h"
#include "cRegistro.h"

bool myfunction(cReceptor& r1, cReceptor& r2);

class cBSA{
	cVector<cCentro> lista_centro;
	cVector<cRegistro> lista_registros;
	cVector<cReceptor> posibles_receptores(cDonante* donante);
	cVector<cReceptor> lista_sangre(cDonante* donante);
	cVector<cReceptor> lista_plasma(cDonante* donante);
	cVector<cReceptor> lista_medula(cDonante* donante);
	cCentro ubicarDonante(cDonante);
public:
	cBSA();
	~cBSA();
	void agregar_centro(cCentro centro);
	cPaciente* match(cDonante* donante);
	cCentro protocolo(cReceptor receptor);
	void Crear_Registro(cReceptor rp, cDonante rd, cCentro centro);
	void buscar_receptor(string DNI);
};

