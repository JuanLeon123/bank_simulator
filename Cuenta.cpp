#include "Cuenta.h"
#include <iostream>

Cuenta::Cuenta(std::string numCuenta, double depositoInicial) 
    : numeroCuenta(numCuenta), saldo(depositoInicial) {
    transacciones.emplace_back("Deposito inicial", depositoInicial, "2023-01-01");
}

void Cuenta::depositar(double monto) {
    saldo += monto;
    transacciones.emplace_back("Deposito", monto, "2023-01-02");
    std::cout << "Depositados $" << monto << ". Nuevo Saldo: $" << saldo << std::endl;
}

bool Cuenta::retirar(double monto) {
    if (monto > saldo) {
        std::cout << "Fondos insuficientes." << std::endl;
        return false;
    }
    saldo -= monto;
    transacciones.emplace_back("Retiro", monto, "2023-01-02");
    std::cout << "Retirados $" << monto << ". Nuevo Saldo: $" << saldo << std::endl;
    return true;
}

void Cuenta::imprimirInformacion() const {
    std::cout << "Numero de Cuenta: " << numeroCuenta << std::endl;
    std::cout << "Saldo Actual: $" << saldo << std::endl;
    std::cout << "Transacciones:" << std::endl;
    for (const auto& trans : transacciones) {
        trans.imprimirTransaccion();
    }
}
