#include "cCentro.h"

cCentro::cCentro()
{
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

void cCentro::agregarPaciente(cPaciente* paciente)
{
    lista_pac+(paciente); 
}

cVector<cReceptor*> cCentro::get_lista_receptor()
{
    this->ordenar_prioridad();
    return this->lista_receptor;
}

cVector<cDonante*> cCentro::get_lista_donante()
{
    return this->lista_donante;
}

void cCentro::eliminar_donante(cDonante* donante)
{
    for (int i = 0;i < this->lista_donante.size();i++)
    {
        if (this->lista_donante[i] == donante)
        {
           this->lista_donante.erase(lista_donante.begin() + i);
        }
    }
    return;
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

void cCentro::ordenar_prioridad()
{
    sort(this->lista_receptor.begin(), this->lista_receptor.end(), myfunction);
}


bool cCentro::realizar_transfusion(cPaciente* Persona, cDonante donante)
{
    if (donante.get_fluido()->tiempoMax(donante.get_fextraccion()))
    {
        srand(time(NULL));
        double exito = rand() % 2; //genero un numero del 0 al 1

        if (exito == 1)
        {
            //this->lista_pac-Persona;

            for (int i = 0;i < this->lista_receptor.size();i++)
            {
                if (this->lista_receptor[i] == Persona)
                {
                    this->lista_receptor;
                }
            }
            return true;
        }
        else
        {
            dynamic_cast<cReceptor*>(Persona)->set_estado(inestable);
            dynamic_cast<cReceptor*>(Persona)->set_prioridad(1);
            return false;
        }
    }
    else
        return false;

}

string cCentro::get_nombre()
{
    return this->nombre;
}

string cCentro::get_provincia()
{
    return  this->provincia;
}

string cCentro::to_string(){

    stringstream ss;
    char comma = ',';
    ss<<"Nombre: "<< this->nombre << comma << "Direccion: " << this->direccion << comma 
        << "Partido: " << this->partido << comma << "Provincia: " << this->provincia << comma 
        << "Telefono: " << this->telefono << endl;
    return ss.str();
}

void cCentro::listar_receptor()
{
    for (int i = 0;i < this->lista_receptor.size();i++)
    {
        cout << this->lista_receptor[i];
    }
}

void cCentro::listar_donante()
{
    
    for (int i = 0;i < this->lista_donante.size();i++)
    {
        cout << this->lista_donante[i];
    }
}

void cCentro::set_nombre(string s)
{
    this->nombre = s;
    return;
}

void cCentro::set_direccion(string s)
{
    this->direccion = s;
    return;
}

void cCentro::set_partido(string s)
{
    this->partido = s;
    return;
}

void cCentro::set_provincia(string s)
{
    this->provincia = s;
    return;
}

void cCentro::set_telefono(string s)
{
    this->telefono = s;
    return;
}

ostream& operator<<(ostream& out, cCentro& element)
{
    out << element.to_string();
    return out;
}

istream& operator>>(istream& in, cCentro& element)
{
    string s=" ";
    cout << "ingrese el nombre del centro" << endl;
    in >> s;
    element.set_nombre(s);

    cout << "ingrese la direccion del centro" << endl;
    in >> s;
    element.set_direccion(s);

    cout << "ingrese el partido del centro" << endl;
    in >> s;
    element.set_partido(s);

    cout << "ingrese el provincia del centro" << endl;
    in >> s;
    element.set_provincia(s);

    cout << "ingrese el telefono del centro" << endl;
    in >> s;
    element.set_telefono(s);

    return in;
}

bool operator==(cCentro c1, cCentro c2)
{
    if (c1.provincia == c2.provincia && c1.partido == c2.partido)
        return true;
    else
        return false;
}

bool myfunction(cReceptor* r1, cReceptor* r2)
{
    if (r1->get_prioridad() > r2->get_prioridad())
    {
        return true;
    }
    else if (r1->get_estado() > r2->get_estado()) {
        return true;
    }
    else if (r1->get_fecha() > r2->get_fecha()) {
        return true;
    }
    return false;
}
