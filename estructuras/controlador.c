#include "controlador.h"

stControlador inicializarControlador(stMemoria * memoria){
    stControlador controlador;

    controlador.memoria = memoria;
    controlador.usuarioLogueado = NULL;

    return controlador;
}

void ejecutarSubprograma(int subprograma, stControlador * controlador){
    system("cls");
    switch(subprograma){
        case SP_INICIAR_SESION:
            controlador->usuarioLogueado = iniciarSesion(controlador->memoria);
            break;
        case SP_CREAR_USUARIO:
            agregarUsuario(controlador->memoria, cargarUsuario());
            break;
        default:
            // Si llegamos aca nos olvidamos un subprograma o nos mandamos una cagada
            printf("ERROR! Subprograma %d invalido o indefinido!\n", subprograma);
            break;
    }
}
stUsuario cargarUsuario() {

stUsuario aux;

int emailValido = 0;
int contraseniaValida = 0;

int dia, mes, anio;

char mail[DIM_USERNAME];
char contrasenia[DIM_PASSWORD];
char username[DIM_USERNAME];
char fechaNacimiento[DIM_FECHA];
char diaStr[3];
char mesStr[3];
char anioStr[3];
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

    printf("Ingrese su email para registrarse (maximo %d caracteres): ", DIM_USERNAME - 1);
    obtenerStringDeUsuario(mail, DIM_USERNAME);
    emailValido = validarEmail(mail);

    while(emailValido == 0){
        printf("\nEl email ingresado es invalido! Intente nuevamente:\n");
        obtenerStringDeUsuario(mail, DIM_USERNAME);
        emailValido = validarEmail(mail);
    }
    strcpy(aux.email, mail);

    system("pause");
    system("cls");

    printf("Ingrese su contrasenia (maximo %d caracteres): ", DIM_PASSWORD - 1);
    obtenerStringDeUsuario(contrasenia, DIM_USERNAME);

    contraseniaValida = validarContrasenia(contrasenia);
    while(contraseniaValida == 0) {
        printf("Contrasenia invalida, por favor prueba con otra: \n");
        obtenerStringDeUsuario(contrasenia, DIM_USERNAME);
        contraseniaValida = validarContrasenia(contrasenia);
    }
    strcpy(aux.password, contrasenia);

    system("pause");
    system("cls");

    do {
        printf("Ingrese un USERNAME (maximo %d caracteres): ", DIM_USERNAME - 1);
        obtenerStringDeUsuario(username, DIM_USERNAME);

        if (strlen(username) >= DIM_USERNAME - 1) {
            printf("El username ingresado es invalido.Ingrese nuevamente (maximo %d caracteres): ", DIM_USERNAME - 1);
        }

    } while (strlen(username) >= DIM_USERNAME - 1);

    strcpy(aux.username, username);

    system("pause");
    system("cls");

    do {
        printf("Ingrese su genero (M / F / X): ");
        fflush(stdin);
        scanf(" %c", &genero);

        genero = toupper(genero);

        if (genero != 'M' && genero != 'F' && genero != 'X') {
            printf("Opcion invalida. Por favor, ingrese M, F o X.\n");

        }
    } while (genero != 'M' && genero != 'F' && genero != 'X');

    aux.genero = genero;

    system("pause");
    system("cls");

    do {
    printf("Ingrese el dia de nacimiento: \n");
    leido = scanf("%d",&dia);

        if (leido != 1) {
        printf("Dia invalido. Por favor, intente nuevamente: \n");
        fflush(stdin);
        }

    }while(dia < 1 || dia > 31);

    do {
    printf("Ingrese el mes de nacimiento: \n");
    leido = scanf("%d",&mes);

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

    sprintf(diaStr, "%d", dia);
    sprintf(mesStr, "%d", mes);
    sprintf(anioStr, "%d", anio);

    sprintf(aux.fechaNacimiento, "%s %s %s %s %s", diaStr, "/", mesStr, "/", anioStr);

    system("pause");
    system("cls");

    do {

    printf("Ingrese su DNI: \n");
    obtenerStringDeUsuario(dni, DIM_DNI);

    }while(strlen(dni) < 8);

    strcpy(aux.dni, dni);

    system("pause");
    system("cls");

    do {
        printf("Ingrese su Domicilio, primero su calle: \n");
        obtenerStringDeUsuario(calle, DIM_CALLE);

    }while(strlen(calle) >= DIM_USERNAME - 1);

    strcpy(aux.domicilio.calle, calle);

    system("pause");
    system("cls");

    do {
        printf("Ingrese su altura: \n");
        leido = scanf("%d", &altura);

        if (leido != 1) {
        printf("Altura invalida. Por favor, intente nuevamente.\n");
        fflush(stdin);
        }

    }while(leido != 1 );

    aux.domicilio.altura = altura;

    system("pause");
    system("cls");

    do {
        printf("Ingrese su ciudad: \n");
        obtenerStringDeUsuario(ciudad, DIM_CIUDAD);

    }while(strlen(ciudad) >= DIM_CIUDAD - 1);

    strcpy(aux.domicilio.ciudad, ciudad);

    system("pause");
    system("cls");

    do {
        printf("Ingrese su localidad: \n");
        obtenerStringDeUsuario(localidad, DIM_LOCALIDAD);

    }while(strlen(localidad) >= DIM_LOCALIDAD - 1);

    strcpy(aux.domicilio.localidad, localidad);

    system("pause");
    system("cls");

    do {
        printf("Ingrese su CP: \n");
        leido = scanf("%d", &codigoPostal);

        if (leido != 1) {
        printf("Codigo Postal invalido. Por favor, intente nuevamente.\n");
        fflush(stdin);
        }

    }while(leido != 1 );

    aux.domicilio.cp = codigoPostal;

    system("pause");
    system("cls");

    do {
        printf("Ingrese su pais: \n");
        obtenerStringDeUsuario(pais, DIM_PAIS);

    }while(strlen(pais) >= DIM_PAIS - 1);

    strcpy(aux.domicilio.pais, pais);

    system("pause");
    system("cls");

    return aux;

}




stUsuario * iniciarSesion(stMemoria * memoria){
    stUsuario * usuarioLogueado = NULL;
    char email[DIM_USERNAME];
    char contrasenia[DIM_PASSWORD];
    int emailValido = 0;
    int contraseniaValida = 0;
    int idUsuario = -1;

    system("cls");
    // 1. Recibir mail del usuario
    printf("Ingrese su email (maximo %d caracteres): ", DIM_USERNAME - 1);
    obtenerStringDeUsuario(email, DIM_USERNAME);

    // Comprobar que el mail sea valido en formato
    emailValido = validarEmail(email);

    // Comprobar si el mail existe
    if(emailValido == 0){
        printf("El email ingresado es invalido! Intente nuevamente.\n");
        system("pause");
    }
    else{
        idUsuario = existeEmail(email, memoria->usuarios, memoria->vUsuarios);

        // 2. Recibir contrasenia
        printf("Ingrese su contrasenia (maximo %d caracteres): ", DIM_PASSWORD - 1);
        obtenerStringDeUsuario(contrasenia, DIM_USERNAME);

        // Comprobar que la contrasenia sea valida en formato
        contraseniaValida = validarContrasenia(contrasenia);

        // Si todo esto es correcto y las credenciales son correctas,
        // buscar en arreglo de usuarios y devolver el puntero al usuario logueado.
        if(idUsuario != -1 && contraseniaValida == 1 && strcmp(memoria->usuarios[idUsuario].password, contrasenia) == 0){
            usuarioLogueado = &memoria->usuarios[idUsuario];

            printf("Sesion iniciada correctamente. Bienvenido, %s!\n", usuarioLogueado->username);
        }
        else{
            printf("Alguno de los datos ingresados es incorrecto! Intente nuevamente.\n");
        }
        system("pause");
    }

    // TODO: agregar funcion para salir del subprograma
    return usuarioLogueado;
}

int existeEmail(char * email, stUsuario * usuarios, int vUsuarios){
    int existeMail = -1; // -1 si no existe, sino devuelve la posicion/id del usuario

    for(int i = 0; i < vUsuarios && existeMail == -1; i++){
        if(strcmpi(usuarios[i].email, email) == 0){
            existeMail = i;
        }
    }

    return existeMail;
}

void obtenerStringDeUsuario(char * buffer, int dimBuffer){
    fflush(stdin);
    fgets(buffer, dimBuffer, stdin);

    // TODO: esto es una chanchada para quitar el salto de linea de fgets
    // Preguntar como mejorar esto

    int encontrado = 0;
    for(int i = dimBuffer; i >= 0 && encontrado == 0; i--){
        if(buffer[i] == 10){
            buffer[i] = 0;
            encontrado = 1;
        }
    }
}

void obtenerOpcion(int * opcion){
    // TODO: sanitizar input
    // Esta entrada de momento solo puede recibir numeros. Cosas MALAS pasaran si recibe cualquier otra cosa.

    // Considerar si scanf es suficiente o si es necesario usar otra forma para capturar input.
    // Un combo de gets() y atoi por ahi es mas versatil
    // Se podria recibir tanto strings como numeros, pero tambien complicaria las cosas
    scanf("%d", opcion);
}
