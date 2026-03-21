#pragma once
#include <cstddef>

class IntArray {
public:
    int*   data;
    size_t size;

    IntArray();                          // конструктор по умолчанию
    explicit IntArray(size_t n);         // конструктор с размером
    IntArray(const IntArray& other);     // конструктор копирования
    IntArray(IntArray&& other) noexcept; // конструктор перемещения
    ~IntArray();                         // деструктор

    IntArray& operator=(const IntArray& other);     // присваивание копированием
    IntArray& operator=(IntArray&& other) noexcept; // присваивание перемещением

    void print(const char* label) const;
};
