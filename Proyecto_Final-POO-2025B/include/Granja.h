#ifndef GRANJA_H
#define GRANJA_H

#include <iostream>
#include <string>
#include <vector>
#include <utility>

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

        // --- INICIO DE LA CORRECCIÓN ---
        // Deshabilitar la copia (que causa el crash)
        Granja(const Granja&) = delete;
        Granja& operator=(const Granja&) = delete;

        // Habilitar explícitamente el movimiento (que es seguro)
        Granja(Granja&&) = default;
        Granja& operator=(Granja&&) = default;
        // --- FIN DE LA CORRECCIÓN ---

    //METODOS GRANJA

        string getNombre() const;
        void setNombre(string);

        int getValor() const;

        //items
        vector<Item> getItemList();
        void setItem(Item);
        void mostrarItems() const;
        Item removerItem(string nombre);

        const Terreno& getTerreno() const;
        Terreno& getTerreno();
        void setTerreno(Terreno&&);
};

#endif // GRANJA_H
