#include "mock.h"

const char nombresUsuario [][50] = {
    "Pepito",
    "Jorgito",
    "Cachito",
    "Danielito",
    "Maxito",
    "Agustinito",
    "Manuelito"
};

const char emails[][50] = {
        "usuario1@example.com",
        "usuario2@example.com",
        "usuario3@example.com",
        "usuario4@example.com",
        "usuario5@example.com",
        "usuario6@example.com",
        "usuario7@example.com",
        "usuario8@example.com",
        "usuario9@example.com",
        "usuario10@example.com"
    };

char calles [][50] = {
    "San Martin",
    "Rivadavia",
    "Belgrano",
    "Moreno",
    "Bolivar",
    "25 de mayo",
    "Independencia"
};

void cargarCalleRandom(char calle[]){
    int cantidadElementos = sizeof(calles)/50;

    strcpy(calle, calles[rand()%cantidadElementos]);
}
