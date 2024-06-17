#include <stdio.h>
#include "comentario.h"

void mostrarComentario(stComentario comentario){

    printf("Comentario: #%d, pelicula #%d, usuario #%d\n", comentario.idComentario, comentario.idPelicula, comentario.idUsuario);
    printf("Fecha: %s\n", comentario.fechaComentario);
    printf("Titulo: %s\n", comentario.titulo);
    printf("Descripcion: %s\n", comentario.descripcion);
    printf("Puntaje: %d estrellas.\n", comentario.puntaje);
}
