#include "memoria.h"

stMemoria inicializarMemoria(){
    stMemoria memoria;

    // Obtener cantidad de elementos en archivos.
    memoria.vComentarios = obtenerCantidadElementos(NOM_ARCHIVO_COMENTARIOS, sizeof(stComentario));
    memoria.vUsuarios = obtenerCantidadElementos(NOM_ARCHIVO_USUARIOS, sizeof(stUsuario));
    memoria.vPeliculas = obtenerCantidadElementos(NOM_ARCHIVO_PELICULAS, sizeof(stPelicula));

    // Reservar memoria
    memoria.dimComentarios = memoria.vComentarios + INCREMENTO_DINAMICO;
    memoria.dimUsuarios = memoria.vUsuarios + INCREMENTO_DINAMICO;
    memoria.dimPeliculas = memoria.vPeliculas + INCREMENTO_DINAMICO;

    memoria.comentarios = (stComentario *)malloc(sizeof(stComentario) * memoria.dimComentarios);
    memoria.usuarios = (stUsuario *)malloc(sizeof(stUsuario) * memoria.dimUsuarios);
    memoria.peliculas = (stPelicula *)malloc(sizeof(stPelicula) * memoria.dimPeliculas);

    cargarArchivosEnMemoria(&memoria);

    return memoria;
}

void cargarArchivosEnMemoria(stMemoria * memoria){
    FILE * archiComentarios = fopen(NOM_ARCHIVO_COMENTARIOS, "rb");
    FILE * archiUsuarios = fopen(NOM_ARCHIVO_USUARIOS, "rb");
    FILE * archiPeliculas = fopen(NOM_ARCHIVO_PELICULAS, "rb");

    if(archiComentarios){
        fread(memoria->comentarios, sizeof(stComentario), memoria->vComentarios, archiComentarios);

        fclose(archiComentarios);
    }

    if(archiUsuarios){
        fread(memoria->usuarios, sizeof(stUsuario), memoria->vUsuarios, archiUsuarios);

        fclose(archiUsuarios);
    }

    if(archiPeliculas){
        fread(memoria->peliculas, sizeof(stPelicula), memoria->vPeliculas, archiPeliculas);

        fclose(archiPeliculas);
    }
}

/// MANEJO DE MEMORIA, INGRESO DE DATOS Y REDIMENSION DE ARRAYS
/*
    Primero se comprueba que haya espacio en memora para alojar la estructura,
    se comparan los validos con la dimension y se redimensiona el arreglo segun corresponda.
    Una funcion por cada estructura.
*/
void agregarComentario(stMemoria * memoria, stComentario comentario){
    if(memoria->vComentarios >= memoria->dimComentarios){
        memoria->dimComentarios += INCREMENTO_DINAMICO;
        memoria->comentarios = (stComentario *)realloc(memoria->comentarios, sizeof(stComentario) * memoria->dimComentarios);
    }

    comentario.idComentario = memoria->vComentarios;
    memoria->comentarios[memoria->vComentarios] = comentario;
    memoria->vComentarios++;
}

void agregarUsuario(stMemoria * memoria, stUsuario usuario){
    if(memoria->vUsuarios >= memoria->dimUsuarios){
        memoria->dimUsuarios += INCREMENTO_DINAMICO;
        memoria->usuarios = (stUsuario *)realloc(memoria->usuarios, sizeof(stUsuario) * memoria->dimUsuarios);
    }

    usuario.idUsuario = memoria->vUsuarios;
    memoria->usuarios[memoria->vUsuarios] = usuario;
    memoria->vUsuarios++;
}

void agregarPelicula(stMemoria * memoria, stPelicula pelicula){
    if(memoria->vPeliculas >= memoria->dimPeliculas){
        memoria->dimPeliculas += INCREMENTO_DINAMICO;
        memoria->peliculas = (stPelicula *)realloc(memoria->peliculas, sizeof(stPelicula) * memoria->dimPeliculas);
    }

    pelicula.idPelicula = memoria->vPeliculas;
    memoria->peliculas[memoria->vPeliculas] = pelicula;
    memoria->vPeliculas++;
}

/// Obtener un dato
stPelicula * obtenerPelicula(stMemoria * memoria, int id){
    stPelicula * pelicula = NULL;

    if(enRango(id, 0, memoria->vPeliculas) == 1){
        pelicula = &memoria->peliculas[id];
    }

    return pelicula;
}

stUsuario * obtenerUsuario(stMemoria * memoria, int id){
    stUsuario * usuario = NULL;

    if(enRango(id, 0, memoria->vUsuarios) == 1){
        usuario = &memoria->usuarios[id];
    }

    return usuario;
}

stComentario * obtenerComentario(stMemoria * memoria, int id){
    stComentario * comentario = NULL;

    if(enRango(id, 0, memoria->vComentarios) == 1){
        comentario = &memoria->comentarios[id];
    }

    return comentario;
}

/// Sobreescribir dato

void sobreescribirPelicula(stMemoria * memoria, stPelicula pelicula){
    memoria->peliculas[pelicula.idPelicula] = pelicula;
}

void sobreescribirUsuario(stMemoria * memoria, stUsuario usuario){
    memoria->usuarios[usuario.idUsuario] = usuario;
}

void sobreescribirComentario(stMemoria * memoria, stComentario comentario){
    memoria->comentarios[comentario.idComentario] = comentario;
}

int obtenerCantidadElementos(char nombreArchivo[], int dimDatos){
    // Funcion generica para contar los elementos de un archivo

    int cantElementos = 0;
    FILE * archi = fopen(nombreArchivo, "rb");

    if(archi){
        fseek(archi, 0, SEEK_END);
        cantElementos = ftell(archi) / dimDatos;
        fclose(archi);
    }
    else{
        printf("No se pudo abrir el archivo %s\n", nombreArchivo);
    }

    return cantElementos;
}

void guardarCambios(stMemoria * memoria){
    FILE * archiComentarios = fopen(NOM_ARCHIVO_COMENTARIOS, "wb");
    FILE * archiUsuarios = fopen(NOM_ARCHIVO_USUARIOS, "wb");
    FILE * archiPeliculas = fopen(NOM_ARCHIVO_PELICULAS, "wb");

    if(archiComentarios){
        fwrite(memoria->comentarios, sizeof(stComentario), memoria->vComentarios, archiComentarios);

        fclose(archiComentarios);
    }

    if(archiUsuarios){
        fwrite(memoria->usuarios, sizeof(stUsuario), memoria->vUsuarios, archiUsuarios);

        fclose(archiUsuarios);
    }

    if(archiPeliculas){
        fwrite(memoria->peliculas, sizeof(stPelicula), memoria->vPeliculas, archiPeliculas);

        fclose(archiPeliculas);
    }
}
