#ifndef INTERFAZ_H_INCLUDED
#define INTERFAZ_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "menu.h"
#include "controlador.h"
#include "../librerias/validacion.h"

#define ID_MENU_INVALIDO 9999
#define DIM_ARR_MENU 200 // TODO: 200 es de prueba, reducir mas adelante
#define DIM_HISTORIAL 50

typedef struct{
    int historial[DIM_HISTORIAL];
    int posHistorial;
    stMenu menus[DIM_ARR_MENU];
}stInterfaz;

stInterfaz inicializarInterfaz();
void ejecutarInterfaz(stInterfaz interfaz, stControlador * controlador);
int obtenerIdProximoMenu(stMenu menu, int opcion);
void obtenerOpcion(int * opcion);
int validarOpcion(int opcion, int validosUsuario, int validosAdmin);
int confirmarSalida(char mensaje[]);

#endif // INTERFAZ_H_INCLUDED
