#include "menu.h"

void mostrarMenu(stMenu menu, int esAdmin){
    // Titulo
    imprimirTitulo(menu.titulo, SEPARADOR_MENU);

    // Opciones
    imprimirOpciones(menu.opcionesUsuario, menu.cantOpcionesUsuario, USUARIO_MENU_OFFSET);

    // Solo imprimir opciones admin si el usuario es administrador
    if(menu.cantOpcionesAdmin > 0 && esAdmin == 1){
        imprimirOpciones(menu.opcionesAdmin, menu.cantOpcionesAdmin, ADMIN_MENU_OFFSET);
    }

    printf("\n[0] Volver\n");
}

void imprimirOpciones(char opciones[][DIM_OPCION_MENU], int validos, int offset){
    imprimirSaltosDeLinea(1);

    for(int i = 0; i < validos; i++){
        printf("[%d] %s\n", i+offset, opciones[i]);
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
