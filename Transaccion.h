#ifndef TRANSACCION_H
#define TRANSACCION_H

#include <string>

class Transaccion {
private:
    std::string tipo;
    double monto;
    std::string fecha;

public:
    Transaccion(std::string tipo, double monto, std::string fecha);
    void imprimirTransaccion() const;
};

#endif