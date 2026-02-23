#pragma once
#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;      // числитель
    int denominator;    // знаменатель
    
    // Вспомогательные функции
    int gcd(int a, int b);  // Не inline, т.к. содержит цикл
    void reduce();          // Не inline, т.к. содержит логику
    
public:
    // Конструкторы
    Fraction();                                    // Конструктор по умолчанию
    Fraction(int num, int denom);                   // Конструктор с параметрами
    Fraction(const Fraction& other);                 // Конструктор копирования
    
    // Деструктор
    ~Fraction();
    
    // inline методы-геттеры
    inline int GetNumerator() const { return numerator; }
    inline int GetDenominator() const { return denominator; }
    
    // inline методы-сеттеры
    inline void SetNumerator(int num) { 
        numerator = num; 
        if (denominator != 0) reduce(); 
    }
    
    inline void SetDenominator(int denom) { 
        if (denom != 0) {
            denominator = denom; 
            reduce();
        } else {
            cout << "Ошибка: знаменатель не может быть 0!" << endl;
        }
    }
    
    // Функция для ввода данных
    void input();
    
    // Функция для вывода данных (inline)
    inline void display() const {
        if (denominator == 1) {
            cout << numerator;
        } else if (numerator == 0) {
            cout << "0";
        } else {
            cout << numerator << "/" << denominator;
        }
    }
    
    // Арифметические операции (изменены для возврата результата)
    Fraction add(const Fraction& f) const;
    Fraction subtract(const Fraction& f) const;
    Fraction multiply(const Fraction& f) const;
    Fraction divide(const Fraction& f) const;
    
    // Сравнение дробей (inline)
    inline bool isEqual(const Fraction& f) const {
        return (numerator * f.denominator == f.numerator * denominator);
    }
    
    // Перегруженные операторы (для удобства)
    Fraction operator+(const Fraction& f) const;
    Fraction operator-(const Fraction& f) const;
    Fraction operator*(const Fraction& f) const;
    Fraction operator/(const Fraction& f) const;
    bool operator==(const Fraction& f) const;
};