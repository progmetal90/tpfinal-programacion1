#ifndef PELICULA_H_INCLUDED
#define PELICULA_H_INCLUDED
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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
    int eliminado; // 0 si esta activo - 1 si esta eliminado
}stPelicula;

stPelicula * inicAPeliculas(stPelicula *p);
int cargarPelicula (stPelicula *pelicula, int i);
int cargarPeliculasRand (stPelicula pelicula[], int cant, int i);
void mostrarPelicula (stPelicula pelicula);
void mostrarPeliculas (stPelicula pelicula[], int v);
int buscarPeliculaTitulo (stPelicula pelicula, char dato[], int v);
int buscarPeliculaCategoria (stPelicula pelicula, char dato[], int v);
int buscarPeliculaDirector (stPelicula pelicula, char dato[], int v);
void mostrarPeliculasPorCategoria (stPelicula pelicula[], char dato[], int v);
void mostrarPeliculasPorDirector (stPelicula pelicula[], char dato[], int v);
void mostrarPeliculasPorTitulo (stPelicula pelicula[], char dato[], int v);
stPelicula modificarInfoPelicula (stPelicula pelicula);

#endif // PELICULA_H_INCLUDED
