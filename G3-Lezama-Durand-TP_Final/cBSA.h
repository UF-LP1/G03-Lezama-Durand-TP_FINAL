#pragma once
#include "cCentro.h"
#include "cRegistro.h"

class cBSA{
	vector<cCentro> lista_centro;
	vector<cRegistro> lista_registros;
	vector<cReceptor> lista_sangre(cDonante* donante);
	vector<cReceptor> lista_plasma(cDonante* donante);
	vector<cReceptor> lista_medula(cDonante* donante);
	cCentro ubicarDonante(cDonante d);

public:
	cBSA();
	~cBSA();

	cPaciente* match(cDonante* donante, vector<cReceptor> *lista);
	cCentro protocolo(cReceptor* receptor);
	void Crear_Registro(cReceptor rp, cDonante rd, cCentro centro);
	void buscar_receptor(string DNI);
	vector<cCentro> get_listacentro();
	void Buscar_receptor_imprimir(string DNI);
	void Informar_Cant_provincia();

	vector<cReceptor> posibles_receptores(cDonante* donante);

	friend ostream& operator<<(ostream& out, cBSA& element);
	void operator+(cCentro centro);
};

ostream& operator<<(ostream& out, cBSA& element);
