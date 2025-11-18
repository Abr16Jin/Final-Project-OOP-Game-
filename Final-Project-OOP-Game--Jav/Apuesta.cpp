#include "Apuesta.h"

Apuesta::Apuesta()
{
    prestigioApuesta = 0;
    plataApuesta = 0;
    // terrenoApuesta se construye por defecto
    terrenoEstaApostado = false;
}

Apuesta::~Apuesta()
{
    for (Animal* animalPtr : animalesApuesta)
    {
        delete animalPtr;
    }
}

//METODOS GETSET

int Apuesta::getPrestigio() const
{
    return prestigioApuesta;
}

int Apuesta::getPlata() const
{
    return plataApuesta;
}

const vector<Animal*>& Apuesta::getAnimales() const
{
    return animalesApuesta;
}

const Terreno& Apuesta::getTerreno() const
{
    return terrenoApuesta;
}

bool Apuesta::getTerrenoApostado() const
{
    return terrenoEstaApostado;
}

vector<Animal*>& Apuesta::getAnimales()
{
    return animalesApuesta;
}

Terreno& Apuesta::getTerreno()
{
    return terrenoApuesta;
}

void Apuesta::setPrestigio(int prestigio)
{
    prestigioApuesta = prestigio;
}

void Apuesta::setPlata(int plata)
{
    plataApuesta = plata;
}

void Apuesta::addAnimal(Animal* animal)
{
    if (animal != nullptr)
    {
        animalesApuesta.push_back(animal);
    }
}

void Apuesta::setTerreno(Terreno&& terreno)
{
    terrenoApuesta = std::move(terreno);
    terrenoEstaApostado = true; // Marcamos que la apuesta SI tiene un terreno
}
