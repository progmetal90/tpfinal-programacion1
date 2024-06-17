#include "controlador.h"

stControlador inicializarControlador(stMemoria * memoria){
    stControlador controlador;

    controlador.memoria = memoria;

    return controlador;
}

void ejecutarSubprograma(int subprograma, stMemoria * memoria){
    switch(subprograma){
        default:
            // Si sucede esto nos mandamos una cagada
            printf("ERROR! Subprograma %d invalido!\n", subprograma);
            break;
    }
}
