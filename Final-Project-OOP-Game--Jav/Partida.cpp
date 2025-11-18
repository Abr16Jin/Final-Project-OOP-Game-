#include "Partida.h"

Partida::Partida(Jugador* p1, Jugador* p2)
    : jugador1(p1), jugador2(p2), apuesta()
{
    cout << "¡Partida creada entre " << jugador1->getNombre()
         << " y " << jugador2->getNombre() << "!" << endl;
}

Partida::~Partida(){}

//Getters
const Jugador& Partida::getJugadorUno() const
{
    return *jugador1;
}
Jugador& Partida::getJugadorUno()
{
    return *jugador1;
}

const Jugador& Partida::getJugadorDos() const
{
    return *jugador2;
}
Jugador& Partida::getJugadorDos()
{
    return *jugador2;
}

const Apuesta& Partida::getApuesta() const
{
    return apuesta;
}
Apuesta& Partida::getApuesta()
{
    return apuesta;
}

//Setter
void Partida::setApuesta(Apuesta&& ap)
{
    apuesta = move(ap);
}
