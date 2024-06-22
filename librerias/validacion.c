#include "validacion.h"

const char ARROBA[] = "@";
const char PUNTO[] = ".";
const char PUNTO_COM[] = ".com";

int validarEmail(char email[]){
    // Comprueba que el email proporcionado sea valido
    // Necesita de un solo arroba, y un solo .com.

    // Pasar mail a minuscula
    email = strlwr(email);

    int valido = 0;
    int puntoCom = 0;
    // Comprobar que el mail tenga un ".com"

    char *substring = strstr(email, ARROBA); ///Busca a partir del @.

    while(substring){
    substring = strstr(substring, PUNTO_COM);
        if(!substring){
            printf("\nEl email no contiene \".COM \" .");
            }
            else{
            puntoCom++;
            substring = strstr(substring + 1, PUNTO_COM);
            }
        }
    /// Compara los 2 strings para que no se repitan el ".com" y el '@'
    if(contarCaracterEnString(email, ARROBA) == 1 && puntoCom == 1){
            valido = 1;
    }else{
    printf("\nEl email es invalido.");
    }
    return valido;
}

int contarCaracterEnString(char string[], char caracter){
    int caracterContado = 0;
    int cantDeCaracteres = 0;

    cantDeCaracteres = strlen(string);

    for(int i = 0 ; i < cantDeCaracteres ; i++){
        if(string[i] == caracter){
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
