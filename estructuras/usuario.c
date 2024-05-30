#include "usuario.h"

void mostrarUsuario(stUsuario usuario){
    char stringNacimiento[DIM_FECHA_STRING];
    fechaAString(usuario.nacimiento, stringNacimiento);

    printf("Id: %d", usuario.idUsuario);
    if(usuario.esAdmin == 1){
        printf(" [ADMINISTRADOR]");
    }
    printf("\nNombre de usuario: %s\n", usuario.username);
    printf("Email: %s\n", usuario.email);
    printf("Genero: %c\n", usuario.genero);
    printf("Fecha nacimiento: %s\n", stringNacimiento);
    printf("DNI: %s\n", usuario.dni);
    mostrarDomicilio(usuario.domicilio);
    // TODO: mostrar peliculas favoritas en un menu distinto?
}
