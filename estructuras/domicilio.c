#include <stdio.h>
#include "domicilio.h"

void mostrarDomicilio(stDomicilio domicilio){
    printf("Direccion: %s %d, ", domicilio.calle, domicilio.altura);
    printf("%s, %s, %s.\n", domicilio.ciudad, domicilio.localidad, domicilio.pais);
    printf("CP: %d\n", domicilio.cp);
}
