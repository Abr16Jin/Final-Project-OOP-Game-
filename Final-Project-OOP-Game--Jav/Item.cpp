#include "Item.h"

Item::Item()
{
    nombreItem = "";
    propiedades = Propiedades();
}

Item::Item(string nombre, Propiedades propiedadesItem)
{
    nombreItem = nombre;
    propiedades = propiedadesItem;
}

Item::~Item(){}

//METODOS ITEM

string Item::getNombre() const
{
    return nombreItem;
}
void Item::setNombre(string nombre)
{
    nombreItem = nombre;
}

Propiedades Item::getPropiedades() const
{
    return propiedades;
}
void Item::setPropiedades(Propiedades* propiedadesItem)
{
    propiedades = *propiedadesItem;
}
