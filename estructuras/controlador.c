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
    switch(subprograma){//
        case SP_INICIAR_SESION:
            controlador->usuarioLogueado = iniciarSesion(controlador->memoria);
            break;
        case SP_CREAR_USUARIO:
            spCrearUsuario(controlador->memoria);
            break;
        case SP_MODIFICAR_USUARIO:
            spModificarUsuario(controlador->memoria, controlador->usuarioLogueado);
            break;
        case SP_VER_USUARIOS:
            spVerUsuarios(controlador->memoria);
            break;
        case SP_ELIMINAR_USUARIO:
            spEliminarUsuario(controlador->memoria);
            break;
        case SP_AGREGAR_PELICULA:
            spAgregarPelicula(controlador->memoria);
            break;
        case SP_FILTRAR_POR_TITULO:
            spFiltrarPorTitulo(controlador->memoria, controlador->usuarioLogueado->esAdmin);
            idProximoMenu = SM_INFO_PELICULA;
            break;
        case SP_FILTRAR_POR_CATEGORIA:
            spFiltrarPorCategoria(controlador->memoria, controlador->usuarioLogueado->esAdmin);
            idProximoMenu = SM_INFO_PELICULA;
            break;
        case SP_FILTRAR_POR_DIRECTOR:
            spFiltrarPorDirector(controlador->memoria, controlador->usuarioLogueado->esAdmin);
            idProximoMenu = SM_INFO_PELICULA;
            break;
        case SP_AGREGAR_COMENTARIO:
            spAgregarComentario(controlador->memoria, controlador->usuarioLogueado->idUsuario);
            break;
        case SP_MODIFICAR_INFO_PELICULA:
            spModificarInfoPelicula(controlador->memoria);
            break;
        case SP_MOSTRAR_COMENTARIOS:
            spMostrarComentarios(controlador->memoria);
            break;
        case SP_MODIFICAR_COMENTARIO:
            spModificarComentario(controlador->memoria, controlador->usuarioLogueado->idUsuario);
            break;
        case SP_QUITAR_COMENTARIO:
            spQuitarComentario(controlador->memoria, controlador->usuarioLogueado->idUsuario);
            break;
        case SP_ELIMINAR_PELICULA:
            spEliminarPelicula(controlador->memoria);
            break;
        case SP_BAJA_PELICULA:
            spDarDeBajaPelicula(controlador->memoria);
            break;
        case SP_ELIMINAR_COMENTARIO:
            spEliminarComentario(controlador->memoria);
            break;
        default:
            // Si llegamos aca nos olvidamos un subprograma o nos mandamos una cagada
            printf("ERROR! Subprograma %d invalido o indefinido!\n", subprograma);
            system("pause");
            break;
    }

    return idProximoMenu;
}

void spEliminarComentario(stMemoria * memoria){
    char opcion;
    int idComentario;
    stComentario * comentario;

    do{
        printf("Ingrese el ID de comentario a borrar: \n");
        scanf("%d", &idComentario);

        comentario = obtenerComentario(memoria, idComentario);

        if(!comentario){
            printf("ID de comentario #%d invalido. ", idComentario);
            printf("Intente nuevamente o presione ESC para salir.");
            opcion = getch();
            system("cls");
        }
    }while(opcion != 27 && !comentario);

    system("cls");

    mostrarComentario(*comentario);

    printf("Desea eliminar el comentario? ");
    printf("Presione ENTER para confirmar, o una tecla cualquiera para cancelar.\n");
    opcion = getch();
    imprimirSaltosDeLinea(1);

    if(opcion == 13){
        comentario->eliminado = 1;
        recalcularValoracion(memoria, comentario->idPelicula);

        printf("\nComentario eliminado exitosamente!\n");
        system("pause");
    }
}

