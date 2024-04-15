#include "Bank.h"
#include <iostream>

void Bank::crearCuenta(const std::string& numeroCuenta, double depositaroInicial) {
    if (cuentas.find(numeroCuenta) != cuentas.end()) {
        std::cout << "Cuenta existente." << std::endl;
        return;
    }
    cuentas[numeroCuenta] = std::make_shared<Account>(numeroCuenta, depositaroInicial);
    std::cout << "Cuenta creada con exito." << std::endl;
}

void Bank::depositararACuenta(const std::string& numeroCuenta, double cantidad) {
    auto it = cuentas.find(numeroCuenta);
    if (it == cuentas.end()) {
        std::cout << "Cuenta no encontrada." << std::endl;
        return;
    }
    it->second->depositar(cantidad);
}

void Bank::retirarDeCuenta(const std::string& numeroCuenta, double cantidad) {
    auto it = cuentas.find(numeroCuenta);
    if (it == cuentas.end()) {
        std::cout << "Cuenta no encontrada." << std::endl;
        return;
    }
    it->second->retirar(cantidad);
}

void Bank::transferir(const std::string& cuentaOrigen, const std::string& cuentaDestino, double cantidad) {
    auto it_from = cuentas.find(cuentaOrigen);
    auto it_to = cuentas.find(cuentaDestino);
    if (it_from == cuentas.end() || it_to == cuentas.end()) {
        std::cout << "Una o ambas cuentas no encontradas." << std::endl;
        return;
    }

    if (it_from->second->retirar(cantidad)) {
        it_to->second->depositar(cantidad);
        std::cout << "Transferido $" << cantidad << " desde " << cuentaOrigen << " hacia " << cuentaDestino << "." << std::endl;
    }
}


void Bank::mostrarDetallesCuenta(const std::string& numeroCuenta) const {
    auto it = cuentas.find(numeroCuenta);
    if (it == cuentas.end()) {
        std::cout << "Cuenta no encontrada." << std::endl;
        return;
    }
    it->second->mostrarDetallesCuenta();
}
