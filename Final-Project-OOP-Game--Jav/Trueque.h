#ifndef TRUEQUE_H_INCLUDED
#define TRUEQUE_H_INCLUDED

#include "consola_utils.h"
#include "Jugador.h"
#include <string>
#include <iostream>

const int PRECIO_PULGAS = 10;
const int PRECIO_ENERGIZANTE = 50;
const int PRECIO_BOMBA = 200;

const int PRECIO_EXPANDIR_RANCHO = 30000;
const int PRECIO_EXPANDIR_FINCA = 112500;

// Helper para dibujar el sub-menú de animales (VERSIÓN CORREGIDA)
void comprarAnimal_menu(Jugador* jugador) {
    system("cls");
    dibujarMargen();
    centrar("=== COMPRAR ANIMALES ===", 3);
    centrar("Plata actual: " + to_string(jugador->getPlata()), 5);

    //animales temporales para leer valor
    Animal* tempGallina = crearGallina();
    Animal* tempConejo = crearConejo();
    Animal* tempCerdo = crearCerdo();
    Animal* tempVaca = crearVaca();
    Animal* tempPerro = crearPerro();

    //Mostramos los precios leidos desde los objetos
    centrar("1. Gallina (Precio: " + to_string(tempGallina->getValor()) + ")", 10);
    centrar("2. Conejo (Precio: " + to_string(tempConejo->getValor()) + ")", 12);
    centrar("3. Cerdo (Precio: " + to_string(tempCerdo->getValor()) + ")", 14);
    centrar("4. Vaca (Precio: " + to_string(tempVaca->getValor()) + ")", 16);
    centrar("5. Perro (Precio: " + to_string(tempPerro->getValor()) + ")", 18);

    centrar("0. Salir", 20);
    centrar("Elige una opcion:", 22);

    //Borrar los animales temporales
    delete tempGallina;
    delete tempConejo;
    delete tempCerdo;
    delete tempVaca;
    delete tempPerro;


    int opcion = 0;
    gotoxy(59, 24);
    cin >> opcion;

    int precioCompra = 0;
    Animal* animalComprado = nullptr;

    switch (opcion) {
        case 1:
            animalComprado = crearGallina();
            break;
        case 2:
            animalComprado = crearConejo();
            break;
        case 3:
            animalComprado = crearCerdo();
            break;
        case 4:
            animalComprado = crearVaca();
            break;
        case 5:
            animalComprado = crearPerro();
        case 0:
            return; // Salir
        default:
            centrar("Opcion INVALIDA.", 26);
            getch();
            return;
    }

    // Obtenemos el precio REAL desde el animal recién creado
    precioCompra = animalComprado->getValor();

    //compra
    if (jugador->getPlata() >= precioCompra) {
        if (jugador->getGranja().getTerreno().agregarAnimal(animalComprado)) {

            jugador->setPlata(jugador->getPlata() - precioCompra);
            centrar("Has comprado un " + animalComprado->getNombre(), 26);
        } else {
            // Error (terreno lleno, etc.)
            centrar("No se pudo agregar el animal. Terreno lleno?", 26);
            delete animalComprado;
        }
    } else {
        centrar("Te hace falta PLATA!", 26);
        delete animalComprado; // Liberar memoria
    }

    getch();


    // Lógica de compra
    if (jugador->getPlata() >= precioCompra) {
        if (jugador->getGranja().getTerreno().agregarAnimal(animalComprado)) {

            jugador->setPlata(jugador->getPlata() - precioCompra);
            centrar("¡Has comprado un " + animalComprado->getNombre() + "!", 26);
        } else {
            // Error (terreno lleno, etc.)
            centrar("No se pudo agregar el animal. ¿Terreno lleno?", 26);
            delete animalComprado;
        }
    } else {
        centrar("No tienes suficiente Plata...", 26);
        delete animalComprado; // Liberar memoria
    }

    getch();
}

