#include "Fraction.h"
#include <cmath>

// Конструктор по умолчанию с инициализатором
Fraction::Fraction() : numerator(0), denominator(1) {
    cout << "Конструктор Fraction по умолчанию" << endl;
}

// Конструктор с параметрами с инициализатором
Fraction::Fraction(int num, int denom) : numerator(num), denominator(denom) {
    cout << "Конструктор Fraction с параметрами" << endl;
    if (denominator == 0) {
        cout << "Ошибка: знаменатель не может быть равен 0! Установлено значение 1." << endl;
        denominator = 1;
    }
    reduce();
}

// Конструктор копирования с инициализатором
Fraction::Fraction(const Fraction& other) : numerator(other.numerator), denominator(other.denominator) {
    cout << "Конструктор копирования Fraction" << endl;
}

// Деструктор
Fraction::~Fraction() {
    cout << "Деструктор Fraction" << endl;
}

// Нахождение НОД (алгоритм Евклида)
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

// Сложение дробей
Fraction Fraction::add(const Fraction& f) const {
    int new_num = numerator * f.denominator + f.numerator * denominator;
    int new_den = denominator * f.denominator;
    return Fraction(new_num, new_den);
}

// Вычитание дробей
Fraction Fraction::subtract(const Fraction& f) const {
    int new_num = numerator * f.denominator - f.numerator * denominator;
    int new_den = denominator * f.denominator;
    return Fraction(new_num, new_den);
}

// Умножение дробей
Fraction Fraction::multiply(const Fraction& f) const {
    int new_num = numerator * f.numerator;
    int new_den = denominator * f.denominator;
    return Fraction(new_num, new_den);
}

// Деление дробей
Fraction Fraction::divide(const Fraction& f) const {
    if (f.numerator == 0) {
        cout << "Ошибка: деление на ноль!" << endl;
        return Fraction(0, 1);
    }
    int new_num = numerator * f.denominator;
    int new_den = denominator * f.numerator;
    return Fraction(new_num, new_den);
}

// Перегруженные операторы
Fraction Fraction::operator+(const Fraction& f) const {
    return add(f);
}

Fraction Fraction::operator-(const Fraction& f) const {
    return subtract(f);
}

Fraction Fraction::operator*(const Fraction& f) const {
    return multiply(f);
}

Fraction Fraction::operator/(const Fraction& f) const {
    return divide(f);
}

bool Fraction::operator==(const Fraction& f) const {
    return isEqual(f);
}