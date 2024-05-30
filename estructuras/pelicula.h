#ifndef PELICULA_H_INCLUDED
#define PELICULA_H_INCLUDED

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

#endif // PELICULA_H_INCLUDED
