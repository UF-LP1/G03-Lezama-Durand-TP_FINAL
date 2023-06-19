#pragma once
#include "cCentro.h"
#include "cRegistro.h"

class cBSA{
	cVector<cCentro> lista_centro;
	cVector<cRegistro*> lista_registros;
	cVector<cReceptor*> posibles_receptores(cDonante* donante);
	cVector<cReceptor*> lista_sangre(cDonante* donante);
	cVector<cReceptor*> lista_plasma(cDonante* donante);
	cVector<cReceptor*> lista_medula(cDonante* donante);
	cCentro ubicarDonante(cDonante);
public:
	cBSA();
	~cBSA();
	void agregar_centro(cCentro centro);
	cPaciente* match(cDonante* donante);
	cCentro protocolo(cReceptor receptor);
	void Crear_Registro(cReceptor rp, cDonante rd, cCentro centro);
	void buscar_receptor(string DNI);
	cVector<cCentro> get_listacentro();
	friend ostream& operator<<(ostream& out, cBSA& element);
	void Buscar_receptor_imprimir(string DNI);
	void Informar_Cant_provincia();
};

ostream& operator<<(ostream& out, cBSA& element);
