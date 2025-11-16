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
    return (ataque*(-1));
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
