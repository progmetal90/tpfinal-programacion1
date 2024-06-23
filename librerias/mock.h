/*
* Libreria para generacion de datos y estructuras de prueba
*/

#ifndef MOCK_H_INCLUDED
#define MOCK_H_INCLUDED

#include <stdio.h>
#include <string.h>

#include "../estructuras/usuario.h"
#include "../estructuras/comentario.h"
#include "../estructuras/pelicula.h"

void cargarCalleRandom(char calle[]);
void cargarEmailRandom(char email[]);
void cargarFechaRandom(char * fecha);
stUsuario cargarUsuarioRandom(int id);
stDomicilio cargarDomicilioRandom();
void cargarCiudadRandom(char ciudad[]);
void cargarLocalidadRandom(char localidad[]);
void cargarPaisRandom(char pais[]);
char cargarGeneroRandom();
void cargarDniRandom(char dni[]);
void cargarUsernameRandom(char username[]);
void cargarTituloComentarioRandom(char tituloComentario[]);
void cargarDescripcionComentarioRandom(char descripcionComentario[]);
stComentario cargarComentarioRandom();
void cargarTituloPeliculaRandom(char tituloPelicula[]);
void cargarDirectorRandom(char director[]);
void cargarEstudioRandom(char estudio[]);
void cargarCategoriaRandom(char categoria[]);
stPelicula cargarPeliculaRandom(int id);
void cargarPasswordRandom(char password[]);


#endif // MOCK_H_INCLUDED
