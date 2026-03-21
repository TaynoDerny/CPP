#include "IntArray.h"
#include <iostream>

using namespace std;

int main() {
    cout << "--- Создание объекта ---\n";
    IntArray a(5);
    for (size_t i = 0; i < a.size; ++i) a.data[i] = (int)i + 1;
    a.print("a");

    cout << "\n--- Копирование (lvalue) ---\n";
    IntArray b = a; // вызов конструктора копирования
    b.print("b");

    cout << "\n--- Перемещение из временного объекта ---\n";
    IntArray c = IntArray(3); // конструктор перемещения (временный объект)
    c.print("c");

    cout << "\n--- Перемещение с std::move ---\n";
    IntArray d = std::move(a); // конструктор перемещения
    d.print("d");
    a.print("a (после move)"); // a теперь пуст

    cout << "\n--- Присваивание копированием ---\n";
    IntArray e(2);
    e = b; // copy assignment
    e.print("e");

    cout << "\n--- Присваивание перемещением ---\n";
    IntArray f(2);
    f = std::move(b); // move assignment
    f.print("f");
    b.print("b (после move)"); // b теперь пуст

    cout << "\n--- Уничтожение объектов ---\n";
    return 0;
}
