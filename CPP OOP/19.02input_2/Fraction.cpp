#include <iostream>
#include "Fraction.h"
using namespace std;

// Нахождение НОД 
int Fraction::gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Сокращение дроби
void Fraction::reduce() {
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
    
    int divisor = gcd(numerator, denominator);
    if (divisor != 0) {
        numerator /= divisor;
        denominator /= divisor;
    }
}

// Ввод данных
void Fraction::input() {
    cout << "Введите числитель: ";
    cin >> numerator;
    
    do {
        cout << "Введите знаменатель (не может быть 0): ";
        cin >> denominator;
        if (denominator == 0) {
            cout << "Знаменатель не может быть равен 0! Попробуйте снова." << endl;
        }
    } while (denominator == 0);
    
    reduce();
}

// Вывод данных
void Fraction::display() {
    if (denominator == 1) {
        cout << numerator;
    } else if (numerator == 0) {
        cout << "0";
    } else {
        cout << numerator << "/" << denominator;
    }
}

// Сложение дробей
void Fraction::add(Fraction f1, Fraction f2) {
    numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    denominator = f1.denominator * f2.denominator;
    reduce();
}

// Вычитание дробей
void Fraction::subtract(Fraction f1, Fraction f2) {
    numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
    denominator = f1.denominator * f2.denominator;
    reduce();
}

// Умножение дробей
void Fraction::multiply(Fraction f1, Fraction f2) {
    numerator = f1.numerator * f2.numerator;
    denominator = f1.denominator * f2.denominator;
    reduce();
}

// Деление дробей
void Fraction::divide(Fraction f1, Fraction f2) {
    numerator = f1.numerator * f2.denominator;
    denominator = f1.denominator * f2.numerator;
    reduce();
}

// Сравнение дробей
bool Fraction::isEqual(Fraction f) {
    return (numerator * f.denominator == f.numerator * denominator);
}