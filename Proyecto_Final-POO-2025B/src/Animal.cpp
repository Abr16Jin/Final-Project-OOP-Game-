#include "Animal.h"

Animal::Animal()
{
    nombreAnimal = "";
    nivelAnimal = Nivel::DOMESTICO;
    ataque = 0;
    vida = 0;
    valorPlata = 0;
}
Animal::Animal(string nombre, int ataqueA, int vidaA, int valor)
{
    nombreAnimal = nombre;
    ataque = ataqueA;
    vida = vidaA;
    valorPlata = valor;
}
Animal::~Animal()
{
    //dtor
}

int Animal::atacar()
{
    cout<<nombreAnimal<<" lanza ataque:"<<" -"<<ataque<<endl;
    return ataque;
}
int Animal::getAtaque()
{
    return ataque;
}

string Animal::getNombre()
{
    return nombreAnimal;
}
int Animal::getVida()
{
    return vida;
}
void Animal::setVida(int newVida)
{
    vida = newVida;
}
int Animal::getValor()
{
    return valorPlata;
}
Nivel Animal::getNivel()
{
    return nivelAnimal;
}

//DOMESTICO
Domestico::Domestico(string nombre, int ataqueA, int vidaA, int valor)
: Animal(nombre, ataqueA, vidaA, valor)
{
    nivelAnimal = Nivel::DOMESTICO;
}
//COMBATE
Combate::Combate(string nombre, int ataqueA, int vidaA, int valor)
: Animal(nombre, ataqueA, vidaA, valor)
{
    nivelAnimal = Nivel::COMBATE;
}
//ALTA_CLASE
Alta_Clase::Alta_Clase(string nombre, int ataqueA, int vidaA, int valor)
: Animal(nombre, ataqueA, vidaA, valor)
{
    nivelAnimal = Nivel::ALTA_CLASE;
}


// Sobrecarga de +
void Animal::operator+(const Item& item)
{
    Propiedades props = item.getPropiedades();
    int salud = props.getSalud();
    int fuerza = props.getFuerza();

    this->vida += salud;
    this->ataque += fuerza;

    cout << "'" << this->getNombre() << "' usa '" << item.getNombre() << "'!" << endl;
    if(salud > 0) cout << "  -> Salud +" << salud << endl;
    if(fuerza > 0) cout << "  -> Ataque +" << fuerza << endl;
}

// Sobrecarga de -
void Animal::operator-(const Item& item)
{
    Propiedades props = item.getPropiedades();
    int salud = props.getSalud();
    int fuerza = props.getFuerza();

    this->vida += salud;
    this->ataque += fuerza;

    cout << "'" << this->getNombre() << "' es afectado por '" << item.getNombre() << "'!" << endl;
    if(salud < 0) cout << "  -> Salud " << salud << endl;
    if(fuerza < 0) cout << "  -> Ataque " << fuerza << endl;
}
// FIN DE SOBRECARGA
