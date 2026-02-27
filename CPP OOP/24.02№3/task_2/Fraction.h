#pragma once
#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;      // числитель
    int denominator;    // знаменатель
    static int count;   // Статический счетчик объектов
    
    // Вспомогательные функции
    int gcd(int a, int b);
    void reduce();
    
public:
    // Конструкторы с делегированием
    Fraction();                                    // Конструктор по умолчанию
    Fraction(int num);                              // Конструктор с одним параметром (целое число)
    Fraction(int num, int denom);                   // Конструктор с параметрами
    Fraction(const Fraction& other);                 // Конструктор копирования
    
    // Деструктор
    ~Fraction();
    
    // inline методы-геттеры
    inline int GetNumerator() const { return numerator; }
    inline int GetDenominator() const { return denominator; }
    
    // Статический метод для получения количества объектов
    static inline int GetCount() { return count; }
    
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
    
    // Функция для вывода данных
    inline void display() const {
        if (denominator == 1) {
            cout << numerator;
        } else if (numerator == 0) {
            cout << "0";
        } else {
            cout << numerator << "/" << denominator;
        }
    }
    
    // Арифметические операции
    Fraction add(const Fraction& f) const;
    Fraction subtract(const Fraction& f) const;
    Fraction multiply(const Fraction& f) const;
    Fraction divide(const Fraction& f) const;
    
    // Сравнение дробей
    inline bool isEqual(const Fraction& f) const {
        return (numerator * f.denominator == f.numerator * denominator);
    }
    
    // Перегруженные операторы
    Fraction operator+(const Fraction& f) const;
    Fraction operator-(const Fraction& f) const;
    Fraction operator*(const Fraction& f) const;
    Fraction operator/(const Fraction& f) const;
    bool operator==(const Fraction& f) const;
};