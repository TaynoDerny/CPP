#include "mystring.h"
#include <cstring>

using namespace std;

// Конструктор с параметром-строкой
MyString::MyString(const char* s) {
    length = strlen(s);
    str = new char[length + 1];  // +1 для нуль-терминатора
    strcpy(str, s);
}

// Конструктор с параметром длина строки
MyString::MyString(size_t len) : length(len) {
    str = new char[length + 1];  // выделяем память с запасом
    str[0] = '\0';                // пустая строка
}

// Конструктор копирования
MyString::MyString(const MyString& other) : length(other.length) {
    str = new char[length + 1];
    strcpy(str, other.str);
}

// Деструктор
MyString::~MyString() {
    delete[] str;  // освобождаем динамическую память
}

// Вывод строки на экран
void MyString::display() const {
    cout << str;
}

// Сеттер с возможностью перевыделения памяти
void MyString::set(const char* s) {
    size_t newLength = strlen(s);
    
    // Если новая строка длиннее текущего буфера - перевыделяем память
    if (newLength > length) {
        delete[] str;                    // освобождаем старую память
        str = new char[newLength + 1];   // выделяем новую
        length = newLength;               // обновляем длину
    }
    
    // Копируем строку (в любом случае)
    strcpy(str, s);
}

// Геттер для длины
size_t MyString::getLength() const {
    return length;
}

// Геттер для строки
const char* MyString::c_str() const {
    return str;
}