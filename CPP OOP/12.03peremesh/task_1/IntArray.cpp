#include "IntArray.h"
#include <iostream>
#include <cstring>

using namespace std;

// Конструктор по умолчанию
IntArray::IntArray() : data(nullptr), size(0) {
    cout << "Конструктор по умолчанию\n";
}

// Конструктор с размером
IntArray::IntArray(size_t n) : data(new int[n]()), size(n) {
    cout << "Конструктор с размером (n=" << n << ")\n";
}

// Конструктор копирования
IntArray::IntArray(const IntArray& other)
    : data(new int[other.size]), size(other.size) {
    memcpy(data, other.data, size * sizeof(int));
    cout << "Конструктор копирования\n";
}

// Конструктор перемещения
IntArray::IntArray(IntArray&& other) noexcept
    : data(other.data), size(other.size) {
    other.data = nullptr;
    other.size = 0;
    cout << "Конструктор перемещения\n";
}

// Деструктор
IntArray::~IntArray() {
    delete[] data;
    cout << "Деструктор (size=" << size << ")\n";
}

// Оператор присваивания копированием
IntArray& IntArray::operator=(const IntArray& other) {
    if (this == &other) return *this;
    delete[] data;
    size = other.size;
    data = new int[size];
    memcpy(data, other.data, size * sizeof(int));
    cout << "Оператор присваивания копированием\n";
    return *this;
}

// Оператор присваивания перемещением
IntArray& IntArray::operator=(IntArray&& other) noexcept {
    if (this == &other) return *this;
    delete[] data;
    data = other.data;
    size = other.size;
    other.data = nullptr;
    other.size = 0;
    cout << "Оператор присваивания перемещением\n";
    return *this;
}

// Метод вывода
void IntArray::print(const char* label) const {
    cout << label << ": [";
    for (size_t i = 0; i < size; ++i)
        cout << data[i] << (i + 1 < size ? ", " : "");
    cout << "] size=" << size << "\n";
}
