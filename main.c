#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "librerias/mock.h"
#include "estructuras/usuario.h"
#include "estructuras/pelicula.h"
#include "estructuras/fecha.h"
#include "estructuras/interfaz.h"

int main()
{
    srand(time(NULL));

//    stMemoria memoria = inicializarMemoria(); // Cargo archivos a memoria
//    stControlador controlador = inicializarControlador(&memoria);

    // TODO: cargar archivos a memoria

    stInterfaz interfaz = inicializarInterfaz();
    ejecutarInterfaz(interfaz); // TODO: pasar memoria a interfaz

    // TODO: guardar memoria en archivos
//    memoria.guardar();

    return 0;
}
