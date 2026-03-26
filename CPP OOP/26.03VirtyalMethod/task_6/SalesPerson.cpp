#include "SalesPerson.h"

SalesPerson::SalesPerson(const string& name, double baseSalary, double salesAmount, double commissionRate)
    : Employee(name), baseSalary(baseSalary), salesAmount(salesAmount), commissionRate(commissionRate) {}

double SalesPerson::calculateSalary() const { return baseSalary + salesAmount * commissionRate; }

void SalesPerson::displayInfo() const {
    cout << "SalesPerson: " << name << " (base $" << baseSalary
         << " + " << commissionRate * 100 << "% of $" << salesAmount << ")\n"
         << "Salary: $" << calculateSalary() << "\n";
}
