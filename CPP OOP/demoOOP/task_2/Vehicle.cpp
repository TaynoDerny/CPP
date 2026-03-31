#include "Vehicle.h"

int Vehicle::totalVehicles = 0;

Vehicle::Vehicle(const std::string& model, int year, const Point& position)
    : model(model), year(year), position(position) {
    totalVehicles++;
}

Vehicle::Vehicle(const Vehicle& other)
    : model(other.model), year(other.year), position(other.position) {
    totalVehicles++;
}

Vehicle::Vehicle(const std::string& model)
    : model(model), year(2020), position(Point(0, 0)) {
    totalVehicles++;
}

void Vehicle::move(const Point& newPos) {
    position = newPos;
}