void recalcularValoracion(stMemoria * memoria, int idPelicula){
    int sumaPuntajes = 0;
    int cantPuntajes = 0;

    for(int i = 0; i < memoria->vComentarios; i++){
        stComentario comentario = memoria->comentarios[i];
        if(comentario.idPelicula == idPelicula && comentario.eliminado == 0){
            sumaPuntajes += comentario.puntaje;
            cantPuntajes++;
        }
    }

    if(cantPuntajes == 0){
        memoria->peliculas[idPelicula].valoracion = 0.0;
    }
    else{
        memoria->peliculas[idPelicula].valoracion = (float)sumaPuntajes / cantPuntajes;
    }
}

void eliminarComentariosDePelicula(stMemoria * memoria, int idPelicula){
    for(int i = 0; i < memoria->vComentarios; i++){
        if(memoria->comentarios[i].idPelicula == idPelicula){
            memoria->comentarios[i].eliminado = 1;
        }
    }

    memoria->peliculas[idPelicula].valoracion = 0;
}

int obtenerIdComentarioDeUsuario(stComentario * comentarios, int validos, int idPelicula, int idUsuario){
    int id = -1;
    // Devuelve -1 si el usuario no posee comentario en la pelicula
    // Si existe, devuelve la id del comentario.

    for(int i = 0; i < validos && id == -1; i++){
        stComentario comentario = comentarios[i];
        if(comentario.idUsuario == idUsuario && comentario.idPelicula == idPelicula){
            id = comentario.idComentario;
        }
    }

    return id;
}

void spModificarComentario(stMemoria * memoria, int idUsuario){
    int idPelicula;
    char nombrePelicula[DIM_TITULO_PELICULA];
    char opcion = 0;
    stPelicula * peliculaP;
    int idComentario;

    do{
        system("cls");
        printf("Ingrese el nombre de la pelicula para modificar un comentario: ");
        obtenerStringDeUsuario(nombrePelicula, DIM_TITULO_PELICULA);

        idPelicula = existePelicula(nombrePelicula, memoria->peliculas, memoria->vPeliculas);

        if(idPelicula == -1){
            printf("La pelicula ingresada no existe. ");
            printf("Intente nuevamente o presione ESC para salir.\n\n");
            fflush(stdin);
            opcion = getch();
        }
        else{
            idComentario = -1;
            peliculaP = obtenerPelicula(memoria, idPelicula);
            // Comprobar que el usuario tenga un comentario en esa pelicula
            idComentario = obtenerIdComentarioDeUsuario(memoria->comentarios, memoria->vComentarios, idPelicula, idUsuario);

            if(idComentario == -1 || memoria->comentarios[idComentario].eliminado == 1){
                printf("Usted no tiene comentarios en la pelicula '%s'.\n", peliculaP->titulo);
                printf("Presione ESC para salir o una tecla cualquiera para intentar otra vez.\n");
                fflush(stdin);
                opcion = getch();
            }
            else{
                printf("Quiere modificar su comentario de la pelicula '%s'?\n", peliculaP->titulo);
                printf("Presione ENTER para confirmar o ESC para cancelar.");
                fflush(stdin);
                opcion = getch();
                if(opcion == 13){
                    stComentario * comentario = obtenerComentario(memoria, idComentario);

                    stComentario comentarioModificado = modificarComentario(*comentario);
                    sobreescribirComentario(memoria, comentarioModificado);

                    // Solo recalcular puntaje si se modifico el mismo
                    if(comentarioModificado.puntaje != comentario->puntaje){
                        recalcularValoracion(memoria, idPelicula);
                    }

                    printf("\nComentario modificado exitosamente!\n");
                    system("pause");
                }
                opcion = 27; // Salir
            }
        }
    }while((idPelicula == -1 || idComentario == -1) && opcion != 27);
}

