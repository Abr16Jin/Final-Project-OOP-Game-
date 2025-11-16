#ifndef PARTIDA_H
#define PARTIDA_H

#include <iostream>
#include <utility>
#include "Jugador.h"
#include "Apuesta.h"

using namespace std;

class Partida
{
    private:
        Jugador* jugador1;
        Jugador* jugador2;
        Apuesta apuesta;

    public:
        Partida(Jugador* p1, Jugador* p2);
        ~Partida();

    // Getters
    const Jugador& getJugadorUno() const;
    Jugador& getJugadorUno();

    const Jugador& getJugadorDos() const;
    Jugador& getJugadorDos();

    const Apuesta& getApuesta() const;
    Apuesta& getApuesta();

    // Setter
    void setApuesta(Apuesta&& ap);

    //sistema de Batalla
    void simularBatalla();
};

#endif // PARTIDA_H
