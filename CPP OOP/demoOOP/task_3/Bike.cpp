#include "Bike.h"
#include <iostream>

Bike::Bike(const std::string& model, int year, const Point& position, const std::string& type)
    : Vehicle(model, year, position), type(type) {}

double Bike::getMaxSpeed() const { return 60.0; }

void Bike::print() const {
    std::cout << "Bike: " << model << ", year: " << year
              << ", pos: " << position << ", type: " << type << "\n";
}
