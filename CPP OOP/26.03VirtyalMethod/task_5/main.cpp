#include <iostream>
#include <vector>
#include "Car.h"
#include "ElectricCar.h"
#include "Bicycle.h"
using namespace std;

int main() {
    vector<Vehicle*> vehicles = { new Car(), new ElectricCar(), new Bicycle() };

    for (Vehicle* v : vehicles) {
        v->startEngine();
        cout << "Max speed: " << v->getMaxSpeed() << " km/h\n";
        v->info();
        cout << "\n";
    }

    for (Vehicle* v : vehicles)
        delete v;

    return 0;
}
