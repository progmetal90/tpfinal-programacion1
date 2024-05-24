#include "usuario.h"

stUsuario cargarUsuarioRandom(){
    stUsuario usuario;

    usuario.idUsuario = rand()%1000;

    usuario.domicilio = cargarDomicilioRandom();

    return usuario;
}
