#include "Bank.h"
#include <iostream>

void Bank::createAccount(const std::string& accountNumber, double initialDeposit) {
    if (accounts.find(accountNumber) != accounts.end()) {
        std::cout << "Account already exists." << std::endl;
        return;
    }
    accounts[accountNumber] = std::make_shared<Account>(accountNumber, initialDeposit);
    std::cout << "Account created successfully." << std::endl;
}

void Bank::depositToAccount(const std::string& accountNumber, double amount) {
    auto it = accounts.find(accountNumber);
    if (it == accounts.end()) {
        std::cout << "Account not found." << std::endl;
        return;
    }
    it->second->deposit(amount);
}

void Bank::withdrawFromAccount(const std::string& accountNumber, double amount) {
    auto it = accounts.find(accountNumber);
    if (it == accounts.end()) {
        std::cout << "Account not found." << std::endl;
        return;
    }
    it->second->withdraw(amount);
}

void Bank::transfer(const std::string& fromAccount, const std::string& toAccount, double amount) {
    auto it_from = accounts.find(fromAccount);
    auto it_to = accounts.find(toAccount);
    if (it_from == accounts.end() || it_to == accounts.end()) {
        std::cout << "One or both accounts not found." << std::endl;
        return;
    }

    if (it_from->second->withdraw(amount)) {
        it_to->second->deposit(amount);
        std::cout << "Transferred $" << amount << " from " << fromAccount << " to " << toAccount << "." << std::endl;
    }
}


void Bank::printAccountDetails(const std::string& accountNumber) const {
    auto it = accounts.find(accountNumber);
    if (it == accounts.end()) {
        std::cout << "Account not found." << std::endl;
        return;
    }
    it->second->printAccountInfo();
}
