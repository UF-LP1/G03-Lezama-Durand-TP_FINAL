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
	cDonante();
	~cDonante();
	unsigned int get_edad();
	unsigned int get_peso();
	bool get_enfermedad();
	bool get_tatuaje();
	time_t get_fextraccion();
	string to_string();
	void set_edad(unsigned int s);
	void set_peso(unsigned int s);
	void set_enfermedad(bool s);
	void set_tatuaje(bool s);

	friend istream& operator>>(istream& in, cDonante& element);
};

istream& operator>>(istream& in, cDonante& element);
