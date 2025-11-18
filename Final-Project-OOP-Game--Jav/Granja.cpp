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
    terrenoJugador = move(terrenoJug);
}
Granja::~Granja(){}

//METODOS GRANJA

string Granja::getNombre() const
{
    return nombreGranja;
}
void Granja::setNombre(string newNombre)
{
    nombreGranja = newNombre;
}

int Granja::getValor() const
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
const Terreno& Granja::getTerreno() const
{
    return terrenoJugador;
}
Terreno& Granja::getTerreno() //modificable sobrecargado
{
    return terrenoJugador;
}
void Granja::setTerreno(Terreno&& terreno)
{
    terrenoJugador = move(terreno);
}

// MOSTRAR items sin modificarlos
void Granja::mostrarItems() const
{
    cout << "  Inventario de Items:" << endl;
    if (listaItems.empty())
    {
        cout << "  - (No hay items)" << endl;
        return;
    }
    for (const Item& item : listaItems)
    {
        cout << "  - Item: " << item.getNombre() << endl;
    }
}
Item Granja::removerItem(string nombre)
{
    for (auto it = listaItems.begin(); it != listaItems.end(); ++it)
    {
        if (it->getNombre() == nombre)
        {
            cout << "Usando item: " << nombre << endl;

            Item itemRemovido = *it;
            listaItems.erase(it);
            return itemRemovido;
        }
    }
    cout << "Error: No tienes un item llamado '" << nombre << "'." << endl;
    return Item();
}
