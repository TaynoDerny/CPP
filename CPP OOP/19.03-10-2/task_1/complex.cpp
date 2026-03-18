#include "complex.h"
#include <cmath>

// Конструкторы
Complex::Complex() : real(0), imag(0) {}

Complex::Complex(double real, double imag) : real(real), imag(imag) {}

// Правило 5
Complex::Complex(const Complex& other) : real(other.real), imag(other.imag) {}

Complex::Complex(Complex&& other) noexcept : real(other.real), imag(other.imag) {
    other.real = 0;
    other.imag = 0;
}

Complex& Complex::operator=(const Complex& other) {
    if (this != &other) {
        real = other.real;
        imag = other.imag;
    }
    return *this;
}

Complex& Complex::operator=(Complex&& other) noexcept {
    if (this != &other) {
        real = other.real;
        imag = other.imag;
        other.real = 0;
        other.imag = 0;
    }
    return *this;
}

Complex::~Complex() {}

// Геттеры
double Complex::getReal() const { return real; }
double Complex::getImag() const { return imag; }

// () — модуль числа
double Complex::operator()() const {
    return sqrt(real * real + imag * imag);
}

// Арифметика
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

// Дружественные операторы ввода/вывода
ostream& operator<<(ostream& os, const Complex& c) {
    os << c.real;
    if (c.imag >= 0) os << "+" << c.imag << "i";
    else             os << c.imag << "i";
    return os;
}

istream& operator>>(istream& is, Complex& c) {
    cout << "real: ";
    is >> c.real;
    cout << "imag: ";
    is >> c.imag;
    return is;
}
