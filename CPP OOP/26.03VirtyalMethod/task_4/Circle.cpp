#include "Circle.h"
#include <iostream>
using namespace std;

Circle::Circle(int x, int y, int r) : x(x), y(y), r(r) {}

void Circle::draw() const {
    cout << "Drawing circle at (" << x << "," << y << ") with radius " << r << "\n";
}

string Circle::serialize() const {
    return "Circle " + to_string(x) + " " + to_string(y) + " " + to_string(r);
}
