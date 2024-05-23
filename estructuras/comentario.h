#ifndef COMENTARIO_H_INCLUDED
#define COMENTARIO_H_INCLUDED

typedef struct {
    int idComentario;  // unico, autoincremental
    int idPelicula;
    int idUsuario;
    char tituloComentario[100];
    char descripcion[500];
    int puntaje; // de 1 a 5 "estrellas"
    char fechaComentario[20]; // o se puede hacer con dia, mes, anio.
    int eliminado; // 0 si está activo - 1 si está eliminado
}stComentario;

#endif // COMENTARIO_H_INCLUDED
