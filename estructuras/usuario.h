#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

typedef struct{
    int idUsuario;
    char email[100];
    char password[20];
    char username[20];
    int esAdmin;  // 1 = si  0 = no
    char genero;
    int fechaNacimiento[3]; // [dia, mes, anio] TODO: fecha podria ser una estructura?
    int pelisFavoritas[50]; // Guarda ID de pelicula
    char dni[10];
    stDomicilio domicilio;
    int eliminado; // 0 si está activo - 1 si está eliminado
}stUsuario;

#endif // USUARIO_H_INCLUDED
