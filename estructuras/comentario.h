#ifndef COMENTARIO_H_INCLUDED
#define COMENTARIO_H_INCLUDED

#define DIM_TITULO_COMENTARIO 100
#define DIM_DESCRIPCION_COMENTARIO 500

#include <stdio.h>
#include <string.h>
#include "fecha.h"
#include "../librerias/validacion.h"
#include "../librerias/consola.h"

typedef struct {
    int idComentario;  // unico, autoincremental
    int idPelicula;
    int idUsuario;
    char titulo[DIM_TITULO_COMENTARIO];
    char descripcion[DIM_TITULO_COMENTARIO];
    int puntaje; // de 1 a 5 "estrellas"
    char fechaComentario[DIM_FECHA];
    int eliminado; // 0 si está activo - 1 si está eliminado
}stComentario;

void mostrarComentario(stComentario comentario);
stComentario cargarComentario(int idUsuario, int idPelicula);
stComentario modificarComentario(stComentario comentario);

#endif // COMENTARIO_H_INCLUDED
