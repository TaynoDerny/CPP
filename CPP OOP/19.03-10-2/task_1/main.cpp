#include <iostream>
#include "complex.cpp"
using namespace std;

int main() {
    cout << "=== Демонстрация класса Комплексное число ===\n\n";

    // Конструкторы
    Complex a(3, 4);
    Complex b(1, -2);
    Complex c;

    cout << "Созданы числа:\n";
    cout << "  a = " << a << endl;
    cout << "  b = " << b << endl;
    cout << "  c (по умолчанию) = " << c << "\n\n";

    // + и -
    cout << "Арифметика:\n";
    cout << "  a + b = " << (a + b) << endl;
    cout << "  a - b = " << (a - b) << "\n\n";

    // == и !=
    cout << "Сравнение:\n";
    cout << "  a == b: ";
    if (a == b) cout << "да"; else cout << "нет";
    cout << endl;

    cout << "  a != b: ";
    if (a != b) cout << "да"; else cout << "нет";
    cout << endl;

    cout << "  a == a: ";
    if (a == a) cout << "да"; else cout << "нет";
    cout << "\n\n";

    // () — модуль числа
    cout << "Модуль числа a = " << a << " равен: " << a() << "\n\n";

    // Копирующий конструктор
    Complex copy(a);
    cout << "Копия числа a: " << copy << "\n\n";

    // Перемещающий конструктор
    Complex moved(move(a));
    cout << "Перемещение числа a:\n";
    cout << "  moved = " << moved << endl;
    cout << "  a после перемещения = " << a << "\n\n";

    // Ввод от пользователя
    cout << "Введите комплексное число:\n";
    Complex input;
    cin >> input;
    cout << "Вы ввели: " << input << endl;
    cout << "Его модуль: " << input() << endl;

    return 0;
}
