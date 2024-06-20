#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#include <time.h>
#include <string.h>
#include <stdlib.h>

#define DIM_FECHA 20
#define FORMATO_FECHA "%04d-%02d-%02d"

void obtenerFechaActual(char * buffer);

#endif // FECHA_H_INCLUDED
