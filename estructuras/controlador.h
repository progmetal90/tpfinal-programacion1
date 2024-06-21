#ifndef CONTROLADOR_H_INCLUDED
#define CONTROLADOR_H_INCLUDED
#define ANCHO_DE_CONSOLA 50

#include <string.h>
#include "../librerias/validacion.h"
#include "memoria.h"
#include "../librerias/mock.h"
#include "../librerias/subprogramas.h"
#include "../librerias/submenus.h"

typedef struct{
    stMemoria * memoria;
    stUsuario * usuarioLogueado;
}stControlador;

stControlador inicializarControlador(stMemoria * memoria);
int ejecutarSubprograma(int subprograma, stControlador * controlador);
stUsuario * iniciarSesion(stMemoria * memoria);
void obtenerStringDeUsuario(char * buffer, int dimBuffer);
int existeEmail(char * email, stUsuario * usuarios, int vUsuarios);
int existePelicula(char * nombrePelicula, stPelicula * peliculas, int validos);
void spCrearUsuario(stMemoria * memoria);
void spAgregarPelicula (stMemoria * memoria);
void spFiltrarPorTitulo(stMemoria * memoria);
void spFiltrarPorCategoria(stMemoria * memoria);
void spFiltrarPorDirector(stMemoria * memoria);
void spAgregarComentario(stMemoria * memoria, int idUsuario);
void spModificarInfoPelicula (stMemoria * memoria);
int buscarSiExisteIdPelicula (stMemoria * memoria, int idPelicula);

#endif // CONTROLADOR_H_INCLUDED
