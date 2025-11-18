#ifndef BATALLA_H
#define BATALLA_H

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

#include "Jugador.h"
#include "Partida.h"

using namespace std;


class Batalla
{
private:
    Partida* partida;
    Jugador* atacante;
    Jugador* defensor;
    bool rendirJ1;
    bool rendirJ2;

    // --- HELPER: Quien ataca primero
    void determinarTurnoInicial();
    // --- HELPER: Cambia el turno
    void cambiarTurno();
    //HELPER turno del jugador
    void ejecutarTurno();
    // --- HELPER: Verifica si la batalla termino
    bool chequearFinBatalla();

public:

    // CTOR
    Batalla(Partida* p);
    // --- METODO PRINCIPAL ---
    void iniciarCombate();
};
#endif // BATALLA_H
