#ifndef PELICULA_H_INCLUDED
#define PELICULA_H_INCLUDED

typedef struct{
    int idPelicula; // unico, autoincremental
    char titulo[100];
    char director[50];
    char estudio[50];
    char categoria[50];
    float valoracion; // inicializar en 0 (sin valoracion)
    int eliminado; // 0 si esta activo - 1 si esta eliminado
}stPelicula;

#endif // PELICULA_H_INCLUDED
