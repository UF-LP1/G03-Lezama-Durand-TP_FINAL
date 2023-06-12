#include "cCentro.h"

cCentro::cCentro()
{
}

cCentro::~cCentro()
{

}

void cCentro::cargarArchivo()
{
    // faltan terminar 

    fstream fp;
    fp.open("Pacientes.cpp", ios::in);

    if (!(fp.is_open()))
        return;

    string headers;
    char coma = ',';
    getline(fp, headers, '\n');

    int i = 0;
    /*while (fp)
    {
        fp >> lista[*n].DNI >> coma;
        getline(fp, lista[*n].Nombre, ',');
        getline(fp, lista[*n].Apellido, ',');
        fp >> lista[*n].sexo >> coma;
        getline(fp, lista[*n].Natalicio, ',');
        getline(fp, lista[*n].Estado, ',');
        fp >> lista[*n].id_os >> coma;
        resizePac(lista, n, 1);
    }
    */

    fp.close();
}

void cCentro::agregarPaciente(cPaciente *paciente)
{
    lista_pac+(*paciente); 
}

cVector<cPaciente> cCentro::getlista()
{
    return this->lista_pac;
}
