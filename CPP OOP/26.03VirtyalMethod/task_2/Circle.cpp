#include "Circle.h"
#include <iostream>
#include <math.h>

Circle::Circle() : radius(0) {}
Circle::Circle(double radius) : radius(radius) {}

double Circle::area() const {
    return M_PI * radius * radius;
}

double Circle::perimeter() const {
    return 2 * M_PI * radius;
}

void Circle::printInfo() const {
    std::cout << "Circle: radius=" << radius << "\n";
    std::cout << "Area: " << area() << "\n";
    std::cout << "Perimeter: " << perimeter() << "\n";
}
