#pragma once
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class var {
private:
    enum Type { INT, DOUBLE, STRING }; // Тип хранимого значения
    Type type;
    union {
        int intVal;
        double doubleVal;
    } data; // Хранение числовых значений
    string strVal; // Хранение строкового значения

    // Методы конвертации к разным типам
    int toInt() const;
    double toDouble() const;
    string toString() const;

public:
    // Конструкторы
    var();
    var(int val);
    var(double val);
    var(const char* val);
    var(const string& val);
    var(const var& other);

    // Операторы присваивания
    var& operator=(const var& other);
    var& operator=(int val);
    var& operator=(double val);
    var& operator=(const char* val);

    // Арифметические операторы
    var operator+(const var& other) const;
    var operator-(const var& other) const;
    var operator*(const var& other) const;
    var operator/(const var& other) const;

    // Составные операторы присваивания
    var& operator+=(const var& other);
    var& operator-=(const var& other);
    var& operator*=(const var& other);
    var& operator/=(const var& other);

    // Операторы сравнения
    bool operator==(const var& other) const;
    bool operator!=(const var& other) const;
    bool operator<(const var& other) const;
    bool operator>(const var& other) const;
    bool operator<=(const var& other) const;
    bool operator>=(const var& other) const;

    // Преобразования типов
    operator int() const;
    operator double() const;
    operator const char*() const;

    // Вывод значения
    void Show() const;
};
