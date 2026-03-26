#include "Rectangle.h"
#include <iostream>
using namespace std;

Rectangle::Rectangle(int x, int y, int w, int h) : x(x), y(y), w(w), h(h) {}

void Rectangle::draw() const {
    cout << "Drawing rectangle at (" << x << "," << y << ") width " << w << " height " << h << "\n";
}

string Rectangle::serialize() const {
    return "Rectangle " + to_string(x) + " " + to_string(y) + " " + to_string(w) + " " + to_string(h);
}
