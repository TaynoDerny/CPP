#include "String.h"

// Конструктор по умолчанию - создает пустую строку
String::String() : str(nullptr), len(0) {
    str = new char[1];
    str[0] = '\0';
}

// Конструктор из C-строки 
String::String(const char* s) {
    // Подсчет длины строки
    len = 0;
    while (s[len] != '\0') {
        len++;
    }
    
    // Выделение памяти и копирование символов
    str = new char[len + 1];
    for (int i = 0; i < len; i++) {
        str[i] = s[i];
    }
    str[len] = '\0';
}

// Конструктор копирования 
String::String(const String& other) {
    // Копирование длины
    len = other.len;
    // Выделение памяти
    str = new char[len + 1];
    // Копирование символов
    for (int i = 0; i < len; i++) {
        str[i] = other.str[i];
    }
    str[len] = '\0';
}

// Деструктор - освобождение выделенной памяти
String::~String() {
    delete[] str;
}

// Оператор присваивания 
String& String::operator=(const String& other) {
    if (this != &other) {
        // Освобождение старой памяти
        delete[] str;
        // Копирование длины
        len = other.len;
        // Выделение новой памяти
        str = new char[len + 1];
        // Копирование символов
        for (int i = 0; i < len; i++) {
            str[i] = other.str[i];
        }
        str[len] = '\0';
    }
    return *this;
}

// Оператор * (пересечение) 
String String::operator*(const String& other) const {
    char temp[256];
    int index = 0;
    // Флаг для отслеживания уже добавленных символов
    bool used[256] = {false};

    // Проход по каждому символу первой строки
    for (int i = 0; i < len; i++) {
        // Пропуск если символ уже добавлен
        if (used[(unsigned char)str[i]]) continue;
        
        // Поиск символа во второй строке
        for (int j = 0; j < other.len; j++) {
            if (str[i] == other.str[j]) {
                // Добавление общего символа
                temp[index++] = str[i];
                // Отметка как использованный
                used[(unsigned char)str[i]] = true;
                break;
            }
        }
    }
    // Завершение строки нулевым символом
    temp[index] = '\0';
    
    return String(temp);
}

// Возврат указателя на массив символов 
const char* String::c_str() const {
    return str;
}

// Возврат длины строки
int String::length() const {
    return len;
}
