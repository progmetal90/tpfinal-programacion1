#ifndef PELICULA_H_INCLUDED
#define PELICULA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

#define ANCHO_DE_CONSOLA 50
#define DIM_TITULO_PELICULA 100
#define DIM_DIRECTOR 50
#define DIM_ESTUDIO 50
#define DIM_CATEGORIA 50

typedef struct{
    int idPelicula; // unico, autoincremental
    char titulo[DIM_TITULO_PELICULA];
    char director[DIM_DIRECTOR];
    char estudio[DIM_ESTUDIO];
    char categoria[DIM_CATEGORIA];
    float valoracion; // inicializar en 0 (sin valoracion)
    int eliminado; // 0 si esta activo - 1 si esta eliminado - 2 si esta dado de baja
}stPelicula;

stPelicula cargarPelicula (char titulo[]);
void mostrarPelicula (stPelicula pelicula);
int filtrarPeliculaTitulo (stPelicula pelicula, char dato[]);
int filtrarPeliculaCategoria (stPelicula pelicula, char dato[]);
int filtrarPeliculaDirector (stPelicula pelicula, char dato[]);
stPelicula modificarInfoPelicula (stPelicula pelicula);

#endif // PELICULA_H_INCLUDED
