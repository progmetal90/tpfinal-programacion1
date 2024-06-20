#ifndef CONTROLADOR_H_INCLUDED
#define CONTROLADOR_H_INCLUDED

#include <string.h>
#include "../librerias/validacion.h"
#include "memoria.h"
#include "../librerias/mock.h"
#include "../librerias/subprogramas.h"

typedef struct{
    stMemoria * memoria;
    stUsuario * usuarioLogueado;
}stControlador;

stControlador inicializarControlador(stMemoria * memoria);
void ejecutarSubprograma(int subprograma, stControlador * controlador);
stUsuario * iniciarSesion(stMemoria * memoria);
void obtenerStringDeUsuario(char * buffer, int dimBuffer);
int existeEmail(char * email, stUsuario * usuarios, int vUsuarios);
void spCrearUsuario(stMemoria * memoria);

#endif // CONTROLADOR_H_INCLUDED
