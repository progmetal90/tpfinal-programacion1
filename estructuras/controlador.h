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
void spModificarUsuario(stMemoria * memoria, stUsuario * usuario);
void spAgregarPelicula (stMemoria * memoria);
void spFiltrarPorTitulo(stMemoria * memoria, int esAdmin);
void spFiltrarPorCategoria(stMemoria * memoria, int esAdmin);
void spFiltrarPorDirector(stMemoria * memoria, int esAdmin);
void spVerUsuarios(stMemoria * memoria);
void spEliminarUsuario(stMemoria * memoria);
void spAgregarComentario(stMemoria * memoria, int idUsuario);
void spModificarInfoPelicula (stMemoria * memoria);
int buscarSiExisteIdPelicula (stMemoria * memoria, int idPelicula);
void spMostrarComentarios(stMemoria * memoria);
void spQuitarComentario(stMemoria * memoria, int idUsuario);
int obtenerIdComentarioDeUsuario(stComentario * comentarios, int validos, int idPelicula, int idUsuario);
void eliminarComentariosDePelicula(stComentario * comentarios, int validos, int idPelicula);
void spEliminarPelicula(stMemoria * memoria);
void spDarDeBajaPelicula(stMemoria * memoria);

#endif // CONTROLADOR_H_INCLUDED
