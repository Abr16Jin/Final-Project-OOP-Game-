#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <vector>
#include <stdexcept>
#include "logo.h"
#include "Jugador.h"
#include "Batalla.h"
#include "Instancias.h"
#include "Trueque.h"


using namespace std;

void iniciarBatalla(Jugador* jugadorReal, vector<Jugador>& oponentes);
void verTrueque(Jugador* jugador);
void verStatus(Jugador* jugador);
void salirJuego();
int menuPrincipal();
bool seleccionarOponente(vector<Jugador>& listaOponentes, Jugador** oponenteSeleccionado);

void mostrarLogo(int filaInicio) {
    for(int i = 0; i < LOGO_LINEAS; i++) {
        centrar(LOGO_ASCII[i], filaInicio + i);
    }
}

void pantallaInicio() { //Bienvenida
    system("cls");
    system("color 0");
    ocultarCursor();

    dibujarMargen();
    centrar("VERSION 1.0", 2);
    mostrarLogo(8);
    centrar("- - - - - - - - - - -", 20);
    centrar("PRESIONA CUALQUIER TECLA PARA EMPEZAR...", 22);
    centrar("PRESIONA ESC PARA SALIR...", 24);

    char tecla = getch();
    if(tecla == 27) { //ESC
        system("cls");
        exit(0);
    }
}

void dibujarHUD() { //Menu y HUD
    int ancho = obtenerAnchoConsola();

    //Texto superior izquierdo
    gotoxy(3, 1);
    cout<<"FARMING BATTLE 1.0";

    //Texto superior derecho
    gotoxy(ancho - 20, 1);
    cout<<"MENU PRINCIPAL";
}

void dibujarOpcionMenu(int numOpcion, string texto, int fila, bool seleccionada) {
    if(seleccionada) {
        centrar(to_string(numOpcion) + ") " + texto + "  <--", fila);
    } else {
        centrar(to_string(numOpcion) + ") " + texto, fila);
    }
}

int menuPrincipal() {
    int opcionSeleccionada = 0;
    int numOpciones = 4;
    char tecla;

    string opciones[] = {
        "INICIAR BATALLA",
        "TRUEQUE",
        "VER STATUS JUGADOR/GRANJA",
        "SALIR DEL JUEGO"
    };

    int filasOpciones[] = {11, 13, 15, 17}; //Posiciones verticales de opciones

    do {
        system("cls");
        system("color 0A");
        ocultarCursor();

        dibujarMargen(); //Dibuja margen

        dibujarHUD(); //Dibuja HUD de títulos superiores

        //Todas las opciones
        for(int i = 0; i < numOpciones; i++) {
            dibujarOpcionMenu(i + 1, opciones[i], filasOpciones[i], i == opcionSeleccionada);
        }

        //Capturar tecla
        tecla = getch();

        //Navegacion con teclas
        if(tecla == 72) { //Flecha arriba
            opcionSeleccionada--;
            if(opcionSeleccionada < 0) opcionSeleccionada = numOpciones - 1;
        }
        else if(tecla == 80) { //Flecha abajo
            opcionSeleccionada++;
            if(opcionSeleccionada >= numOpciones) opcionSeleccionada = 0;
        }
        else if(tecla >= '1' && tecla <= '4') { //Seleccion por numero
            opcionSeleccionada = tecla - '1';
            tecla = 13; //Simula Enter
        }

    } while(tecla != 13); //Enter para seleccionar

    return opcionSeleccionada;
}
bool seleccionarOponente(vector<Jugador>& listaOponentes, Jugador** oponenteSeleccionado)
{
    system("cls");
    dibujarMargen();
    centrar("--- SELECCIONAR OPONENTE ---", 3);

    for (size_t i = 0; i < listaOponentes.size(); ++i) {

        const Jugador& oponente = listaOponentes[i];

        int plataApostada = 100 + (oponente.getPrestigio() / 2);

        string apuestaExtra = "";
        if (oponente.getPrestigio() > 500)
        {
            apuestaExtra = " + BIENES";
        }

        string infoOponente = to_string(i + 1) + ". " + oponente.getNombre();
        string infoApuesta = " (Apuesta: " + to_string(plataApostada) + " Plata" + apuestaExtra + ")";

        centrar(infoOponente + infoApuesta, 8 + i*2);
    }
    centrar("Elige un oponente (0 para cancelar):", 20);

    int eleccion = 0;
    gotoxy(59, 22); // Centrar cursor para 'cin'
    cin >> eleccion;

    if (eleccion <= 0 || (size_t)eleccion > listaOponentes.size()) {
        *oponenteSeleccionado = nullptr;
        return false;
    }
    // ¡Usamos el puntero a puntero!
    *oponenteSeleccionado = &listaOponentes[eleccion - 1];
    return true;
}
void iniciarBatalla(Jugador* jugadorReal, vector<Jugador>& oponentes) {
    system("cls");
    system("color 0C");
    dibujarMargen();

    Jugador* oponenteElegido = nullptr; // Puntero a clase

    //Llamar al helper de selección
    if (seleccionarOponente(oponentes, &oponenteElegido))
    {
        //Crear la Partida
        centrar("¡Batalla iniciada contra " + oponenteElegido->getNombre() + "!", 24);
        Sleep(1500);

        Partida miPartida(jugadorReal, oponenteElegido);

        //Configurar Apuesta (basada en prestigio)
        centrar("Configurando apuesta...", 25);
        Sleep(1000);

        Apuesta miApuesta;
        int prestigioOp = oponenteElegido->getPrestigio();
        int plataApostada = 100 + (prestigioOp / 2);

        miApuesta.setPlata(plataApostada);
        centrar("Apuesta base: " + to_string(plataApostada) + " Plata", 26);
        Sleep(1000);


        if (prestigioOp > 500) // Si es el Baron...
        {
            centrar("¡El Baron sube la apuesta!", 27);
            Sleep(1000);

            Animal* animalApostado = oponenteElegido->getGranja().getTerreno().removerAnimal("Zorro");

            if (animalApostado != nullptr)
            {
                centrar("LE DA un " + animalApostado->getNombre() + " a la apuesta", 28);

                miApuesta.addAnimal(animalApostado);
                Sleep(1500);
            }
        }
        miPartida.setApuesta(std::move(miApuesta));

        // Crear y lanzar la Batalla
        try {
            Batalla laBatalla(&miPartida);

            // Limpiamos la pantalla para el motor de batalla
            system("cls");
            laBatalla.iniciarCombate();

            centrar("Batalla terminada. Presiona una tecla para ver resultados...", 24);
            getch();

            // Mostramos resultados (verStatus)
            verStatus(jugadorReal);

        } catch (const exception& e) {
            centrar("Error fatal en batalla: " + string(e.what()), 26);
            getch();
        }
    }
    else {
        centrar("Batalla cancelada.", 24);
        Sleep(1000);
    }
}

