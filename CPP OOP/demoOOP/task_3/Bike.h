#pragma once
#include "../task_2/Vehicle.h"

class Bike : public Vehicle {
public:
    Bike(const std::string& model, int year, const Point& position, const std::string& type);

    double getMaxSpeed() const override;
    void print() const override;

private:
    std::string type;
};
