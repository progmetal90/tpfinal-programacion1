#ifndef CONTROLADOR_H_INCLUDED
#define CONTROLADOR_H_INCLUDED

#include "memoria.h"
#include "../librerias/mock.h"

typedef struct{
    stMemoria * memoria;
}stControlador;

stControlador inicializarControlador(stMemoria * memoria);
void ejecutarSubprograma(int subprograma, stMemoria * memoria);

#endif // CONTROLADOR_H_INCLUDED