void verTrueque(Jugador* jugador) {
    int opcion = 0;
    while (opcion != 4) { // 4 será nuestra opción de "Break"
        system("cls");
        system("color 0E");
        dibujarMargen();

        centrar("=== TRUEQUE ===", 3);
        centrar("Plata actual: " + to_string(jugador->getPlata()), 5);

        centrar("1. Comprar Animales", 10);
        centrar("2. Expandir Terreno", 12);
        centrar("3. Comprar Items", 14);
        centrar("4. Volver al Menu Principal", 16);
        centrar("Elige una opcion:", 18);

        gotoxy(59, 20);
        cin >> opcion;

        switch (opcion) {
            case 1:
                comprarAnimal_menu(jugador);
                break;
            case 2:
                expandirTerreno_menu(jugador);
                break;
            case 3:
                comprarItem_menu(jugador);
                break;
            case 4:
                // Salir del bucle while
                break;
            default:
                centrar("Opcion no valida.", 22);
                getch();
                break;
        }
    }
}

void verStatus(Jugador* jugador) { // Acepta el puntero
    system("cls");
    system("color 0A");
    dibujarMargen();

    centrar("=== VER STATUS JUGADOR/GRANJA ===", 3);

    centrar("Jugador: " + jugador->getNombre(), 10);
    centrar("Plata: " + to_string(jugador->getPlata()), 12);
    centrar("Prestigio: " + to_string(jugador->getPrestigio()), 13);
    centrar("Terreno de Capacidad: " + to_string(((int)jugador->getGranja().getTerreno().getCapacidadP()+1)), 14);
    centrar("Granja: " + jugador->getGranja().getNombre(), 15);
    centrar("Animales totales: " + to_string(jugador->getGranja().getTerreno().getConteoAnimales()), 17);
    centrar("--------------------------------------", 18);
    jugador->getGranja().getTerreno().mostrarAnimalesDisponibles();
    centrar("Presiona cualquier tecla para volver al menu", 26);

    getch();
}

void salirJuego() {
    system("cls");
    system("color 0");
    dibujarMargen();

    mostrarLogo(2);
    centrar("- - - - - - - - - - -", 14);

    centrar("Desarolladores:", 16);
    centrar("Abraham Rodriguez Cruz", 18);
    centrar("Javier Pulido Meza", 20);
    centrar("Modos de juego: Abraham Rodriguez Cruz", 22);
    centrar("HUD y pantalla: Javier Pulido Meza", 24);
    Sleep(3000);
    exit(0);
}

int main() {
    system("mode con: cols=120 lines=30");

    pantallaInicio(); //pantalla de bienvenida

    vector<Jugador> oponentes;
    oponentes.push_back(crearOponenteParcela());
    oponentes.push_back(crearOponenteRancho());
    oponentes.push_back(crearOponenteFinca());

    Jugador jugadorReal;
    system("cls");
    dibujarMargen();
    centrar("--- CREACION DE PERSONAJE ---", 10);
    centrar("Bienvenido! Por favor, crea tu personaje:", 12);
    gotoxy(40, 14); // Mover cursor para 'cin'
    cin >> jugadorReal;
    jugadorReal.setPlata(145500);
    centrar("Personaje creado! Presiona una tecla...", 16);
    getch();

    while(true) { //Loop del menu
        int opcion = menuPrincipal();

        switch(opcion) {
            case 0: //Iniciar Batalla
                iniciarBatalla(&jugadorReal, oponentes);
                break;
            case 1: //Trueque
                verTrueque(&jugadorReal);
                break;
            case 2: //Status
                verStatus(&jugadorReal);
                break;
            case 3: //Salir
                salirJuego();
                break;
        }
    }
    return 0;
}
