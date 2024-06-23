/*
* Libreria con metodos para validacion de datos.
*/

#define DIM_EMAIL 100

#ifndef AUTENTIFICACION_H_INCLUDED
#define AUTENTIFICACION_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

int esAlfanumerico(char caracter);
int validarEmail(char email[]);
int validarContrasenia(char contrasenia[]);
int contarCaracterEnString(char string[], char caracter);
int enRango(int valor, int min, int max);
int validarGenero(char genero);
int validarfecha(int dia, int mes, int anio);
int esNumeroValido(char * buffer);


#endif // AUTENTIFICACION_H_INCLUDED