void spQuitarComentario(stMemoria * memoria, int idUsuario){
    int idPelicula;
    char nombrePelicula[DIM_TITULO_PELICULA];
    char opcion = 0;
    stPelicula * aux;
    int idComentario;

    do{
        system("cls");
        printf("Ingrese el nombre de la pelicula para quitar un comentario: ");
        obtenerStringDeUsuario(nombrePelicula, DIM_TITULO_PELICULA);

        idPelicula = existePelicula(nombrePelicula, memoria->peliculas, memoria->vPeliculas);

        if(idPelicula == -1){
            printf("La pelicula ingresada no existe. ");
            printf("Intente nuevamente o presione ESC para salir.\n\n");
            fflush(stdin);
            opcion = getch();
        }
        else{
            idComentario = -1;
            aux = obtenerPelicula(memoria, idPelicula);
            // Comprobar que el usuario tenga un comentario en esa pelicula
            idComentario = obtenerIdComentarioDeUsuario(memoria->comentarios, memoria->vComentarios, idPelicula, idUsuario);

            if(idComentario == -1 || memoria->comentarios[idComentario].eliminado == 1){
                printf("Usted no tiene comentarios en la pelicula '%s'.\n", aux->titulo);
                printf("Presione ESC para salir o una tecla cualquiera para intentar otra vez.\n");
                fflush(stdin);
                opcion = getch();
            }
            else{
                printf("Quiere eliminar su comentario de la pelicula '%s'?\n", aux->titulo);
                printf("Presione ENTER para confirmar o ESC para cancelar.");
                fflush(stdin);
                opcion = getch();
                if(opcion == 13){
                    memoria->comentarios[idComentario].eliminado = 1;
                    recalcularValoracion(memoria, idPelicula);

                    printf("\nComentario eliminado exitosamente!\n");
                    system("pause");
                }
                opcion = 27; // Salir
            }
        }
    }while((idPelicula == -1 || idComentario == -1) && opcion != 27);
}

void spMostrarComentarios(stMemoria * memoria){
    int idPelicula;
    char nombrePelicula[DIM_TITULO_PELICULA];
    char opcion = 0;
    stPelicula * aux;

    do{
        system("cls");
        printf("Ingrese el nombre de la pelicula para ver los comentario: ");
        obtenerStringDeUsuario(nombrePelicula, DIM_TITULO_PELICULA);

        idPelicula = existePelicula(nombrePelicula, memoria->peliculas, memoria->vPeliculas);

        if(idPelicula == -1){
            printf("La pelicula ingresada no existe. ");
            printf("Intente nuevamente o presione ESC para salir.\n\n");
            fflush(stdin);
            opcion = getch();
        }
        else{
            aux = obtenerPelicula(memoria, idPelicula);
            printf("Quiere ver los comentarios de la pelicula '%s'?\n", aux->titulo);
            printf("Presione ENTER para confirmar, ESC para salir u otra tecla para reintentar.");
            fflush(stdin);
            opcion = getch();
            if(opcion != 13){
                idPelicula = -1;
            }
        }
    }while(idPelicula == -1 && opcion != 27 && opcion != 13);

    system("cls");

    if(idPelicula != -1){
        // Mostrar comentarios
        int comentariosMostrados = 0;
        char tituloBusqueda[] = "Comentarios de pelicula: ";
        printf("%s%s\n", tituloBusqueda, aux->titulo);
        imprimirLineaSeparadora(SEPARADOR_ESTRUCTURAS, strlen(tituloBusqueda) + strlen(aux->titulo));
        imprimirSaltosDeLinea(1);

        for(int i = 0; i < memoria->vComentarios; i++){
            stComentario comentario = memoria->comentarios[i];
            if(comentario.eliminado != 1){
                mostrarComentario(comentario);
                imprimirSaltosDeLinea(1);
                imprimirLineaSeparadora(SEPARADOR_ESTRUCTURAS, ANCHO_DE_CONSOLA);
                imprimirSaltosDeLinea(1);
                comentariosMostrados++;
            }
        }

        if(comentariosMostrados == 0){
            printf("No se encontraron comentarios.\n\n");
        }
    }
    system("pause");
}

int existeComentarioDeUsuario(stMemoria * memoria, int idPelicula, int idUsuario){
    int existeComentario = -1; // 0 si no existe, sino devuelve la posicion/id del usuario

    for(int i = 0; i < memoria->vComentarios && existeComentario == -1; i++){
        stComentario comentario = memoria->comentarios[i];
        if(comentario.idPelicula == idPelicula && comentario.idUsuario == idUsuario){
            existeComentario= i;
        }
    }

    return existeComentario;
}

