#pragma once

#include <iostream>

using namespace std;

class Circle {
private:
    double radius;
public:
    Circle(double r = 0.0);

    double getRadius() const;
    void setRadius(double r);

    bool operator==(const Circle& other) const;
    bool operator>(const Circle& other) const;
    Circle& operator+=(double delta);
    Circle& operator-=(double delta);
    Circle& operator=(const Circle& other);

    friend ostream& operator<<(ostream& os, const Circle& c);
};