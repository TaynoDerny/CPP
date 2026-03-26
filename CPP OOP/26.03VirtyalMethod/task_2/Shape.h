#pragma once 
#include <iostream>
class Shape {
public:
    Shape(){}
    virtual ~Shape()=default;
    virtual double perimeter() const = 0;
    virtual double area() const = 0;
    virtual void printInfo() const = 0;
        
};