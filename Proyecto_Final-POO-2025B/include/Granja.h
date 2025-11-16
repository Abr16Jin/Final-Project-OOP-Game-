#ifndef GRANJA_H
#define GRANJA_H

#include <iostream>
#include <string>
#include <vector>

#include "Item.h"
#include "Terreno.h"


using namespace std;

class Granja
{
    private:
        string nombreGranja;
        int valorGranja;
        Terreno terrenoJugador;
        vector<Item> listaItems;
    public:
        Granja();
        Granja(string, int, Item, Terreno); //incluir TERRENO
        ~Granja();

    //METODOS GRANJA

        string getNombre();
        void setNombre(string);

        int getValor();

        vector<Item> getItemList();  //devuelve elemento del vector de items
        void setItem(Item);  //anade item al final

        Terreno getTerreno();
        void setTerreno(Terreno);
};

#endif // GRANJA_H
