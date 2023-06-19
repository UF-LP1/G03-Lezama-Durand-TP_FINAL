#pragma once

#include "cVector.h"
#include "cDonante.h"
#include "cReceptor.h"

bool myfunction(cReceptor* r1, cReceptor* r2);

class cCentro {
private:
	string nombre, direccion, partido, provincia, telefono;
	friend class cBSA;
	cVector<cPaciente*> lista_pac;
	cVector<cDonante*> lista_donante;
	cVector<cReceptor*> lista_receptor;

public:
	cCentro();//necesitamos para la funcion buscar el centro del donante
	cCentro(string nombre, string direccion, string partido, string provincia, string telefono);
	~cCentro();
	void agregarPaciente(cPaciente* paciente);
	cVector<cPaciente*> get_lista();
	cVector<cReceptor*> get_lista_receptor();
	cVector<cDonante*> get_lista_donante();
	void eliminar_donante(cDonante* donante);
	void condiciones_donante();
	void clasificar_paciente();
	void ordenar_prioridad();
	friend bool operator==(cCentro c1, cCentro c2);
	bool realizar_transfusion(cPaciente* Persona, cDonante donante);
	string get_nombre();
	string get_provincia();
	string to_string();
	void listar_receptor();
	void listar_donante();
	friend ostream& operator<<(ostream& out, cCentro& element);
};

ostream& operator<<(ostream& out, cCentro& element); 

bool operator==(cCentro c1,cCentro c2);