void spAgregarComentario(stMemoria * memoria, int idUsuario){
    int idPelicula;
    char nombrePelicula[DIM_TITULO_PELICULA];
    char opcion = 0;
    stComentario comentario;
    int existeComentario;

    do{
        system("cls");
        printf("Ingrese el nombre de la pelicula para agregar un comentario: ");
        obtenerStringDeUsuario(nombrePelicula, DIM_TITULO_PELICULA);

        idPelicula = existePelicula(nombrePelicula, memoria->peliculas, memoria->vPeliculas);

        if(idPelicula == -1){
            printf("La pelicula ingresada no existe. ");
            printf("Intente nuevamente o presione ESC para salir.");
            fflush(stdin);
            opcion = getch();
            if(opcion != 27){
                opcion = 0;
            }
        }
        else{
            stPelicula * aux = obtenerPelicula(memoria, idPelicula);
            existeComentario = existeComentarioDeUsuario(memoria, idPelicula, idUsuario);

            if(existeComentario == -1){
                printf("Quiere comentar la pelicula '%s'?\n", aux->titulo);
                printf("Presione ENTER para confirmar, ESC para salir u otra tecla para reintentar.");
                fflush(stdin);
                opcion = getch();
                if(opcion != 13){
                    idPelicula = -1;
                }
            }
            else{
                printf("Usted ya comento la pelicula '%s'.\n", aux->titulo);
                system("pause");
            }
        }
    }while(idPelicula == -1 && opcion != 27 && opcion != 13);

    system("cls");

    if(idPelicula != -1 && existeComentario == -1){
        comentario = cargarComentario(idUsuario, idPelicula);

        agregarComentario(memoria, comentario);
        recalcularValoracion(memoria, idPelicula);

        printf("Comentario cargado con exito!\n");
        system("pause");
    }
}

void spModificarUsuario(stMemoria * memoria, stUsuario * usuario) {

    stUsuario aux = *usuario;

    aux = modificarUsuario (aux);

    *usuario = aux;
}

void spEliminarUsuario(stMemoria * memoria) {

    char mail[DIM_EMAIL];
    int existeMail;

    printf("Ingrese el mail para buscar el usuario a eliminar: ");
    obtenerStringDeUsuario(mail, DIM_EMAIL);

    existeMail = existeEmail(mail, memoria->usuarios, memoria->vUsuarios);

    if(existeMail != -1) {

        stUsuario aux = memoria->usuarios[existeMail];

        if(aux.idUsuario == 0) {
            printf("No se puede bloquear al usuario admin (ID 0).\n");
        }
        else{
            printf("Desea bloquear al usuario ID %d?\n", aux.idUsuario);
            system("pause");

            if (aux.eliminado == 1) {
                printf("El usuario ya se encuentra bloqueado en el sistema.\n");
            }
            else {
                aux.eliminado = 1;
                sobreescribirUsuario(memoria, aux);
                printf("Usuario bloqueado exitosamente. \n");
            }
        }
    }
    else{
        printf("No existe el mail %s en la base de datos.\n", mail);
    }

    system("pause");
}

void spVerUsuarios(stMemoria * memoria) {

int vUsuarios =  memoria->vUsuarios;

    for(int i = 0 ; i < vUsuarios ; i++) {
        mostrarUsuario(memoria->usuarios[i]);
        imprimirLineaSeparadora(SEPARADOR_ESTRUCTURAS, ANCHO_DE_CONSOLA);
        if ((i + 1) % 3 == 0 || i == vUsuarios - 1) {
            system("pause");
            system("cls");
        }
    }
}

