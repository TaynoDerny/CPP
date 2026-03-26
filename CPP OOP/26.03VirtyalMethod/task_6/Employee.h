#pragma once
#include <string>
#include <iostream>
using namespace std;

class Employee {
protected:
    string name;
public:
    Employee(const string& name);
    virtual ~Employee() = default;
    virtual double calculateSalary() const = 0;
    virtual void displayInfo() const = 0;
};
