#include "Account.h"
#include <iostream>

Account::Account(std::string accNumber, double initialDeposit) 
    : accountNumber(accNumber), balance(initialDeposit) {
    transactions.emplace_back("Initial Deposit", initialDeposit, "2023-01-01");
}

void Account::deposit(double amount) {
    balance += amount;
    transactions.emplace_back("Deposit", amount, "2023-01-02");
    std::cout << "Deposited $" << amount << ". New Balance: $" << balance << std::endl;
}

bool Account::withdraw(double amount) {
    if (amount > balance) {
        std::cout << "Insufficient funds." << std::endl;
        return false;
    }
    balance -= amount;
    transactions.emplace_back("Withdrawal", amount, "2023-01-02");
    std::cout << "Withdrew $" << amount << ". New Balance: $" << balance << std::endl;
    return true;
}

void Account::printAccountInfo() const {
    std::cout << "Account Number: " << accountNumber << std::endl;
    std::cout << "Current Balance: $" << balance << std::endl;
    std::cout << "Transactions:" << std::endl;
    for (const auto& trans : transactions) {
        trans.printTransaction();
    }
}
