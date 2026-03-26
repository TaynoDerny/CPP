#include "ElectricCar.h"

void ElectricCar::startEngine() const { cout << "Electric motor silently started\n"; }
double ElectricCar::getMaxSpeed() const { return 180; }
void ElectricCar::info() const { cout << "I am an electric car\n"; }
