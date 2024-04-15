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
    void createAccount(const std::string& accountNumber, double initialDeposit);
    void depositToAccount(const std::string& accountNumber, double amount);
    void withdrawFromAccount(const std::string& accountNumber, double amount);
    void transfer(const std::string& fromAccount, const std::string& toAccount, double amount);
    void printAccountDetails(const std::string& accountNumber) const;
};

#endif
