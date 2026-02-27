#pragma once
#include <iostream>
using namespace std;

class String {
private:
    char* str;          // Указатель на строку
    int length;         // Длина строки
    static int objectCount;  // Статический счетчик объектов

public:
    // Конструкторы
    String();                               // Конструктор по умолчанию (80 символов)
    String(int size);                        // Конструктор с произвольным размером
    String(const char* input);                // Конструктор с инициализацией от пользователя
    
    // Деструктор
    ~String();
    
    // Методы ввода/вывода
    void input();                            // Ввод строки с клавиатуры
    void output() const;                      // Вывод строки на экран
    
    // Статическая функция для получения количества объектов
    static int getObjectCount();
    
    // Геттер для длины (может пригодиться)
    int getLength() const;
};

