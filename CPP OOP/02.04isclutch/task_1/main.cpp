#include <iostream>
#include "BankAccount.cpp"

using namespace std;

int main() {
    // Отрицательный начальный баланс
    try {
        BankAccount acc("Alice", -100);
    } catch (const invalid_argument& e) {
        cout << "Invalid argument: " << e.what() << "\n";
    }

    BankAccount acc("Bob", 500);

    // Отрицательная сумма снятия
    try {
        acc.withdraw(-50);
    } catch (const invalid_argument& e) {
        cout << "Invalid argument: " << e.what() << "\n";
    }

    // Недостаточно средств
    try {
        acc.withdraw(1000);
    } catch (const runtime_error& e) {
        cout << "Runtime error: " << e.what() << "\n";
    }

    // Успешное снятие
    acc.withdraw(200);
    cout << "Balance after withdrawal: " << acc.getBalance() << "\n";

    return 0;
}
