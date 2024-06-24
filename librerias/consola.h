#ifndef CONSOLA_H_INCLUDED
#define CONSOLA_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#define COLOR_ROJO "\x1b[31m"
#define COLOR_VERDE "\x1b[32m"
#define COLOR_AMARILLO "\x1b[33m"
#define COLOR_AZUL "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN "\x1b[36m"
#define COLOR_RESET "\x1b[0m"

#define SEPARADOR_MENU '='
#define SEPARADOR_ESTRUCTURAS '-'

void imprimirSaltosDeLinea(int cantidad);
void imprimirLineaSeparadora(char separador, int cantidad);
int separadorDeConsola ();

#endif // CONSOLA_H_INCLUDED
