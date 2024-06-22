#include "menu.h"

void mostrarMenu(stMenu menu, int esAdmin){
    // Titulo
    imprimirTitulo(menu.titulo, SEPARADOR_MENU);

    // Opciones
    imprimirOpciones(menu.opcionesUsuario, menu.cantOpcionesUsuario, USUARIO_MENU_OFFSET);

    // Solo imprimir opciones admin si el usuario es administrador
    if(menu.cantOpcionesAdmin > 0 && esAdmin == 1){
        printf(COLOR_ROJO);
        printf("\n** OPCIONES DE ADMINISTRADOR**");
        imprimirOpciones(menu.opcionesAdmin, menu.cantOpcionesAdmin, ADMIN_MENU_OFFSET);
        printf(COLOR_RESET);
    }

    printf("\n[0] ");
    switch(menu.idMenu){
        case SM_LOGIN:
            printf("Salir del programa");
            break;
        case SM_MENU_PRINCIPAL:
            printf("Cerrar sesion");
            break;
        default:
            printf("Volver");
            break;
    }
    imprimirSaltosDeLinea(1);
}

void imprimirOpciones(char opciones[][DIM_OPCION_MENU], int validos, int offset){
    imprimirSaltosDeLinea(1);

    for(int i = 0; i < validos; i++){
        printf("[%d] %s\n", i+offset, opciones[i]);
    }
}

void imprimirTitulo(char titulo[], char separador){
    int largoTitulo = strlen(titulo);

    imprimirLineaSeparadora(separador, largoTitulo);
    printf("%s\n", titulo);
    imprimirLineaSeparadora(separador, largoTitulo);
}
