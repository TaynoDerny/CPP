#pragma once
#include <iostream>

using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex();
    Complex(double r);
    Complex(double r, double i);

    friend istream& operator>>(istream& in, Complex& c);
    friend ostream& operator<<(ostream& out, const Complex& c);
    
    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;
    double operator()() const;
};
