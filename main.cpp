#include "Banco.h"
#include <iostream>
#include <string>
#include <limits>
#include <cctype>

// Prototipos de las funciones
bool esNumero(const std::string& str);
double obtenerMontoValido();
std::string obtenerNumeroDeCuentaValido();

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

        // Verificar que la entrada sea un número entero.
        if (std::cin.fail()) {
            std::cin.clear(); // Limpia el estado de fallo de cin.
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta la entrada hasta la próxima línea.
            std::cout << "Entrada inválida. Por favor, ingrese un número entero.\n";
            continue;
        }

        switch (opcion) {
            case 1:
                numeroCuenta = obtenerNumeroDeCuentaValido();
                monto = obtenerMontoValido();
                banco.crearCuenta(numeroCuenta, monto);
                break;
                case 2:
                numeroCuenta = obtenerNumeroDeCuentaValido();
                monto = obtenerMontoValido();
                banco.depositarEnCuenta(numeroCuenta, monto);
                break;
            case 3:
                numeroCuenta = obtenerNumeroDeCuentaValido();
                monto = obtenerMontoValido();
                banco.retirarDeCuenta(numeroCuenta, monto);
                break;
            case 4:
                std::cout << "Ingrese el numero de cuenta de origen: ";
                numeroCuenta = obtenerNumeroDeCuentaValido();
                std::cout << "Ingrese el numero de cuenta destino: ";
                aCuenta = obtenerNumeroDeCuentaValido();
                monto = obtenerMontoValido();
                banco.transferir(numeroCuenta, aCuenta, monto);
                break;
            case 5:
                numeroCuenta = obtenerNumeroDeCuentaValido();
                banco.imprimirDetallesCuenta(numeroCuenta);
                break;
            case 6:
                std::cout << "Saliendo del programa.\n";
                return 0;
            default:
                std::cout << "Opcion no valida. Intente de nuevo.\n";
                break;
        }
    }
    return 0;
}

bool esNumero(const std::string& str) {
    for (char const &ch : str) {
        if (!std::isdigit(ch)) return false;
    }
    return true;
}

double obtenerMontoValido() {
    double monto;
    do {
        std::cout << "Ingrese un monto valido (mayor a 0): ";
        std::cin >> monto;
        if (std::cin.fail() || monto <= 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            monto = -1;
        }
    } while (monto <= 0);
    return monto;
}

std::string obtenerNumeroDeCuentaValido() {
    std::string numeroCuenta;
    do {
        std::cout << "Ingrese el numero de cuenta (solo numeros): ";
        std::cin >> numeroCuenta;
        if (!esNumero(numeroCuenta)) {
            std::cout << "El numero de cuenta debe contener solo numeros.\n";
            numeroCuenta = ""; // Resetear el numero de cuenta para el bucle
        }
    } while (numeroCuenta.empty());
    return numeroCuenta;
}