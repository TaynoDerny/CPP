#pragma once
#include <string>

class BankAccount {
    std::string owner;
    double balance;
public:
    BankAccount(const std::string& owner, double initialBalance);
    void withdraw(double amount);
    double getBalance() const { return balance; }
};
