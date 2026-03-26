#pragma once
#include "Employee.h"

class Engineer : public Employee {
    double hourlyRate;
    int hours;
public:
    Engineer(const string& name, double hourlyRate, int hours);
    double calculateSalary() const override;
    void displayInfo() const override;
};
