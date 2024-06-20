#include "pelicula.h"

stPelicula cargarPelicula (char titulo[]){

    stPelicula pelicula;
    //TODO: ver que no se repita titulo

    strcpy(pelicula.titulo, titulo);

    printf("Categoria: ");
    obtenerStringDeUsuario(&pelicula.categoria, DIM_CATEGORIA);

    printf("Director: ");
    obtenerStringDeUsuario(&pelicula.director, DIM_DIRECTOR);

    printf("Estudio: ");
    obtenerStringDeUsuario(&pelicula.estudio, DIM_ESTUDIO);

    pelicula.valoracion = 0;

    return pelicula;
}


void mostrarPelicula (stPelicula pelicula){

    printf("\nTitulo: %s\n", pelicula.titulo);
    printf("Categoria: %s\n", pelicula.categoria);
    printf("Director: %s\n", pelicula.director);
    printf("Estudio: %s\n", pelicula.estudio);
    printf("Valoracion: %.2f\n", pelicula.valoracion);
    printf("ID: %d", pelicula.idPelicula);
}

int filtrarPeliculaTitulo (stPelicula pelicula, char dato[]){

    int esIgual = -1;
    char aux[DIM_TITULO_PELICULA];
    strcpy(aux, pelicula.titulo);

    //Convierte las strings a minusculas para comparar.
    strlwr(dato);
    strlwr(aux);

    //Compara que la busqueda este contenida en el titulo.
    if(strstr(aux, dato)){
        esIgual = 1;
    }

return esIgual;
}

int filtrarPeliculaCategoria (stPelicula pelicula, char dato[]){

    int esIgual = -1;
    char aux[DIM_CATEGORIA];
    strcpy(aux, pelicula.categoria);

    strlwr(dato);
    strlwr(aux);

    if(strstr(aux, dato)){
        esIgual = 1;
    }

return esIgual;
}

int filtrarPeliculaDirector (stPelicula pelicula, char dato[]){

    int esIgual = -1;
    char aux[DIM_DIRECTOR];
    strcpy(aux, pelicula.director);

    strlwr(dato);
    strlwr(aux);

    if(strstr(aux, dato)){
        esIgual = 1;
    }

return esIgual;
}

stPelicula modificarInfoPelicula (stPelicula pelicula){

    char control = 0;
    int opcion = 0;

    do{
        system("cls");
        printf("SELECCIONE EL CAMPO QUE DESEA CAMBIAR...\n");
        printf("1- TITULO.\n");
        printf("2- CATEGORIA.\n");
        printf("3- DIRECTOR.\n");
        printf("4- ESTUDIO.\n");

        scanf("%d", &opcion);

        switch(opcion){

            case 1:

                system("cls");

                printf("TITULO: %s\n", pelicula.titulo);
                printf("NUEVO TITULO: ");
                fflush(stdin);
                gets(pelicula.titulo);

                break;

            case 2:

                system("cls");

                printf("CATEGORIA: %s\n", pelicula.categoria);
                printf("NUEVA CATEGORIA: ");
                fflush(stdin);
                gets(pelicula.categoria);

                break;

            case 3:

                system("cls");

                printf("DIRECTOR: %s\n", pelicula.director);
                printf("NUEVO DIRECTOR: ");
                fflush(stdin);
                gets(pelicula.director);

                break;

            case 4:

                system("cls");

                printf("ESTUDIO: %s\n", pelicula.estudio);
                printf("NUEVO ESTUDIO: ");
                fflush(stdin);
                gets(pelicula.estudio);

                break;

            default:

                printf("EL NUMERO INGRESADO NO COINCIDE CON LAS OPCIONES...\n");
        }
        printf("DESEA MODIFICAR OTRO CAMPO? s/n\n");
        fflush(stdin);
        scanf("%c", &control);
    }while(control == 's' || control == 'S');

return pelicula;
}
