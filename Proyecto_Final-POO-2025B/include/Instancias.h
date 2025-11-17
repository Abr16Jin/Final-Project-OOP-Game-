#ifndef INSTANCIAS_H_INCLUDED
#define INSTANCIAS_H_INCLUDED

#include "Jugador.h"

    //ITEMS PROPIEDADES
    Item crearEnerg();
    Item crearpulgas();
    Item crearbombaKap();

    //ANIMALES
    Animal* crearGallina();
    Animal* crearVaca();
    Animal* crearConejo();
    Animal* crearCerdo();
    Animal* crearGallo();
    Animal* crearPerro();
    Animal* crearCaballo();
    Animal* crearZorro();
    Animal* crearAguila();
    Animal* crearDragon();

    //TERRENOS POR DEFECTO
    Terreno crearTerreno_Inicial();

    // OPONENTES DE PRUEBA

    Jugador crearOponenteParcela(); // Nivel 1: Parcela Pequeña
    Jugador crearOponenteRancho();  // Nivel 2: Rancho Mediano
    Jugador crearOponenteFinca();    // Nivel 3: Finca Mayor



#endif // INSTANCIAS_H_INCLUDED
