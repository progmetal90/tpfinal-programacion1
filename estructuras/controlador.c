#include "controlador.h"

stControlador inicializarControlador(stMemoria * memoria){
    stControlador controlador;

    controlador.memoria = memoria;
    controlador.usuarioLogueado = NULL;

    return controlador;
}

int ejecutarSubprograma(int subprograma, stControlador * controlador){
    int idProximoMenu = subprograma;
    system("cls");
    switch(subprograma){
        case SP_INICIAR_SESION:
            controlador->usuarioLogueado = iniciarSesion(controlador->memoria);
            break;
        case SP_CREAR_USUARIO:
            spCrearUsuario(controlador->memoria);
            break;
        case SP_AGREGAR_PELICULA:
            spAgregarPelicula(controlador->memoria);
            break;
        case SP_FILTRAR_POR_TITULO:
            spFiltrarPorTitulo(controlador->memoria);
            idProximoMenu = SM_INFO_PELICULA;
            break;
        case SP_FILTRAR_POR_CATEGORIA:
            spFiltrarPorCategoria(controlador->memoria);
            idProximoMenu = SM_INFO_PELICULA;
            break;
        case SP_FILTRAR_POR_DIRECTOR:
            spFiltrarPorDirector(controlador->memoria);
            idProximoMenu = SM_INFO_PELICULA;
            break;
        case SP_AGREGAR_COMENTARIO:
            spAgregarComentario(controlador->memoria, controlador->usuarioLogueado);
            break;
        default:
            // Si llegamos aca nos olvidamos un subprograma o nos mandamos una cagada
            printf("ERROR! Subprograma %d invalido o indefinido!\n", subprograma);
            system("pause");
            break;
    }

    return idProximoMenu;
}

void spAgregarComentario(stMemoria * memoria, stUsuario * usuarioLogueado){
    // TODO: finalizar interfaz para recibir parametros
    //cargarComentario(usuarioLogueado->idUsuario, 0);
}

void spCrearUsuario(stMemoria * memoria){

    char mail[DIM_EMAIL];
    int existe = -1;
    int emailValido = 0;

    do{
        printf("Ingrese su email para registrarse (maximo %d caracteres): ", DIM_EMAIL - 1);
        obtenerStringDeUsuario(mail, DIM_EMAIL);
        emailValido = validarEmail(mail);

    while(emailValido == 0){
        printf("\nEl email ingresado es invalido! Intente nuevamente:\n");
        obtenerStringDeUsuario(mail, DIM_EMAIL);
        emailValido = validarEmail(mail);
    }
    existe = existeEmail(mail, memoria->usuarios, memoria->vUsuarios);

        if(existe != -1) {
            printf("Ya existe un usuario registrado con ese correo. \n");
        }

    }while(existe != -1); // No existe mail en la db

    stUsuario aux = cargarUsuario(mail);

    agregarUsuario(memoria, aux);

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

void spAgregarPelicula (stMemoria * memoria){

    system("cls");

    stPelicula pelicula;
    char titulo[DIM_TITULO_PELICULA];
    int esIgual;
    int i;
    char control = 0;

    //Pedir titulo
    do{
        i = 0;
        esIgual = -1;

        printf("Titulo: ");
        obtenerStringDeUsuario(titulo, DIM_TITULO_PELICULA);

        //Verificar que ese titulo no exista en memoria
        while(i < memoria->vPeliculas && esIgual == -1){
            pelicula = memoria->peliculas[i];
            esIgual = filtrarPeliculaTitulo(pelicula, titulo);

            i++;
        }
        //Si existe se pregunta si quiere salir o seguir cargando
        if(esIgual == 1){
            printf("EL TITULO INGRESADO YA EXISTE\n");
            printf("para salir presione esc");
            fflush(stdin);
            control = getch();

            system("cls");
        }else{
            //Una vez que se cargo un titulo que no existe se sigue con la carga de los demas datos
            pelicula = cargarPelicula(titulo);

            printf("PELICULA CARGADA CON EXITO!\n");

            agregarPelicula(memoria, pelicula);

            system("pause");
        }
    }while(esIgual == 1 && control != 27);
}

void spFiltrarPorTitulo(stMemoria * memoria){

    // Pedirle al usuario el nombre a buscar
    char dato[DIM_TITULO_PELICULA];

    printf("TITULO DE LA PELICULA A BUSCAR: ");
    obtenerStringDeUsuario(dato, DIM_TITULO_PELICULA);

    // Buscar en el arreglo de peliculas
    for(int i = 0; i < memoria->vPeliculas; i++){
        int esIgual = filtrarPeliculaTitulo(memoria->peliculas[i], dato);

        //Si el titulo esa pelicula es igual a lo que se busca
        if(esIgual == 1){
            mostrarPelicula(memoria->peliculas[i]);

            imprimirSaltosDeLinea(2);
            imprimirLineaSeparadora('-', ANCHO_DE_CONSOLA);
        }
    }


    system("pause");
    puts("");
}

void spFiltrarPorDirector(stMemoria * memoria){

    // Pedirle al usuario el nombre a buscar
    char dato[DIM_DIRECTOR];

    printf("DIRECTOR DE LA PELICULA A BUSCAR: ");
    obtenerStringDeUsuario(dato, DIM_DIRECTOR);

    // Buscar en el arreglo de peliculas
    for(int i = 0; i < memoria->vPeliculas; i++){
        int esIgual = filtrarPeliculaDirector(memoria->peliculas[i], dato);

        //Si el titulo esa pelicula es igual a lo que se busca
        if(esIgual == 1){
            mostrarPelicula(memoria->peliculas[i]);

            imprimirSaltosDeLinea(2);
            imprimirLineaSeparadora('-', ANCHO_DE_CONSOLA);
        }
    }


    system("pause");
}

void spFiltrarPorCategoria(stMemoria * memoria){

    // Pedirle al usuario el nombre a buscar
    char dato[DIM_CATEGORIA];

    printf("TITULO DE LA PELICULA A BUSCAR: ");
    obtenerStringDeUsuario(dato, DIM_CATEGORIA);

    // Buscar en el arreglo de peliculas
    for(int i = 0; i < memoria->vPeliculas; i++){
        int esIgual = filtrarPeliculaCategoria(memoria->peliculas[i], dato);

        //Si el titulo esa pelicula es igual a lo que se busca
        if(esIgual == 1){
            mostrarPelicula(memoria->peliculas[i]);

            imprimirSaltosDeLinea(2);
            imprimirLineaSeparadora('-', ANCHO_DE_CONSOLA);
        }
    }


    system("pause");
}
