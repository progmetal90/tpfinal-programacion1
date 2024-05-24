#include "domicilio.h"
// TODO: averiguar por que no es necesario incluir mock

stDomicilio cargarDomicilioRandom(){
    stDomicilio domicilio;

    // Cargar otros valores
    cargarCalleRandom(domicilio.calle);
    domicilio.altura = rand()%10000;
    domicilio.cp = rand()%10000;

    return domicilio;
}
