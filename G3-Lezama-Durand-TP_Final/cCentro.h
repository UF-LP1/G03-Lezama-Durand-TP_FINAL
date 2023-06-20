#pragma once

#include "cVector.h"
#include "cDonante.h"
#include "cReceptor.h"

bool myfunction(cReceptor r1, cReceptor r2);

template <typename T>
inline void operator+(vector<T>lista, T persona);

inline void operator-(vector<cPaciente*>lista, cPaciente* persona);

class cCentro {
private:
	string nombre, direccion, partido, provincia, telefono;
	friend class cBSA;
	vector<cPaciente*> lista_pac;
	vector<cDonante> lista_donante;
	vector<cReceptor> lista_receptor;

public:
	cCentro();//necesitamos para la funcion buscar el centro del donante
	cCentro(string nombre, string direccion, string partido, string provincia, string telefono);
	~cCentro();
	void agregarDonante(cDonante paciente);
	vector<cPaciente*> get_lista();
	vector<cReceptor> get_lista_receptor();
	vector<cDonante> get_lista_donante();
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
	friend istream& operator>>(istream& in, cCentro& element);
	void set_nombre(string s);
	void set_direccion(string s);
	void set_partido(string s);
	void set_provincia(string s);
	void set_telefono(string s );
	void agregarReceptor(cReceptor paciente);
	void imprimir();
};


ostream& operator<<(ostream& out, cCentro& element);

istream& operator>>(istream& in, cCentro& element);

bool operator==(cCentro c1,cCentro c2);
