#pragma once
#include <iostream>
using namespace std;

class Complex {
    double real, imag;
public:
    // Конструкторы
    Complex();
    Complex(double real, double imag = 0);

    // Правило 5
    Complex(const Complex& other);              // копирующий конструктор
    Complex(Complex&& other) noexcept;          // перемещающий конструктор
    Complex& operator=(const Complex& other);   // копирующее присваивание
    Complex& operator=(Complex&& other) noexcept; // перемещающее присваивание
    ~Complex();

    // Методы
    double getReal() const;
    double getImag() const;

    // () — возвращает модуль комплексного числа sqrt(a²+b²)
    double operator()() const;

    // Обычная перегрузка (методы класса)
    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;

    // Дружественная перегрузка (свободные функции с доступом к private)
    friend ostream& operator<<(ostream& os, const Complex& c);
    friend istream& operator>>(istream& is, Complex& c);
};
