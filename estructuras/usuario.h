#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

#define DIM_EMAIL 100
#define DIM_PASSWORD 20
#define DIM_USERNAME 20
#define CANT_GENEROS 3
#define DIM_PELISFAVORITAS 50
#define DIM_DNI 10

#include "domicilio.h"
#include "fecha.h"

typedef struct{
    int idUsuario;
    char email[DIM_EMAIL];
    char password[DIM_PASSWORD];
    char username[DIM_USERNAME];
    int esAdmin;  // 1 = si  0 = no
    char genero;
    stFecha nacimiento;
    int pelisFavoritas[DIM_PELISFAVORITAS]; // Guarda ID de pelicula
    char dni[DIM_DNI];
    stDomicilio domicilio;
    int eliminado; // 0 si está activo - 1 si está eliminado
}stUsuario;

void mostrarUsuario(stUsuario usuario);

#endif // USUARIO_H_INCLUDED
