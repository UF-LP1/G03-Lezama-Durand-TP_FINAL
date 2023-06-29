#include "cBSA.h"


//hola fran (o cualquier otro ayudante) 
//el const esta en el la clase fluidos y el static esta en el clase cBSA
//ya nuestro programa funciona!!!! solo encuentra dos macth porque son solo dos los que son compatibles 
//si queres que encuentre mas acomodalos, y encontrara mas!!
//la sobrecarga de cin esta bella 
//fue un dolor de cabeza la funcion de ordenar 
//te sugiero que cuando deses buscar un receptor pongas este DNI:96159664
//espero que les gueste el TP los hicomos con mucho cariño, saludos MARIA Y SAUL

int menu();

int main()
{

	cBSA BSA;
	time_t tiempo_actual = time(nullptr);

	//creamos fluidos
		cSangre Bmen(B, '-');
		cSangre A_pos(A, '+');
		cSangre ABpos(AB, '+');
		cPlasma Plasma_A(A, '+');
		cPlasma Plasma_B(B, '-');
		cPlasma Plasma_AB(AB, '+');
		cMedulaOsea Med_AB(AB, '+', "HLA - A");
		cMedulaOsea Med_A(A, '+', "HLA - A");
		cMedulaOsea Med_B(B, '+', "HLA - A");

	//creamos centros
		cCentro centro_favaloro("Favaloro", "Belgano 2023", "CABA", "Capital Federal", "1126564789");
		cCentro centro_SanMartin("San Martin", "Santa Fe 1400", "CABA", "Capital Federal", "1126564789");
		cCentro centro_Corazon("Corazon", "Justicia 2443", "Posadas", "Misiones", "48767773");
		cCentro centro_Adrogue("Adrogue", "Sarmiento 788", "Adrogue", "Buenos Aires", "1135763992");
		cCentro centro_SanMiguel("San Miguel", "Juramento 2153", "San Miguel de Tucuman", "Tucuman", "67553211");
		cCentro centro_Salud("Salud", "Pacheco de Melo 6049", "CABA", "Capital Federal", "45662213");
		cCentro centro_CruzRoja("Cruz Roja", "25 de Mayo 3009", "Neuquen", "Neuquen", "100987655");
		cCentro centro_Saavedra("Saavedra", "Solis 4065", "Navarro", "Buenos Aires", "1108554992");
		cCentro centro_LaVida("La Vida", "Moreno 901", "Santa Rosa", "La Pampa", "1232723292");
		cCentro centro_Sanacion("Sanacion", "Lbertador 5633", "Parana", "Entre Rios", "111169352");
	

	//cremos donantes
		cDonante Saul("Saul", "18/09/2003", "1123654789", "961596640", 'M', 19, 60, false, false, &A_pos, tiempo_actual);
		cDonante Maria("Maria", "30/07/2003", "112614589", "45289745", 'F', 19, 51, false, true, &Med_A, tiempo_actual);
		cDonante Emilia("Emilia", "21/02/2003", "154789632", "45896214", 'F', 19, 55, false, false, &Bmen, tiempo_actual);
		cDonante Camila("Camila", "21/02/2004", "1125897413", "44236589", 'F', 18, 57, false, false, &Plasma_A, tiempo_actual);
		cDonante isabella("Isabella", "05/10/2003", "8569741233", "961596640", 'F', 19, 55, false, false, &Med_AB, tiempo_actual);
		cDonante lorenzo("lorenzo", "28/08/2003", "43366552", "96212326", 'M', 19, 60, false, false, &A_pos, tiempo_actual);
		cDonante renata("Renata", "23/ 07 / 2002", "112614589", "45289745", 'F', 19, 51, false, true, &Med_A, tiempo_actual);
		cDonante juan("Juan", "25/11/2009", "154789632", "45236874", 'M', 19, 55, false, false, &Bmen, tiempo_actual);
		cDonante gustavo("Gustavo", "29/07/2004", "11258975", "44236589", 'M', 18, 63, false, false, &Plasma_A, tiempo_actual);
		cDonante lupe("Guadalupe", "29/07/2004", "11258975", "44236589", 'M', 18, 63, false, false, &Plasma_A, tiempo_actual);

	//creamos receptores 
		cReceptor valentina("Valentina", "02/09/2010", "1123654789", "96159664", 'F', inestable, 546844, 1, &Med_A);
		cReceptor flor("Flor", "04/10/2012", "1121549865", "96369745", 'F', inestable, 546844, 1, &Plasma_AB);
		cReceptor saumuel("Samuel", "23/02/2001", "1147586936", "96458632", 'M', inestable, 546844, 1, &A_pos);
		cReceptor Daniel("Daniel", "13/11/2006", "11201256987", "44226688", 'M', estable, 546844, 1, &A_pos);
		cReceptor Romelia("Romelia", "29/12/2009", "1100325689", "37022559", 'F', estable, 546844, 1, &Bmen);
		cReceptor Juana("Juana", "22/10/1993", "1147586930", "3799229", 'F', inestable, 546844, 1, &ABpos);
		cReceptor Gabriel("Gabrel", "31/01/2008", "1145823601", "44545688", 'M', recibio, 546844, 5, &Med_A);
		cReceptor Olivia("Olivia", "11/11/2016", "474466760", "11233565889", 'F', inestable, 546844, 2, &Med_B);
		cReceptor Selena("Selena", "22/12/1966", "1826500789", "1752018623", 'F', recibio, 546844, 1, &Plasma_B);
		cReceptor Franco("Franco", "18/04/2001", "1122452279", "427886889", 'M', estable, 546844, 1, &Plasma_AB);
		cReceptor Julieta("Julieta", "01/02/1993", "1123454089", "33356711", 'F', estable, 546844, 3, &Med_A);
		cReceptor Javier("Javier", "17/08/2004", "112566869", "44886640", 'M', inestable, 546844, 2, &Med_A);
		cReceptor Tobias("Tobias", "13/12/1989", "112893789", "35688662", 'M', recibio, 546844, 5, &Med_A);
		cReceptor Josefina("Josefina", "31/12/2003", "119966344", "444778876", 'F', inestable, 546844, 3, &Med_A);
		cReceptor Julian("Julian", "09/12/2000", "112338878", "78265242", 'M', recibio, 546844, 5, &Med_A);
		cReceptor Enzo("Enzo", "30/07/2003", "1123609779", "44889651", 'M', estable, 546844, 2, &Med_A);
		cReceptor Harry("Harry", "18/09/2003", "1125588789", "44066340", 'M', estable, 546844, 3, &Med_A);
		cReceptor Sofia("Sofia", "25/06/2014", "112886789", "45366228", 'F', inestable, 546844, 1, &Med_A);

	//agregamos los donantes a la lista de centros
		centro_favaloro+(Emilia);
		centro_Adrogue+(Maria);
		centro_Salud+(Camila);
		centro_SanMartin+(isabella);
		centro_Corazon+(Saul);
		centro_CruzRoja+(lorenzo);
		centro_Saavedra+(renata);
		centro_LaVida+(juan);
		centro_Sanacion+(gustavo);
		centro_SanMiguel + lupe;
	
	//agregamos receptores a la lista de centros
		centro_favaloro+(valentina);
		centro_SanMartin+(flor);
		centro_Corazon+(saumuel);
		centro_Adrogue+(Daniel);
		centro_SanMiguel+(Romelia);
		centro_CruzRoja+(Juana);
		centro_Salud+(Gabriel);
		centro_Saavedra+(Olivia);
		centro_LaVida+(Selena);
		centro_Sanacion+(Franco);
		centro_favaloro+(Julieta);
		centro_SanMartin+(Javier);
		centro_Corazon+(Tobias);
		centro_Adrogue+(Josefina);
		centro_SanMartin+(Julian);
		centro_Salud+(Enzo);
		centro_SanMiguel+(Harry);
		centro_CruzRoja+(Sofia);

	//agregamos centros a la lista de BSA
		BSA+(centro_favaloro);
		BSA+(centro_SanMartin);
		BSA+(centro_Adrogue);
		BSA+(centro_Corazon);
		BSA+(centro_CruzRoja);
		BSA+(centro_LaVida);
		BSA+(centro_Saavedra);
		BSA+(centro_Salud);
		BSA+(centro_Sanacion);
		BSA+(centro_SanMiguel);

		vector<cReceptor> lista;
		cPaciente* persona =nullptr;
		int pos = 0;
		bool bandera = true;

		do {
			int opcion = menu();
			string DNI;
			cCentro centro;
			cDonante donante;
			cReceptor receptor;

			switch (opcion)
			{
			case 1:
				cin >> centro;
				BSA+(centro);
				break;
			case 2:
				cin >> donante;
				centro_favaloro + donante;
				break;
			case 3:
				cin >> receptor;
				centro_favaloro + receptor;
				break;
			case 4:
				cout << BSA;//usamos la sobrecarga de ostream
				break;
			case 5:
				for (int i = 0;i < BSA.get_listacentro().size(); i++)
				{
					try
					{
						BSA.get_listacentro()[i].listar_donante();
					}
					catch (exception& e) {
						cerr << e.what();
					}

				}break;

			case 6:
				for (int i = 0;i < BSA.get_listacentro().size(); i++)
				{
					try
					{
						BSA.get_listacentro()[i].listar_receptor();
					}
					catch (exception& e) {
						cerr << e.what();
					}
				}
				break;
			case 7:
				cout << "Ingrese el DNI que quiere buscar" << endl;
				cin >> DNI;

				try
				{
					BSA.buscar_receptor(DNI);
				}
				catch (exception& e) {
					cerr << e.what();
				}
				break;
			case 8:
				for (int i = 0;i<BSA.get_listacentro().size();i++)
				{
					for (int k = 0;k < BSA.get_listacentro()[i].get_lista_donante().size();k++)
					{
						lista = BSA.posibles_receptores(&BSA.get_listacentro()[i].get_lista_donante()[k]);
						persona = BSA.match(&BSA.get_listacentro()[i].get_lista_donante()[k], &lista);

						if (persona == nullptr)
						{
							cout << "el donante: " << BSA.get_listacentro()[i].get_lista_donante()[pos].get_nombre() << " no es compatible un paciente" << endl;
						}
						else if(BSA.get_listacentro()[i].realizar_transfusion(persona, BSA.get_listacentro()[i].get_lista_donante()[pos]))
						{
							cout <<"el receptor: "<<persona->get_nombre()<<" recibio su tranfucion exitosamente de parte de:"<<
								BSA.get_listacentro()[i].get_lista_donante()[k].get_nombre() << endl;
						}
						else
						{
							cout << "el receptor: " << persona->get_nombre() << " no recibio su tranfucion exitosamente, su estado es urgente" << endl;
						}
					}
				}
				break;

			case 9:
				BSA.Informar_Cant_provincia();
				break;
			default:
				break;
			}

			string s;
			cout << "¿Desea seguir en el Menu? si/no"<<endl;
			cin >> s;

			if (s == "si")
				bandera = true;
			else
				bandera = false;

		}while (bandera);

	return 0;
}

 int menu() {
	cout << "BIENVANIDO AL BANCO DE SANGRE DE ARGENTINA" << endl << endl;
	cout << "Eleija una de las siguientes opciones" << endl;
	cout << "1)Agregar Centro" << endl;
	cout << "2)Agregar Donante" << endl;
	cout << "3)Agregar Receptor" << endl;
	cout << "4)Imprimir lista de Centros" << endl;
	cout << "5)Imprimir lista de Donantes" << endl;
	cout << "6)Imprimir lista de Receptores" << endl;
	cout << "7)Buscar Receptor por DNI" << endl;
	cout << "8)Buscar match para los Donantes" << endl;
	cout << "9)Imprimir lista de donaciones por provincia por mes " << endl;

	unsigned int opcion;
	cin >> opcion;
	return opcion;
}