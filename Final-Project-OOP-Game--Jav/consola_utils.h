#ifndef CONSOLA_UTILS_H
#define CONSOLA_UTILS_H
#include <windows.h>
#include <string>
#include <iostream>

using namespace std;

          //BASICOS

// Posiciona cursor en coordenadas (x, y)
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//Obtiene alto de la consola
int obtenerAltoConsola() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

// Obtiene ancho de la consola
int obtenerAnchoConsola() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

//Centra el texto horizontal en una fila
void centrarTexto(string texto, int fila) {
    int anchoConsola = obtenerAnchoConsola();
    int posX = (anchoConsola - texto.length()) / 2;
    gotoxy(posX, fila);
    cout<<texto;
}

//Ocultar cursor
void ocultarCursor() {
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

//Mostrar cursor
void mostrarCursor() {
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    cursorInfo.bVisible = true;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

//Funcion del margen

void dibujarMargen() { //Se dibuja margen
    int ancho = obtenerAnchoConsola();
    int alto = obtenerAltoConsola();

    //superior
    gotoxy(0, 0);
    for(int i = 0; i < ancho; i++) {
        cout<<(char)219; // Bloque solido
    }

    //inferior
    gotoxy(0, alto - 1);
    for(int i = 0; i < ancho; i++) {
        cout<<(char)219;
    }

    //laterales
    for(int i = 1; i < alto - 1; i++) {
        gotoxy(0, i);
        cout<<(char)219;
        gotoxy(ancho - 1, i);
        cout<<(char)219;
    }
}

//inserted from main

void centrar(string texto, int fila) {
    int anchoConsola = obtenerAnchoConsola();
    int posX = (anchoConsola - texto.length()) / 2;
    gotoxy(posX, fila);
    cout<<texto;
}
#endif
