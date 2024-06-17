#include <stdio.h>
#include <stdlib.h>
#include "estructuras/interfaz.h"

int main()
{
    srand(time(NULL));

    stMemoria memoria = inicializarMemoria(); // Cargo archivos a memoria
    stControlador controlador = inicializarControlador(&memoria);

    // Provisorio: cargar 10 de cada estructura a memoria
    for(int i = 0; i < 50; i++){
        agregarComentario(&memoria, cargarComentarioRandom());
        agregarUsuario(&memoria, cargarUsuarioRandom());
        agregarPelicula(&memoria, cargarPeliculaRandom());
    }

    stInterfaz interfaz = inicializarInterfaz();
    ejecutarInterfaz(interfaz, controlador);

    // TODO: guardar memoria en archivos
    guardarCambios(&memoria);

    return 0;
}
