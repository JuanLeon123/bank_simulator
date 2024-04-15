#include <iostream>
#include <string>
#include "Bank.h"

int main() {
    Bank bank;
    std::string numeroCuenta, cuentaDestino;
    double cantidad;
    int opcion;

    while (true) {
        std::cout << "\n*** Bank Simulator ***\n";
        std::cout << "1. Crear una cuenta\n";
        std::cout << "2. depositarar\n";
        std::cout << "3. Retirar\n";
        std::cout << "4. Transferir\n";
        std::cout << "5. Informacion de cuenta\n";
        std::cout << "6. Salir\n";
        std::cout << "Elija una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                std::cout << "Digitar numero de cuenta ";
                std::cin >> numeroCuenta;
                std::cout << "Digitar un depositaro inicial: ";
                std::cin >> cantidad;
                bank.crearCuenta(numeroCuenta, cantidad);
                break;
            case 2:
                std::cout << "Digitar numero de cuenta: ";
                std::cin >> numeroCuenta;
                std::cout << "Digitar cantidad a depositarar: ";
                std::cin >> cantidad;
                bank.depositararACuenta(numeroCuenta, cantidad);
                break;
            case 3:
                std::cout << "Digitar numero de cuenta: ";
                std::cin >> numeroCuenta;
                std::cout << "Digitar cantidad a retirar: ";
                std::cin >> cantidad;
                bank.retirarDeCuenta(numeroCuenta, cantidad);
                break;
            case 4:
                std::cout << "Digitar numero de cuenta de origen: ";
                std::cin >> numeroCuenta;
                std::cout << "Digitar numero de cuenta de destino: ";
                std::cin >> cuentaDestino;
                std::cout << "Digitar cantidad a transferir: ";
                std::cin >> cantidad;
                bank.transferir(numeroCuenta, cuentaDestino, cantidad);
                break;
            case 5:
                std::cout << "Digitar numero de cuenta: ";
                std::cin >> numeroCuenta;
                bank.mostrarDetallesCuenta(numeroCuenta);
                break;
            case 6:
                std::cout << "Saliendo del programa...";
                return 0;
            default:
                std::cout << "Opcion invalida. Intente nuevamente.\n";
                break;
        }
    }

    return 0;
}
