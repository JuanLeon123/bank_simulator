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
    void depositar(double cantidad);
    bool retirar(double cantidad);
    void mostrarDetallesCuenta() const;
    std::string obtenerNumeroCuenta() const;
    double obtenerSaldo() const;
};

#endif
