#include "set.h"
#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    // Демонстрация конструкторов
    Set a;                      // пустое
    Set b{ 1, 2, 3, 2 };           // из списка (дубликат 2 игнорируется)
    Set c(5);                    // от int -> {5}
    Set d = b;                   // копирование

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "c: " << c << endl;
    cout << "d (копия b): " << d << endl;

    // Проверка принадлежности
    cout << "b содержит 2? " << b.contains(2) << " (через метод)" << endl;
    cout << "b содержит 2? " << b(2) << " (через operator())" << endl;

    // Доступ по индексу
    // Порядок элементов не гарантирован, но доступ возможен
    cout << "Первый элемент b: " << b[0] << endl;

    // Операции с элементами
    b += 4;          // добавление
    b -= 2;          // удаление
    cout << "b после +=4 и -=2: " << b << endl;

    Set e = b + 10;  // добавление через бинарный +
    cout << "e = b + 10: " << e << endl;

    // Операции с множествами
    Set x{ 1, 2, 3 };
    Set y{ 2, 3, 4 };
    cout << "x: " << x << ", y: " << y << endl;
    cout << "x + y (объединение): " << x + y << endl;
    cout << "x - y (разность): " << x - y << endl;
    cout << "x * y (пересечение): " << x * y << endl;

    // Присваивание и сравнение
    Set z;
    z = x;
    cout << "z = x: " << z << endl;
    cout << "z == x? " << (z == x) << endl;
    cout << "z != y? " << (z != y) << endl;

    // Проверка пустоты
    Set empty;
    cout << "empty пусто? " << !empty << endl;

    // Ввод из потока (пример: введите {1 2 3} или {} )
    cout << "Введите множество в формате { a b c }: ";
    cin >> a;
    cout << "Вы ввели: " << a << endl;

    return 0;
}