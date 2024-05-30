#include <stdio.h>
#include "mock.h"

const char directores[][DIM_DIRECTOR] = {
    "Steven Spielberg",
    "Martin Scorsese",
    "Quentin Tarantino",
    "Christopher Nolan",
    "Alfred Hitchcock",
    "Stanley Kubrick",
    "Ridley Scott",
    "James Cameron",
    "Peter Jackson",
    "David Fincher"
};

const char titulosPeliculas[][DIM_TITULO_PELICULA] = {
    "Blade Runner",
    "Matrix",
    "El origen",
    "2001: Una odisea del espacio",
    "Star Wars",
    "Terminator",
    "Interestelar",
    "E.T., el extraterrestre",
    "Jurassic Park",
    "Volver al futuro"
};

const char estudios[][DIM_ESTUDIO] = {
    "Warner Bros",
    "Paramount Pictures",
    "Universal Pictures",
    "20th Century Fox",
    "Columbia Pictures",
    "Walt Disney Pictures",
    "MGM",
    "Lionsgate",
    "Sony Pictures",
    "DreamWorks"
};

const char categorias [][DIM_CATEGORIA] = {
    "Accion",
    "Comedia",
    "Drama",
    "Ciencia ficcion",
    "Terror"
};

const char titulosComentarios[][DIM_TITULO_COMENTARIO] = {
    "Increible final!",
    "Muy aburrida.",
    "Actuacion brillante",
    "Mal guion.",
    "Visuales geniales",
    "Gran banda sonora",
    "Mucha accion",
    "Romantica y dulce",
    "Sorprendente giro",
    "Buena para ninios"
};

const char descripcionComentarios[][DIM_DESCRIPCION_COMENTARIO] = {
    "Una montana rusa de emociones, desde el principio hasta el final. Altamente recomendable!",
    "La trama es predecible, pero los personajes son entranables y bien desarrollados.",
    "Efectos especiales impresionantes que realmente te sumergen en el mundo de la pelicula.",
    "Un guion flojo que deja muchas preguntas sin responder. Esperaba mucho mas.",
    "Actuaciones magistrales que elevan una historia ya de por si poderosa y conmovedora.",
    "Demasiado larga, se podria haber contado la misma historia en una hora menos.",
    "Musica y cinematografia que se combinan perfectamente para crear una experiencia visual unica.",
    "La quimica entre los protagonistas es palpable, lo que hace que la historia de amor sea creible.",
    "Una comedia ligera y divertida, perfecta para desconectar y pasar un buen rato.",
    "Intriga y suspense mantenidos hasta el ultimo minuto. No pude apartar la vista de la pantalla."
};

const char nombresUsuario [][DIM_USERNAME] = {
    "Pepito",
    "Jorgito",
    "Cachito",
    "Danielito",
    "Maxito",
    "Agustinito",
    "Manuelito"
};

const char emails[][DIM_EMAIL] = {
    "juan.perez@gmail.com",
    "maria.gomez@yahoo.com",
    "carlos.fernandez@outlook.com",
    "ana.lopez@icloud.com",
    "luis.martinez@protonmail.com",
    "sofia.garcia@hotmail.com",
    "diego.rodriguez@live.com",
    "lucia.morales@aol.com",
    "julian.sanchez@mail.com",
    "valeria.torres@zoho.com"
    };

char calles [][DIM_CALLE] = {
    "San Martin",
    "Rivadavia",
    "Belgrano",
    "Moreno",
    "Bolivar",
    "25 de mayo",
    "Independencia"
};

char ciudades [][DIM_CIUDAD] = {
    "Mechongue",
    "Mar del Plata",
    "Carlos Paz",
    "Rosario",
    "Necochea",
    "Miramar"
};

char localidades [][DIM_LOCALIDAD] = {
    "Buenos Aires",
    "Cordoba",
    "Santa Fe",
    "Mendoza",
    "San Luis"
};

char paises [][DIM_PAIS] = {
    "Argentina",
    "Chile",
    "Paraguay",
    "Uruguay",
    "Brasil"
};

void cargarCalleRandom(char calle[]){
    int cantidadElementos = sizeof(calles)/DIM_CALLE;

    strcpy(calle, calles[rand()%cantidadElementos]);
}

void cargarEmailRandom(char email[]){
    int cantidadElementos = sizeof(emails)/DIM_EMAIL;

    strcpy(email, emails[rand()%cantidadElementos]);
}

void cargarCiudadRandom(char ciudad[]){
    int cantidadElementos = sizeof(ciudades)/DIM_CIUDAD;

    strcpy(ciudad, ciudades[rand()%cantidadElementos]);
}

