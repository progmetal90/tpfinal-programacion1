#ifndef MEMORIA_H_INCLUDED
#define MEMORIA_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include "comentario.h"
#include "usuario.h"
#include "pelicula.h"

#define INCREMENTO_DINAMICO 100

#define NOM_ARCHIVO_USUARIOS "usuarios.dat"
#define NOM_ARCHIVO_PELICULAS "peliculas.dat"
#define NOM_ARCHIVO_COMENTARIOS "comentarios.dat"

typedef struct{
    stComentario * comentarios;
    int vComentarios;
    int dimComentarios;
    stPelicula * peliculas;
    int vPeliculas;
    int dimPeliculas;
    stUsuario * usuarios;
    int vUsuarios;
    int dimUsuarios;
}stMemoria;

stMemoria inicializarMemoria();
void guardarCambios(stMemoria * memoria);
void agregarComentario(stMemoria * memoria, stComentario comentario);
void agregarUsuario(stMemoria * memoria, stUsuario usuario);
void agregarPelicula(stMemoria * memoria, stPelicula pelicula);
stPelicula * obtenerPelicula(stMemoria * memoria, int id);
stUsuario * obtenerUsuario(stMemoria * memoria, int id);
stComentario * obtenerComentario(stMemoria * memoria, int id);
void sobreescribirPelicula(stMemoria * memoria, stPelicula pelicula);
void sobreescribirUsuario(stMemoria * memoria, stUsuario usuario);
void sobreescribirComentario(stMemoria * memoria, stComentario comentario);
int obtenerCantidadElementos(char nombreArchivo[], int dimDatos);
void cargarArchivosEnMemoria(stMemoria * memoria);


#endif // MEMORIA_H_INCLUDED