void spCrearUsuario(stMemoria * memoria){

    char mail[DIM_EMAIL];
    int existe = 0;
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
    stUsuario * aux;
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
        aux = obtenerUsuario(memoria, idUsuario);

        if(aux){
            // Comprobar si esta bloqueado
            if(aux->eliminado == 1) {
                printf("Este usuario se encuentra bloqueado en el sistema.\n");
                system("pause");
            }
            else {
                // 2. Recibir contrasenia
                printf("Ingrese su contrasenia (maximo %d caracteres): ", DIM_PASSWORD - 1);
                obtenerStringDeUsuario(contrasenia, DIM_USERNAME);

                // Comprobar que la contrasenia sea valida en formato
                contraseniaValida = validarContrasenia(contrasenia);


                // Si todo esto es correcto y las credenciales son correctas,
                // buscar en arreglo de usuarios y devolver el puntero al usuario logueado.
                if(idUsuario != -1 && contraseniaValida == 1 && strcmp(aux->password, contrasenia) == 0){
                    usuarioLogueado = aux;

                    printf("Sesion iniciada correctamente. Bienvenido, %s!\n", usuarioLogueado->username);
                }
                else{
                    printf("Alguno de los datos ingresados es incorrecto! Intente nuevamente.\n");
                }
                system("pause");
            }
        }
        else{
            printf("Alguno de los datos ingresados es incorrecto! Intente nuevamente.\n");
        }
    }

    // TODO: agregar funcion para salir del subprograma
    return usuarioLogueado;
}

int existeEmail(char * email, stUsuario * usuarios, int vUsuarios){
    int existeMail = -1; // 0 si no existe, sino devuelve la posicion/id del usuario

    for(int i = 0; i < vUsuarios && existeMail == -1; i++){
        if(strcmpi(usuarios[i].email, email) == 0){
            existeMail = i;
        }
    }

    return existeMail;
}

int existePelicula(char * nombrePelicula, stPelicula * peliculas, int validos){
    int existe = 0;
    int i;
    stPelicula pelicula;

    //Verificar que ese titulo no exista en memoria
    for(i = 0; i < validos && existe == 0; i++){
        pelicula = peliculas[i];
        existe = filtrarPeliculaTitulo(pelicula, nombrePelicula);
    }

    if(existe){
        existe = i - 1; // Devuelve id de pelicula, o -1 si no existe
    }
    else{
        existe = -1;
    }

    return existe;
}

void spAgregarPelicula(stMemoria * memoria){
    system("cls");

    stPelicula pelicula;
    char titulo[DIM_TITULO_PELICULA];
    int esIgual;
    char control = 0;

    //Pedir titulo
    do{
        printf("Titulo: ");
        obtenerStringDeUsuario(titulo, DIM_TITULO_PELICULA);

        esIgual = existePelicula(titulo, memoria->peliculas, memoria->vPeliculas);

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

            agregarPelicula(memoria, pelicula);

            printf("PELICULA CARGADA CON EXITO!\n");

            system("pause");
        }
    }while(esIgual == 1 && control != 27);
}

void spFiltrarPorTitulo(stMemoria * memoria, int esAdmin){

    stPelicula aux;
    char dato[DIM_TITULO_PELICULA];
    int esIgual;
    int encontroAlgo = 0;

    // Pedirle al usuario el nombre a buscar
    printf("TITULO DE LA PELICULA A BUSCAR: ");
    obtenerStringDeUsuario(dato, DIM_TITULO_PELICULA);

    // Buscar en el arreglo de peliculas
    for(int i = 0; i < memoria->vPeliculas; i++){
        aux = memoria->peliculas[i];
        esIgual = filtrarPeliculaTitulo(aux, dato);

        //Si el titulo esa pelicula es igual a lo que se busca
        if(esIgual == 1){
            if(aux.eliminado == 0 || esAdmin == 1){
                encontroAlgo = 1;
                mostrarPelicula(memoria->peliculas[i]);
                //Si es admin mostramos en que estado esta esa pelicula
                if(esAdmin){
                    printf("ELIMINADO: %d\n", aux.eliminado);
                }
                imprimirSaltosDeLinea(2);
                imprimirLineaSeparadora('-', ANCHO_DE_CONSOLA);
            }
        }
    }
    if(!encontroAlgo){
        printf("%s NO SE ENCUENTRA EN EL SISTEMA\n", dato);
    }

    system("pause");
    puts("");
}

