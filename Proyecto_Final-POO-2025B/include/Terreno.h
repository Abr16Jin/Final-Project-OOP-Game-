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
        int valorTerreno;

        //distribución de animales
        vector<Nivel> nivelPermitidoA;
        map<string, vector<Animal*>> listasAnimales;

    public:
        Terreno();
        Terreno(int, int, Tipo, int, vector<Nivel>);
        ~Terreno();

        // --- INICIO DE LA CORRECCIÓN ---
        // Deshabilitar la copia (que causa el crash)
        Terreno(const Terreno&) = delete;
        Terreno& operator=(const Terreno&) = delete;

        // Habilitar explícitamente el movimiento (que es seguro)
        Terreno(Terreno&&) = default;
        Terreno& operator=(Terreno&&) = default;
        // --- FIN DE LA CORRECCIÓN ---

    //METODOS TERRENO

        int getCespecies() const;
        void setCespecies(int);
        int getCstack() const;
        void setStack(int);

        int getValorTerreno() const;
        void setValorTerreno(int);

        Tipo getCapacidadP() const;
        void setCapacidadP(Tipo);

        //metodos MAP

        bool helperNivel(Nivel);
        bool agregarAnimal(Animal*);


};

#endif // TERRENO_H
