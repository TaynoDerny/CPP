#pragma once
#include "Shape.h"

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle();
    Rectangle(double width, double height);
    double area() const override;
    double perimeter() const override;
    void printInfo() const override;
};