void spFiltrarPorDirector(stMemoria * memoria, int esAdmin){

    stPelicula aux;
    char dato[DIM_DIRECTOR];
    int esIgual;
    int encontroAlgo = 0;

    // Pedirle al usuario el nombre a buscar
    printf("DIRECTOR DE LA PELICULA A BUSCAR: ");
    obtenerStringDeUsuario(dato, DIM_DIRECTOR);

    // Buscar en el arreglo de peliculas
    for(int i = 0; i < memoria->vPeliculas; i++){
        aux = memoria->peliculas[i];
        esIgual = filtrarPeliculaDirector(aux, dato);

        //Si el titulo esa pelicula es igual a lo que se busca
        if(esIgual == 1){
            if(aux.eliminado == 0 || esAdmin == 1){
                encontroAlgo = 1;

                mostrarPelicula(memoria->peliculas[i]);
                //Si es admin mostramos en que estado esta esa pelicula
                if(esAdmin){
                    printf("ELIMINADO: %d\n", aux.eliminado);
                }
                imprimirSaltosDeLinea(2);
                imprimirLineaSeparadora('-', ANCHO_DE_CONSOLA);
            }
        }
    }
    if(!encontroAlgo){
        printf("%s NO SE ENCUENTRA EN EL SISTEMA\n", dato);
    }

    system("pause");
}

void spFiltrarPorCategoria(stMemoria * memoria, int esAdmin){

    stPelicula aux;
    char dato[DIM_CATEGORIA];
    int esIgual;
    int encotroAlgo = 0;

    // Pedirle al usuario el nombre a buscar
    printf("CATEGORIA DE LA PELICULA A BUSCAR: ");
    obtenerStringDeUsuario(dato, DIM_CATEGORIA);


    // Buscar en el arreglo de peliculas
    for(int i = 0; i < memoria->vPeliculas; i++){
        aux = memoria->peliculas[i];
        esIgual = filtrarPeliculaCategoria(aux, dato);

        //Si el titulo esa pelicula es igual a lo que se busca
        if(esIgual == 1){
            if(aux.eliminado == 0 || esAdmin == 1){
                encotroAlgo = 1;
                mostrarPelicula(memoria->peliculas[i]);
                //Si es admin mostramos en que estado esta esa pelicula
                if(esAdmin){
                    printf("ELIMINADO: %d\n", aux.eliminado);
                }
                imprimirSaltosDeLinea(2);
                imprimirLineaSeparadora('=', ANCHO_DE_CONSOLA);
            }
        }
    }

    if(encotroAlgo == 0){
        printf("%s NO SE ENCUENTRA EN EL SISTEMA\n", dato);
    }

    system("pause");
}

void spModificarInfoPelicula (stMemoria * memoria){

    char tituloPelicula[DIM_TITULO_PELICULA];
    int existe;
    int i = 0;
    stPelicula pelicula;

    //Se pide el titulo a buscar
    printf("INGRESE EL TITULO DE LA PELICULA QUE DESEA MODIFICAR:");
    obtenerStringDeUsuario(tituloPelicula, DIM_TITULO_PELICULA);

    //Se verifica su existencia
    while(existe == 0 && i < memoria->vPeliculas){
        existe = filtrarPeliculaTitulo(memoria->peliculas[i], tituloPelicula);
        if(existe == 0){
            i++;
        }
    }

    //Si existe se copia a la variable pelicula
    if(existe == 1){
        pelicula = memoria->peliculas[i];
        //Si esta eliminada aca termina la funcion
        if(pelicula.eliminado == 1 || pelicula.eliminado == 2){
            printf("%s Se encuentra eliminada del sistema", pelicula.titulo);
            imprimirSaltosDeLinea(2);
            system("pause");
            system("cls");
        }else{
            //Se llama a la funcion de modificar y se muestra
            pelicula = modificarInfoPelicula(pelicula);

            sobreescribirPelicula(memoria, pelicula);

            printf("\nSE MODIFICO CON EXITO!\n");

            //Se muestra despues de modificaciones
            imprimirLineaSeparadora('=', ANCHO_DE_CONSOLA);
            mostrarPelicula(pelicula);
            imprimirSaltosDeLinea(2);
            imprimirLineaSeparadora('=', ANCHO_DE_CONSOLA);
            imprimirSaltosDeLinea(2);
        }
    }else{
        //Si no existe se devuelve al menu anterior
        printf("EL TITULO INGRESADO NO EXISTE\n");
        system("pause");
        system("cls");
    }
}

