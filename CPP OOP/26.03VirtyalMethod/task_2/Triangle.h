#pragma once 
#include "Shape.h"
class Triangle : public Shape
{
private:
    double a, b, c;
public:
    Triangle();
    Triangle(double a, double b,double c);
    double perimeter() const;
    double area() const;
    void printInfo() const;
};