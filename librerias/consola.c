#include "consola.h"

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

int separadorDeConsola (){

    char control;
    int respuesta = 0;

    printf("ENTER PARA PASAR A LA SIGUENTE PAGINA\n");
    control = getch();

    if(control == 13){
        respuesta = 1;
    }

    system("cls");

    return respuesta;
}
