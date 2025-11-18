#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>
#include "Item.h"

using namespace std;

enum class Nivel
{
    DOMESTICO,
    COMBATE,
    ALTA_CLASE
};

class Animal
{
    protected:
        string nombreAnimal;
        Nivel nivelAnimal;
        int ataque;
        int vida;
        int valorPlata;

    public:
        Animal();
        Animal(string, int, int, int);
        ~Animal();
    //METODOS ANIMAL
        int atacar();
        int getAtaque();
        string getNombre();
        int getVida();
        void setVida(int);
        int getValor();
        Nivel getNivel();

        void operator+(const Item& item);
        void operator-(const Item& item);
};

//ANIMALES QUE HARÁN HERENCIA DE ANIMAL

class Domestico : public Animal
{
    public:
    Domestico(string, int, int, int);
};

class Combate : public Animal
{
    public:
        Combate(string, int, int, int);
};

class Alta_Clase : public Animal
{
    public:
        Alta_Clase(string, int, int, int);
};
#endif // ANIMAL_H
