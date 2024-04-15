#include "Transaccion.h"
#include <iostream>

Transaccion::Transaccion(std::string tipo, double monto, std::string fecha) 
    : tipo(tipo), monto(monto), fecha(fecha) {}

void Transaccion::imprimirTransaccion() const {
    std::cout << fecha << " - " << tipo << " - $" << monto << std::endl;
}
