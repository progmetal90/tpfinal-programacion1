#include <stdlib.h>
#include <string.h>
#include "fecha.h"

const char SEPARADOR_FECHA[] = "-";

void fechaAString(stFecha fecha, char * buffer){
    // Produce una string en formato AAAA-MM-DD

    char aux[5];

    // Transformar anio en string
    itoa(fecha.anio, aux, 10);

    // Encadenarlo en el buffer con un separador
    buffer = strcat(buffer, aux);
    buffer = strcat(buffer, SEPARADOR_FECHA);


    // Repito con mes
    itoa(fecha.mes, aux, 10);

    buffer = strcat(buffer, aux);
    buffer = strcat(buffer, SEPARADOR_FECHA);

    // Repito con dia
    itoa(fecha.dia, aux, 10);

    buffer = strcat(buffer, aux);
}
