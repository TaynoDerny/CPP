#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

class MyString {
private:
    size_t length;        // Длина без учета нуль-терминатора
    char* str;            // Указатель на блок памяти (динамический)

public:
    // Конструктор с параметром-строкой
    MyString(const char* s);
    
    // Конструктор с параметром длина строки
    MyString(size_t len);
    
    // Конструктор копирования
    MyString(const MyString& other);
    
    // Деструктор
    ~MyString();
    
    // Вывод строки на экран
    void display() const;
    
    // Сеттер, принимающий строку
    void set(const char* s);
    
    // Геттер для длины (добавим для удобства)
    size_t getLength() const;
    
    // Геттер для строки (добавим для удобства)
    const char* c_str() const;
};

#endif