#ifndef CUENTA_H
#define CUENTA_H

#include <string>
#include <vector>
#include "Transaccion.h"

class Cuenta {
private:
    std::string numeroCuenta;
    double saldo;
    std::vector<Transaccion> transacciones;

public:
    Cuenta(std::string numeroCuenta, double depositoInicial);
    void depositar(double monto);
    bool retirar(double monto);
    void imprimirInformacion() const;
};

#endif // CUENTA_H
