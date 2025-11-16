#include "Jugador.h"
#include "Granja.h"

//#include "Granja.h"

Jugador::Jugador()
{
    nombre = "";
    prestigio = 0;
    plata = 0;
    granjaJugador = Granja();
}
Jugador::Jugador(string nombreJugador, int plataJugador, int prestigioJugador, Granja GranjaJu)
{
    nombre = nombreJugador;
    plata = plataJugador;
    prestigio = prestigioJugador;
    granjaJugador = move(GranjaJu);
}
Jugador::~Jugador(){}

//METODOS JUGADOR

string Jugador::getNombre() const
{
    return nombre;
}
void Jugador::setNombre(string nombre)
{
    this -> nombre = nombre;
}

int Jugador::getPrestigio() const
{
    return prestigio;
}
void Jugador::setPrestigio(int prestigio)
{
    this -> prestigio = prestigio;
}

int Jugador::getPlata() const
{
    return plata;
}
void Jugador::setPlata(int plata)
{
    this -> plata = plata;
}

const Granja& Jugador::getGranja() const
{
    return granjaJugador;
}
Granja& Jugador::getGranja()
{
    return granjaJugador;
}
void Jugador::setGranja(Granja&& newGranja)
{
    granjaJugador = move(newGranja);
}
