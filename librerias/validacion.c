#include "validacion.h"

const char ARROBA = '@';
const char PUNTO_COM[] = ".com";

int validarEmail(char email[]){
    // Comprueba que el email proporcionado sea valido
    // Necesita de un solo arroba, y un solo .com.

    // Pasar mail a minuscula
    email = strlwr(email);

    int valido = 0;
    // Comprobar que el mail tenga un ".com"
    char * substring = strstr(email, PUNTO_COM);

    if(substring != NULL){
        /// Compara los 2 strings para que no se repitan el ".com" y el '@'
        if(contarCaracterEnString(email, ARROBA) == 1 && strcmpi(substring, PUNTO_COM) == 0){
            valido = 1;
        }
    }
    return valido;
}

int contarCaracterEnString(char string[], char caracter){
    int caracterContado = 0;
    int cantDeCaracteres = 0;

    cantDeCaracteres = strlen(string);

    for(int i = 0 ; i < cantDeCaracteres ; i++){
        if(string[i] == ARROBA){
            caracterContado++;}
    }

    return caracterContado;
}

int validarContrasenia(char contrasenia[]){
    // Comprueba que la contrasenia proporcionada sea valida
    // Necesita al menos una mayuscula y una minuscula

    int cantDeCaracteres = strlen(contrasenia);
    int tieneMayusc = 0;
    int tieneMinusc = 0;
    int valido = 0;

    for(int i = 0; i < cantDeCaracteres; i++){
        if(isupper(contrasenia[i]) > 0){
            tieneMayusc = 1;
        }else if(islower(contrasenia [i]) > 0){
            tieneMinusc = 1;
        }
    }

    if(tieneMayusc == 1 && tieneMinusc == 1){
        valido = 1;
    }

    return valido;
}

int enRango(int valor, int min, int max){
    int estaEnRango = 0;

    if(valor >= min && valor < max){ // Incluye minimo, excluye maximo
        estaEnRango = 1;
    }

    return estaEnRango;
}

int validarGenero(char genero) {
    int esValido = 0;

    genero = tolower(genero);

    if (genero == 'm' || genero == 'f' || genero == 'x') {
        esValido = 1;
    }

    return esValido;
}

int esBisiesto(int anio) {
    int esBisiesto = 0;

    if(anio % 4 == 0) {
        esBisiesto = 1;
    }

    return esBisiesto;
}

int validarfecha(int dia, int mes, int anio) {
    int fechaValida = 0;

    if (mes < 1 || mes > 12) {
        fechaValida = 0;
    }

    int bisiesto = esBisiesto(anio);

    int diasPorMes[12][2] = {
        {31, 31},
        {28, 29},
        {31, 31},
        {30, 30},
        {31, 31},
        {30, 30},
        {31, 31},
        {31, 31},
        {30, 30},
        {31, 31},
        {30, 30},
        {31, 31}
    };

    if (dia >= 1 && dia <= diasPorMes[mes - 1][bisiesto]) {
        fechaValida = 1;
    }

    if(anio > 2023 || anio < 1920) { // TODO: Usar anio actual
        fechaValida = 0;
    }

    return fechaValida;
}





