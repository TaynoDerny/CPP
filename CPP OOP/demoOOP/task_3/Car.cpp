#include "Car.h"
#include <iostream>

Car::Car(const std::string& model, int year, const Point& position, int doors)
    : Vehicle(model, year, position), doors(doors) {}

Car::Car(const std::string& model)
    : Vehicle(model), doors(4) {}

double Car::getMaxSpeed() const { return 180.0; }

void Car::print() const {
    std::cout << "Car: " << model << ", year: " << year<< ", position: " << position << ", doors: " << doors << "\n";
}

Car& Car::operator++() {
    ++doors;
    return *this;
}

Car Car::operator++(int) {
    Car tmp = *this;
    ++doors;
    return tmp;
}
