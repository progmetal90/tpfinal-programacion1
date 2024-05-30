#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#define DIM_FECHA_STRING 11

typedef struct{
    int dia;
    int mes;
    int anio;
}stFecha;

void fechaAString(stFecha fecha, char * buffer);

#endif // FECHA_H_INCLUDED
