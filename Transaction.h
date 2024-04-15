#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction {
private:
    std::string type;
    double amount;
    std::string date;

public:
    Transaction(std::string type, double amount, std::string date);
    void printTransaction() const;
};

#endif
