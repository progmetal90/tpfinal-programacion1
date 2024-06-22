#include "memoria.h"

stMemoria inicializarMemoria(){
    stMemoria memoria;

    // Obtener cantidad de elementos en archivos.
    memoria.vComentarios = obtenerCantidadElementos(NOM_ARCHIVO_COMENTARIOS, sizeof(stComentario));
    memoria.vUsuarios = obtenerCantidadElementos(NOM_ARCHIVO_USUARIOS, sizeof(stUsuario));
    memoria.vPeliculas = obtenerCantidadElementos(NOM_ARCHIVO_PELICULAS, sizeof(stPelicula));

    // Reservar memoria
    memoria.dimComentarios = memoria.vComentarios + INCREMENTO_FIJO;
    memoria.dimUsuarios = memoria.vUsuarios + INCREMENTO_FIJO;
    memoria.dimPeliculas = memoria.vPeliculas + INCREMENTO_FIJO;

    memoria.comentarios = (stComentario *)malloc(sizeof(stComentario) * memoria.dimComentarios);
    memoria.usuarios = (stUsuario *)malloc(sizeof(stUsuario) * memoria.dimUsuarios);
    memoria.peliculas = (stPelicula *)malloc(sizeof(stPelicula) * memoria.dimPeliculas);

    cargarArchivosEnMemoria(&memoria);

    return memoria;
}

int validarMemoria(stMemoria * memoria){
    return (memoria->comentarios && memoria->usuarios && memoria->peliculas);
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
        memoria->dimComentarios *= MULTIPLICADOR_REALLOC;
        memoria->comentarios = (stComentario *)realloc(memoria->comentarios, sizeof(stComentario) * memoria->dimComentarios);
    }

    if(memoria->comentarios){
        comentario.idComentario = memoria->vComentarios;
        memoria->comentarios[memoria->vComentarios] = comentario;
        memoria->vComentarios++;
    }
    else{
        printf(COLOR_ROJO);
        printf("Fallo redimensionando memoria! No se ha guardado el comentario.\n");
        system("pause");
        printf(COLOR_RESET);
    }
}

void agregarUsuario(stMemoria * memoria, stUsuario usuario){
    if(memoria->vUsuarios >= memoria->dimUsuarios){
        memoria->dimUsuarios *= MULTIPLICADOR_REALLOC;
        memoria->usuarios = (stUsuario *)realloc(memoria->usuarios, sizeof(stUsuario) * memoria->dimUsuarios);
    }

    if(memoria->usuarios){
        usuario.idUsuario = memoria->vUsuarios;
        memoria->usuarios[memoria->vUsuarios] = usuario;
        memoria->vUsuarios++;
    }
    else{
        printf(COLOR_ROJO);
        printf("Fallo redimensionando memoria! No se ha guardado el usuario.\n");
        system("pause");
        printf(COLOR_RESET);
    }

}

void agregarPelicula(stMemoria * memoria, stPelicula pelicula){
    if(memoria->vPeliculas >= memoria->dimPeliculas){
        memoria->dimPeliculas *= MULTIPLICADOR_REALLOC;
        memoria->peliculas = (stPelicula *)realloc(memoria->peliculas, sizeof(stPelicula) * memoria->dimPeliculas);
    }

    if(memoria->peliculas){
        pelicula.idPelicula = memoria->vPeliculas;
        memoria->peliculas[memoria->vPeliculas] = pelicula;
        memoria->vPeliculas++;
    }
    else{
        printf(COLOR_ROJO);
        printf("Fallo redimensionando memoria! No se ha guardado la pelicula.\n");
        system("pause");
        printf(COLOR_RESET);
    }
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
    else{
        printf("Error guardando comentarios en disco!\n");
    }

    if(archiUsuarios){
        fwrite(memoria->usuarios, sizeof(stUsuario), memoria->vUsuarios, archiUsuarios);

        fclose(archiUsuarios);
    }
    else{
        printf("Error guardando usuarios en disco!\n");
    }

    if(archiPeliculas){
        fwrite(memoria->peliculas, sizeof(stPelicula), memoria->vPeliculas, archiPeliculas);

        fclose(archiPeliculas);
    }
    else{
        printf("Error guardando comentarios en disco!\n");
    }
}
