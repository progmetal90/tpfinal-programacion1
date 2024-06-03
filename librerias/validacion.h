/*
* Libreria con metodos para validacion de datos.
*/

#ifndef AUTENTIFICACION_H_INCLUDED
#define AUTENTIFICACION_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>


int validarEmail(char email[]);
int validarContrasenia(char contrasenia[]);
int contarCaracterEnString(char string[], char caracter);


#endif // AUTENTIFICACION_H_INCLUDED
