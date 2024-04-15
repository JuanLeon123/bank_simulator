#ifndef TRANSACCION_H
#define TRANSACCION_H

#include <string>

class Transaccion {
private:
    std::string tipo;
    double cantidad;
    std::string fecha;

public:
    Transaccion(std::string tipo, double cantidad, std::string fecha);
    void mostrarTransaccion() const;
};

#endif