void spEliminarPelicula (stMemoria * memoria) {

    char tituloPelicula[DIM_TITULO_PELICULA];
    char control = 0;
    int idPelicula;
    stPelicula aux;

    //Se pide el dato a buscar
    printf("INGRESE EL TITULO DE LA PELICULA: ");
    obtenerStringDeUsuario(tituloPelicula, DIM_TITULO_PELICULA);

    //Se comprueba si existe
    idPelicula = existePelicula(tituloPelicula, memoria->peliculas, memoria->vPeliculas);

    if(idPelicula >= 0) {
        //Si existe una pelicula con ese titulo se copia en aux
        aux = memoria->peliculas[idPelicula];

        if(aux.eliminado == 1){
            //Si se encuentra eliminada aca termina la funcion
            printf("%s ya se encuentra eliminada del sistema.\n", aux.titulo);
        }else{
            //Si no esta eliminada se muestra
            imprimirLineaSeparadora('=', strlen(aux.titulo));
            printf("%s", aux.titulo);
            imprimirSaltosDeLinea(1);
            imprimirLineaSeparadora('=', strlen(aux.titulo));
            imprimirSaltosDeLinea(2);

            //Se confirma que se quiera eliminar
            printf("SI SE ELIMINA DEL SISTEMA NO SE PODRA RECUPERAR\n");
            printf("Enter para eliminar o cualquier tecla para cancelar\n");
            control = getch();
            if(control == 13){
                aux.eliminado = 1;
                sobreescribirPelicula(memoria, aux);
                system("cls");
                printf("pelicula eliminada exitosamente. \n");
            }
        }
    }

    system("pause");
}

void spDarDeBajaPelicula (stMemoria * memoria) {

    stPelicula aux;
    char tituloPelicula[DIM_TITULO_PELICULA];
    char control = 0;
    char control2 = 0;
    int idPelicula;

    //Se pide el dato a buscar
    printf("INGRESE EL TITULO DE LA PELICULA: ");
    obtenerStringDeUsuario(tituloPelicula, DIM_TITULO_PELICULA);

    //Se comprueba si existe
    idPelicula = existePelicula(tituloPelicula, memoria->peliculas, memoria->vPeliculas);

    if(idPelicula >= 0) {
        //Si existe una pelicula con ese titulo se copia en aux
        aux = memoria->peliculas[idPelicula];

        if(aux.eliminado == 1){
            //Si se encuentra eliminada aca termina la funcion
            printf("%s ya se encuentra eliminada del sistema.\n", aux.titulo);
        }else if (aux.eliminado == 2){
            //Si ya esta dada de baja se pregunta si se quiere dar de alta
            printf("%s ya se encuentra dada de baja del sistema.\n", aux.titulo);
            printf("Si desea darla de alta presione enter\n");
            control2 = getch();
            if(control2 == 13){
                aux.eliminado = 0;
                sobreescribirPelicula(memoria, aux);
                system("cls");
                printf("\nPELICULA DADA DE ALTA EXITOSAMENTE\n");
            }
        }
        else {
            imprimirLineaSeparadora('=', strlen(aux.titulo));
            printf("%s", aux.titulo);
            imprimirSaltosDeLinea(1);
            imprimirLineaSeparadora('=', strlen(aux.titulo));
            imprimirSaltosDeLinea(2);

            printf("Enter para dar de baja o cualquier tecla para cancelar\n");
            control = getch();
            //Se confirma que se quiere dar de baja
            if(control == 13){
                aux.eliminado = 2;
                sobreescribirPelicula(memoria, aux);
                system("cls");
                printf("\nPELICULA DADA DE BAJA EXITOSAMENTE\n");
            }
        }
    }

    system("pause");
}
