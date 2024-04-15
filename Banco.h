#ifndef BANCO_H
#define BANCO_H

#include <unordered_map>
#include <memory>
#include "Cuenta.h"

class Banco {
private:
    std::unordered_map<std::string, std::shared_ptr<Cuenta>> cuentas;

public:
    void crearCuenta(const std::string& numeroCuenta, double depositoInicial);
    void depositarEnCuenta(const std::string& numeroCuenta, double monto);
    void retirarDeCuenta(const std::string& numeroCuenta, double monto);
    void transferir(const std::string& deCuenta, const std::string& aCuenta, double monto);
    void imprimirDetallesCuenta(const std::string& numeroCuenta) const;
};

#endif
