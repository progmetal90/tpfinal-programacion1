#include "interfaz.h"

stInterfaz inicializarInterfaz(){
    stInterfaz interfaz = {
        .historial = {SM_LOGIN}, // Primer menu siempre sera id 0 (pantalla login)
        .posHistorial = 0, // Inicializa interfaz en la primer posicion (login)

        // Declaracion de menus
        {
            {
                .idMenu = 0,
                .titulo = "LOGIN",
                .opcionesUsuario = {
                    "Iniciar sesion",
                    "Crear nuevo usuario",
                },
                .cantOpcionesUsuario = 2,
                .opcionesAdmin = {
                },
                .cantOpcionesAdmin = 0,
                .menuObjetivoUsuario = {
                    SP_INICIAR_SESION,
                    SP_CREAR_USUARIO,
                }, // TODO: definir constantes para cada menu, no usar nros magicos
                .menuObjetivoAdmin = {
                }
            },
            {
                .idMenu = 1,
                .titulo = "MENU PRINCIPAL",
                .opcionesUsuario = {
                    "Agregar pelicula",
                    "Filtrar pelicula",
                    "Agregar comentario",
                    "Modificar datos de usuario",
                },
                .cantOpcionesUsuario = 4,
                .opcionesAdmin = {
                    "Modificar usuarios",
                    "OpcionAdmin 2",
                },
                .cantOpcionesAdmin = 2,
                .menuObjetivoUsuario = {
                    1, // placeholder
                    2,
                    1,
                    },
                .menuObjetivoAdmin = {
                    1,
                    1}
            },
            {
                .idMenu = 2,
                .titulo = "FILTRAR PELICULA",
                .opcionesUsuario = {
                    "Filtrar por NOMBRE",
                    "Filtrar por DIRECTOR",
                    "Filtrar por ESTUDIO",
                },
                .cantOpcionesUsuario = 3,
                .opcionesAdmin = {
                },
                .cantOpcionesAdmin = 0,
                .menuObjetivoUsuario = {
                    2, // placeholder
                    2,
                    2,
                    },
                .menuObjetivoAdmin = {
                }
            },
        }
    };

    return interfaz;
}

void ejecutarInterfaz(stInterfaz interfaz, stControlador * controlador){
    int opcion;
    int idMenuActual;
    stMenu menuActual;
    int idProximoMenu;

    // Posicion menor a 0 indica que salimos del login (cerrar programa)
    while(interfaz.posHistorial >= 0){
        system("cls");

        if(interfaz.posHistorial == 0 && controlador->usuarioLogueado){
            // Si se inicio sesion correctamente, navegar hacia el menu principal
            interfaz.posHistorial++;
            interfaz.historial[1] = SM_MENU_PRINCIPAL;
        }

        idMenuActual = interfaz.historial[interfaz.posHistorial];
        menuActual = interfaz.menus[idMenuActual];
        mostrarMenu(menuActual);

        printf("\nIngrese una opcion: ");
        obtenerOpcion(&opcion);

        if(opcion == 0){
            // Volver atras en el menu
            interfaz.posHistorial--;

            if(controlador->usuarioLogueado){
                if(interfaz.posHistorial == 0 && confirmarSalida("Desea cerrar sesion?") == 1){
                    // Cierra sesion y vuelve al login
                    controlador->usuarioLogueado = NULL;
                }
                else{
                    // Regresa al menu principal
                    interfaz.posHistorial = 1;
                }
            }
        }
        else if (validarOpcion(opcion, menuActual.cantOpcionesUsuario, menuActual.cantOpcionesAdmin)){
            idProximoMenu = interfaz.menus[interfaz.posHistorial].menuObjetivoUsuario[opcion - 1];
            // TODO: hacer un IF para opciones de admin

            if(idProximoMenu >= 1000){
                // Es un subprograma, ejecutar por switch
                // No cambiar historial
                // Posiblemente en una libreria aparte (controlador)
                ejecutarSubprograma(idProximoMenu, controlador);
            }
            else if(idProximoMenu != idMenuActual){
                // Navegar hacia el proximo menu
                interfaz.posHistorial++;
                interfaz.historial[interfaz.posHistorial] = idProximoMenu;
            }
        }

        if(interfaz.posHistorial == -1 && !confirmarSalida("Desea salir del programa?")){
            interfaz.posHistorial = 0;
        }
    }
}

int confirmarSalida(char mensaje[]){
    int confirma = 1;
    char opcion = 's';

    printf(mensaje);
    printf(" Presione ESC para salir, u otra tecla para continuar.");
    fflush(stdin);
    opcion = getch();

    if(opcion != 27){
        confirma = 0;
    }

    return confirma;
}

int obtenerIdProximoMenu(stMenu menu, int opcion){
    int idProximoMenu;

    if(opcion > 0 && opcion < 10){
        // Es submenu usuario
        idProximoMenu = menu.menuObjetivoUsuario[opcion - 1];
    }
    else if(opcion > 100 && opcion < 110){
        // Es submenu admin
        idProximoMenu = menu.menuObjetivoAdmin[opcion - 101];
    }
    else{
        // Si esto aparece en pantalla, hay algo roto :)
        printf("Opcion invalida!\n");
        system("pause");
    }

    return idProximoMenu;
}

void obtenerOpcion(int * opcion){
    // TODO: sanitizar input
    // Esta entrada de momento solo puede recibir numeros. Cosas MALAS pasaran si recibe cualquier otra cosa.

    // Considerar si scanf es suficiente o si es necesario usar otra forma para capturar input.
    // Un combo de gets() y atoi por ahi es mas versatil
    // Se podria recibir tanto strings como numeros, pero tambien complicaria las cosas
    scanf("%d", opcion);
}

int validarOpcion(int opcion, int validosUsuario, int validosAdmin){
    int valido = 1;

    // Chequea que la opcion sea valida
    if(!(enRango(opcion, USUARIO_MENU_OFFSET, USUARIO_MENU_OFFSET + validosUsuario) || enRango(opcion, ADMIN_MENU_OFFSET, ADMIN_MENU_OFFSET + validosAdmin))){
        valido = 0;
    }

    return valido;
}
