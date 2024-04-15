#include "Banco.h"
#include <iostream>

void Banco::crearCuenta(const std::string& numCuenta, double depositoInicial) {
    if (cuentas.find(numCuenta) != cuentas.end()) {
        std::cout << "La cuenta ya existe." << std::endl;
        return;
    }
    cuentas[numCuenta] = std::make_shared<Cuenta>(numCuenta, depositoInicial);
    std::cout << "Cuenta creada exitosamente." << std::endl;
}

void Banco::depositarEnCuenta(const std::string& numCuenta, double monto) {
    auto it = cuentas.find(numCuenta);
    if (it == cuentas.end()) {
        std::cout << "Cuenta no encontrada." << std::endl;
        return;
    }
    it->second->depositar(monto);
}

void Banco::retirarDeCuenta(const std::string& numCuenta, double monto) {
    auto it = cuentas.find(numCuenta);
    if (it == cuentas.end()) {
        std::cout << "Cuenta no encontrada." << std::endl;
        return;
    }
    it->second->retirar(monto);
}

void Banco::transferir(const std::string& deCuenta, const std::string& aCuenta, double monto) {
    auto it_from = cuentas.find(deCuenta);
    auto it_to = cuentas.find(aCuenta);
    if (it_from == cuentas.end() || it_to == cuentas.end()) {
        std::cout << "Una o ambas cuentas no se encuentran." << std::endl;
        return;
    }
    if (it_from->second->retirar(monto)) {
        it_to->second->depositar(monto);
        std::cout << "Transferidos $" << monto << " de " << deCuenta << " a " << aCuenta << "." << std::endl;
    }
}

void Banco::imprimirDetallesCuenta(const std::string& numCuenta) const {
    auto it = cuentas.find(numCuenta);
    if (it == cuentas.end()) {
        std::cout << "Cuenta no encontrada." << std::endl;
        return;
    }
    it->second->imprimirInformacion();
}
