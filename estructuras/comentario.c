#include "comentario.h"

void mostrarComentario(stComentario comentario){

    printf("Comentario #%d\n", comentario.idComentario);
    printf("Fecha: %s\n", comentario.fechaComentario);
    printf("Titulo: %s\n", comentario.titulo);
    printf("Descripcion: %s\n", comentario.descripcion);
    printf("Puntaje: %d estrellas.\n", comentario.puntaje);
}

stComentario modificarComentario(stComentario comentario){
    char control = 0;
    int opcion = 0;

    do{
        system("cls");
        printf("SELECCIONE EL CAMPO QUE DESEA CAMBIAR...\n");
        printf("1- TITULO.\n");
        printf("2- DESCRIPCION.\n");
        printf("3- PUNTAJE.\n");

        scanf("%d", &opcion);

        switch(opcion){
            case 1:
                system("cls");
                printf("Titulo: %s\n", comentario.titulo);

                do{
                    printf("Ingrese el nuevo titulo: ");
                    obtenerStringDeUsuario(comentario.titulo, DIM_TITULO_COMENTARIO);
                }while(strlen(comentario.titulo) == 0);

                break;
            case 2:
                system("cls");
                printf("Descripcion: %s\n", comentario.descripcion);

                do{
                    printf("Ingrese la nueva descripcion: ");
                    obtenerStringDeUsuario(comentario.descripcion, DIM_DESCRIPCION_COMENTARIO);
                }while(strlen(comentario.descripcion) == 0);

                break;
            case 3:
                system("cls");
                printf("Puntaje: %d\n", comentario.puntaje);

                do{
                    printf("Ingrese el nuevo puntaje: ");
                    scanf("%d", &comentario.puntaje);
                }while(enRango(comentario.puntaje, 1, 5 + 1));

                break;
            default:
                    printf("EL NUMERO INGRESADO NO COINCIDE CON LAS OPCIONES...\n");
        }

        printf("DESEA MODIFICAR OTRO CAMPO? s/n\n");
        fflush(stdin);
        scanf("%c", &control);

        }while(control == 's' || control == 'S');

    return comentario;
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
        else{
            comentario.puntaje = puntaje;
        }

    }while(!enRango(puntaje, 1, 5 + 1));

    obtenerFechaActual(comentario.fechaComentario);

    return comentario;
}
