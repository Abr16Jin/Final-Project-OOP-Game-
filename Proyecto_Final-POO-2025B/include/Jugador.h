#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
#include <string>
#include <limits>
#include "Granja.h"
#include "Apuesta.h"

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

        Jugador(const Jugador&) = delete;
        Jugador& operator=(const Jugador&) = delete;

        Jugador(Jugador&&) = default;
        Jugador& operator=(Jugador&&) = default;

    //metodos Jugador

        string getNombre() const;
        void setNombre(string);

        int getPrestigio() const;
        void setPrestigio(int);

        int getPlata() const;
        void setPlata(int);

        const Granja& getGranja() const;
        Granja& getGranja();
        void setGranja(Granja&&);

        //sobrecargas
        void operator+=(Apuesta& apuestaGanada); // Ganador
        void operator-=(Apuesta& apuestaPerdida); // Perdedor
        //sobrecarga inicializadora
        friend istream& operator>>(istream& in, Jugador& j);
};

#endif // JUGADOR_H
