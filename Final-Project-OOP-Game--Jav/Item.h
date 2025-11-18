#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include "Propiedades.h"

using namespace std;

class Item
{
    private:
        string nombreItem;
        Propiedades propiedades;

    public:
        Item();
        Item(string, Propiedades);
        ~Item();
        //METODOS ITEM

        string getNombre() const;
        void setNombre(string);

        Propiedades getPropiedades() const;
        void setPropiedades(Propiedades*);

};

#endif // ITEM_H
