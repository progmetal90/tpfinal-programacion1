#include "usuario.h"

void mostrarUsuario(stUsuario usuario){
    printf("Id: %d", usuario.idUsuario);
    if(usuario.esAdmin == 1){
        printf(" [ADMINISTRADOR]");
    }
    printf("\nNombre de usuario: %s\n", usuario.username);
    printf("Email: %s\n", usuario.email);
    printf("Genero: %c\n", usuario.genero);
    printf("Fecha nacimiento: %s\n", usuario.fechaNacimiento);
    printf("DNI: %s\n", usuario.dni);
    mostrarDomicilio(usuario.domicilio);
    // TODO: mostrar peliculas favoritas en un menu distinto?
}

stUsuario cargarUsuario(){
    stUsuario aux;

    int emailValido = 0;
    int contraseniaValida = 0;

    int dia, mes, anio;

    char mail[DIM_EMAIL];
    char contrasenia[DIM_PASSWORD];
    char username[DIM_USERNAME];
    char diaStr[3];
    char mesStr[3];
    char anioStr[5];
    char dni[DIM_DNI];

    char genero;

    char calle[DIM_CALLE];
    char ciudad[DIM_CIUDAD];
    char localidad[DIM_LOCALIDAD];
    char pais[DIM_PAIS];

    int codigoPostal;
    int altura;
    int leido = 0;

    /// INICIAMOS LOS VALIDOS DE PELIS FAVORITAS EN 0
    aux.vFavoritos = 0;

    /// INICIALIZA SU ESTADO COMO ACTIVO
    aux.eliminado = 0;

    // No tiene privilegios de administrador
    aux.esAdmin = 0;

    // Inicializar id en -1. Se le asignara el ID correspondiente al cargar a memoria
    aux.idUsuario = -1;

    printf("Ingrese su email para registrarse (maximo %d caracteres): ", DIM_EMAIL - 1);
    obtenerStringDeUsuario(mail, DIM_EMAIL);
    emailValido = validarEmail(mail);

    while(emailValido == 0){
        printf("\nEl email ingresado es invalido! Intente nuevamente:\n");
        obtenerStringDeUsuario(mail, DIM_EMAIL);
        emailValido = validarEmail(mail);
    }

    strcpy(aux.email, mail);

    system("cls");

    printf("Ingrese su contrasenia (maximo %d caracteres): ", DIM_PASSWORD - 1);
    obtenerStringDeUsuario(contrasenia, DIM_PASSWORD);

    contraseniaValida = validarContrasenia(contrasenia);
    while(contraseniaValida == 0) {
        printf("Contrasenia invalida, por favor prueba con otra: \n");
        obtenerStringDeUsuario(contrasenia, DIM_PASSWORD);
        contraseniaValida = validarContrasenia(contrasenia);
    }
    strcpy(aux.password, contrasenia);

    system("cls");

    do{
        printf("Ingrese un USERNAME (maximo %d caracteres): ", DIM_USERNAME - 1);
        obtenerStringDeUsuario(username, DIM_USERNAME);

        if (strlen(username) >= DIM_USERNAME - 1) {
            printf("El username ingresado es invalido.Ingrese nuevamente (maximo %d caracteres): ", DIM_USERNAME - 1);
        }

    } while (strlen(username) >= DIM_USERNAME - 1);

    strcpy(aux.username, username);

    system("cls");

    do{
        printf("Ingrese su genero (M / F / X): ");
        fflush(stdin);
        scanf("%c", &genero); // TODO: no usar scanf

        genero = toupper(genero); // TODO: usar minusculas

        // TODO: modularizar validacion de genero, mover a validacion.c
        // deberia quedar: if(esGeneroValido(genero))
        // Tambien estas haciendo lo mismo dos veces, en el if y en el while
        // Usar una variable 0 o 1 para definir si es valido y reutilizarla
        if (genero != 'M' && genero != 'F' && genero != 'X') {
            printf("Opcion invalida. Por favor, ingrese M, F o X.\n");
        }
    }while (genero != 'M' && genero != 'F' && genero != 'X');

    aux.genero = genero;

    system("cls");

    // TODO: para capturar dia/mes/anio usar tambien obtenerStringDeUsuario
    // Validar si es un numero usando atoi
    do{
        printf("Ingrese el dia de nacimiento: \n");
        leido = scanf("%d", &dia); // TODO: no usar scanf

        if (leido != 1) {
        printf("Dia invalido. Por favor, intente nuevamente: \n");
        fflush(stdin);
        }

    }while(dia < 1 || dia > 31);
    // TODO: cambiar logica de validacion de fecha
    // Considerar los meses que tienen 28, 29, 30 o 31 dias

    do{
        printf("Ingrese el mes de nacimiento: \n");
        leido = scanf("%d", &mes); // TODO: no usar scanf

        if (leido != 1) {
        printf("Mes invalido. Por favor, intente nuevamente: \n");
        fflush(stdin);
        }

    }while(mes < 1 || mes > 12);

    do {
        printf("Ingrese el anio de nacimiento: \n");
        leido = scanf("%d", &anio);

        if (leido != 1) {
        printf("Anio invalido. Por favor, intente nuevamente: \n");
        fflush(stdin);
        }

    }while (anio < 1900 || anio > 2023);

    // TODO: refactorear obtener fecha
    // Cambiar los scanf por obtenerStringDeUsuario
    // Si es posible, mover todo lo referido a fecha a fecha.c
    sprintf(diaStr, "%d", dia);
    sprintf(mesStr, "%d", mes);
    sprintf(anioStr, "%d", anio);

    sprintf(aux.fechaNacimiento, "%s %s %s %s %s", diaStr, "/", mesStr, "/", anioStr);

    system("pause");
    system("cls");

    do {

    printf("Ingrese su DNI: \n");
    obtenerStringDeUsuario(dni, DIM_DNI);

    }while(strlen(dni) < 7); // (provisorio) Valida DNIs a partir de 1 millon
    // TODO: validar un DNI por el tamanio de string no es lo ideal
    // Se podria usar atoi para obtener un entero y validar un rango de DNIs

    strcpy(aux.dni, dni);

    system("cls");

    do {
        printf("Ingrese su Domicilio, primero su calle: \n");
        obtenerStringDeUsuario(calle, DIM_CALLE);

    }while(strlen(calle) >= DIM_CALLE - 1);

    strcpy(aux.domicilio.calle, calle);

    system("cls");

    do {
        printf("Ingrese su altura: \n");
        leido = scanf("%d", &altura); // TODO: no usar scanf

        if (leido != 1) {
        printf("Altura invalida. Por favor, intente nuevamente.\n");
        fflush(stdin);
        }

    }while(leido != 1 );

    aux.domicilio.altura = altura;

    system("cls");

    do {
        printf("Ingrese su ciudad: \n");
        obtenerStringDeUsuario(ciudad, DIM_CIUDAD);

    }while(strlen(ciudad) >= DIM_CIUDAD - 1);

    strcpy(aux.domicilio.ciudad, ciudad);

    system("cls");

    do {
        printf("Ingrese su localidad: \n");
        obtenerStringDeUsuario(localidad, DIM_LOCALIDAD);

    }while(strlen(localidad) >= DIM_LOCALIDAD - 1);

    strcpy(aux.domicilio.localidad, localidad);

    system("cls");

    do {
        printf("Ingrese su CP: \n");
        leido = scanf("%d", &codigoPostal); // TODO: no usar scanf

        if (leido != 1) {
        printf("Codigo Postal invalido. Por favor, intente nuevamente.\n");
        fflush(stdin);
        }

    }while(leido != 1 );

    aux.domicilio.cp = codigoPostal;

    system("cls");

    do {
        printf("Ingrese su pais: \n");
        obtenerStringDeUsuario(pais, DIM_PAIS);

    }while(strlen(pais) >= DIM_PAIS - 1);

    strcpy(aux.domicilio.pais, pais);

    printf("Usuario cargado con exito!\n");
    mostrarUsuario(aux);
    system("pause");
    system("cls");
    return aux;
}
