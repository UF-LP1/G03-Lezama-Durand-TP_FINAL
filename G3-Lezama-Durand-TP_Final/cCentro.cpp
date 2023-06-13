#include "cCentro.h"

bool cCentro::myfunction(cReceptor* r1, cReceptor* r2)
{
    if (r1->get_prioridad() > r2->get_prioridad())
    {
        return true;
    }
    else if (r1->get_estado() > r2->get_estado()){
        return true;
    }
    else if (r1->get_fecha() > r2->get_fecha()) {
        return true;
    }
    return false;
}

cCentro::cCentro(string nombre, string direccion, string partido, string provincia, string telefono)
{
    this->nombre = nombre;
    this->direccion = direccion;
    this->partido = partido;
    this->provincia = provincia;
    this->telefono = telefono;
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

    char estado;
    string nombre, fecha_nac, telefono, DNI;
    char sexo;

    int i = 0;
    while (fp)
    {
        fp >> estado >> coma >> nombre >> coma >> fecha_nac >> coma >> telefono >> coma >> DNI >> coma>>sexo>>coma;

        if (estado == 'D')
        {
            unsigned int edad=0, peso=0;
            bool enfermedad=true, tatuaje=true;

            cDonante persona(nombre, fecha_nac, telefono, DNI, sexo, edad, peso, enfermedad, tatuaje);
            agregarPaciente(&persona);
        }
        else if (estado == 'R') 
        {
            time_t f_listaEsp=0;
            unsigned int prioridad=0;
            string estado_="";
            cReceptor persona(nombre, fecha_nac, telefono, DNI, sexo, estado_, f_listaEsp,prioridad);
            agregarPaciente(&persona);
        }
        fp.close();
    }

}

void cCentro::agregarPaciente(cPaciente* paciente)
{
    lista_pac+(paciente); 
}

cVector<cReceptor*> cCentro::get_lista_receptor()
{
    return this->lista_receptor;
}

cVector<cDonante*> cCentro::get_lista_donante()
{
    return this->lista_donante;
}

cVector<cPaciente*> cCentro::get_lista()
{
    return this->lista_pac;
}

void cCentro::condiciones_donante()
{
    for (int i = 0;i < lista_donante.size();i++)
    {
        if ((lista_donante[i])->get_edad() <= 18 && lista_donante[i]->get_edad() >= 65)
        {
            eliminar_donante(lista_donante[i]);
        }
        else if (lista_donante[i]->get_peso() <= 50)
        {
            eliminar_donante(lista_donante[i]);
        }
        else if (lista_donante[i]->get_tatuaje() != false) {
            eliminar_donante(lista_donante[i]);
        }
        else if (lista_donante[i]->get_enfermedad() != false) {
            eliminar_donante(lista_donante[i]);
        }
    }
}

void cCentro::clasificar_paciente()
{
    for (int i = 0;i < this->lista_pac.size();i++)
    {
        if (dynamic_cast<cReceptor*>(this->lista_pac[i]) != nullptr)
        {
            cReceptor* aux = dynamic_cast<cReceptor*>(this->lista_pac[i]);
            //Lista_receptores.push_back(aux_r);
            if (aux != nullptr) {
                this->lista_receptor + (aux);
            }
        }
        else if (dynamic_cast<cDonante*>(this->lista_pac[i]) != nullptr)
        {
            cDonante* aux = dynamic_cast<cDonante*>(this->lista_pac[i]);
            if (aux != nullptr)
            {
                this->lista_donante + (aux);
            }
            return;
        }
    }

    this->ordenar_prioridad();
}

void cCentro::eliminar_donante(cDonante *paciente)
{
    this->lista_donante - (paciente);
}

void cCentro::ordenar_prioridad()
{
    sort(this->lista_receptor.begin(), this->lista_receptor.end(), myfunction);
}
