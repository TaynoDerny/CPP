#pragma once
#include <string>
#include "../task_1/Point.h"

class Vehicle {
public:
    Vehicle(const std::string& model, int year, const Point& position);
    Vehicle(const Vehicle& other);
    explicit Vehicle(const std::string& model);
    virtual ~Vehicle() {}

    virtual double getMaxSpeed() const = 0;
    virtual void print() const = 0;

    void move(const Point& newPos);

    static int totalVehicles;

protected:
    std::string model;
    int year;
    Point position;
};
