#include "cBSA.h"

cBSA::cBSA()
{
}

cBSA::~cBSA()
{
}


vector<cReceptor> cBSA::posibles_receptores(cDonante* donante)
{
	vector<cReceptor> lista;

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

cPaciente* cBSA::match(cDonante* donante, vector<cReceptor> *lista)
{
	cCentro centro_donante=this->ubicarDonante(*donante);
	cCentro centro_receptor;

	//sort(lista.begin(),lista.end(), myfunction);//ordeno la lista por prioridad

	int i, pos = 0, cont=0;

	cPaciente* persona=nullptr;

	if (!(lista->empty()))
	{
		for(i = 0;i < lista->size();i++)
		{
			centro_receptor =this->protocolo(&lista->at(i));

			if (centro_donante == centro_receptor && cont==0)
			{
				persona = (&lista->at(i));
				cont++;
			}
		}
		return persona;
	}
	else
		return persona;
}

cCentro cBSA::protocolo(cReceptor* receptor)
{
	cCentro centro;

	for (int i = 0;i < this->lista_centro.size();i++)
	{
		for (int k = 0;k < this->lista_centro[i].get_lista_receptor().size();k++)
		{
			if (lista_centro[i].get_lista_receptor()[k] == receptor)
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

	this->lista_registros.push_back(registro);
}

void cBSA::buscar_receptor(string DNI)
{
	for (int i = 0;i < this->lista_centro.size();i++)
	{
		for (int k = 0;k < this->lista_centro[i].get_lista_receptor().size();k++)
		{
			if(this->lista_centro[i].get_lista_receptor()[k].get_DNI()==DNI)
			{
				cout << &lista_centro[i].get_lista_receptor()[k];
			}
		}
	}

	return;
}

vector<cCentro> cBSA::get_listacentro()
{
	return this->lista_centro;
}

vector<cReceptor> cBSA::lista_sangre(cDonante* donante){

	vector<cReceptor> lista;

	for (int i = 0;i < this->lista_centro.size();i++)
	{
		for (int k = 0;k < this->lista_centro[i].get_lista_receptor().size();k++)
		{
			cFluidos* aux = dynamic_cast<cSangre*>(this->lista_centro[i].get_lista_receptor()[k].get_fluido());
			
			if(aux!=nullptr  && lista_centro[i].get_lista_receptor()[k].get_fluido() == donante->get_fluido())
			{
				lista.push_back(lista_centro[i].get_lista_receptor()[k]);
			}
		}
	}
	return lista;
}

vector<cReceptor> cBSA::lista_plasma(cDonante* donante)
{
	vector<cReceptor> lista;

	for (int i = 0;i < this->lista_centro.size();i++)
	{
		for (int k = 0;k < this->lista_centro[i].get_lista_receptor().size();k++)
		{
			cFluidos* aux = dynamic_cast<cPlasma*>(lista_centro[i].get_lista_receptor()[k].get_fluido());
			if (aux != nullptr&& lista_centro[i].get_lista_receptor()[k].get_fluido() == donante->get_fluido())
			{
				lista.push_back(lista_centro[i].get_lista_receptor()[k]);
			}
		}
	}
	return lista;
}

vector<cReceptor> cBSA::lista_medula(cDonante* donante)
{
	vector<cReceptor> lista;

	for (int i = 0;i < this->lista_centro.size();i++)
	{
		for (int k = 0;k < this->lista_centro[i].get_lista_receptor().size();k++)
		{
			cFluidos* aux = dynamic_cast<cMedulaOsea*>(lista_centro[i].get_lista_receptor()[k].get_fluido());

			if (aux != nullptr && lista_centro[i].get_lista_receptor()[k].get_fluido() == donante->get_fluido())
			{
				lista.push_back(lista_centro[i].get_lista_receptor()[k]);
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
			if (donante==&lista_centro[i].get_lista_donante()[k])//sobrecarga de == con nombre DNI y Nombre
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

void cBSA::Buscar_receptor_imprimir(string DNI) {
	int i;
	for (i = 0; i < this->lista_centro.size();i++)
	{
		for (int k = 0; k < this->lista_centro[i].get_lista_receptor().size();k++)
		{
			if (lista_centro[i].get_lista_receptor()[k].get_DNI() == DNI)
				cout << lista_centro[i].get_lista_receptor()[k].to_string();
		}
	}
	if (i == this->lista_centro.size())
	{
		throw new exception("no se encontro el receptor");
	}
	return;
}

void cBSA::Informar_Cant_provincia()
{
	unsigned int contCABA=0, contBA=0, contMend=0,contSanLuis=0, contSantaFe=0, contSanJuan=0, contSantiago=0, contNeuquen=0, contLaPampa=0, 
		contLaRioja=0,contCatamarca=0, contRioNegro=0, contChubut=0, contTierraDelFuego=0, contCordoba=0, contEntreRios=0, contCorrientes=0,
		contMisiones=0, contTucuman=0, contJujuy=0, contSalta=0, contFormosa=0, contSantCruz=0, contChaco=0;

	time_t now = time(NULL);//obtengo la fecha actual en segundos
	tm* ahora = new tm;
	localtime_s(ahora, &now);//convierto now a tm y lo guardo en ahora

	tm* fechaAux = new tm;
	time_t donancion;
	string provincia;

	if (ahora->tm_isdst == 28)//mi final de mes va a ser 28 porque todos los meses tienen 28 dias
	{
		for (int i = 0;i < lista_registros.size();i++)
		{
			donancion = lista_registros[i].get_fecha();
			localtime_s(fechaAux, &donancion);
			
			if (fechaAux->tm_mday == ahora->tm_mday)
			{
				if (lista_registros[i].get_provincia() == "CABA")
				{
					contCABA++;
				}
				else if (lista_registros[i].get_provincia() == "Buenos Aires")
				{
					contBA++;
				}else if (lista_registros[i].get_provincia() == "Santa Fe")
				{
					contSantaFe++;
				}
				else if (lista_registros[i].get_provincia() == "Cordoba")
				{
					contCordoba++;
				}else if (lista_registros[i].get_provincia() == "San Luis")
				{
					contSanLuis++;

				}else if (lista_registros[i].get_provincia() == "La Pampa")
				{
					contLaPampa++;
				}else if (lista_registros[i].get_provincia() == "Misiones")
				{
					contMisiones++;
				}
				else if (lista_registros[i].get_provincia() == "Corrientes")
				{
					contCorrientes++;
				}
				else if (lista_registros[i].get_provincia() == "Entre Rios")
				{
					contEntreRios++;

				}else if (lista_registros[i].get_provincia() == "Jujuy")
				{
					contJujuy++;
				}else if (lista_registros[i].get_provincia() == "Salta")
				{
					contSalta++;
				}else if (lista_registros[i].get_provincia() == "Tucuman")
				{
					contTucuman++;
				}
				else if (lista_registros[i].get_provincia() == "Santiago del Estero")
				{
					contSantiago++;
				}else if (lista_registros[i].get_provincia() == "Catamarca")
				{
					contCatamarca++;
				}else if (lista_registros[i].get_provincia() == "La Rioja")
				{
					contLaRioja++;
				}else if (lista_registros[i].get_provincia() == "Chaco")
				{
					contChaco++;
				}else if (lista_registros[i].get_provincia() == "Formosa")
				{
					contFormosa++;
				}else if (lista_registros[i].get_provincia() == "San Juan")
				{
					contSanJuan++;
				}else if (lista_registros[i].get_provincia() == "Mendoza")
				{
					contMend++;
				}else if (lista_registros[i].get_provincia() == "Chubut")
				{
					contChubut++;
				}else if (lista_registros[i].get_provincia() == "Neuquen")
				{
					contNeuquen++;
				}else if (lista_registros[i].get_provincia() == "San Cruz")
				{
					contSantCruz++;
				}else if (lista_registros[i].get_provincia() == "Tierra del Fuego")
				{
					contTierraDelFuego++;
				}else if (lista_registros[i].get_provincia() == "Rio Negro")
				{
					contRioNegro++;
				}
			}
		}
	}

	cout << "Donantes en: " << endl;
	cout << "Jujuy: " << contJujuy << endl;
	cout << "Salta: " << contSalta << endl;
	cout << "Formosa: " << contFormosa << endl;
	cout << "Tucuman: " << contTucuman << endl;
	cout << "Misiones: " << contMisiones << endl;
	cout << "San Luis: " << contSanLuis << endl;
	cout << "San Juan: " << contSanJuan << endl;
	cout << "Mendoza: " << contMend << endl;
	cout << "Cordoba: " << contCordoba << endl;
	cout << "Corrientes: " << contCorrientes << endl;
	cout << "Entre Rios: " << contEntreRios << endl;
	cout << "Bs As: " << contBA << endl;
	cout << "CABA: " << contCABA << endl;
	cout << "Neuquen: " << contNeuquen << endl;
	cout << "La Pampa: " << contLaPampa << endl;
	cout << "Santa Cruz: " << contSantCruz << endl;
	cout << "Chubut: " << contChubut << endl;
	cout << "Tierra del Fuego: " << contTierraDelFuego << endl;
	cout << "La Rioja: " << contLaRioja << endl;
	cout << "Chaco: " << contChaco << endl;
	cout << "Santa Fe: " << contSantaFe << endl;
	cout << "Catamarca: " << contCatamarca << endl;
	cout << "Rio Negro: " << contRioNegro << endl;
	cout << "Santiago del Estero: " << contSantiago << endl << endl;
	
	return;
}

void cBSA::operator+(cCentro centro)
{
	this->lista_centro.push_back(centro);
}
