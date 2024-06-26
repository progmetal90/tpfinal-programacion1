#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

#define DIM_PASSWORD 20
#define DIM_USERNAME 20
#define CANT_GENEROS 3
#define DIM_PELISFAVORITAS 50
#define DIM_DNI 10

#include <stdio.h>
#include "domicilio.h"
#include "../librerias/validacion.h"
#include "fecha.h"
#include "../librerias/consola.h"

typedef struct{
    int idUsuario;
    char email[DIM_EMAIL];
    char password[DIM_PASSWORD];
    char username[DIM_USERNAME];
    int esAdmin;  // 1 = si  0 = no
    char genero;
    char fechaNacimiento[DIM_FECHA];
    int favoritos[DIM_PELISFAVORITAS]; // Guarda ID de pelicula
    int vFavoritos;
    char dni[DIM_DNI];
    stDomicilio domicilio;
    int eliminado; // 0 si est� activo - 1 si est� eliminado
}stUsuario;

void mostrarUsuario(stUsuario usuario);
stUsuario cargarUsuario(char * mail);
stUsuario modificarUsuario(stUsuario usuario);
stUsuario eliminarUsuario(char * mail);
stUsuario agregarFavorito(stUsuario usuario, int idPelicula);
stUsuario quitarFavorito(stUsuario usuario, int idPelicula);

#endif // USUARIO_H_INCLUDED
