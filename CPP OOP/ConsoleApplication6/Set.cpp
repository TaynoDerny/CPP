#include "set.h"
#include <iostream>   // для cerr, endl
#include <cstdlib>    // для exit

using namespace std;

// Вспомогательные методы
int Set::find(int value) const {
    for (int i = 0; i < size; ++i) {
        if (data[i] == value) return i;
    }
    return -1;
}

void Set::ensure_capacity(int new_capacity) {
    if (new_capacity <= capacity) return;
    int* new_data = new int[new_capacity];
    for (int i = 0; i < size; ++i) new_data[i] = data[i];
    delete[] data;
    data = new_data;
    capacity = new_capacity;
}

// Конструкторы и деструктор
Set::Set() : data(nullptr), size(0), capacity(0) {}

Set::Set(int value) : data(new int[1]), size(1), capacity(1) {
    data[0] = value;
}

Set::Set(initializer_list<int> list) : data(nullptr), size(0), capacity(0) {
    for (int x : list) {
        *this += x;
    }
}

Set::Set(const Set& other) : data(new int[other.capacity]), size(other.size), capacity(other.capacity) {
    for (int i = 0; i < size; ++i) data[i] = other.data[i];
}

Set::~Set() {
    delete[] data;
}

// Методы проверки
bool Set::contains(int value) const {
    return find(value) != -1;
}

bool Set::isEmpty() const {
    return size == 0;
}

int Set::getSize() const {
    return size;
}

// Операторы сравнения
bool Set::operator==(const Set& other) const {
    if (size != other.size) return false;
    for (int i = 0; i < size; ++i) {
        if (!other.contains(data[i])) return false;
    }
    return true;
}

bool Set::operator!=(const Set& other) const {
    return !(*this == other);
}

bool Set::operator!() const {
    return isEmpty();
}

// Доступ
int Set::operator[](int index) const {
    // Простая проверка индекса; при ошибке выводим сообщение и завершаем программу
    if (index < 0 || index >= size) {
        cerr << "Ошибка: индекс вне диапазона в operator[]" << endl;
        exit(1);
    }
    return data[index];
}

bool Set::operator()(int value) const {
    return contains(value);
}

// Присваивание и swap
Set& Set::operator=(const Set& other) {
    if (this != &other) {
        Set temp(other);
        swap(temp);
    }
    return *this;
}

void Set::swap(Set& other) noexcept {
    // Ручной обмен вместо std::swap
    int* tempData = data;
    data = other.data;
    other.data = tempData;

    int tempSize = size;
    size = other.size;
    other.size = tempSize;

    int tempCapacity = capacity;
    capacity = other.capacity;
    other.capacity = tempCapacity;
}

// Добавление/удаление одного элемента
Set& Set::operator+=(int value) {
    if (!contains(value)) {
        if (size == capacity) {
            ensure_capacity(capacity == 0 ? 1 : capacity * 2);
        }
        data[size++] = value;
    }
    return *this;
}

Set Set::operator+(int value) const {
    Set result(*this);
    result += value;
    return result;
}

Set& Set::operator-=(int value) {
    int idx = find(value);
    if (idx != -1) {
        for (int i = idx; i < size - 1; ++i) data[i] = data[i + 1];
        --size;
    }
    return *this;
}

Set Set::operator-(int value) const {
    Set result(*this);
    result -= value;
    return result;
}

// Операции с множествами
Set& Set::operator+=(const Set& other) {
    for (int i = 0; i < other.size; ++i) {
        *this += other.data[i];
    }
    return *this;
}

Set Set::operator+(const Set& other) const {
    Set result(*this);
    result += other;
    return result;
}

Set& Set::operator-=(const Set& other) {
    for (int i = 0; i < other.size; ++i) {
        *this -= other.data[i];
    }
    return *this;
}

Set Set::operator-(const Set& other) const {
    Set result(*this);
    result -= other;
    return result;
}

Set& Set::operator*=(const Set& other) {
    Set temp;
    for (int i = 0; i < size; ++i) {
        if (other.contains(data[i])) {
            temp += data[i];
        }
    }
    *this = temp;
    return *this;
}

Set Set::operator*(const Set& other) const {
    Set result(*this);
    result *= other;
    return result;
}

// Потоковый вывод
ostream& operator<<(ostream& os, const Set& s) {
    os << '{';
    for (int i = 0; i < s.size; ++i) {
        if (i > 0) os << ' ';
        os << s.data[i];
    }
    os << '}';
    return os;
}

// Потоковый ввод
istream& operator>>(istream& is, Set& s) {
    s = Set();  // очистить текущее множество
    char ch;
    is >> ch;
    if (ch != '{') {
        is.setstate(ios::failbit);
        return is;
    }
    while (is >> ws && is.peek() != '}') {
        int value;
        if (is >> value) {
            s += value;
        }
        else {
            is.setstate(ios::failbit);
            return is;
        }
    }
    is >> ch;
    if (ch != '}') {
        is.setstate(ios::failbit);
    }
    return is;
}

// Внешний оператор
Set operator+(int value, const Set& s) {
    return s + value;
}