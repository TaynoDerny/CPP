#include "fraction.h"
#include <cmath>

using namespace std;

// Нахождение наибольшего общего делителя
int Fraction::gcd(int a, int b) const {
    a = abs(a);
    b = abs(b);
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Сокращение дроби
void Fraction::reduce() {
    if (denominator == 0) {
        cerr << "Ошибка: знаменатель не может быть нулем!" << endl;
        denominator = 1;
    }
    
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
    
    int divisor = gcd(numerator, denominator);
    if (divisor > 1) {
        numerator /= divisor;
        denominator /= divisor;
    }
}

// Конструктор с параметрами (использует список инициализации)
Fraction::Fraction(int num, int denom) : numerator(num), denominator(denom) {
    reduce();
}

// Конструктор по умолчанию (делегирование конструктору с параметрами)
Fraction::Fraction() : Fraction(0, 1) {}

// Вывод на экран
void Fraction::display() const {
    cout << numerator << "/" << denominator;
}

// Сложение дроби с дробью
Fraction* Fraction::add(const Fraction& other) {
    int newNumerator = numerator * other.denominator + other.numerator * denominator;
    int newDenominator = denominator * other.denominator;
    numerator = newNumerator;
    denominator = newDenominator;
    reduce();
    return this;
}

// Вычитание дроби из дроби
Fraction* Fraction::subtract(const Fraction& other) {
    int newNumerator = numerator * other.denominator - other.numerator * denominator;
    int newDenominator = denominator * other.denominator;
    numerator = newNumerator;
    denominator = newDenominator;
    reduce();
    return this;
}

// Умножение дроби на дробь
Fraction* Fraction::multiply(const Fraction& other) {
    numerator *= other.numerator;
    denominator *= other.denominator;
    reduce();
    return this;
}

// Сложение дроби с целым числом
Fraction* Fraction::add(int number) {
    numerator += number * denominator;
    reduce();
    return this;
}

// Вычитание целого числа из дроби
Fraction* Fraction::subtract(int number) {
    numerator -= number * denominator;
    reduce();
    return this;
}

// Умножение дроби на целое число
Fraction* Fraction::multiply(int number) {
    numerator *= number;
    reduce();
    return this;
}

// Геттеры
int Fraction::getNumerator() const {
    return numerator;
}

int Fraction::getDenominator() const {
    return denominator;
}