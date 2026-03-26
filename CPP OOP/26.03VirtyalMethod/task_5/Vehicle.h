#pragma once
#include <iostream>
using namespace std;

class Vehicle {
public:
    virtual ~Vehicle() = default;
    virtual void startEngine() const;
    virtual double getMaxSpeed() const;
    virtual void info() const;
};
