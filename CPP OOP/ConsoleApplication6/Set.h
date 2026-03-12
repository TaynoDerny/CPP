#pragma once

#include <iostream>  // для istream/ostream

class Set {
private:
    int* data;
    int size;
    int capacity;

    int find(int value) const;
    void ensure_capacity(int new_capacity);

public:
    // Конструкторы и деструктор
    Set();
    explicit Set(int value);
    explicit Set(std::initializer_list<int> list);
    Set(const Set& other);
    ~Set();

    // Методы
    bool contains(int value) const;
    bool isEmpty() const;
    int getSize() const;

    // Операторы сравнения
    bool operator==(const Set& other) const;
    bool operator!=(const Set& other) const;
    bool operator!() const;

    // Доступ
    int operator[](int index) const;  // без проверки индекса (для скорости) или с проверкой? Мы добавим проверку с выходом.
    bool operator()(int value) const;

    // Присваивание
    Set& operator=(const Set& other);
    void swap(Set& other) noexcept;

    // Добавление/удаление элемента
    Set& operator+=(int value);
    Set operator+(int value) const;
    Set& operator-=(int value);
    Set operator-(int value) const;

    // Операции с множествами
    Set& operator+=(const Set& other);
    Set operator+(const Set& other) const;
    Set& operator-=(const Set& other);
    Set operator-(const Set& other) const;
    Set& operator*=(const Set& other);
    Set operator*(const Set& other) const;

    // Дружественные функции для ввода/вывода
    friend std::ostream& operator<<(std::ostream& os, const Set& s);
    friend std::istream& operator>>(std::istream& is, Set& s);
};

// Внешний оператор для int + Set
Set operator+(int value, const Set& s);

