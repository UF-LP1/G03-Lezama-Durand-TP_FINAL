#include "cBSA.h"

int main()
{
	cBSA BSA;

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
		cDonante Saul("Saul", "18/09/2003", "1123654789", "961596640", 'M', 19, 60, false, false, &A_pos);
		cDonante Maria("Maria", "30/07/2003", "112614589", "45289745", 'F', 19, 51, false, true, &Med_A);
		cDonante Emilia("Emilia", "21/02/2003", "154789632", "45896214", 'F', 19, 55, false, false, &Bmen);
		cDonante Camila("Camila", "21/02/2004", "1125897413", "44236589", 'F', 18, 57, false, false, &Plasma_A);
		cDonante isabella("Isabella", "05/10/2003", "8569741233", "961596640", 'F', 19, 55, false, false, &Med_AB);
		cDonante lorenzo("lorenzo", "28/08/2003", "43366552", "96212326", 'M', 19, 60, false, false, &A_pos);
		cDonante renata("Renata", "23/ 07 / 2002", "112614589", "45289745", 'F', 19, 51, false, true, &Med_A);
		cDonante juan("Juan", "25/11/2009", "154789632", "45236874", 'M', 19, 55, false, false, &Bmen);
		cDonante gustavo("Gustavo", "29/07/2004", "11258975", "44236589", 'M', 18, 63, false, false, &Plasma_A);

	//creamos receptores 
		cReceptor valentina("Valentina", "02/09/2010", "1123654789", "96159664", 'F', inestable, 546844, 1, &Med_A);
		cReceptor flor("Flor", "04/10/2012", "1121549865", "96369745", 'F', inestable, 546844, 1, &Plasma_AB);
		cReceptor saumuel("Samuel", "23/02/2001", "1147586936", "96458632", 'M', inestable, 546844, 1, &Med_B);
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
		centro_favaloro.agregarPaciente(&Emilia);
		centro_Adrogue.agregarPaciente(&Maria);
		centro_Salud.agregarPaciente(&Camila);
		centro_SanMartin.agregarPaciente(&isabella);
		centro_Corazon.agregarPaciente(&Saul);
		centro_CruzRoja.agregarPaciente(&lorenzo);
		centro_Saavedra.agregarPaciente(&renata);
		centro_LaVida.agregarPaciente(&juan);
		centro_Sanacion.agregarPaciente(&gustavo);

	//agregamos centros a la lista de BSA
		BSA.agregar_centro(centro_favaloro);
		BSA.agregar_centro(centro_SanMartin);
		BSA.agregar_centro(centro_Adrogue);
		BSA.agregar_centro(centro_Corazon);
		BSA.agregar_centro(centro_CruzRoja);
		BSA.agregar_centro(centro_LaVida);
		BSA.agregar_centro(centro_Saavedra);
		BSA.agregar_centro(centro_Salud);
		BSA.agregar_centro(centro_Sanacion);
		BSA.agregar_centro(centro_SanMiguel);

	//agregamos receptores a la lista de centros
		centro_favaloro.agregarPaciente(&valentina);
		centro_SanMartin.agregarPaciente(&flor);
		centro_Corazon.agregarPaciente(&saumuel);
		centro_Adrogue.agregarPaciente(&Daniel);
		centro_SanMiguel.agregarPaciente(&Romelia);
		centro_CruzRoja.agregarPaciente(&Juana);
		centro_Salud.agregarPaciente(&Gabriel);
		centro_Saavedra.agregarPaciente(&Olivia);
		centro_LaVida.agregarPaciente(&Selena);
		centro_Sanacion.agregarPaciente(&Franco);
		centro_favaloro.agregarPaciente(&Julieta);
		centro_SanMartin.agregarPaciente(&Javier);
		centro_Corazon.agregarPaciente(&Tobias);
		centro_Adrogue.agregarPaciente(&Josefina);
		centro_SanMartin.agregarPaciente(&Julian);
		centro_Salud.agregarPaciente(&Enzo);
		centro_SanMiguel.agregarPaciente(&Harry);
		centro_CruzRoja.agregarPaciente(&Sofia);

		cPaciente* persona=nullptr;
		int pos = 0;

		for (int i = 0;BSA.get_listacentro().size();i++)
		{
			for (int k = 0;k < BSA.get_listacentro()[i].get_lista_donante().size();k++)
			{
				persona=BSA.match(BSA.get_listacentro()[i].get_lista_donante()[k]);
				pos = k;
			}

			if (persona == nullptr)
			{
				cout << "no se encontro donardor";
			}
			else
			{
				BSA.get_listacentro()[i].realizar_transfusion(persona, *BSA.get_listacentro()[i].get_lista_donante()[pos]);
			}
		}

	return 0;
}