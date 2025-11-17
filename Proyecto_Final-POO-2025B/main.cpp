#include <iostream>
#include "Jugador.h"
#include "Instancias.h"
#include "Batalla.h"

/*Bienvenido querido Javier al Archivo MAIN del proyecto final uwu*/

using namespace std;

int main()
{
    Jugador jugadorReal;
    cin >> jugadorReal;

    Jugador oponente = crearOponenteRancho();

    cout << "¡Tu oponente es " << oponente.getNombre() << "!" << endl;
    cout << "Stats del Oponente:" << endl;
    cout << "  - Prestigio: " << oponente.getPrestigio() << endl;
    cout << "  - Plata: " << oponente.getPlata() << endl;
    cout << "  - Animales: " << oponente.getGranja().getTerreno().getConteoAnimales() << endl;

    oponente.getGranja().getTerreno().agregarAnimal(crearVaca());

    cout << "\nIniciando Partida..." << endl;
    Partida miPartida(&jugadorReal, &oponente);

    Apuesta miApuesta;
    miApuesta.setPlata(250);
    miPartida.setApuesta(std::move(miApuesta));

    Batalla laBatalla(&miPartida);
    laBatalla.iniciarCombate();

    cout << "\n--- Post-Batalla ---" << endl;
    cout << "Tu Plata: " << jugadorReal.getPlata() << endl;
    cout << "Tu Prestigio: " << jugadorReal.getPrestigio() << endl;
return 0;
}
