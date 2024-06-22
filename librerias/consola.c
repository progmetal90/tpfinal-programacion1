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
