#include "interfaz.h"

stInterfaz inicializarInterfaz(){
    stInterfaz interfaz = {
        .historial = {SM_LOGIN}, // Primer menu siempre sera id 0 (pantalla login)
        .posHistorial = 0, // Inicializa interfaz en la primer posicion (login)

        // Declaracion de menus de usuario
        {
            {
                .idMenu = SM_LOGIN,
                .limpiarConsola = 1,
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
                .limpiarConsola = 1,
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
                    "Submenu prueba",
                },
                .cantOpcionesAdmin = 4,
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
                    SP_AGREGAR_COMENTARIO,
                }
            },
            {
                .idMenu = SM_BUSCAR_PELICULA,
                .limpiarConsola = 1,
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
                    SP_FILTRAR_POR_TITULO,
                    SP_FILTRAR_POR_DIRECTOR,
                    SP_FILTRAR_POR_CATEGORIA,
                },
                .menuObjetivoAdmin = {
                }
            },
            {
                .idMenu = SM_FAVORITOS,
                .limpiarConsola = 1,
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
                    SP_FILTRAR_POR_TITULO,
                    SP_FILTRAR_POR_DIRECTOR,
                    SP_FILTRAR_POR_CATEGORIA,
                },
                .menuObjetivoAdmin = {
                }
            },
            {
                .idMenu = SM_INFO_PELICULA,
                .limpiarConsola = 0,
                .titulo = "OPCIONES DE PELICULA",
                .opcionesUsuario = {
                    "Modificar pelicula",
                    "Ver comentarios",
                    "Agregar comentario",
                },
                .cantOpcionesUsuario = 3,
                .opcionesAdmin = {
                },
                .cantOpcionesAdmin = 0,
                .menuObjetivoUsuario = {
                    SP_MODIFICAR_INFO_PELICULA,
                    SM_MOSTRAR_COMENTARIOS, // TODO: convertir a subprograma
                    SP_AGREGAR_COMENTARIO,
                },
                .menuObjetivoAdmin = {
                }
            },
            {
                .idMenu = SM_BAJA_USUARIO,
                .limpiarConsola = 1,
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
                .limpiarConsola = 1,
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
    int esAdmin = 0;

    // Posicion menor a 0 indica que salimos del login (cerrar programa)
    while(interfaz.posHistorial >= 0){
        if(interfaz.posHistorial == 0 && controlador->usuarioLogueado){
            // Si se inicio sesion correctamente, navegar hacia el menu principal
            interfaz.posHistorial++;
            interfaz.historial[1] = SM_MENU_PRINCIPAL;

            esAdmin = controlador->usuarioLogueado->esAdmin;
        }

        idMenuActual = interfaz.historial[interfaz.posHistorial];
        menuActual = obtenerMenu(interfaz.menus, idMenuActual);

        if(menuActual.limpiarConsola == 1){
            system("cls");
        }

        mostrarMenu(menuActual, esAdmin);

        printf("\nIngrese una opcion: ");
        obtenerOpcion(&opcion);

        if(opcion == 0){
            // Volver atras en el menu
            interfaz.posHistorial--;

            if(controlador->usuarioLogueado && interfaz.posHistorial == 0 && confirmarSalida("Desea cerrar sesion?")){
                // Preguntar al usuario si quiere cerrar sesion
                // Cierra sesion y vuelve al login
                controlador->usuarioLogueado = NULL;
                }
        }
        else if (validarOpcion(opcion, menuActual.cantOpcionesUsuario, menuActual.cantOpcionesAdmin)){
            // Opcion ingresada es valida
            if(enRango(opcion, ADMIN_MENU_OFFSET, ADMIN_MENU_OFFSET + MAX_OPCIONES_MENU) && esAdmin == 1){
                // Menu destino admin
                idProximoMenu = interfaz.menus[interfaz.posHistorial].menuObjetivoAdmin[opcion - ADMIN_MENU_OFFSET];
            }
            else if(enRango(opcion, USUARIO_MENU_OFFSET, USUARIO_MENU_OFFSET + MAX_OPCIONES_MENU)){
                // Menu destino usuario
                idProximoMenu = interfaz.menus[interfaz.posHistorial].menuObjetivoUsuario[opcion - USUARIO_MENU_OFFSET];
            }
            else{
                // Destino invalido, mantenerse en el menu actual
                idProximoMenu = idMenuActual;
            }

            if(idProximoMenu >= 1000){
                // Es un subprograma, ejecutar por switch
                // No cambiar historial
                // Posiblemente en una libreria aparte (controlador)
                idProximoMenu = ejecutarSubprograma(idProximoMenu, controlador);
                if(idProximoMenu < 1000){
                    interfaz.posHistorial++;
                    interfaz.historial[interfaz.posHistorial] = idProximoMenu;
                }
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
