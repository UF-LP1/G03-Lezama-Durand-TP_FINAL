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
    vector<cPaciente*> lista_pac;
    vector<cDonante*> lista_donante;
    vector<cReceptor*> lista_receptor;
}

cCentro::~cCentro()
{
}


void cCentro::imprimir()
{
    for (int i = 0;i < this->lista_pac.size();i++)
    {
        cout<< &this->lista_pac[i] << endl;
    }
    return;
}

vector<cReceptor> cCentro::get_lista_receptor()
{
    vector<cReceptor> lista_aux;

    for (int i = 0;i < this->lista_pac.size();i++)
    {
        if (dynamic_cast<cReceptor*>(this->lista_pac[i]) != nullptr)
        {
            cReceptor* aux = dynamic_cast<cReceptor*>(this->lista_pac[i]);
            lista_aux.push_back(*aux);
        }
    }

    ordenar_lista(lista_aux);
    return lista_aux;
}

vector<cDonante> cCentro::get_lista_donante()
{
    vector<cDonante> lista_aux;

    for (int i = 0;i < this->lista_pac.size();i++)
    {
        if (dynamic_cast<cDonante*>(this->lista_pac[i]) != nullptr)
        {
            cDonante* aux = dynamic_cast<cDonante*>(this->lista_pac[i]);
            lista_aux.push_back(*aux);
        }
    }
    return lista_aux;
}


vector<cPaciente*> cCentro::get_lista()//obtengo la lista de pacinte 
{
    return this->lista_pac;
}

void cCentro::condiciones_donante()//aqui usamos la sobrecarga del menos como metodo 
{
    for (int i = 0;i < this->get_lista_donante().size();i++)
    {
        if ((this->get_lista_donante()[i]).get_edad() <= 18 && this->get_lista_donante()[i].get_edad() >= 65)
        {
            this->lista_pac - &this->get_lista_donante()[i];
        }
        else if (this->get_lista_donante()[i].get_peso() <= 50)
        {
            this->lista_pac - &this->get_lista_donante()[i];
        }
        else if (this->get_lista_donante()[i].get_tatuaje() != false) 
        {
            this->lista_pac - &this->get_lista_donante()[i];
        }
        else if (this->get_lista_donante()[i].get_enfermedad() != false) 
        {
            this->lista_pac - &this->get_lista_donante()[i];
        }
    }
    return;
}

bool cCentro::realizar_transfusion(cPaciente* Persona, cDonante donante)
{
    if (donante.get_fluido()->tiempoMax(donante.get_fextraccion()))
    {
        srand(time(NULL));
        double exito = rand() % 2; //genero un numero del 0 al 1

        if (exito == 1)
        {
            this->lista_pac-&donante;

            for (int i = 0;i < this->get_lista_receptor().size();i++)
            {
                if (this->get_lista_receptor()[i] == Persona)
                {
                    this->lista_pac-Persona;
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

void cCentro::operator+(cPaciente& persona)
{
    this->lista_pac.push_back(&persona);
}

void cCentro::operator-(cPaciente& persona)
{
    for (int i = 0;i < this->lista_pac.size();i++)
    {
        if (this->lista_pac[i] == &persona)
        {
            this->lista_pac.erase(lista_pac.begin() + i);
        }
    }
    return;
}

void cCentro::listar_receptor()
{
    for (int i = 0;i < this->get_lista_receptor().size();i++)
    {
        cout << &this->get_lista_receptor()[i]<<endl;
    }
}

void cCentro::listar_donante()
{
    cout << "en el centro: " << get_nombre()<<endl;

    for (int i = 0; i < this->get_lista_donante().size();i++)
    {
        cout << &this->get_lista_donante()[i]<<endl;
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

void ordenar_lista(vector<cReceptor>& lista)
{
    for (int i = 0;i < lista.size();i++)
    {
        for (int k = i;k < lista.size();k++)
        {
            if (myfunction(lista[i], lista[k]))
            {
                swap(lista[i], lista[k]);
            }
        }
    }
}

bool myfunction(cReceptor r1, cReceptor r2)
{
    if (r1.get_prioridad() > r2.get_prioridad())
    {
        return true;
    }
    else if (r1.get_estado() > r2.get_estado()) {
        return true;
    }
    else if (r1.get_fecha() > r2.get_fecha()) {
        return true;
    }
    return false;
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

void operator-(vector<cPaciente*> lista, cPaciente* persona)
{
    for (int i = 0;i <lista.size();i++)
    {
        if (*lista[i] == persona)
        {
            lista.erase(lista.begin() + i);
        }
    }
    return;
}