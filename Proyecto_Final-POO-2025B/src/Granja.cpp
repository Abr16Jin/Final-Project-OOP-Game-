#include "Granja.h"

Granja::Granja()
{
    nombreGranja = "";
    valorGranja = 0;
    terrenoJugador = Terreno();
}
Granja::Granja(string nombreGranja, int valorPlata, Item newItem, Terreno terrenoJug)
{
    this -> nombreGranja = nombreGranja;
    valorGranja = valorPlata;
    listaItems.push_back(newItem);
    terrenoJugador = terrenoJug;
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
    //sumas de valores en plata de terreno y animales
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
Terreno Granja::getTerreno()
{
    return terrenoJugador;
}
void Granja::setTerreno(Terreno terreno)
{
    terrenoJugador = terreno;
}
