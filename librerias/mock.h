/*
* Libreria para generacion de datos y estructuras de prueba
*/

#ifndef MOCK_H_INCLUDED
#define MOCK_H_INCLUDED

#include "../estructuras/usuario.h"
#include "../estructuras/comentario.h"
#include "../estructuras/pelicula.h"

void cargarCalleRandom(char calle[]);
void cargarEmailRandom(char email[]);
stFecha cargarFechaRandom();
stUsuario cargarUsuarioRandom();
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
stPelicula cargarPeliculaRandom();


#endif // MOCK_H_INCLUDED
