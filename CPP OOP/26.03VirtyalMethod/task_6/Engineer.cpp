#include "Engineer.h"

Engineer::Engineer(const string& name, double hourlyRate, int hours)
    : Employee(name), hourlyRate(hourlyRate), hours(hours) {}

double Engineer::calculateSalary() const { return hourlyRate * hours; }

void Engineer::displayInfo() const {
    cout << "Engineer: " << name << " (" << hours << " hours at $" << hourlyRate << "/hour)\n"
         << "Salary: $" << calculateSalary() << "\n";
}
