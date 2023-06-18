#pragma once
#include "Header.h"
#include "cVector.h"
#include "cDonante.h"
#include "cReceptor.h"
#include "list"


bool myfunction(cReceptor& r1, cReceptor& r2);

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
	//void cargarArchivo();
	void agregarPaciente(cPaciente* paciente);
	cVector<cPaciente*> get_lista();
	cVector<cReceptor*> get_lista_receptor();
	cVector<cDonante*> get_lista_donante();
	void condiciones_donante();
	void clasificar_paciente();
	void eliminar_donante(cDonante *paciente);
	void ordenar_prioridad();
	bool operator==(cCentro element);
	bool realizar_transfusion(cPaciente* Persona, cDonante donante);
	string get_nombre();
	string get_provincia();
};


bool myfunction(cReceptor& r1, cReceptor& r2)
{
	if (r1.get_prioridad() > r2.get_prioridad())
	{
		return true;
	}
	else if (r1.get_estado() > r2.get_estado()) {
		return true;
	}
	else if (r1.get_fecha() > r2.get_fecha()) {
		return true;
	}
	return false;
}
