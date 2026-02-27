#include "String.h"
#include <cstring>
#include <cstdlib>
using namespace std;

// Инициализация статической переменной
int String::objectCount = 0;

// Конструктор по умолчанию - строка 80 символов
String::String() : String(80) {
    // Делегирование конструктору с параметром
}

// Конструктор с произвольным размером
String::String(int size) {
    length = size;
    str = new char[length + 1];  // +1 для нуль-терминатора
    str[0] = '\0';  // Пустая строка
    objectCount++;
    cout << "Создан объект String (размер " << length << "). Всего объектов: " << objectCount << endl;
}

// Конструктор с инициализацией от пользователя
String::String(const char* input) {
    length = strlen(input);
    str = new char[length + 1];
    strcpy(str, input);
    objectCount++;
    cout << "Создан объект String с текстом. Всего объектов: " << objectCount << endl;
}

// Деструктор
String::~String() {
    delete[] str;
    objectCount--;
    cout << "Уничтожен объект String. Осталось объектов: " << objectCount << endl;
}

// Метод ввода строки с клавиатуры
void String::input() {
    cout << "Введите строку: ";
    char buffer[1000];  // Временный буфер
    cin.getline(buffer, 1000);
    
    // Если текущий буфер недостаточен, перераспределяем память
    if (strlen(buffer) > length) {
        delete[] str;
        length = strlen(buffer);
        str = new char[length + 1];
    }
    
    strcpy(str, buffer);
}

// Метод вывода строки на экран
void String::output() const {
    cout << "Строка: " << str << " (длина: " << length << ")" << endl;
}

// Статическая функция для получения количества объектов
int String::getObjectCount() {
    return objectCount;
}

// Геттер для длины
int String::getLength() const {
    return length;
}