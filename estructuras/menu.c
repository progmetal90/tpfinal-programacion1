#include "menu.h"

void mostrarMenu(stMenu menu){
    // Titulo
    imprimirTitulo(menu.titulo, SEPARADOR_MENU);

    // Opciones
    imprimirOpciones(menu.opcionesUsuario, menu.cantOpcionesUsuario, 0);

    // TODO: comprobar credenciales de admin
    // Solo imprimir opciones admin si el usuario es administrador
    // Pasar esAdmin desde la funcion verificadora
    if(menu.cantOpcionesAdmin > 0){ // placeholder
        imprimirOpciones(menu.opcionesAdmin, menu.cantOpcionesAdmin, 1);
    }

    printf("\n[0] Volver\n");
}

void imprimirOpciones(char opciones[][DIM_OPCION_MENU], int validos, int esAdmin){
    int offset = 0;

    if(esAdmin){
        offset += 100;
    }

    imprimirSaltosDeLinea(1);

    for(int i = 0; i < validos; i++){
        printf("[%d] %s\n", i+1+offset, opciones[i]);
    }
}

void imprimirSaltosDeLinea(int cantidad){
    for(int i = 0; i < cantidad; i++){
        printf("\n");
    }
}

void imprimirLineaSeparadora(char separador, int cantidad){
    for(int i = 0; i < cantidad; i++){
        printf("%c", separador);
    }

    imprimirSaltosDeLinea(1);
}

void imprimirTitulo(char titulo[], char separador){
    int largoTitulo = strlen(titulo);

    imprimirLineaSeparadora(separador, largoTitulo);
    printf("%s\n", titulo);
    imprimirLineaSeparadora(separador, largoTitulo);
}
