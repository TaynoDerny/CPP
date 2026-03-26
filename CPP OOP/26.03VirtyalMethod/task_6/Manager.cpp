#include "Manager.h"

Manager::Manager(const string& name, double fixedSalary)
    : Employee(name), fixedSalary(fixedSalary) {}

double Manager::calculateSalary() const { return fixedSalary; }

void Manager::displayInfo() const {
    cout << "Manager: " << name << "\nSalary: $" << calculateSalary() << "\n";
}
