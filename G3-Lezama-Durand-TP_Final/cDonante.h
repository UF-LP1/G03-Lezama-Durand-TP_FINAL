#pragma once
#include "cPaciente.h"

class cDonante : public cPaciente{
private: 
	unsigned int edad, peso;
	bool enfermedad, tatuaje;
public:
	cDonante(string nombre, string fecha, string tel, string dni, char sexo, unsigned int edad, unsigned int peso, bool enfermedad,bool tatuaje);
	~cDonante();
	void hola() {}
	unsigned int get_edad();
	unsigned int get_peso();
	bool get_enfermedad();
	bool get_tatuaje();
	string to_string();
	friend ostream& operator<<(ostream& out, const cDonante& element);
};