#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
#include <string>
#include "Granja.h"

using namespace std;

class Jugador
{
    private:
        string nombre;
        int prestigio;
        int plata;
        Granja granjaJugador;

    public:
        Jugador();
        Jugador(string, int, int, Granja);
        ~Jugador();
    //metodos Jugador

        string getNombre();
        void setNombre(string);

        int getPrestigio();
        void setPrestigio(int);

        int getPlata();
        void setPlata(int);

        Granja getGranja();
        void setGranja(Granja);
};

#endif // JUGADOR_H
