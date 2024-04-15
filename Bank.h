#ifndef BANK_H
#define BANK_H

#include <unordered_map>
#include <memory>
#include <string>
#include "Account.h"

class Bank {
private:
    std::unordered_map<std::string, std::shared_ptr<Account>> accounts;

public:
    void crearCuenta(const std::string& numeroCuenta, double depositaroInicial);
    void depositararACuenta(const std::string& numeroCuenta, double cantidad);
    void retirarDeCuenta(const std::string& numeroCuenta, double cantidad);
    void transferir(const std::string& cuentaOrigen, const std::string& cuentaDestino, double cantidad);
    void mostrarDetallesCuenta(const std::string& numeroCuenta) const;
};

#endif
