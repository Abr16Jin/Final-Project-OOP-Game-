#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include "logo.h"

using namespace std;


// FUNCIONES AUXILIARES


void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int obtenerAnchoConsola() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

int obtenerAltoConsola() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

void centrar(string texto, int fila) {
    int anchoConsola = obtenerAnchoConsola();
    int posX = (anchoConsola - texto.length()) / 2;
    gotoxy(posX, fila);
    cout << texto;
}

void ocultarCursor() {
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void dibujarMargen() {
    int ancho = obtenerAnchoConsola();
    int alto = obtenerAltoConsola();

    // Línea superior
    gotoxy(0, 0);
    for(int i = 0; i < ancho; i++) cout << (char)219;

    // Línea inferior
    gotoxy(0, alto - 1);
    for(int i = 0; i < ancho; i++) cout << (char)219;

    // Líneas laterales
    for(int i = 1; i < alto - 1; i++) {
        gotoxy(0, i);
        cout << (char)219;
        gotoxy(ancho - 1, i);
        cout << (char)219;
    }
}

void mostrarLogo(int filaInicio) {
    for(int i = 0; i < LOGO_LINEAS; i++) {
        centrar(LOGO_ASCII[i], filaInicio + i);
    }
}

// PANTALLA DE BIENVENIDA


void pantallaInicio() {
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
    if(tecla == 27) { // ESC
        system("cls");
        exit(0);
    }
}

// ============================================
// MENÚ PRINCIPAL CON HUD
// ============================================

void dibujarHUD() {
    int ancho = obtenerAnchoConsola();

    // Título superior izquierdo
    gotoxy(3, 1);
    cout << "FARMING BATTLE 1.0";

    // Título superior derecho
    gotoxy(ancho - 20, 1);
    cout << "MENU PRINCIPAL";
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

    int filasOpciones[] = {12, 14, 16, 19}; // Posiciones verticales de cada opción

    do {
        system("cls");
        system("color 0A");
        ocultarCursor();

        // Dibujar margen
        dibujarMargen();

        // Dibujar HUD (títulos superior)
        dibujarHUD();

        // Dibujar todas las opciones
        for(int i = 0; i < numOpciones; i++) {
            dibujarOpcionMenu(i + 1, opciones[i], filasOpciones[i], i == opcionSeleccionada);
        }

        // Capturar tecla
        tecla = getch();

        // Navegación
        if(tecla == 72) { // Flecha arriba
            opcionSeleccionada--;
            if(opcionSeleccionada < 0) opcionSeleccionada = numOpciones - 1;
        }
        else if(tecla == 80) { // Flecha abajo
            opcionSeleccionada++;
            if(opcionSeleccionada >= numOpciones) opcionSeleccionada = 0;
        }
        else if(tecla >= '1' && tecla <= '4') { // Selección por número
            opcionSeleccionada = tecla - '1';
            tecla = 13; // Simular Enter
        }

    } while(tecla != 13); // Enter para seleccionar

    return opcionSeleccionada;
}

// PANTALLAS TEMPORALES (PLACEHOLDERS)

void iniciarBatalla() {
    system("cls");
    system("color 0C");
    dibujarMargen();

    centrar("=== INICIAR BATALLA ===", 3);
    centrar("Sistema de batalla en desarrollo...", 12);
    centrar("Presiona cualquier tecla para volver al menu", 26);

    getch();
}

void verTrueque() {
    system("cls");
    system("color 0E");
    dibujarMargen();

    centrar("=== TRUEQUE ===", 3);
    centrar("Sistema de trueque en desarrollo...", 12);
    centrar("Presiona cualquier tecla para volver al menu", 26);

    getch();
}

void verStatus() {
    system("cls");
    system("color 0B");
    dibujarMargen();

    centrar("=== VER STATUS JUGADOR/GRANJA ===", 3);
    centrar("Sistema de estadisticas en desarrollo...", 12);
    centrar("Presiona cualquier tecla para volver al menu", 26);

    getch();
}

void salirJuego() {
    system("cls");
    system("color 0");

    centrar("Gracias por jugar FARMING BATTLE!", 15);
    centrar("Creado por Abraham y Javier", 16);
    Sleep(3000);
    exit(0);
}

int main() {
    system("mode con: cols=120 lines=30");

    // Mostrar pantalla de bienvenida
    pantallaInicio();

    // Loop del menú principal
    while(true) {
        int opcion = menuPrincipal();

        switch(opcion) {
            case 0: // Iniciar Batalla
                iniciarBatalla();
                break;
            case 1: // Trueque
                verTrueque();
                break;
            case 2: // Status
                verStatus();
                break;
            case 3: // Salir
                salirJuego();
                break;
        }
    }

    return 0;
}
