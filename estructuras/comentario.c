#include <stdio.h>
#include "comentario.h"

void mostrarComentario(stComentario comentario){

    printf("Comentario: #%d, pelicula #%d, usuario #%d\n", comentario.idComentario, comentario.idPelicula, comentario.idUsuario);
    printf("Fecha: %s\n", comentario.fechaComentario);
    printf("Titulo: %s\n", comentario.titulo);
    printf("Descripcion: %s\n", comentario.descripcion);
    printf("Puntaje: %d estrellas.\n", comentario.puntaje);
}

stComentario cargarComentario(int idUsuario, int idPelicula){
    const int DIM_PUNTAJE = 3;

    system("cls");
    stComentario comentario;
    int puntaje;
    char puntajeString[DIM_PUNTAJE];

    // Inicializar en -1, al cargar se le asignara un id unico
    comentario.idComentario = -1;

    comentario.idPelicula = idPelicula;
    comentario.idUsuario = idUsuario;
    comentario.eliminado = 0;

    printf("Ingrese el titulo del comentario: ");
    obtenerStringDeUsuario(comentario.titulo, DIM_TITULO_COMENTARIO);

    system("cls");
    printf("Ingrese el comentario: ");
    obtenerStringDeUsuario(comentario.descripcion, DIM_DESCRIPCION_COMENTARIO);

    system("cls");
    do{
        printf("Ingrese un puntaje (del 1 al 5): ");
        obtenerStringDeUsuario(puntajeString, DIM_PUNTAJE);
        puntaje = atoi(puntajeString);
        if(!enRango(puntaje, 1, 5 + 1)){
            printf("Puntaje invalido! Intente nuevamente.\n");
        }

    }while(!enRango(puntaje, 1, 5 + 1));

    obtenerFechaActual(comentario.fechaComentario);

    printf("Comentario cargado con exito!\n");

    mostrarComentario(comentario);

    system("pause");
    return comentario;
}
