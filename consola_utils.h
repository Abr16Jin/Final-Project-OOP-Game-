#ifndef CONSOLA_UTILS_H
#define CONSOLA_UTILS_H

#include <windows.h>
#include <string>
#include <iostream>

using namespace std;

// Funcion para posicionar el cursor en coordenadas
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Funcion para obtener el ancho de la consola
int obtenerAnchoConsola() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

// Funcion para obtener el alto de la consola
int obtenerAltoConsola() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

// Funcion para centrar texto horizontalmente
void centrarTexto(string texto, int fila) {
    int anchoConsola = obtenerAnchoConsola();
    int posX = (anchoConsola - texto.length()) / 2;
    gotoxy(posX, fila);
    cout << texto;
}

// Funcion para dibujar un margen completo en la consola
void dibujarMargen(char caracter = (char)219) {
    int ancho = obtenerAnchoConsola();
    int alto = obtenerAltoConsola();

    // Linea superior
    gotoxy(0, 0);
    for(int i = 0; i < ancho; i++) cout << caracter;

    // Linea inferior
    gotoxy(0, alto - 1);
    for(int i = 0; i < ancho; i++) cout << caracter;

    // Lineas laterales
    for(int i = 1; i < alto - 1; i++) {
        gotoxy(0, i);
        cout << caracter;
        gotoxy(ancho - 1, i);
        cout << caracter;
    }
}

// Funcion para dibujar un margen con caracteres personalizados
void dibujarMargenPersonalizado(char esquinaSI, char esquinaSD, char esquinaII, char esquinaID,
                                 char horizontal, char vertical) {
    int ancho = obtenerAnchoConsola();
    int alto = obtenerAltoConsola();

    // Esquina superior izquierda
    gotoxy(0, 0);
    cout << esquinaSI;

    // Línea superior
    for(int i = 1; i < ancho - 1; i++) cout << horizontal;

    // Esquina superior derecha
    cout << esquinaSD;

    // Líneas laterales
    for(int i = 1; i < alto - 1; i++) {
        gotoxy(0, i);
        cout << vertical;
        gotoxy(ancho - 1, i);
        cout << vertical;
    }

    // Esquina inferior izquierda
    gotoxy(0, alto - 1);
    cout << esquinaII;

    // Línea inferior
    for(int i = 1; i < ancho - 1; i++) cout << horizontal;

    // Esquina inferior derecha
    cout << esquinaID;
}

// Función para dibujar margen doble (estilo box drawing)
void dibujarMargenDoble() {
    dibujarMargenPersonalizado(201, 187, 200, 188, 205, 186);
}

// Función para dibujar margen simple (estilo box drawing)
void dibujarMargenSimple() {
    dibujarMargenPersonalizado(218, 191, 192, 217, 196, 179);
}

// Función para ocultar el cursor de la consola
void ocultarCursor() {
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

// Función para mostrar el cursor de la consola
void mostrarCursor() {
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    cursorInfo.bVisible = true;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

// Función para configurar el color de la consola
void configurarColor(int fondo, int texto) {
    string comando = "color " + to_string(fondo) + to_string(texto);
    system(comando.c_str());
}

// Función para limpiar la pantalla
void limpiarPantalla() {
    system("cls");
}

// Función para configurar el tamaño de la consola
void configurarTamanoConsola(int columnas, int lineas) {
    string comando = "mode con: cols=" + to_string(columnas) + " lines=" + to_string(lineas);
    system(comando.c_str());
}

// Funcion para dibujar una línea horizontal
void dibujarLineaHorizontal(int fila, char caracter = (char)196) {
    int ancho = obtenerAnchoConsola();
    gotoxy(1, fila);
    for(int i = 1; i < ancho - 1; i++) {
        cout << caracter;
    }
}

// Funcion para dibujar una caja/recuadro en posicion especifica
void dibujarCaja(int x, int y, int ancho, int alto, char caracter = (char)219) {
    // Linea superior
    gotoxy(x, y);
    for(int i = 0; i < ancho; i++) cout << caracter;

    // Linea inferior
    gotoxy(x, y + alto - 1);
    for(int i = 0; i < ancho; i++) cout << caracter;

    // Lineas laterales
    for(int i = 1; i < alto - 1; i++) {
        gotoxy(x, y + i);
        cout << caracter;
        gotoxy(x + ancho - 1, y + i);
        cout << caracter;
    }
}

#endif // CONSOLA_UTILS_H
