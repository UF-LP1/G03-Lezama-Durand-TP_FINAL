#pragma once
#include "Header.h"
#include "cVector.h"
#include "cDonante.h"
#include "cReceptor.h"


class cCentro {
private:
	string nombre, direccion, partido, provincia, telefono;
	cVector<cPaciente> lista_pac;
	
public:
	cCentro();
	~cCentro();
	void cargarArchivo();
	void agregarPaciente(cPaciente *paciente);
	cVector<cPaciente> getlista();
};

