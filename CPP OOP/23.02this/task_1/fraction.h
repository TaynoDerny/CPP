#pragma once
#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;

    // Нахождение наибольшего общего делителя
    int gcd(int a, int b) const;
    
    // Сокращение дроби
    void reduce();

public:
    // Конструктор с параметрами (использует список инициализации)
    Fraction(int num, int denom);
    
    // Конструктор по умолчанию (делегирование конструктору с параметрами)
    Fraction();
    
    // Вывод на экран
    void display() const;
    
    // Сложение дроби с дробью
    Fraction* add(const Fraction& other);
    
    // Вычитание дроби из дроби
    Fraction* subtract(const Fraction& other);
    
    // Умножение дроби на дробь
    Fraction* multiply(const Fraction& other);
    
    // Сложение дроби с целым числом
    Fraction* add(int number);
    
    // Вычитание целого числа из дроби
    Fraction* subtract(int number);
    
    // Умножение дроби на целое число
    Fraction* multiply(int number);
    
    // Геттеры
    int getNumerator() const;
    int getDenominator() const;
};

