#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>
#include "Transaction.h"

class Account {
private:
    std::string accountNumber;
    double balance;
    std::vector<Transaction> transactions;

public:
    Account(std::string accNumber, double initialDeposit);
    void deposit(double amount);
    bool withdraw(double amount);
    void printAccountInfo() const;
    std::string getAccountNumber() const;
    double getBalance() const;
};

#endif
