#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle() : width(0), height(0) {}
Rectangle::Rectangle(double width, double height) : width(width), height(height) {}

double Rectangle::area() const {
    return width * height;
}

double Rectangle::perimeter() const {
    return 2 * (width + height);
}

void Rectangle::printInfo() const {
    std::cout << "Rectangle: width=" << width << " height=" << height << "\n";
    std::cout << "Area: " << area() << "\n";
    std::cout << "Perimeter: " << perimeter() << "\n";
}
