#pragma once
#include "Employee.h"

class Manager : public Employee {
    double fixedSalary;
public:
    Manager(const string& name, double fixedSalary);
    double calculateSalary() const override;
    void displayInfo() const override;
};
