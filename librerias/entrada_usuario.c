#include "entrada_usuario.h"

void obtenerStringDeUsuario(char * buffer, int dimBuffer){
    fflush(stdin);
    fgets(buffer, dimBuffer, stdin);

    // TODO: esto es una chanchada para quitar el salto de linea de fgets
    // Preguntar como mejorar esto

    int encontrado = 0;
    for(int i = dimBuffer; i >= 0 && encontrado == 0; i--){
        if(buffer[i] == 10){
            buffer[i] = 0;
            encontrado = 1;
        }
    }
}

void obtenerOpcion(int * opcion){
    // TODO: refactorear esto para quitar los scanf del resto del proyecto
    const int DIM_OPCION_STRING = 4;
    char opcionString[DIM_OPCION_STRING];

    obtenerStringDeUsuario(opcionString, DIM_OPCION_STRING);

    if(strlen(opcionString) > 0 && esNumeroValido(opcionString)){
        *opcion = atoi(opcionString);
    }
    else{
        *opcion = -1;
    }
}
