#include "fecha.h"

void obtenerFechaActual(char * buffer) {

    time_t tiempo_actual;
    struct tm* tiempo_local;

    tiempo_actual = time(NULL);

    tiempo_local = localtime(&tiempo_actual);

    strftime(buffer, DIM_FECHA, FORMATO_FECHA , tiempo_local);
}
