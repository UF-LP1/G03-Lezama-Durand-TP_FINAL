#pragma once
#include "Header.h"
#include "cVector.h"
#include "cDonante.h"
#include "cReceptor.h"
#include "list"



class cCentro {
private:
	string nombre, direccion, partido, provincia, telefono;
	cVector<cPaciente*> lista_pac;
	cVector<cDonante*> lista_donante;
	cVector<cReceptor*> lista_receptor;
	bool myfunction(cReceptor* r1, cReceptor* r2);

public:
	cCentro(string nombre, string direccion, string partido, string provincia, string telefono);
	~cCentro();
	void cargarArchivo();
	void agregarPaciente(cPaciente* paciente);
	cVector<cPaciente*> get_lista();
	cVector<cReceptor*> get_lista_receptor();
	cVector<cDonante*> get_lista_donante();
	void condiciones_donante();
	void clasificar_paciente();
	void eliminar_donante(cDonante *paciente);
	void ordenar_prioridad();
};
