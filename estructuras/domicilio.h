#ifndef DOMICILIO_H_INCLUDED
#define DOMICILIO_H_INCLUDED

#define DIM_CALLE 100
#define DIM_CIUDAD 100
#define DIM_LOCALIDAD 100
#define DIM_PAIS 100

#include <string.h>

typedef struct{
    char calle[DIM_CALLE];
    int altura;
    int cp;
    char ciudad[DIM_CIUDAD];
    char localidad[DIM_LOCALIDAD];
    char pais[DIM_PAIS];
} stDomicilio;

void mostrarDomicilio(stDomicilio domicilio);

#endif // DOMICILIO_H_INCLUDED
