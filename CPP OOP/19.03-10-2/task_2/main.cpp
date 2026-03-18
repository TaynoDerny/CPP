#include <iostream>
#include "time.cpp"
using namespace std;

int main() {
    cout << "=== Демонстрация класса Time ===\n\n";

    // Конструкторы
    Time t1(10, 30, 45);
    Time t2(12, 0, 0);
    Time t3;

    cout << "Созданы объекты времени:\n";
    cout << "  t1 = " << t1 << endl;
    cout << "  t2 = " << t2 << endl;
    cout << "  t3 (по умолчанию) = " << t3 << "\n\n";

    // Функция addSecond
    cout << "Добавляем 1 секунду к t1:\n";
    t1.addSecond();
    cout << "  t1 = " << t1 << "\n\n";

    // Префиксный ++
    cout << "Префиксный ++t1:\n";
    ++t1;
    cout << "  t1 = " << t1 << "\n\n";

    // Постфиксный ++
    cout << "Постфиксный t1++:\n";
    Time old = t1++;
    cout << "  старое значение = " << old << endl;
    cout << "  новое t1 = " << t1 << "\n\n";

    // Префиксный --
    cout << "Префиксный --t1:\n";
    --t1;
    cout << "  t1 = " << t1 << "\n\n";

    // Постфиксный --
    cout << "Постфиксный t1--:\n";
    old = t1--;
    cout << "  старое значение = " << old << endl;
    cout << "  новое t1 = " << t1 << "\n\n";

    // += и -=
    cout << "t1 += 120 секунд:\n";
    t1 += 120;
    cout << "  t1 = " << t1 << "\n\n";

    cout << "t1 -= 60 секунд:\n";
    t1 -= 60;
    cout << "  t1 = " << t1 << "\n\n";

    // Сравнения
    cout << "Сравнение t1 и t2:\n";
    cout << "  t1 = " << t1 << endl;
    cout << "  t2 = " << t2 << endl;
    
    cout << "  t1 == t2: ";
    if (t1 == t2) cout << "да"; else cout << "нет";
    cout << endl;

    cout << "  t1 != t2: ";
    if (t1 != t2) cout << "да"; else cout << "нет";
    cout << endl;

    cout << "  t1 > t2: ";
    if (t1 > t2) cout << "да"; else cout << "нет";
    cout << endl;

    cout << "  t1 < t2: ";
    if (t1 < t2) cout << "да"; else cout << "нет";
    cout << "\n\n";

    // () — общее количество секунд
    cout << "Общее количество секунд в t1 = " << t1 << ": " << t1() << " сек\n\n";

    // Копирование
    Time copy = t1;
    cout << "Копия t1: " << copy << "\n\n";

    // Ввод от пользователя
    cout << "Введите время:\n";
    Time input;
    cin >> input;
    cout << "Вы ввели: " << input << endl;
    cout << "Это " << input() << " секунд от начала суток\n";

    return 0;
}
