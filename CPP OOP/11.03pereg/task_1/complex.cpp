#include "complex.h"
#include <cmath>

using namespace std;

Complex::Complex() : real(0), imag(0) {}

Complex::Complex(double r) : real(r), imag(0) {}

Complex::Complex(double r, double i) : real(r), imag(i) {}

istream& operator>>(istream& in, Complex& c) {
    in >> c.real >> c.imag;
    return in;
}

ostream& operator<<(ostream& out, const Complex& c) {
    out << c.real;
    if (c.imag >= 0)
        out << "+" << c.imag << "i";
    else
        out << c.imag << "i";
    return out;
}

Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, imag + other.imag);
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(real - other.real, imag - other.imag);
}

bool Complex::operator==(const Complex& other) const {
    return real == other.real && imag == other.imag;
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

double Complex::operator()() const {
    return sqrt(real * real + imag * imag);
}
