#include "Granja.h"

Granja::Granja()
{
    valorGranja = 0;
}
Granja::Granja(string nombreGranja, int valorPlata, Item newItem)
{
    this -> nombreGranja = nombreGranja;
    valorGranja = valorPlata;
    listaItems.push_back(newItem);
}
Granja::~Granja(){}

//METODOS GRANJA

string Granja::getNombre()
{
    return nombreGranja;
}
void Granja::setNombre(string newNombre)
{
    nombreGranja = newNombre;
}

int Granja::getValor()
{
    //sumas de valores de terreno y animales
    return valorGranja;
}
vector<Item> Granja::getItemList()
{
    return listaItems;
}
void Granja::setItem(Item newItem)
{
    listaItems.push_back(newItem);
}
