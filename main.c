#include <stdio.h>
#include <stdlib.h>
#include "estructuras/interfaz.h"

int main()
{
    srand(time(NULL));

    stMemoria memoria = inicializarMemoria(); // Cargo archivos a memoria
    stControlador controlador = inicializarControlador(&memoria);

//    stUsuario admin = cargarUsuarioRandom();
//    admin.esAdmin = 1;
//    strcpy(admin.username, "administrador");
//    strcpy(admin.email, "admin@gmail.com");
//    strcpy(admin.password, "Abc123");
//
//    agregarUsuario(&memoria, admin);
//
//    // Provisorio: cargar 10 de cada estructura a memoria
//    for(int i = 0; i < 50; i++){
//        agregarPelicula(&memoria, cargarPeliculaRandom());
//    }

    int memoriaValida = validarMemoria(&memoria);

    if(memoriaValida){
        stInterfaz interfaz = inicializarInterfaz();
        ejecutarInterfaz(interfaz, &controlador);

        // TODO: guardar memoria en archivos
        guardarCambios(&memoria);
    }
    else{
        printf("No se pudo alojar suficiente memoria! Saliendo del programa...");
        system("pause");
    }

    return 0;
}
