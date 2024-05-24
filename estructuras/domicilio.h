#ifndef DOMICILIO_H_INCLUDED
#define DOMICILIO_H_INCLUDED

#define TAM_CALLE 50
#include <string.h>
#include "mock.h"

typedef struct{
    char calle[TAM_CALLE];
    int altura;
    int cp;
    char ciudad[100];
    char localidad[50];
    char pais[100];
} stDomicilio;

stDomicilio cargarDomicilioRandom();

#endif // DOMICILIO_H_INCLUDED
