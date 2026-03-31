#pragma once
#include <iostream>
using namespace std;
class Point{
    private:
        double x,y;
        static int pointCount;
        

    public:
        Point();
        Point(double x, double y);
        Point(const Point& other);
        Point(Point&& other);
        ~Point();
        Point& operator=(const Point& other);
        Point& operator=(Point&& other);
        bool operator==(const Point& other);
        bool operator!=(const Point& other);
        friend ostream& operator<<(ostream& os, const Point& p);
        friend istream& operator>>(istream& is, Point& p);
        double getX ()const;
        double getY ()const;
        double distance() const;
        static int getCount();
        void setX(double x);
        void setY(double y);
};
