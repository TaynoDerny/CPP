#pragma once
#include "Shape.h"

class Circle : public Shape {
    double radius;
public:
    Circle();
    Circle(double radius);
    double area() const override;
    double perimeter() const override;
    void printInfo() const override;
};
