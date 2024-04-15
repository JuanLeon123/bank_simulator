#include "Transaction.h"
#include <iostream>

Transaction::Transaction(std::string type, double amount, std::string date) 
    : type(type), amount(amount), date(date) {}

void Transaction::printTransaction() const {
    std::cout << date << " - " << type << " - $" << amount << std::endl;
}
