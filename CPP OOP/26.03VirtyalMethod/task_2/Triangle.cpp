#include "Triangle.h"
#include <iostream>
#include <math.h>

Triangle::Triangle() : a(0), b(0), c(0) {}

Triangle::Triangle(double a, double b, double c) : a(a), b(b), c(c) {}

double Triangle::perimeter() const{
    return a+b+c;
}
double Triangle::area() const{
    double p =perimeter()/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

void Triangle::printInfo() const{
    std::cout << "Triangle: a=" << a << " b=" << b << " c=" << c << std::endl;
    std::cout << "Area: " << area() << "\n";
    std::cout << "Perimeter: " << perimeter() << "\n";
}