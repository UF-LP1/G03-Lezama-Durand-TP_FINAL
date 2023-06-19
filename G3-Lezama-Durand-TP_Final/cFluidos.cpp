#include "cFluidos.h"

cFluidos::cFluidos()
{
	this->tipo = A;
	this->RH = ' ';
}

cFluidos::cFluidos(TipoS tipo, char rh)
{
	this->tipo = tipo;
	this->RH= rh;
}

cFluidos::~cFluidos()
{

}

TipoS cFluidos::get_tipo()
{
	return this-> tipo;
}

bool cFluidos::operator==(cFluidos* element)
{
	bool compatible=false;

	switch (this->tipo)
	{
	case A:
		if (this->RH == '+') {
			if (element->get_tipo() == A && element->RH == '+' || element->get_tipo() == A && element->RH == '+'||
				element->get_tipo() == O && element->RH == '+' || element->get_tipo() == O && element->RH == '+') // A+ Recibe A+ A- O+ O-
				compatible = true;
			else
				compatible = false;
		}
		else if (this->RH == '-') {
			if (element->get_tipo() == A && element->RH == '-' || element->get_tipo() == O && element->RH == '-') // A- recibe A- O-
				compatible = true;
			else
				compatible = false;
		}
		break;

	case B:
		if (this->RH == '+') {
			if (element->get_tipo() == B && element->RH == '+' || element->get_tipo() == B && element->RH == '+' ||
				element->get_tipo() == O && element->RH == '+' || element->get_tipo() == O && element->RH == '+') // B+ dona a B+ y AB+
				compatible = true;
			else
				compatible = false;
		}
		else if (this->RH == '-') {
			if (element->get_tipo() == B && element->RH == '-' || element->get_tipo() == O && element->RH == '-')
				compatible = true;
			else
				compatible = false;
		}
		break;

	case AB:
		if (this->RH == '+') {
			if (element->get_tipo() == A && element->RH == '+' || element->get_tipo() == A && element->RH == '-' ||
				element->get_tipo() == O && element->RH == '+' || element->get_tipo() == O && element->RH == '-' ||
				element->get_tipo() == B && element->RH == '+' || element->get_tipo() == B && element->RH == '-'||
				element->get_tipo() == AB && element->RH == '+' || element->get_tipo() == AB && element->RH == '+')//recibe de todos 

				compatible = true;
			else 
				compatible = false;

		}
		else if (this->RH == '-') {
			if (element->get_tipo() == B && element->RH == '-' || element->get_tipo() == A && element->RH == '-' ||
				element->get_tipo() == O && element->RH == '-' || element->get_tipo() == AB && element->RH == '-') // AB- recibe de B- A- O- AB-
				compatible = true;
			else
				compatible = false;
		}
		break;

	case O:
		if (this->RH == '+') {
			if (element->get_tipo() == O && element->RH == '+' || element->get_tipo() == O && element->RH == '-') // O+ recibe de
				compatible = true;
			else
				compatible = false;
		}
		else if (this->RH == '-') {
			if(element->get_tipo() == O && element->RH == '-')
				compatible = true; 
			else
				compatible = false;
		}
		break;
	}

	return compatible;
}

