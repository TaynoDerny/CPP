#pragma once
#include "../task_2/Vehicle.h"

class Car : public Vehicle {
public:
    Car(const std::string& model, int year, const Point& position, int doors);
    explicit Car(const std::string& model);

    double getMaxSpeed() const override;
    void print() const override;

    Car& operator++();
    Car operator++(int);

private:
    int doors;
};
