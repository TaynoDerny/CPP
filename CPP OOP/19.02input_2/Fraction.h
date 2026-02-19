#pragma once
class Fraction {
private:
    int numerator;      // числитель
    int denominator;    // знаменатель
    
    // Вспомогательные функции
    int gcd(int a, int b);
    void reduce();
    
public:
    // Функция для ввода данных
    void input();
    
    // Функция для вывода данных
    void display();
    
    // Арифметические операции
    void add(Fraction f1, Fraction f2);
    void subtract(Fraction f1, Fraction f2);
    void multiply(Fraction f1, Fraction f2);
    void divide(Fraction f1, Fraction f2);
    
    // Сравнение дробей
    bool isEqual(Fraction f);
};

