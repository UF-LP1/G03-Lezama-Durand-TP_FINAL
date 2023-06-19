#pragma once
#include "Header.h"
#include "cVector.h"
#include "cDonante.h"
#include "cReceptor.h"
#include "list"


bool myfunction(cReceptor& r1, cReceptor& r2);
void operator-(cVector<cPaciente*> lista, cPaciente* element);
;
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
	bool operator==(cCentro element);
	bool realizar_transfusion(cPaciente* Persona, cDonante donante);
	string get_nombre();
	string get_provincia();
	string to_string();
	void listar_receptor();
	void listar_donante();
	friend ostream& operator<<(ostream& out, cCentro& element);
	friend void operator-(cVector<cPaciente*> lista, cPaciente* element);
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

void operator-(cVector<cPaciente*> lista, cPaciente* element) {

	for (int i = 0;i < lista.size();i++)
	{
		if (lista[i] == element)
		{
			lista.erase(lista.begin() + i);
		}
	}
	return;
}
