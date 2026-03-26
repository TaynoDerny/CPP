#pragma once
#include "Vehicle.h"

class Car : public Vehicle {
public:
    void startEngine() const override;
    double getMaxSpeed() const override;
    void info() const override;
};
