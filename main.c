#include <stdio.h>
#include <stdlib.h>
#include "estructuras/interfaz.h"

int main()
{
    srand(time(NULL));

    stMemoria memoria = inicializarMemoria(); // Cargo archivos a memoria
    stControlador controlador = inicializarControlador(&memoria);

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
