#include "Cuenta.h"
#include <iostream>

Account::Account(std::string numeroCuenta, double depositoInicial) 
    : numeroCuenta(numeroCuenta), saldo(depositoInicial) {
    transacciones.emplace_back("Deposito inicial", depositoInicial, "2023-01-01");
}

void Account::depositar(double cantidad) {
    saldo += cantidad;
    transacciones.emplace_back("Deposito", cantidad, "2023-01-02");
    std::cout << "Depositado $" << cantidad << ". Nuevo saldo: $" << saldo << std::endl;
}

bool Account::retiro(double cantidad) {
    if (cantidad > saldo) {
        std::cout << "Fondos insuficientes" << std::endl;
        return false;
    }
    saldo -= cantidad;
    transacciones.emplace_back("Retiro", cantidad, "2023-01-02");
    std::cout << "Retirado $" << cantidad << ". Nuevo saldo: $" << saldo << std::endl;
    return true;
}

void Account::mostrarDetallesCuenta() const {
    std::cout << "Numero Cuenta: " << numeroCuenta << std::endl;
    std::cout << "Saldo Total: $" << saldo << std::endl;
    std::cout << "Transacciones:" << std::endl;
    for (const auto& transacciones : transacciones) {
        transacciones.mostrarTransaccion();
    }
}