// Helper para dibujar el sub-menu items
void comprarItem_menu(Jugador* jugador)
{
    system("cls");
    dibujarMargen();
    centrar("=== COMPRAR ITEMS ===", 3);
    centrar("Plata actual: " + to_string(jugador->getPlata()), 5);

    centrar("1. Pulgas (Precio: " + to_string(PRECIO_PULGAS) + ")", 10);
    centrar("2. Energizante (Precio: " + to_string(PRECIO_ENERGIZANTE) + ")", 12);
    centrar("3. Bomba Kapossai (Precio: " + to_string(PRECIO_BOMBA) + ")", 14);
    centrar("0. Salir", 20);
    centrar("Elige una opcion:", 22);

    int opcion = 0;
    gotoxy(59, 24);
    cin >> opcion;

    int precioCompra = 0;
    Item itemComprado;

    switch (opcion) {
        case 1:
            precioCompra = PRECIO_PULGAS;
            itemComprado = crearpulgas();
            break;
        case 2:
            precioCompra = PRECIO_ENERGIZANTE;
            itemComprado = crearEnerg();
            break;
        case 3:
            precioCompra = PRECIO_BOMBA;
            itemComprado = crearbombaKap();
            break;
        case 0:
            return; // Salir
        default:
            centrar("Opcion no valida.", 26);
            getch();
            return;
    }

    // Lógica de compra
    if (jugador->getPlata() >= precioCompra) {
        jugador->getGranja().setItem(itemComprado);
        jugador->setPlata(jugador->getPlata() - precioCompra);
        centrar("¡Has comprado " + itemComprado.getNombre() + "!", 26);
    } else {
        centrar("Necesitas mas Plata...", 26);
    }

    getch();
    // (Volvemos al menú de Trueque)
}

// Helper para la lógica de expansión
void expandirTerreno_menu(Jugador* jugador)
{
    system("cls");
    dibujarMargen();
    centrar("=== EXPANDIR TERRENO ===", 3);
    centrar("Plata actual: " + to_string(jugador->getPlata()), 5);

    // 1. Obtener estado actual
    Tipo tipoActual = jugador->getGranja().getTerreno().getCapacidadP();
    int precioExp = 0;
    string nombreMejora;
    Tipo tipoNuevo;
    Nivel nivelNuevo;

    // 2. Determinar la siguiente mejora posible
    if (tipoActual == Tipo::PARCELA_P) {
        nombreMejora = "Rancho Mediano";
        precioExp = PRECIO_EXPANDIR_RANCHO;
        tipoNuevo = Tipo::RANCHO_M;
        nivelNuevo = Nivel::COMBATE;
    } else if (tipoActual == Tipo::RANCHO_M) {
        nombreMejora = "Finca Mayor";
        precioExp = PRECIO_EXPANDIR_FINCA;
        tipoNuevo = Tipo::FINCA_M;
        nivelNuevo = Nivel::ALTA_CLASE;
    } else { // tipoActual == Tipo::FINCA_MY
        centrar("Tu terreno ya esta al nivel maximo!", 12);
        getch();
        return;
    }

    // 3. Pedir confirmación
    centrar("Siguiente mejora: " + nombreMejora, 12);
    centrar("Costo: " + to_string(precioExp) + " Plata", 13);
    centrar("Deseas expandir? (1 = SI, 0 = NO):", 15);

    int opcion = 0;
    gotoxy(59, 17);
    cin >> opcion;

    if (opcion != 1) {
        centrar("Expansion cancelada.", 19);
        getch();
        return;
    }

    // 4. Procesar la compra
    if (jugador->getPlata() >= precioExp) {
        jugador->getGranja().getTerreno().mejorarTerreno(tipoNuevo, nivelNuevo);
        jugador->setPlata(jugador->getPlata() - precioExp);
        centrar("Has expandido tu terreno a " + nombreMejora, 19);
        // (Imprimir valores actuales [cite: 42])
        centrar("Tu terreno ahora admite animales de Nivel " + to_string((int)nivelNuevo+1), 20);
    } else {
        centrar("Te falta plata para expandir!", 19);
    }

    getch();
}


#endif // TRUEQUE_H_INCLUDED
