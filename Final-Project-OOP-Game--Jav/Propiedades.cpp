#include "Propiedades.h"

Propiedades::Propiedades()
{
    efectoFuerza = 0;
    efectoSalud = 0;
}
Propiedades::Propiedades(int fuerza, int salud)
{
    efectoFuerza = fuerza;
    efectoSalud = salud;
}
Propiedades::~Propiedades(){}

//METODOS PROPIEDADES

int Propiedades::getFuerza() const
{
    return efectoFuerza;
}
void Propiedades::setFuerza(int fuerza)
{
    efectoFuerza = fuerza;
}

int Propiedades::getSalud() const
{
    return efectoSalud;
}
void Propiedades::setSalud(int salud)
{
    efectoSalud = salud;
}
