#pragma once
#include "Employee.h"

class SalesPerson : public Employee {
    double baseSalary, salesAmount, commissionRate;
public:
    SalesPerson(const string& name, double baseSalary, double salesAmount, double commissionRate);
    double calculateSalary() const override;
    void displayInfo() const override;
};
