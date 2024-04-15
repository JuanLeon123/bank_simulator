#include <iostream>
#include <string>
#include "Bank.h"

int main() {
    Bank bank;
    std::string accountNumber, toAccount;
    double amount;
    int choice;

    while (true) {
        std::cout << "\n*** Bank Simulator ***\n";
        std::cout << "1. Create Account\n";
        std::cout << "2. Deposit\n";
        std::cout << "3. Withdraw\n";
        std::cout << "4. Transfer\n";
        std::cout << "5. Account Info\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                std::cout << "Enter initial deposit: ";
                std::cin >> amount;
                bank.createAccount(accountNumber, amount);
                break;
            case 2:
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                std::cout << "Enter amount to deposit: ";
                std::cin >> amount;
                bank.depositToAccount(accountNumber, amount);
                break;
            case 3:
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                std::cout << "Enter amount to withdraw: ";
                std::cin >> amount;
                bank.withdrawFromAccount(accountNumber, amount);
                break;
            case 4:
                std::cout << "Enter from account number: ";
                std::cin >> accountNumber;
                std::cout << "Enter to account number: ";
                std::cin >> toAccount;
                std::cout << "Enter amount to transfer: ";
                std::cin >> amount;
                bank.transfer(accountNumber, toAccount, amount);
                break;
            case 5:
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                bank.printAccountDetails(accountNumber);
                break;
            case 6:
                std::cout << "Exiting program.";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}
