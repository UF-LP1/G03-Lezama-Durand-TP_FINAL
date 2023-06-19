#pragma once
#include "cPaciente.h"

class cDonante : public cPaciente{
private: 
	unsigned int edad, peso;
	bool enfermedad, tatuaje;
	time_t fecha_extraccion;// la fecha de extraccion en segundos
public:
	cDonante(string nombre, string fecha, string tel, string dni, char sexo, unsigned int edad, 
		unsigned int peso, bool enfermedad,bool tatuaje, cFluidos* fluido);
	~cDonante();
	void hola() {}
	unsigned int get_edad();
	unsigned int get_peso();
	bool get_enfermedad();
	bool get_tatuaje();
	time_t get_fextraccion();
	string to_string();
	friend ostream& operator<<(ostream& out, const cDonante& element);
};

ostream& operator<<(ostream& out, const cDonante& element);