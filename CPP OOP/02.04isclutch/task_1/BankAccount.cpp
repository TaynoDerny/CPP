#include "BankAccount.h"
#include <stdexcept>

BankAccount::BankAccount(const std::string& owner, double initialBalance)
    : owner(owner), balance(initialBalance) {
    if (initialBalance < 0)
        throw std::invalid_argument("Initial balance cannot be negative");
}

void BankAccount::withdraw(double amount) {
    if (amount < 0)
        throw std::invalid_argument("Withdrawal amount cannot be negative");
    if (amount > balance)
        throw std::runtime_error("Insufficient funds");
    balance -= amount;
}
