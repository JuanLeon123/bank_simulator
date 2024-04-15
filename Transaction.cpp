#include "Transaccion.h"
#include <iostream>

Transaccion::Transaccion(std::string tipo, double cantidad, std::string fecha) 
    : type(tipo), cantidad(cantidad), date(fecha) {}

void Transaccion::mostrarTransaccion() const {
    std::cout << fecha << " - " << tipo << " - $" << cantidad << std::endl;
}
