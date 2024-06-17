#include "pelicula.h"
#include "../librerias/mock.h"
#define DIM_PELICULAS 100
#define DIM_TITULOS 10
#define DIM_DIRECTORES 10
#define DIM_ESTUDIOS 10
#define DIM_CATEGORIAS 5
#define REALLOC_MULTIPLICADOR 1.5

stPelicula * inicAPeliculas(stPelicula * p){

    p = (stPelicula *) malloc(sizeof(stPelicula) * 100);
return p;
}


int cargarPelicula (stPelicula *pelicula, int i){

    char control = 0;
    int cant = DIM_PELICULAS;

    do{
        system("cls");
        if(i >= cant){
                cant *= REALLOC_MULTIPLICADOR;
                pelicula = (stPelicula*)realloc(pelicula, sizeof(stPelicula) * cant);
        }else{
            printf("Titulo: ");
            fflush(stdin);
            gets(pelicula[i].titulo);
            system("cls");

            printf("Categoria: ");
            fflush(stdin);
            gets(pelicula[i].categoria);
            system("cls");

            printf("Director: ");
            fflush(stdin);
            gets(pelicula[i].director);
            system("cls");

            printf("Estudio: ");
            fflush(stdin);
            gets(pelicula[i].estudio);
            system("cls");

            pelicula[i].idPelicula = i+1;

            pelicula[i].valoracion = 0;

            i++;
            printf("Para dejar de cargar presione esc ...");
            fflush(stdin);
            control = getch();
        }
    }while(control != 27);

return i;
}

int cargarPeliculasRand (stPelicula pelicula[], int cant, int inicio){

    int i = inicio;

    do{
        pelicula[i] = cargarPeliculaRandom();
        i++;

    }while(i < inicio + cant);

return inicio + cant;
}

void mostrarPelicula (stPelicula pelicula){

    printf("\nTitulo: %s\n", pelicula.titulo);
    printf("Categoria: %s\n", pelicula.categoria);
    printf("Director: %s\n", pelicula.director);
    printf("Estudio: %s\n", pelicula.estudio);
    printf("Valoracion: %f.2\n", pelicula.valoracion);
    printf("ID: %d", pelicula.idPelicula);
}

void mostrarPeliculas (stPelicula pelicula[], int v){
    system("cls");
    for(int i = 0; i < v; i++){
        mostrarPelicula(pelicula[i]);
        printf("\n---------------------------------------------------------\n");
    }
}

int buscarPeliculaTitulo (stPelicula pelicula, char dato[], int v){

    int idPelicula = -1;

    //Convierte las strings a minusculas para comparar.
    strlwr(dato);
    strlwr(pelicula.titulo);

    //Compara que la busqueda este contenida en el titulo.
    if(strstr(pelicula.titulo, dato)){
        idPelicula = pelicula.idPelicula;
    }

return idPelicula;
}

int buscarPeliculaCategoria (stPelicula pelicula, char dato[], int v){

    int bandera = -1;

    strlwr(dato);
    strlwr(pelicula.categoria);

    if(strstr(pelicula.categoria, dato)){
        bandera = 1;
    }

return bandera;
}

int buscarPeliculaDirector (stPelicula pelicula, char dato[], int v){

    int bandera = -1;

    strlwr(dato);
    strlwr(pelicula.director);

    if(strstr(pelicula.director, dato)){
        bandera = 1;
    }

return bandera;
}

void mostrarPeliculasPorCategoria (stPelicula pelicula[], char dato[], int v){

    for(int i = 0; i < v; i++){
        if(buscarPeliculaCategoria(pelicula[i], dato, v) != -1){
            printf("\n---------------------------------------------------------\n");
            mostrarPelicula(pelicula[i]);
        }
    }
}

void mostrarPeliculasPorDirector (stPelicula pelicula[], char dato[], int v){

    for(int i = 0; i < v; i++){
        if(buscarPeliculaDirector(pelicula[i], dato, v) != -1){
            printf("\n---------------------------------------------------------\n");
            mostrarPelicula(pelicula[i]);
        }
    }
}

void mostrarPeliculasPorTitulo (stPelicula pelicula[], char dato[], int v){

    for(int i = 0; i < v; i++){
        if(buscarPeliculaTitulo(pelicula[i], dato, v) != -1){
            printf("\n---------------------------------------------------------\n");
            mostrarPelicula(pelicula[i]);
        }
    }
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
