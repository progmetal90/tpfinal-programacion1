#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include "../librerias/consola.h"

#define DIM_TITULO_MENU 40
#define DIM_OPCION_MENU 60
#define MAX_OPCIONES_MENU 9
#define USUARIO_MENU_OFFSET 1 // Menus usuario comienzan en 1
#define ADMIN_MENU_OFFSET 101 // Menus admin comienzan en 100

#include "../librerias/submenus.h"

typedef struct{
    int idMenu;
    int limpiarConsola;
    char titulo[DIM_TITULO_MENU];
    char opcionesUsuario[MAX_OPCIONES_MENU][DIM_OPCION_MENU];
    int cantOpcionesUsuario; // Validos
    char opcionesAdmin[MAX_OPCIONES_MENU][DIM_OPCION_MENU];
    int cantOpcionesAdmin; // Validos
    int menuObjetivoUsuario[MAX_OPCIONES_MENU];
    int menuObjetivoAdmin[MAX_OPCIONES_MENU];
}stMenu;

void mostrarMenu(stMenu menu, int esAdmin);
void imprimirOpciones(char opciones[][DIM_OPCION_MENU], int validos, int esAdmin);
void imprimirTitulo(char titulo[], char separador);

#endif // MENU_H_INCLUDED