void cargarLocalidadRandom(char localidad[]){
    int cantidadElementos = sizeof(localidades)/DIM_LOCALIDAD;

    strcpy(localidad, localidades[rand()%cantidadElementos]);
}

void cargarUsernameRandom(char username[]){
    int cantidadElementos = sizeof(nombresUsuario)/DIM_USERNAME;

    strcpy(username, nombresUsuario[rand()%cantidadElementos]);
}

void cargarPaisRandom(char pais[]){
    int cantidadElementos = sizeof(paises)/DIM_PAIS;

    strcpy(pais, paises[rand()%cantidadElementos]);
}

void cargarTituloComentarioRandom(char tituloComentario[]){
    int cantidadElementos = sizeof(titulosComentarios)/DIM_TITULO_COMENTARIO;

    strcpy(tituloComentario, titulosComentarios[rand()%cantidadElementos]);
}

void cargarDescripcionComentarioRandom(char descripcionComentario[]){
    int cantidadElementos = sizeof(descripcionComentarios)/DIM_DESCRIPCION_COMENTARIO;

    strcpy(descripcionComentario, descripcionComentarios[rand()%cantidadElementos]);
}

void cargarTituloPeliculaRandom(char tituloPelicula[]){
    int cantidadElementos = sizeof(titulosPeliculas)/DIM_TITULO_PELICULA;

    strcpy(tituloPelicula, titulosPeliculas[rand()%cantidadElementos]);
}

void cargarDirectorRandom(char director[]){
    int cantidadElementos = sizeof(directores)/DIM_DIRECTOR;

    strcpy(director, directores[rand()%cantidadElementos]);
}

void cargarEstudioRandom(char estudio[]){
    int cantidadElementos = sizeof(estudios)/DIM_ESTUDIO;

    strcpy(estudio, estudios[rand()%cantidadElementos]);
}

void cargarCategoriaRandom(char categoria[]){
    int cantidadElementos = sizeof(categorias)/DIM_CATEGORIA;

    strcpy(categoria, categorias[rand()%cantidadElementos]);
}

stPelicula cargarPeliculaRandom(){
    stPelicula pelicula;

    pelicula.idPelicula = rand();
    cargarTituloPeliculaRandom(pelicula.titulo);
    cargarDirectorRandom(pelicula.director);
    cargarEstudioRandom(pelicula.estudio);
    cargarCategoriaRandom(pelicula.categoria);
    pelicula.valoracion = (float)(rand()%50+10) / 10;
    pelicula.eliminado = 0;

    return pelicula;
}

stFecha cargarFechaRandom(){
    stFecha fecha;

    fecha.dia = rand()%28+1;
    fecha.mes = rand()%12+1;
    fecha.anio = rand()%105+1900;

    return fecha;
}

stComentario cargarComentarioRandom(){
    stComentario comentario;

    comentario.idComentario = rand();
    comentario.idPelicula = rand();
    comentario.idUsuario= rand();
    cargarTituloComentarioRandom(comentario.titulo);
    cargarDescripcionComentarioRandom(comentario.descripcion);
    comentario.puntaje = rand()%5+1;
    comentario.fechaComentario = cargarFechaRandom();
    comentario.eliminado = 0;

    return comentario;
}

stUsuario cargarUsuarioRandom(){
    stUsuario usuario;

    usuario.idUsuario = rand()%1000;
    cargarEmailRandom(usuario.email);
    cargarUsernameRandom(usuario.username);
    usuario.esAdmin = 0;
    usuario.genero = cargarGeneroRandom();
    usuario.nacimiento = cargarFechaRandom();
    // TODO: cargar pelis favoritas??
    usuario.domicilio = cargarDomicilioRandom();
    cargarDniRandom(usuario.dni);
    usuario.eliminado = 0;

    return usuario;
}

void cargarDniRandom(char dni[]){
    // rand() no genera un numero lo suficientemente grande como para un DNI
    // Se multiplica el numero random para obtener un DNI de 7 u 8 cifras
    int num = rand() * 180+5000000;

    // Almacena el numero como string
    sprintf(dni, "%d", num);
}

char cargarGeneroRandom(){
    char genero;
    int num = rand()%CANT_GENEROS;

    switch(num){
        case 0:
            genero = 'm';
            break;
        case 1:
            genero = 'f';
            break;
        case 2:
            genero = 'x';
            break;
        default:
            genero = 'x';
            break;
    }

    return genero;
}

stDomicilio cargarDomicilioRandom(){
    stDomicilio domicilio;

    cargarCalleRandom(domicilio.calle);
    domicilio.altura = rand()%10000;
    domicilio.cp = rand()%10000;
    cargarCiudadRandom(domicilio.ciudad);
    cargarLocalidadRandom(domicilio.localidad);
    cargarPaisRandom(domicilio.pais);

    return domicilio;
}
