#include "cBSA.h"

cBSA::cBSA()
{
}

cBSA::~cBSA()
{
}

void cBSA::agregar_centro(cCentro centro)
{
	this->lista_centro + (centro);
}

cVector<cReceptor*> cBSA::posibles_receptores(cDonante* donante)
{
	cVector<cReceptor*> lista;

	cFluidos* aux = dynamic_cast<cSangre*>(donante->get_fluido());
	if (aux != nullptr)
	{
		lista = this->lista_sangre(donante);
	}
	aux = dynamic_cast<cPlasma*>(donante->get_fluido());
	if (aux != nullptr)
	{
		lista = this->lista_plasma(donante);
	}
	aux = dynamic_cast<cMedulaOsea*>(donante->get_fluido());
	if (aux != nullptr)
	{
		lista = this->lista_medula(donante);
	}

	return lista;
}

cPaciente* cBSA::match(cDonante* donante)
{
	cVector<cReceptor*> lista=posibles_receptores(donante);
	cCentro centro_donante=this->ubicarDonante(*donante);
	cCentro centro_receptor;

	sort(lista.begin(), lista.end(), myfunction);//ordeno la lista por prioridad

	int i, pos = 0, cont=0;

	cPaciente* persona=0;

	if (!(lista.empty()))
	{
		for(i = 0;i < lista.size();i++)
		{
			centro_receptor =this->protocolo(*lista[i]);

			if (centro_donante == centro_receptor && cont==0)
			{
				persona = lista[i];
				cont++;
			}
		}

		return persona;
	}
	else
		return nullptr;
}

cCentro cBSA::protocolo(cReceptor receptor)
{
	cCentro centro;

	for (int i = 0;i < this->lista_centro.size();i++)
	{
		for (int k = 0;k < this->lista_centro[i].get_lista_receptor().size();k++)
		{
			if (receptor == lista_centro[i].get_lista_donante()[k])
			{
				centro = lista_centro[i];
			}
		}
	}

	return centro;
}

void cBSA::Crear_Registro(cReceptor rp, cDonante rd, cCentro centro)
{
	string centro_ = centro.get_nombre();
	time_t fecha_t = rd.get_fextraccion(); 
	string donante = rd.get_nombre(); 
	string receptor = rp.get_nombre(); 
	string fluido = " ";

	if (dynamic_cast<cSangre*>(rd.get_fluido()) != nullptr)
	{
		fluido = "Sangre";
	}
	else if (dynamic_cast<cPlasma*>(rd.get_fluido()) != nullptr)
	{
		fluido = "Plasma";
	}
	else if (dynamic_cast<cMedulaOsea*>(rd.get_fluido()) != nullptr)
	{
		fluido = "Medula Osea";
	}

	cFluidos* datos_fluidos = rd.get_fluido();
	string provincia = centro.get_provincia();

	cRegistro registro(centro_, fecha_t, donante, receptor, fluido, datos_fluidos, provincia);

	this->lista_registros.push_back(&registro);
}

void cBSA::buscar_receptor(string DNI)
{
	for (int i = 0;i < this->lista_centro.size();i++)
	{
		for (int k = 0;k < this->lista_centro[i].lista_receptor.size();k++)
		{
			if(lista_centro[i].lista_receptor[k]->get_DNI()==DNI)
			{
				cout << lista_centro[i].lista_receptor[k];
			}
		}
	}

	return;
}

cVector<cCentro> cBSA::get_listacentro()
{
	return this->lista_centro;
}

cVector<cReceptor*> cBSA::lista_sangre(cDonante* donante){

	cVector<cReceptor*> lista;

	for (int i = 0;i < this->lista_centro.size();i++)
	{
		for (int k = 0;k < this->lista_centro[i].lista_receptor.size();k++)
		{
			cFluidos* aux = dynamic_cast<cSangre*>(this->lista_centro[i].lista_receptor[k]->get_fluido());
			if(aux!=nullptr  && lista[i]->get_fluido() == donante->get_fluido())
			{
				lista + (lista_centro[i].lista_receptor[k]);
			}
		}
	}
	return lista;
}

cVector<cReceptor*> cBSA::lista_plasma(cDonante* donante)
{
	cVector<cReceptor*> lista;

	for (int i = 0;i < this->lista_centro.size();i++)
	{
		for (int k = 0;k < this->lista_centro[i].lista_receptor.size();k++)
		{
			cFluidos* aux = dynamic_cast<cPlasma*>(lista_centro[i].lista_receptor[k]->get_fluido());
			if (aux != nullptr && lista[i]->get_fluido() == donante->get_fluido())
			{
				lista + (lista_centro[i].lista_receptor[k]);
			}
		}
	}
	return lista;
}

cVector<cReceptor*> cBSA::lista_medula(cDonante* donante)
{
	cVector<cReceptor*> lista;

	for (int i = 0;i < this->lista_centro.size();i++)
	{
		for (int k = 0;k < this->lista_centro[i].lista_receptor.size();k++)
		{
			cFluidos* aux = dynamic_cast<cMedulaOsea*>(lista_centro[i].lista_receptor[k]->get_fluido());
			if (aux != nullptr && lista[i]->get_fluido() == donante->get_fluido())
			{
				lista + (lista_centro[i].lista_receptor[k]);
			}
		}
	}
	return lista;
}

cCentro cBSA::ubicarDonante(cDonante donante)
{
	cCentro centro;

	for (int i = 0;i < this->lista_centro.size();i++)
	{
		for (int k = 0;k < this->lista_centro[i].get_lista_donante().size();k++)
		{
			if (donante==lista_centro[i].get_lista_donante()[k])//sobrecarga de == con nombre DNI y Nombre
			{
				centro = lista_centro[i];
			}
		}
	}
	return centro;
}

ostream& operator<<(ostream& out, cBSA& element) {

	for (int i = 0;i < element.lista_centro.size();i++)
	{
		out << element.lista_centro[i];
	}

	return out;
}

