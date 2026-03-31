#include <iostream>
#include <cmath>
#include "Point.h"
using namespace std;

int Point::pointCount = 0;  

Point::Point() : x(0), y(0) { pointCount++; }
Point::Point(double x, double y) : x(x), y(y) { pointCount++; }
Point::Point(const Point& other) : x(other.x), y(other.y) { pointCount++; }
Point::Point(Point&& other) : x(other.x), y(other.y) { other.x = 0; other.y = 0; pointCount++; }
Point::~Point() { pointCount--; }
Point& Point::operator=(const Point& other) {
    x = other.x;
    y = other.y;
    return *this;
}

Point& Point::operator=(Point&& other) {
    x = other.x;
    y = other.y;
    other.x = 0;
    other.y = 0;
    return *this;
}
bool Point::operator==(const Point& other){
    if (x==other.x && y==other.y){
        return true;
    }
    else {
        return false;
    }
}
bool Point::operator!=(const Point& other){
    if (x==other.x && y==other.y){
        return false;
    }
    else {
        return true;
    }

}

ostream& operator<<(ostream& os, const Point& p) {
    os << "(" << p.x << "; " << p.y << ")";
    return os;
}

istream& operator>>(istream& is, Point& p) {
    is >> p.x >> p.y;
    return is;
}


void Point::setX(double x){ this->x = x; }
void Point::setY(double y){ this->y = y; }

double Point::getX ()const { return x; }
double Point::getY ()const { return y; }

int Point::getCount() { return pointCount; }

double Point::distance() const {
    return sqrt(x * x + y * y);
}