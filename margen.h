#ifndef MARGEN_H
#define MARGEN_H

#include <windows.h>
#include <iostream>

using namespace std;

// ============================================
// FUNCIONES AUXILIARES PRIVADAS
// ============================================

// Función para posicionar el cursor en coordenadas específicas
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Función para obtener el ancho de la consola
int obtenerAnchoConsola() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

// Función para obtener el alto de la consola
int obtenerAltoConsola() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

// ============================================
// FUNCIONES PRINCIPALES DE MARGEN
// ============================================

/**
 * Dibuja un margen completo alrededor de la consola
 * @param caracter: Carácter a usar para dibujar (por defecto: bloque sólido █)
 */
void dibujarMargen(char caracter = (char)219) {
    int ancho = obtenerAnchoConsola();
    int alto = obtenerAltoConsola();

    // Línea superior
    gotoxy(0, 0);
    for(int i = 0; i < ancho; i++) {
        cout << caracter;
    }

    // Línea inferior
    gotoxy(0, alto - 1);
    for(int i = 0; i < ancho; i++) {
        cout << caracter;
    }

    // Líneas laterales
    for(int i = 1; i < alto - 1; i++) {
        gotoxy(0, i);
        cout << caracter;
        gotoxy(ancho - 1, i);
        cout << caracter;
    }
}

/**
 * Dibuja un margen con caracteres personalizados para esquinas y bordes
 * @param esquinaSI: Esquina Superior Izquierda
 * @param esquinaSD: Esquina Superior Derecha
 * @param esquinaII: Esquina Inferior Izquierda
 * @param esquinaID: Esquina Inferior Derecha
 * @param horizontal: Carácter para líneas horizontales
 * @param vertical: Carácter para líneas verticales
 */
void dibujarMargenPersonalizado(char esquinaSI, char esquinaSD,
                                char esquinaII, char esquinaID,
                                char horizontal, char vertical) {
    int ancho = obtenerAnchoConsola();
    int alto = obtenerAltoConsola();

    // Esquina superior izquierda
    gotoxy(0, 0);
    cout << esquinaSI;

    // Línea superior
    for(int i = 1; i < ancho - 1; i++) {
        cout << horizontal;
    }

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
    for(int i = 1; i < ancho - 1; i++) {
        cout << horizontal;
    }

    // Esquina inferior derecha
    cout << esquinaID;
}

/**
 * Dibuja un margen con líneas dobles (estilo elegante)
 * Caracteres ASCII: ╔ ╗ ╚ ╝ ═ ║
 */
void dibujarMargenDoble() {
    dibujarMargenPersonalizado(201, 187, 200, 188, 205, 186);
}

/**
 * Dibuja un margen con líneas simples (estilo minimalista)
 * Caracteres ASCII: ┌ ┐ └ ┘ ─ │
 */
void dibujarMargenSimple() {
    dibujarMargenPersonalizado(218, 191, 192, 217, 196, 179);
}

/**
 * Dibuja un margen con bloques completos (estilo sólido)
 * Carácter ASCII: █
 */
void dibujarMargenSolido() {
    dibujarMargen((char)219);
}

/**
 * Dibuja un margen con asteriscos (estilo retro)
 */
void dibujarMargenAsteriscos() {
    dibujarMargen('*');
}

/**
 * Dibuja un margen con caracteres de sombreado medio
 * Carácter ASCII: ▒
 */
void dibujarMargenSombreado() {
    dibujarMargen((char)177);
}

#endif // MARGEN_H
