#include <stdio.h>
#include "comentario.h"

void mostrarComentario(stComentario comentario){
    char fechaString[DIM_FECHA_STRING];
    fechaAString(comentario.fechaComentario, fechaString);

    printf("Comentario: #%d, pelicula #%d, usuario #%d\n", comentario.idComentario, comentario.idPelicula, comentario.idUsuario);
    printf("Fecha: %s\n", fechaString);
    printf("Titulo: %s\n", comentario.titulo);
    printf("Descripcion: %s\n", comentario.descripcion);
    printf("Puntaje: %d estrellas.", comentario.puntaje);
}
