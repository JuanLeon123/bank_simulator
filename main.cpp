#include "Banco.h"
#include <iostream>

int main() {
    Banco banco;
    std::string numeroCuenta, aCuenta;
    double monto;
    int opcion;

    while (true) {
        std::cout << "\n*** Simulador de Banco ***\n";
        std::cout << "1. Crear cuenta\n";
        std::cout << "2. Depositar\n";
        std::cout << "3. Retirar\n";
        std::cout << "4. Transferir\n";
        std::cout << "5. Detalles de la cuenta\n";
        std::cout << "6. Salir\n";
        std::cout << "Ingrese su opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                std::cout << "Ingrese el numero de cuenta: ";
                std::cin >> numeroCuenta;
                std::cout << "Ingrese el deposito inicial: ";
                std::cin >> monto;
                banco.crearCuenta(numeroCuenta, monto);
                break;
            case 2:
                std::cout << "Ingrese el numero de cuenta: ";
                std::cin >> numeroCuenta;
                std::cout << "Ingrese el monto a depositar: ";
                std::cin >> monto;
                banco.depositarEnCuenta(numeroCuenta, monto);
                break;
            case 3:
                std::cout << "Ingrese el numero de cuenta: ";
                std::cin >> numeroCuenta;
                std::cout << "Ingrese el monto a retirar: ";
                std::cin >> monto;
                banco.retirarDeCuenta(numeroCuenta, monto);
                break;
            case 4:
                std::cout << "Ingrese el numero de cuenta de origen: ";
                std::cin >> numeroCuenta;
                std::cout << "Ingrese el numero de cuenta destino: ";
                std::cin >> aCuenta;
                std::cout << "Ingrese el monto a transferir: ";
                std::cin >> monto;
                banco.transferir(numeroCuenta, aCuenta, monto);
                break;
            case 5:
                std::cout << "Ingrese el numero de cuenta: ";
                std::cin >> numeroCuenta;
                banco.imprimirDetallesCuenta(numeroCuenta);
                break;
            case 6:
                std::cout << "Saliendo del programa.";
                return 0;
            default:
                std::cout << "Opcion no valida. Intente de nuevo.\n";
                break;
        }
    }

    return 0;
}
