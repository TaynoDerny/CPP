#include "Circle.h"

using namespace std;

Circle::Circle(double r) : radius(r) {}

double Circle::getRadius() const {
    return radius;
}

void Circle::setRadius(double r) {
    radius = r;
}

bool Circle::operator==(const Circle& other) const {
    return radius == other.radius;
}

bool Circle::operator>(const Circle& other) const {
    return radius > other.radius;
}

Circle& Circle::operator+=(double delta) {
    radius += delta;
    return *this;
}

Circle& Circle::operator-=(double delta) {
    radius -= delta;
    if (radius < 0) radius = 0;
    return *this;
}

Circle& Circle::operator=(const Circle& other) {
    if (this != &other) {
        radius = other.radius;
    }
    return *this;
}

ostream& operator<<(ostream& os, const Circle& c) {
    os << "Circle(radius=" << c.radius << ")";
    return os;
}