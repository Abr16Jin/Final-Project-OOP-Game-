#ifndef TERRENO_H
#define TERRENO_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "Animal.h"

using namespace std;

enum class Tipo
{
    PARCELA_P,
    RANCHO_M,
    FINCA_M
};

class Terreno
{
    private:
        int capacidadEspecie;
        int capacidadStack;
        Tipo capacidadTipo;

        //distribución de animales
        vector<Nivel> nivelPermitidoA;
        map<string, vector<Animal*>> listasAnimales;

    public:
        Terreno();
        ~Terreno();

    //METODOS TERRENO

        int getCespecies();
        void setCespecies(int);
        int getCstack();
        void setStack(int);

        Tipo getCapacidadP();
        void setCapacidadP(Tipo);

        //metodos MAP

        bool helperNivel(Nivel);
        bool agregarAnimal(Animal*);


};

#endif // TERRENO_H
