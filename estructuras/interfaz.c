#include "interfaz.h"

stInterfaz inicializarInterfaz(){
    stInterfaz interfaz = {
        .historial = {SM_LOGIN}, // Primer menu siempre sera id 0 (pantalla login)
        .posHistorial = 0, // Inicializa interfaz en la primer posicion (login)

        // Declaracion de menus de usuario
        {
            {
                .idMenu = SM_LOGIN,
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
                },
                .menuObjetivoAdmin = {
                }
            },
            {
                .idMenu = SM_MENU_PRINCIPAL,
                .titulo = "MENU PRINCIPAL",
                .opcionesUsuario = {
                    "Buscar pelicula",
                    "Agregar pelicula",
                    "Favoritos",
                    "Modificar datos de usuario",
                },
                .cantOpcionesUsuario = 4,
                .opcionesAdmin = {
                    "Ver usuarios",
                    "Eliminar usuario",
                    "Eliminar pelicula",
                },
                .cantOpcionesAdmin = 3,
                .menuObjetivoUsuario = {
                    SM_BUSCAR_PELICULA,
                    SP_AGREGAR_PELICULA,
                    SM_FAVORITOS,
                    SP_MODIFICAR_USUARIO,
                },
                .menuObjetivoAdmin = {
                    SP_VER_USUARIOS,
                    SM_BAJA_USUARIO,
                    SM_BAJA_PELICULA,
                }
            },
            {
                .idMenu = SM_BUSCAR_PELICULA,
                .titulo = "BUSCAR PELICULA",
                .opcionesUsuario = {
                    "Filtrar por NOMBRE",
                    "Filtrar por DIRECTOR",
                    "Filtrar por CATEGORIA",
                },
                .cantOpcionesUsuario = 3,
                .opcionesAdmin = {
                },
                .cantOpcionesAdmin = 0,
                .menuObjetivoUsuario = {
                    SP_FILTRAR_POR_NOMBRE,
                    SP_FILTRAR_POR_DIRECTOR,
                    SP_FILTRAR_POR_CATEGORIA,
                },
                .menuObjetivoAdmin = {
                }
            },
            {
                .idMenu = SM_FAVORITOS,
                .titulo = "FAVORITOS",
                .opcionesUsuario = {
                    "Mostrar favoritos",
                    "Agregar",
                    "Quitar",
                },
                .cantOpcionesUsuario = 3,
                .opcionesAdmin = {
                },
                .cantOpcionesAdmin = 0,
                .menuObjetivoUsuario = {
                    SP_FILTRAR_POR_NOMBRE,
                    SP_FILTRAR_POR_DIRECTOR,
                    SP_FILTRAR_POR_CATEGORIA,
                },
                .menuObjetivoAdmin = {
                }
            },
            {
                .idMenu = SM_BAJA_USUARIO,
                .titulo = "ADMINISTRAR USUARIO",
                .opcionesUsuario = {
                    "Dar de baja",
                    "Eliminar definitivamente",
                },
                .cantOpcionesUsuario = 2,
                .opcionesAdmin = {
                },
                .cantOpcionesAdmin = 0,
                .menuObjetivoUsuario = {
                    SP_BAJA_USUARIO,
                    SP_ELIMINAR_USUARIO,
                },
                .menuObjetivoAdmin = {
                }
            },
            {
                .idMenu = SM_BAJA_PELICULA,
                .titulo = "ADMINISTRAR PELICULA",
                .opcionesUsuario = {
                    "Dar de baja",
                    "Eliminar definitivamente",
                },
                .cantOpcionesUsuario = 2,
                .opcionesAdmin = {
                },
                .cantOpcionesAdmin = 0,
                .menuObjetivoUsuario = {
                    SP_BAJA_PELICULA,
                    SP_ELIMINAR_PELICULA,
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
        menuActual = obtenerMenu(interfaz.menus, idMenuActual);
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
            if(opcion > 100 && controlador->usuarioLogueado->esAdmin == 1){
                // Menu destino admin
                idProximoMenu = interfaz.menus[interfaz.posHistorial].menuObjetivoAdmin[opcion - ADMIN_MENU_OFFSET];
            }
            else{
                // Menu destino usuario
                idProximoMenu = interfaz.menus[interfaz.posHistorial].menuObjetivoUsuario[opcion - USUARIO_MENU_OFFSET];
            }

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

stMenu obtenerMenu(stMenu * menus, int idMenu){
    stMenu aux;
    int encontrado = 0;
    for(int i = 0; i < DIM_ARR_MENU && encontrado == 0; i++){
        if(menus[i].idMenu == idMenu){
            aux = menus[i];
            encontrado = 1;
        }
    }
    return aux;
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

int validarOpcion(int opcion, int validosUsuario, int validosAdmin){
    int valido = 0;

    int esOpcionValidaUsuario = enRango(opcion, USUARIO_MENU_OFFSET, USUARIO_MENU_OFFSET + validosUsuario);
    int esOpcionValidaAdmin = enRango(opcion, ADMIN_MENU_OFFSET, ADMIN_MENU_OFFSET + validosAdmin);

    // Chequea que la opcion sea valida
    if(esOpcionValidaAdmin || esOpcionValidaUsuario){
        valido = 1;
    }

    return valido;
}
