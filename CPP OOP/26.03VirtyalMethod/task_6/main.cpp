#include <iostream>
#include <vector>
#include "Manager.h"
#include "Engineer.h"
#include "SalesPerson.h"
using namespace std;

int main() {
    vector<Employee*> employees = {
        new Manager("Alice", 5000),
        new Engineer("Bob", 30, 160),
        new SalesPerson("Charlie", 2000, 50000, 0.05)
    };

    double total = 0;
    for (Employee* e : employees) {
        e->displayInfo();
        total += e->calculateSalary();
        cout << "\n";
    }

    cout << "Total payroll: $" << total << "\n";

    for (Employee* e : employees)
        delete e;

    return 0;
}
